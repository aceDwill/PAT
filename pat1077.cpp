/*
	思路: 1.将所有字符串反转，便于后续处理，并求出最短字符串长度
          2.从0索引比较所有反转字符串各字符是否相等
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	getchar();	// 接收换行符
	string sentences[110];
	int minLen = 300;
	for (int i = 0; i < N; i++) {
		getline(cin, sentences[i]);
		reverse(sentences[i].begin(), sentences[i].end());
		if (sentences[i].length() < minLen) {
			minLen = sentences[i].length();
		}
	}

	int suffixIndex = 0;  //公共后缀长度 
	for (int i = 0; i < minLen; i++) {
		char commonC = sentences[0][i];
		bool hasSuffix = true;  // 表示所有句子同一个位置的字符都相同
		for (int j = 1; j < N; j++) {
			if (sentences[j][i] != commonC) {
				hasSuffix = false;
				break;
			}
		}

		if (hasSuffix) {
			suffixIndex++;
		}
		else {
			break;
		}
	}

	if (suffixIndex == 0) {
		cout << "nai";
	}
	else {
		string suffix = sentences[0].substr(0, suffixIndex);
		reverse(suffix.begin(), suffix.end());
		cout << suffix;
	}

	return 0;
}