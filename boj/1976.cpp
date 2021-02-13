#include <iostream>

using namespace std;

int S[202];
int path[1005];

void Union(int r1, int r2);
int Find(int v);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int chk;

	//init root
	for (int i = 1; i <= n; i++) {
		S[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> chk;
			if (chk == 1) {
				//there's a way
				Union(i, j);
			}
		}
	}
	int res = 1;
	int city;

	for (int i = 1; i <= m; i++) {
		cin >> city;
		path[i] = city;
	}

	for (int i = 1; i < m; i++) {
		if (Find(path[i]) != Find(path[i + 1])) {
			res = 0;
			break;
		}
	}

	if (res == 0) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}

void Union(int a, int b) {
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 != r2) {
		S[r2] = r1;
	}
}
int Find(int v) {
	if (v == S[v]) return v;
	return S[v] = Find(S[v]);
}