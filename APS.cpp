/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long
#define ull unsigned long long
		 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define M0D 1000000007
#define MAXM 10000005

ll dp[MAXM];
int sieve[MAXM];

void sieveFun()
{
	memset(sieve, 0, sizeof(sieve));
	for(ll i=2;i<MAXM;i++)
	{
		if(sieve[i] == 0)
		{
			for(ll j=i*i; j<MAXM; j+=i)
			{
				if(sieve[j] == 0)
					sieve[j] = i;
			}
			dp[i] = dp[i-1] + i;
		}
		else
			dp[i] = dp[i-1] + sieve[i];
	}

}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	dp[0] = dp[1] = 0;
	sieveFun();
	while(t--)
	{
		ll n;
		cin>>n;

		cout<<dp[n]<<endl;
	}
	return 0;
}