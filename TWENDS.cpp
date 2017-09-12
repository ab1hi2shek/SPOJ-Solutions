/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/09/2017
	Logic -	DP
	Category -	Easy 
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

ll dp[MAXM][MAXM];

ll dynamic(ll arr[], ll i, ll j)
{
	if(i>j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	ll x,y;

	if(arr[j-1] > arr[i])
		x = arr[j] + dynamic(arr,i,j-2);
	else
		x = arr[j] + dynamic(arr,i+1,j-1);
	if(arr[i+1] >= arr[j])
		y = arr[i] + dynamic(arr,i+2,j);
	else
		y = arr[i] + dynamic(arr,i+1,j-1);

	return dp[i][j] = max(x,y);

}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	ll p = 1;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;

		memset(dp,-1,sizeof(dp));
		ll arr[n];
		ll sum = 0;
		loop(i,0,n-1)
		{
			cin>>arr[i];
			sum += arr[i];
		}

		ll ans = dynamic(arr,0,n-1);
		//cout<<ans<<endl;

		cout<<"In game "<<p++<<", the greedy strategy might lose by as many as "<<2*ans - sum<<" points.\n";
	}
}