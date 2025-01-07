#include<bits/stdc++.h>
using namespace std;
unordered_map<long long, int> states;
vector<int> primes;

void prime_factors(int x) {
	for (int i=2; i*i <= x; i++) {
		if (x % i == 0) {
			primes.push_back(i);
			while(x % i == 0) x /= i;
		}
	}
	if (x > 1) primes.push_back(x);
	return;
}

long long custom_hash(int a, int b) {
	return a * 1e9 + b;
}

int f(int a, int delta) {
	// cout << a << " " << delta << "\n";
	if (a == 1) return 0;
	if (delta == 1) return a-1;
	if (delta == 0) return 1;

	auto cur = custom_hash(a, delta);
	if (states.count(cur)) return states[cur];

	int res = a-1;
	for (int fac : primes) {
		if (delta % fac == 0) {
			res = min(res, f(a/fac, delta/fac) + a % fac + 1);
			res = min(res, f(a/fac+1, delta/fac) + fac - a % fac + 1);
		}
	}
	return states[cur] = res;
}

void solve() {
    int a, b;
	states.clear();
	primes.clear();
	cin >> a >> b;
	
	if (a > b) swap(a, b);
	prime_factors(b-a);

	cout << f(a, b-a) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int T=1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
