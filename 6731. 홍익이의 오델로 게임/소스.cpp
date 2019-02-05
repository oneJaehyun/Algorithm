#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory.h>
using namespace std;
int T, N;
char map[1000][1000];
int temp[2][1000];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("sample_input.txt", "r", stdin);
	//scanf("%d", &T);
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		//scanf("%d", &N);
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				//scanf("%1s", &map[i][j]);
				if (map[i][j] == 'B') {
					temp[0][j] += 1;
					temp[1][i] += 1;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int count;
				count = temp[0][j] + temp[1][i];
				if (map[i][j] == 'B') {
					count--;
				}
				if (count % 2 == 1) {
					result++;
				}
			}
		}
		cout << "#" << testcase << " " << result << "\n";
		memset(temp, 0, sizeof(temp));
		//printf("#%d %d\n", testcase,result);
	}

}