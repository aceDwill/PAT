/*
	思路：1.对name进行转化，如"AAA"对应0，0对应"AAA"
		  2.对各个连通变量进行dfs遍历，对满足要求的结果进行保存

*/


#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> nameToId, Gang;
map<int, string> idToName;
int N, K;
int numPerson = 0;
int weight[2010] = { 0 };
int G[2010][2010] = { 0 };
bool visited[2010] = { false };

void dfs(int nowVisit, int& head, int& numMember, int& totalValue) {
	numMember++;
	visited[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (visited[i] == false) {
				dfs(i, head, numMember, totalValue);
			}
		}

	}

}

void dfsTravel() {
	for (int i = 0; i < numPerson; i++) {
		
		if (visited[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > K) {
				Gang[idToName[head]] = numMember;
			}
		}
	}
}

int transfer(string name) {
	if (nameToId.find(name) != nameToId.end()) {
		return nameToId[name];
	}
	else {
		nameToId[name] = numPerson;
		idToName[numPerson] = name;
		return numPerson++;
	}
}
 
int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string n1, n2;
		int t;
		cin >> n1 >> n2 >> t;
		int id1 = transfer(n1);
		int id2 = transfer(n2);
		weight[id1] += t;
		weight[id2] += t;
		G[id1][id2] += t;
		G[id2][id1] += t;

	}
	dfsTravel();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}



	return 0;
}