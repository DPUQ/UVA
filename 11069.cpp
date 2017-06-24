#include <bits/stdc++.h>
#define 	MAX 		77
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;

long prec[MAX];

void fill(){
	prec[1] = 1; prec[2] = 2; prec[3] = 2;
	rep(i,4,MAX) prec[i] = prec[i-2] + prec[i-3];
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n; 
	fill();
	while(cin >> n)
		cout << prec[n] << enl;
	return 0;
}
