#include <bits/stdc++.h>
#define 	MAX 		1000001
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	long long 			ll;

ll prec[MAX];

void fill(){
	ll au,ac;
	au = ac = ll(0);
	rep(i,3,MAX){
		if(i%2 == 0)
			au++;
		ac += au;
		prec[i] = prec[i-1] + ac;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill();
	int n;
	while(cin >> n && n > 2){
		cout << prec[n] << enl;
	}
	return 0;
}
