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

ll dp[2005][2005];

ll findMax(ll arr[], ll low, ll high, ll age)
{
	if(low > high)
		return 0;
	if(dp[low][high] != -1)
		return dp[low][high];
	ll x = arr[low]*age  + findMax(arr,low+1,high,age+1);
	ll y = arr[high]*age + findMax(arr,low,high-1,age+1);
	return dp[low][high] = max(x,y);
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	ll n;
	cin>>n;

	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];

	cout<<findMax(arr,0,n-1,1)<<endl;
	return 0;
}