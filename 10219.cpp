#include <bits/stdc++.h>
#define 	enl 		"\n"

using namespace std;
typedef 	unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull n,k;
	while(cin >> n >> k){
		double ans = 0;
		for(ull i = n-k+1; i <= n; i++) ans += log10(i);
		for(ull i = k; i >= 1; i--) ans -= log10(i);
		cout << floor(ans) + 1 << enl;
	}
	return 0;
}
