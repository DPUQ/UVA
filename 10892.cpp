#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	bg 			begin()
#define 	ed 			end()
#define 	in 			insert

using namespace std;
typedef 	long long 			ll;
typedef 	set<ll> 			si;

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }

ll solve(ll n){
	si divs;
	for(int i = 1; i*i <= n; i++){
		if(n%i==0){
			divs.in(i);
			divs.in(n/i);
		}
	}

	ll card = 0;
	for(si::iterator i = divs.bg; i != divs.ed; i++)
		for(si::iterator j = i; j != divs.ed; j++)
			if(gcd(*i,*j) == 1) card++;
	return card;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while(cin >> n && n)
		cout << n << " " << solve(n) << enl;
	return 0;
}
