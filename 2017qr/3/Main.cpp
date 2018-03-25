#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXT = 100;

LL func(LL n, LL k) {
  if (k == 1) return n;
  if ((k-1)%2 == 1) return func(n/2, k/2);
  else return func((n-1)/2, k/2);
}

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
    LL N, K;
    cin >> N >> K;
    res[t] = func(N, K);
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << (res[i]/2) << " " << ((res[i]-1)/2) << endl;
	return 0;
}