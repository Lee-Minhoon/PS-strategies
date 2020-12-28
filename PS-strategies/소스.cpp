#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int C, N, L, n[1001];
int main() {
	for (scanf("%d", &C); C--;) {
		scanf("%d %d", &N, &L);
		for (int i = 1; i <= N; i++) scanf("%d", &n[i]), n[i] += n[i - 1];
		for (int i = 1; i <= N; i++) {
			printf("%d", n[i]);
		}
		double ans = 1e9;
		// N-L -> 0 1 2 3
		for (int i = 0; i <= N - L; i++)
			// 3 4 5 6 부터 6보다 작을때까지
			for (int j = i + L; j <= N; j++)
				ans = min(ans, double(n[j] - n[i]) / (j - i));
		// n[3] - n[0] / 3
		// n[4] - n[0] / 4
		// n[5] - n[0] / 5
		// n[6] - n[0] / 6

		// n[4] - n[1] / 3
		// n[5] - n[1] / 4
		printf("%.11f\n", ans);
	}
	return 0;
}