#include <bits/stdc++.h>
#define 	MAX 		13
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef long long ll;

ll fact[MAX],sfact[MAX];

void fill(){
	fact[0] = fact[1] = sfact[0] = ll(1);
	sfact[1] = ll(0);

	rep(i,2,MAX){
		fact[i] = i * fact[i-1];
		sfact[i] = (i-1) * (sfact[i-1] + sfact[i-2]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t;
	fill();
	cin >> t;
	while(t--){
		cin >> n;
		cout << sfact[n] << "/" << fact[n] << enl;
	}
	return 0;
}
