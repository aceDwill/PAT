/*
	思路：1.用结构体Record存储输入记录，停车时间转化为秒为单位，方便计算
	      2.先按车牌号字母表顺序排序，再按记录时间先后排序
		  3.遍历所有记录，配对成功的为有效记录，并记录最大停车时间
		  4.输出停车时间等于最大停车时间的车牌号

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

map<string, int> park_time_result;		// 存储车牌号对应的停车时间

int main() {

	int N, K, p_hour, p_min, p_sec;
	cin >> N >> K;
	Record r;
	vector<Record> records, valid_records;		// 所有记录和有效记录
	for (int i = 0; i < N; i++) {
		cin >> r.plate_number;
		scanf("%d:%d:%d", &p_hour, &p_min, &p_sec);
		// 将时间转化为秒为单位
		r.park_time = p_hour * 3600 + p_min * 60 + p_sec;
		cin >> r.status;
		records.push_back(r);
	}

	sort(records.begin(), records.end(), comp1);
	int max_park_time = 0;
	for (int i = 0; i < N - 1; i++) {
		// 如果这条记录的车牌号和下一条记录的车牌号相同并且这条记录的状态为in，
		//下条记录的状态为out,则匹配成功
		if (records[i].plate_number == records[i + 1].plate_number &&
			records[i].status == "in" && records[i + 1].status == "out") {
			valid_records.push_back(records[i]);
			valid_records.push_back(records[i + 1]);
			// 累加停车时间
			park_time_result[records[i].plate_number] +=
				records[i + 1].park_time - records[i].park_time;
			// 记录最大停车时间
			max_park_time = max(park_time_result[records[i].plate_number], max_park_time);
			i++;		// 配对成功可以跳过下一条记录

		}
	}
	// 按时间先后对有效记录排序
	sort(valid_records.begin(), valid_records.end(), comp2);

	int numCar = 0;	// 表示停车数量
	int record_index = 0;		// 表示从哪条记录开始查询
	for (int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &p_hour, &p_min, &p_sec);
		int query_time = p_hour * 3600 + p_min * 60 + p_sec;
		for ( ; record_index < valid_records.size(); record_index++) {
			// 记录时间小于查询时间，如果状态为in，停车数量+1，状态为out，停车时间-1
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