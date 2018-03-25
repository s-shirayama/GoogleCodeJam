#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 100;
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
		int N, Q, S[MAXN], U, V, curs = 0;
		LL E[MAXN], D[MAXN], d;
		LD ti[MAXN];
		cin >> N >> Q;
		for (int i = 0; i < N; i++) cin >> E[i] >> S[i];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			cin >> d;
			if (j == i + 1) D[i] = d;
		}
		cin >> U >> V;
		for (int i = 0; i < N; i++) ti[i] = -1;
		ti[0] = 0;
		//
		for (int i = 0; i < N-1; i++) {
			LL d = 0;
			for (int j = i + 1; j < N; j++) {
				d += D[j-1];
				if (d <= E[i] && (ti[j] < 0 || ti[i] + (LD)(d / (LD)S[i]) < ti[j])) ti[j] = ti[i] + (LD)(d / (LD)S[i]);
			}
		}
		res[t] = ti[N-1];
	}

	for (int i = 0; i < T; i++) cout << fixed << setprecision(9) << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}