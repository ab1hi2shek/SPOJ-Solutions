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
#define MAXM 100010

ll arr[MAXM];
ll dp[MAXM];

ll recFun(ll n, ll f)
{
	//cout<<" n = "<<n<<endl;
	if(n>=f)
		return 0;
	if(dp[n] != -1)
		return dp[n];
	ll x = LONG_MIN,y = LONG_MIN, z = LONG_MIN;
	if(f-n>=0)
		x = arr[n] + recFun(n+2,f);
	if(f-n >= 1)
		y = arr[n] + arr[n+1] + recFun(n+4,f);
	if(f-n>=2)
		z = arr[n] + arr[n+1] + arr[n+2] + recFun(n+6,f);

	//cout<<x<<" "<<y<<" "<<z<<endl;

	return dp[n] = max(x, max(y,z));
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;

		loop(i,0,MAXM-1)
		{
			dp[i] = -1;
			arr[i] = 0;
		}
		// loop(i,0,20)
		// 	cout<<dp[i]<<" ";
		loop(i,0,n-1)
			cin>>arr[i];
		cout<<recFun(0,n)<<endl;
	}
	return 0;
}