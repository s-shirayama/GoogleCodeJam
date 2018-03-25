#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 20;
const int MAXT = 100;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
  LL res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
    LL N;
    cin >> N;
    res[t] = N;
    LL n = N;
    int pre = 9, cnt = -1;
    for (int i = 0; n > 0; i++, n /= 10) {
      if (n%10 > pre) {
        cnt = i;
        n -= 1;
      }
      pre = n%10;
    }
    if (cnt > -1) {
      LL _n = 1; // 10^cnt
      while (cnt-- > 0) _n *= 10;
      res[t] = N - (N%_n) - 1;
    }
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}