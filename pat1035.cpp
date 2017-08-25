#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	int N;
	cin >> N;
	string IDs[1000], passwords[1000];
	vector<int> modified_index;
	for (int i = 0; i < N; i++) {
		string ID, password;
		cin >> ID >> password;
		IDs[i] = ID;
		passwords[i] = password;

	}
	int modified_cnt = 0;
	for (int i = 0; i < N; i++) {
		string new_password = "";
		for (int j = 0; j < passwords[i].length(); j++) {
				if (passwords[i][j] == '1') {
					new_password += '@';
				}
				else if (passwords[i][j] == '0'){
					new_password += '%';
				}
				else if (passwords[i][j] == 'l') {
					new_password += 'L';
				}
				else if (passwords[i][j] == 'O') {
					new_password += 'o';
				}
				else {
					new_password += passwords[i][j];
				}
				
		}
		if (new_password.compare(passwords[i]) != 0) {
			modified_cnt++;
			passwords[i] = new_password;
			modified_index.push_back(i);
		}
	}

	if (modified_cnt == 0) {
		if (N == 1) {
			cout << "There is " << N << " account and no account is modified";
		}
		else {
			cout << "There are " << N << " accounts and no account is modified";
		}
	}
	else {
		cout << modified_cnt << endl;
		for (int i = 0; i < modified_cnt; i++) {
			int index = modified_index[i];
			cout << IDs[index] << ' ' << passwords[index] << endl;
		}
	}


	return 0;
}
