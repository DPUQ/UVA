#include <bits/stdc++.h>
#define 	MAX 		20000001
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(long i = a; i<n; i++)
#define 	ft 			first
#define 	sd 			second
#define 	sz 			size()
#define 	pb 			push_back

using namespace std;
typedef 	pair<long,long> 	ii;
typedef 	vector<long> 		vi;

bitset<20000010> bs;
vi primes;
vector<ii> twins;

void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;
	for(int i = 2; i <= MAX; i++){
		if(bs[i]){
			for(int j = 2*i; j <= MAX ; j+=i) bs[j] = 0;
			primes.pb(i);
    	}
    }
}

void prec(){
	sieve();
	long j;
	rep(i,0,primes.sz - 1){
		j = i + 1;
		if(primes[j] - primes[i] == 2) twins.pb(ii(primes[i],primes[j]));
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prec();
	int n;
	while(cin >> n){
		ii twin = twins[n-1];
		cout << "(" << twin.ft << ", " << twin.sd << ")" << enl;
	}
	return 0;
}
