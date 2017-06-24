#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	pc(i,o) 	cout << "Case " << (i+1) << ": " << o << enl

using namespace std;
typedef 	long double 		ld;
typedef 	long long 			ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ld ans;
	ll n;
	int i = 0;
	while(cin>>n && n){
		ans = (3 + sqrt(9+8*n)) / 2;
		pc(i++,ll(ceil(ans)));
	}
	return 0;
}
