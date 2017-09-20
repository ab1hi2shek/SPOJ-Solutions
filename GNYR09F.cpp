/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
*/	  

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
#define MAXM 105

ll dp[MAXM][MAXM][2];

ll solution(ll n, ll k, ll prevBit)
{
	if(k < 0)
		return 0;
	if(k==0 && n<=0)
		return 1;
	if(k>0 && n<=0)
		return 0;
	if(dp[n][k][prevBit] != -1)
		return dp[n][k][prevBit];

	ll x = solution(n-1, k - 1*prevBit, 1);
	ll y = solution(n-1, k, 0);

	return dp[n][k][prevBit] = x + y;
}

 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		ll indx,n,k;
		cin>>indx>>n>>k;

		if(k>=n)
			cout<<indx<<" 0"<<endl;
		else
			cout<<indx<<" "<<solution(n,k,0)<<endl;
	}
}