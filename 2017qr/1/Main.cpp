#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 2002;
const int MAXT = 100;

int bit[MAXN];

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i&-i; // i&-i => last bit which is 1.  0110&1010=0010
  }
  return s;
}

void add(int i, int x) {
  while(i <= MAXN) {
    bit[i] += x;
    i += i&-i; // i&-i => last bit which is 1.
  }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
    string S;
    int K, L;
    cin >> S >> K;
    L = S.length();
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < L; i++) {
      int s = sum(i+1), c = (S[i] == '+')?1:0;
      if ((s+c)%2 == 0) {
        if (i > L - K) {
          res[t] = -1;
          break;
        }
        res[t]++;
        add(i+1, 1);
        add(i+1+K, -1);
      }
    }
	}

	for (int i = 0; i < T; i++) {
    cout << "Case #" << i+1 << ": ";
    if (res[i]==-1) {
      cout << "IMPOSSIBLE";
    } else {
      cout << res[i];
    }
    cout << endl;
  }
	return 0;
}