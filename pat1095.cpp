/*
	˼·��1.�ýṹ��Record�洢�����¼��ͣ��ʱ��ת��Ϊ��Ϊ��λ���������
	      2.�Ȱ����ƺ���ĸ��˳�������ٰ���¼ʱ���Ⱥ�����
		  3.�������м�¼����Գɹ���Ϊ��Ч��¼������¼���ͣ��ʱ��
		  4.���ͣ��ʱ��������ͣ��ʱ��ĳ��ƺ�

*/


#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Record{

	string plate_number;
	int park_time;
	string status;
};

bool comp1(Record r1, Record r2) {
	if (r1.plate_number != r2.plate_number) return r1.plate_number < r2.plate_number;
	else return r1.park_time < r2.park_time;
}

bool comp2(Record r1, Record r2) {
	return r1.park_time < r2.park_time;
}

map<string, int> park_time_result;		// �洢���ƺŶ�Ӧ��ͣ��ʱ��

int main() {

	int N, K, p_hour, p_min, p_sec;
	cin >> N >> K;
	Record r;
	vector<Record> records, valid_records;		// ���м�¼����Ч��¼
	for (int i = 0; i < N; i++) {
		cin >> r.plate_number;
		scanf("%d:%d:%d", &p_hour, &p_min, &p_sec);
		// ��ʱ��ת��Ϊ��Ϊ��λ
		r.park_time = p_hour * 3600 + p_min * 60 + p_sec;
		cin >> r.status;
		records.push_back(r);
	}

	sort(records.begin(), records.end(), comp1);
	int max_park_time = 0;
	for (int i = 0; i < N - 1; i++) {
		// ���������¼�ĳ��ƺź���һ����¼�ĳ��ƺ���ͬ����������¼��״̬Ϊin��
		//������¼��״̬Ϊout,��ƥ��ɹ�
		if (records[i].plate_number == records[i + 1].plate_number &&
			records[i].status == "in" && records[i + 1].status == "out") {
			valid_records.push_back(records[i]);
			valid_records.push_back(records[i + 1]);
			// �ۼ�ͣ��ʱ��
			park_time_result[records[i].plate_number] +=
				records[i + 1].park_time - records[i].park_time;
			// ��¼���ͣ��ʱ��
			max_park_time = max(park_time_result[records[i].plate_number], max_park_time);
			i++;		// ��Գɹ�����������һ����¼

		}
	}
	// ��ʱ���Ⱥ����Ч��¼����
	sort(valid_records.begin(), valid_records.end(), comp2);

	int numCar = 0;	// ��ʾͣ������
	int record_index = 0;		// ��ʾ��������¼��ʼ��ѯ
	for (int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &p_hour, &p_min, &p_sec);
		int query_time = p_hour * 3600 + p_min * 60 + p_sec;
		for ( ; record_index < valid_records.size(); record_index++) {
			// ��¼ʱ��С�ڲ�ѯʱ�䣬���״̬Ϊin��ͣ������+1��״̬Ϊout��ͣ��ʱ��-1
			if (valid_records[record_index].park_time <= query_time) {
				if (valid_records[record_index].status == "in") {
					numCar++;
					
				}
				else {
					numCar--;
				}
			}
			else{
				break;
			}
		}
		cout << numCar << endl;
	}

	map<string, int>::iterator it;
	for (it = park_time_result.begin(); it != park_time_result.end(); it++) {
		if (it->second == max_park_time) {
			cout << it->first << " ";
		}
	}
	printf("%02d:%02d:%02d", max_park_time / 3600, max_park_time % 3600 / 60, max_park_time % 60);
	return 0;
}