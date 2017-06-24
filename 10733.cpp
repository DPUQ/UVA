#include <bits/stdc++.h>
#define 	enl 		"\n"

using namespace std;
typedef 	unsigned long long ull;

ull _pow( int b, int e)
{
    ull r = 1;
    ull pow = b;
    while(e)
    {
        if( e&1 ) r = ( r*pow );
        pow = ( pow*pow );
        e >>= 1;
    }
    return r;
}

ull solve(int n){
	ull ans = ull(_pow(n,6));
	ans += ull(_pow(n,4)) * 3;
	ans += ull(_pow(n,3)) * 12;
	ans += ull(_pow(n,2)) * 8;
	ans = ull(ans / 24);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n && n)
		cout << solve(n) << enl;
	return 0;
}
