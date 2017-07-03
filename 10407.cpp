#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sz 			size()
#define 	pb 			push_back
#define 	cl 			clear()

using namespace std;
typedef 	long long 		ll;
typedef 	vector<ll> 		vi;

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll f,j,g;
	vi n;
	while(cin >> f && f){
		n.cl; n.pb(f);
		while(cin >> f && f) n.pb(f);
		g = 0;
		rep(i,1,n.sz)
			g = gcd(n[i] - n[i-1],g);
		cout << abs(g) << enl;
	}
	return 0;
}
