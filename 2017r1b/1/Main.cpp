#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<LL, int> P;

const int MAXN = 1000;
const int MAXT = 100;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
  LD res[MAXT];
  memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
    int N, S;
    LL D, K;
    LD maxt = 0.0;
    vector<P> p;
    cin >> D >> N;
    for (int i = 0; i < N; i++) {
      cin >> K >> S;
      p.push_back(P(K, S));
    }
    sort(p.begin(), p.end(), greater<P>());
    for (int i = 0; i < N; i++) {
      LD t = (LD)(D - p[i].first) / (LD)p[i].second;
      if (t > maxt) maxt = t;
//      cout << p[i].first << ":" << p[i].second << ":" << t << endl;
    }
    res[t] = D / maxt;
//    cout << fixed << setprecision(10) << maxt << endl;
	}

	for (int i = 0; i < T; i++) cout << fixed << setprecision(6) << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}