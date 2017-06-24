#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	sp 			swap

using namespace std;
typedef 	unsigned long long ull;

ull line(ull n, ull m){
	return ull(n * m *( m - 1));
}

ull diag(ull n, ull m){
	ull ans = 2 * (n * (n-1) * (n-2)) / 3;
	ans += line(m - n + 1,n);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull n,m;
	ull ans;
	while(cin >> n >> m && (n+m)){
		if(n>m) sp(n,m);
		ans = line(n,m) + line(m,n);
		ans += 2 * diag(n,m);
		cout << ans << enl;
	}
	return 0;
}
