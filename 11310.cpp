#include <bits/stdc++.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#define 	MAX 		41
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	long long 			ull;

ull prec[MAX];

void fill(){
	prec[0] = 1; prec[1] = 1; prec[2] = 5;
	rep(i,3,MAX)
		prec[i] = prec[i-1] + 4*prec[i-2] + 2*prec[i-3];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	fill();
	cin >> t;
	while(t--){
		cin >> n;
		cout << prec[n] << enl;
	}
	return 0;
}
