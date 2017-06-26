#include <bits/stdc++.h>
#define 	MAX 		1000001
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sp 			swap
#define 	sz 			size()

using namespace std;

bitset<10000010> bs;
vector<int> primes;

void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;
	for(int i = 2; i <= MAX; i++){
		if(bs[i]){
			for(int j = 2*i; j <= MAX ; j+=i) bs[j] = 0;
			primes.push_back(i);
    	}
    }
}

long lower(int x){  
    int l=0,r=primes.sz;  
    int mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= primes[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
}

void solve(int n){
	int bound = lower(n);
	int a = -1, b = -1, best =  0;
	rep(i,0,bound){
		a = primes[i] , b = n - a; 
		if(bs[b]) break;
	}

	if(a == -1 && b == -1) cout << "Goldbach's conjecture is wrong" << enl;
	else cout << n << " = " << a << " + " << b << enl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	sieve();
	while(cin >> n && n)
		solve(n);
	return 0;
}
