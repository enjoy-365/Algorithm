#include <iostream>

using namespace std;

int S[1000003];
int Find(int v) {
	if (v == S[v]) return v;
	return S[v] = Find(S[v]);
}

void Union(int a, int b) {
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 != r2) {
		S[r1] = r2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		S[i] = i;
	}
	//input m command
	int cmd;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			Union(a, b);
		}
		else if (cmd == 1) {
			if (Find(a) != Find(b)) cout << "NO\n";
			else cout << "YES\n";
		}
	}


	return 0;
}