#include <bits/stdc++.h>
#define 	MAX 		101
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	irep(i,a,n) for(int i = n; i>=a; i--)


using namespace std;
typedef 	unsigned long long ull;

int coefs[MAX];

int w2s (const void * a, const void * b){ return ( *(int*)b - *(int*)a );}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	ull ans;
	while(cin >> n >> k){
		rep(i,0,k) cin >> coefs[i];
		qsort(coefs, k , sizeof(int), w2s);
		ans = ull(1);
		irep(i,coefs[0]+1,n) ans *= i;
		rep(i,1,k){
			irep(j,2,coefs[i]) ans /= j;
		}
		cout << ans << enl;
	}
	return 0;
}
