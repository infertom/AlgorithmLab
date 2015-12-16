/*
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 200 + 10;

int f[MAXN][MAXN];
int matr[MAXN][MAXN];
int N;

void init()
{
	memset(f, -1, sizeof f);
	memset(matr, -1, sizeof matr);
}

int cal(int st, int ed)
{
	if ( ed - st == 1 ) return matr[st][ed];

	int ans = matr[st][ed];
	for (int i = st+1; i < ed; i++){
		ans = min(ans, val(st, i) + val(i, ed));
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while ( scanf("%d", &N) != EOF )
	{
		init();
		for (int i = 1; i < N; i++){
			for (int j = i+1; j <= N; j++){
				scanf("%d", &matr[i][j]);
			}
		}

		printf("%d\n", cal(1, N));
	}

	return 0;
}

/ *
3
5 15
7

5
1 2 3 4
3 4 5
5 6
7

5
1 2 4 8
1 4 8
1 4
1

* /*/