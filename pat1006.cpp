/*
	思路：1.构造一个结构体records
		  2.用sort排序

	注意：1.vs2017中使用scanf会报错，解决办法：右键单击工程文件-->属性(最后一个)-------->  c/c++  ------>SDL checks ------------> no.
		  2.scanf函数输入字符串在vs会报错，如scanf("%s",&s)，最好用cin
		  	
*/



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Records
{
	string s;
	int sign_in_hour;
	int sign_in_minute;
	int sign_in_second;
	int sign_out_hour;
	int sign_out_minute;
	int sign_out_second;
};

bool sign_in_compare(Records r1, Records r2) {
	if (r1.sign_in_hour == r2.sign_in_hour) {
		if (r1.sign_in_minute == r2.sign_in_minute) {
			return r1.sign_in_second < r2.sign_in_second;

		}
		else
		{
			return r1.sign_in_minute < r2.sign_in_minute;
		}
	}
	else
	{
		return r1.sign_in_hour < r2.sign_in_hour;
	}
}

bool sign_out_compare(Records r1, Records r2) {
	if (r1.sign_out_hour == r2.sign_out_hour) {
		if (r1.sign_out_minute == r2.sign_out_minute) {
			return r1.sign_out_second > r2.sign_out_second;

		}
		else
		{
			return r1.sign_out_minute > r2.sign_out_minute;
		}
	}
	else
	{
		return r1.sign_out_hour > r2.sign_out_hour;
	}
}

int main() {

	vector<Records> v1,v2;
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		Records r;
		cin >> r.s;
		scanf("%d:%d:%d %d:%d:%d",&r.sign_in_hour, &r.sign_in_minute, &r.sign_in_second,
			&r.sign_out_hour, &r.sign_out_minute, &r.sign_out_second);
		v1.push_back(r);
		v2.push_back(r);
	}
	sort(v1.begin(), v1.end(), sign_in_compare);
	sort(v2.begin(), v2.end(), sign_out_compare);
	cout << v1[0].s << ' ' << v2[0].s;
	return 0;
}