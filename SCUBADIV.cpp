/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 14/09/2017
	Logic -	Dynamic Programming
	Category - Easy
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
#define MAXM 1005
 
struct scuba{
	ll oxy;
	ll nit;
	ll wt;
};
 
ll dp[MAXM][25][85];
 
ll minWeight(scuba arr[], ll n, ll a, ll b)
{
	if(a<=0 && b<=0)
		return 0;
	if(n<0)
		return INT_MAX;
	if(a<0)
		a = 0;
	if(b<0)
		b = 0;
	if(dp[n][a][b] != -1)
		return dp[n][a][b];
 
	ll x = min( minWeight(arr, n-1, a, b), arr[n].wt + minWeight(arr, n-1, a-arr[n].oxy, b-arr[n].nit));
	return dp[n][a][b] = x;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
 
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		ll a,b;
		cin>>a>>b;
		ll n;
		cin>>n;
		scuba arr[n];
 
		for(ll i=0;i<n;i++)
			cin>>arr[i].oxy>>arr[i].nit>>arr[i].wt;
 
		cout<<minWeight(arr, n-1, a, b)<<endl;
	}
} 