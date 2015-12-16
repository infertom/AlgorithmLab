//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXSIZE = 10000 + 100;
const int MAXN = 1000 + 100;

int N, C;
int val[MAXN], cost[MAXN];
int bag[MAXSIZE][MAXSIZE], vis[MAXSIZE][MAXSIZE];
int ans[MAXN];

void init()
{
	memset(bag, 0, sizeof bag);
	memset(vis, 0, sizeof vis);
}

int cal()
{
	for (int i = 1; i <= N; i++){
		for (int sum = C; sum; sum--){
			/*bag[sum] = max(bag[sum], bag[sum-cost[i]] + val[i]);*/
			if ( sum >= cost[i] && bag[i-1][sum] < bag[i-1][sum-cost[i]] + val[i] ){
				bag[i][sum] = bag[i-1][sum-cost[i]] + val[i];
				vis[i][sum] = i;
			}else{
				bag[i][sum] = bag[i-1][sum];
				vis[i][sum] = vis[i-1][sum];
			}
		}
	}
// 	for (int i = 1; i <= N; i++){
// 		for (int j = 0; j <= C; j++){
// 			printf("%d ", vis[i][j]);
// 		}
// 		cout<<endl;
// 	}

	int sum = C, k = N;
	while ( sum && k )
	{
		k = vis[k][sum];
		ans[k] = 1;
		sum -= cost[k];
		k--;
	}

	return bag[N][C];
}

int main()
{
	freopen("in.txt", "r", stdin);

	while ( scanf("%d%d", &N, &C) != EOF )
	{
		init();
		for (int i = 1; i <= N; i++){
			scanf("%d", &cost[i]);
		}
		for (int i = 1; i <= N; i++){
			scanf("%d", &val[i]);
		}

		//printf("%d\n", cal());
		cal();
		for (int i = 1; i <= N; i++){
			printf("%d%c", ans[i], (i==N)? '\n':' ');
		}
	}

	return 0;
}