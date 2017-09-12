#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define sz(a) (a).size()
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
#define MAX 1000001
#define MOD 1000000007

vi dp;

void fib()
{
	dp.push_back(0);// = 0;
	dp.push_back(1);//[1] = 1;

	for(ll i=2;i<MAX;i++)
		dp.push_back((dp[i-1]%MOD + dp[i-2]%MOD)%MOD);
}


 
int main()
{
	std::ios::sync_with_stdio(false);
	fib();
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,m;
		cin>>n>>m;

		cout<<dp[m+2] - dp[n+1]<<endl;

	}
}