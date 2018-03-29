/*
	˼·��1.�ýṹ��Record�洢ÿһ����¼
		  2.�����м�¼��������
		  3.����Լ�¼������ò������¼��û�гɹ�ͨ����¼�Ĳ�������κ���Ϣ
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int toll[24];	//	��ʱ��ͨ������

struct Record{
	string name;
	int month, day, hour, min;
	bool state;
};

//	�Լ�¼�����߼������ֲ�ͬ����ĸ��˳����ͬ���£��գ�ʱ����ʱ���Ⱥ�˳��
bool comp(Record r1, Record r2) {
	if (r1.name != r2.name) {
		return r1.name < r2.name;
	}
	else if (r1.month != r2.month) {
		return r1.month < r2.month;
	}
	else if (r1.day != r2.day) {
		return r1.day < r2.day;
	}
	else if (r1.hour != r2.hour) {
		return r1.hour < r2.hour;
	}
	else {
		return r1.min < r2.min;
	}
}

//	����ͨ��ʱ��������

float call_charge(Record r1, Record r2, int &last_time) {
	last_time = (r2.day - r1.day) * 24 * 60 + (r2.hour - r1.hour) * 60 + r2.min - r1.min;
	float amount = 0;
	int day1, day2, hour1, hour2, min1, min2;
	day1 = r1.day;
	day2 = r2.day;
	hour1 = r1.hour;
	hour2 = r2.hour;
	min1 = r1.min;
	min2 = r2.min;
	while (day1 < day2 || hour1 < hour2 || min1 < min2) {
		amount += toll[hour1];
		min1 += 1;
		if (min1 == 60) {
			hour1 += 1;
			min1 = 0;
		}
		if (hour1 == 24) {
			day1 += 1;
			hour1 = 0;
		}
	}
	return amount;
}

int main() {

	int N;
	vector<Record> records;
	for (int i = 0; i < 24; i++) {
		cin >> toll[i];
	}
	cin >> N;
	string state;		//	��ʾͨ��״̬
	for (int i = 0; i < N; i++) {
		Record r;
		cin >> r.name;
		scanf("%d:%d:%d:%d", &r.month, &r.day, &r.hour, &r.min);
		cin >> state;
		if (state == "on-line") {
			r.state = true;
		}
		else
		{
			r.state = false;
		}
		records.push_back(r);

	}
	sort(records.begin(), records.end(), comp);
	bool has_online = false;		//	off-lineǰ�Ƿ����online��¼
	Record last_online_record;	//	�ݴ�ǰһ��online��¼
	string current_name = "";			//	��¼��ǰ�û���,��ʼΪ���ַ���
	float amount = 0, total_amount = 0;	//	��Լ�¼���ã�ÿ���˷��ü�¼
	for (int i = 0; i < N; i++) {
		if (records[i].state) {
			last_online_record = records[i];
			has_online = true;
		}
		else {
			if (has_online && last_online_record.name == records[i].name) {
				//	��Գɹ�
				if (records[i].name != current_name) {
					//	���û���¼
					if (current_name != "") {
						//	���ǰһ���û��ܷ���
						printf("Total amount: $%.2f\n", total_amount/100);
					}
					total_amount = 0;
					current_name = records[i].name;
					cout << records[i].name << " ";
					printf("%02d\n", records[i].month);
				}
				//	����ͨ��ʱ���ͷ���
				int last_time = 0;
				amount = call_charge(last_online_record, records[i], last_time);
				total_amount += amount;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
					last_online_record.day, last_online_record.hour, last_online_record.min,
					records[i].day, records[i].hour, records[i].min, last_time, amount/100);
				has_online = false;	//	��ʾһ��ͨ����Խ���

			}
		}
	}
	//	������һ���û���ͨ������
	if (total_amount != 0) {
		printf("Total amount: $%.2f\n", total_amount/100);
	}
	return 0;
}