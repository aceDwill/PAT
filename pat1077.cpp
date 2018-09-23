/*
	˼·: 1.�������ַ�����ת�����ں����������������ַ�������
          2.��0�����Ƚ����з�ת�ַ������ַ��Ƿ����
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	getchar();	// ���ջ��з�
	string sentences[110];
	int minLen = 300;
	for (int i = 0; i < N; i++) {
		getline(cin, sentences[i]);
		reverse(sentences[i].begin(), sentences[i].end());
		if (sentences[i].length() < minLen) {
			minLen = sentences[i].length();
		}
	}

	int suffixIndex = 0;  //������׺���� 
	for (int i = 0; i < minLen; i++) {
		char commonC = sentences[0][i];
		bool hasSuffix = true;  // ��ʾ���о���ͬһ��λ�õ��ַ�����ͬ
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