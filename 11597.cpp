#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	pc(i,o) 	cout << "Case " << (i+1) << ": " << o << enl

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i = 0;
	while(cin >> n && n)
		pc(i++,n/2);
	return 0;
}
