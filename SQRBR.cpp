/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	13/09/2017
	Logic -	Dynamic Programming
	Category - Medium
	Platform - SPOJ
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

bool arr[40];
ll dp[20][20];

ll proper(ll open, ll close, ll n)
{
	if(open==0 && close==0)
		return 1;
	if(open < 0 || close < 0 || close < open)
		return 0;
	if(dp[open][close] != -1)
		return dp[open][close];
	if(arr[2*n - open - close + 1])
		return dp[open][close] = proper(open-1, close, n);
	else if(close > open)
		return dp[open][close] = proper(open,close-1, n) +  proper(open-1,close, n);
	else
		return dp[open][close] = proper(open-1, close, n);

}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(arr,false,sizeof(arr));
		memset(dp,-1,sizeof(dp));
		ll n,k;
		cin>>n>>k;

		while(k--)
		{
			ll a;
			cin>>a;
			arr[a] = true;
		}
		cout<<proper(n,n,n)<<endl;
	}
}