#include <bits/stdc++.h>
#define 	MAX 		32770
#define 	gl(s) 		getline(cin,s)
#define 	enl 		"\n"
#define 	dig(c) 		(c - '0')
#define 	cl 			clear()
#define 	bg 			begin()
#define 	ed 			end()

using namespace std;
typedef 	string 				st;
typedef 	long long 			ll;

bitset<40000> bs;
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

map<long,int> factors;

void primeFactors(ll n){

	int index = 0, factor = primes[index], power; 
	while(factor*factor <= n){
		power = 0;
		while(n % factor == 0){ n /= factor; power++;}
		if(power) factors[factor] = power;
		factor = primes[++index];
	}

	if(n != 1) factors[n] = 1;
}

ll _pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b;
    while( e )
    {
        if( e&1 ) r = ( r*pow );
        pow = ( pow*pow );
        e >>= 1;
    }
    return r;
}

ll factors2number(){
	ll ans = ll(1);
	for(map<long,int>::iterator it = factors.bg; it != factors.ed; it++)
		ans *= _pow(ll (it -> first), ll (it -> second));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	st s;
	long n;
	int pow;
	ll number;
	while(1){
		gl(s);
		if(dig(s[0]) == 0) break;
		istringstream iss(s);
		factors.cl;
		while(iss >> n){
			iss >> pow;
			factors[n] = pow;
		}
		number = factors2number();
		number--; factors.cl;
		primeFactors(number);
		int c = 0;
		for(map<long,int>::reverse_iterator it = factors.rbegin(); it != factors.rend(); ++it){
			if(c) cout << " ";
			cout <<  it -> first << " " << it -> second;
			c++;
		}
		cout << enl;
	}
	return 0;
}
