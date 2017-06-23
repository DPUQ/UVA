#include <bits/stdc++.h>
#define 	MAX 		14
#define 	enl 		"\n"
#define 	debug(x) 	cout << #x " = " << (x) << enl
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	unsigned long long ull;

int coefs[MAX];
ull fact[MAX];

void fill(){
	fact[0] = fact[1] = ull(1);
	rep(i,2,MAX) fact[i] = i * fact[i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	ull ans;
	fill();
	while(cin >> n >> k){
		rep(i,0,k) cin >> coefs[i];
		ans = fact[n];
		rep(i,0,k) ans /= fact[coefs[i]]; 
		cout << ans << enl;
	}
	return 0;
}
