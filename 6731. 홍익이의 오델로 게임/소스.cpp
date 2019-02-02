#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<memory.h>
using namespace std;

struct point {
	int x, y;
};
int T;
int N;
char map[1000][1000];
char temp[1000][1000];
char str;
int visit[1000000];
int result;

point v[1000000];

point cal(int num) {
	int y = num / N;
	int x = num % N;
	return { x,y };
}

void reverse(int x, int y) {
	for (int i = 0; i < N; i++) {
		temp[i][x] = temp[i][x] == 'W' ? 'B' : 'W';
		temp[y][i] = temp[y][i] == 'W' ? 'B' : 'W';
	}
	temp[y][x] = temp[y][x] == 'W' ? 'B' : 'W';
}
int check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != temp[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}
void solu(int n) {
	for (int i = 0; i < n; i++) {
		int x = v[i].x;
		int y = v[i].y;
		reverse(x, y);
	}
	if (check() == 1) {
		result = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 'W';
		}
	}
}
void combi(int n, int r, int idx, int before) { // n개 중에 r개 고르는 조합 idx == 선택된 인덱스 
	if (r == idx) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (visit[i] == 1) {
				v[count] = cal(i);
				count++;
			}

		}
		solu(r);
	}
	else {
		for (int i = before; i < n; i++) {
			if (visit[i] != 1) {
				visit[i] = 1;
				combi(n, r, idx + 1, i);
				visit[i] = 0;
			}
		}
	}
}


int main() {

	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++) {
		scanf("%d", &N);
		str = NULL;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1s", &map[i][j]);
				str += map[i][j];
				temp[i][j] = 'W';
			}
		}
		result = 0;
		int answer = 0;
		for (int i = 0; i <= (N*N) / 2; i++) {
			combi((N*N), i, 0, 0);
			if (result == 1) {
				answer = i;
				break;
			}
		}

		printf("#%d %d\n", testcase, answer);
	}

}