#include <bits/stdc++.h>
#define 	MAX 		21
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	long long 			ll;

ll comb[MAX][MAX],sfact[MAX];

void fill()
{

    sfact[1] = ll(0); sfact[0] = ll(1);
    rep(i,2,MAX)
        sfact[i] = (i-1)*(sfact[i-2] + sfact[i-1]);

    rep(i,0,MAX)
    {
        comb[i][0] = comb[i][i] = ll(1);

        rep(k,1,i)
            if(i - 1 < k)
				comb[i][k] = comb[i - 1][k - 1];
			else
				comb[i][k] =  comb[i - 1][k] + comb[i - 1][k - 1];
    }
}

ll solve(int n, int m){
	ll ans = 0;
	rep(i,0,m+1)
		ans += comb[n][i] * sfact[n-i];
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	fill();
	while(cin >> n >> m){
		cout << solve(n,m) << enl;
	}
	return 0;
}
