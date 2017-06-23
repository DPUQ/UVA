#include <bits/stdc++.h>
#define 	MAX 		21
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	unsigned long long ull;

ull fact[MAX];

void fill(){
	fact[0] = fact[1] = ull(1);
	rep(i,2,MAX)
		fact[i] = ull(i*fact[i-1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; ull ans;
	fill();
	bool f = false;
	while(cin>>n){
		if(!f) f = true;
		else cout << enl;
		ans = fact[2*n];
		ans /= fact[n]; ans /= fact[n];
		ans /= (n+1);
		cout << ans << enl;
	}
	return 0;
}
