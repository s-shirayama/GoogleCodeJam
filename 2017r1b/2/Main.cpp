#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 20;
const int MAXT = 100;
const	char C[3] = {'R', 'Y', 'B'};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	string res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, R, O, Y, G, B, V;
		string _R = "", _Y = "", _B = "";
		cin >> N >> R >> O >> Y >> G >> B >> V;
		// 
		for (int i = 0; i < G; i++) _R += "RG";
		for (int i = 0; i < V; i++) _Y += "YV";
		for (int i = 0; i < O; i++) _B += "BO";
		string _S[3] = {_R, _Y, _B};
		//
		if (N == R + G && R == G) {
			res[t] = _R;
			continue;
		} else if (N == Y + V && Y == V) {
			res[t] = _Y;
			continue;
		} else if (N == B + O && B == O) {
			res[t] = _B;
			continue;
		}
		//
		if ((G > 0 && R < G + 1) || (V > 0 && Y < V + 1) || (O > 0 && B < O + 1)) {
			res[t] = "IMPOSSIBLE";
			continue;
		}
		// 
		R -= G, Y -= V, B -= O;
		N = R + Y + B;
		int n[3] = {R, Y, B};
		// 0: R, 1: Y, 2: B
		int idx, st = 2;
		if (R > Y && R > B) st = 0;
		else if (Y > B) st = 1;
		if (_S[st].size()) {
			res[t] += _S[st];
  		_S[st] = "";
  	}
		res[t] += C[st];
		n[st]--;
		idx = st;
		while (--N) {
			int _idx = -1;
			if (N == 2 && idx != st && n[st] > 0) _idx = st;
			else if (idx == 0) {
				if (n[1] > 0 || n[2] > 0) _idx = (n[1] > n[2])? 1 : 2;
			} else if (idx == 1) {
				if (n[0] > 0 || n[2] > 0) _idx = (n[0] > n[2])? 0 : 2;
			} else {
				if (n[0] > 0 || n[1] > 0) _idx = (n[0] > n[1])? 0 : 1;
			}
			if (_idx == -1) {
				res[t] = "IMPOSSIBLE";
				break;
			}
			idx = _idx;
			if (_S[idx].size()) {
				res[t] += _S[idx];
	  		_S[idx] = "";
	  	}
			res[t] += C[idx];
  		n[idx]--;
		}
		if (idx == st) res[t] = "IMPOSSIBLE";
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}