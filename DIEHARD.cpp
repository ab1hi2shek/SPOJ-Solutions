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

ll dp[2002][2002];

ll survive(ll health, ll armor)
{
	//cout<<"health = "<<health<<" armor = "<<armor<<endl;
	if(health<=0 || armor<=0)
		return -1;
	if(dp[health][armor] != -1)
		return dp[health][armor];

	ll y = survive(health-17, armor+7);
	ll z = survive(health-2, armor-8);
	return dp[health][armor] = max(y,z) + 2;

	//return 1 + max(x, max(y,z));
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	ll t;
	cin>>t;

	while(t--)
	{
		ll h,a;
		cin>>h>>a;

		cout<<survive(h,a)<<endl;
	}
}