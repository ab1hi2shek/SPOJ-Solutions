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

ll dp[10005];

ll modifiedKnapsack(vi &P, vi &W, ll f, ll n)
{
	dp[0] = 0;

	for(l i=0; i<=f; i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(W[j] <= i)
			{
				if(dp[i-W[j]] != -1 && (dp[i]== -1 ||  P[j] + dp[i-W[j]] <= dp[i]))	
					dp[i] = P[j] + dp[i-W[j]];
			}
		}
	}

	return dp[f];
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll e,f;
		cin>>e>>f;

		f-=e;

		ll n;
		cin>>n;

		vi P(n), W(n);
		for(ll i=0;i<n;i++)
			cin>>P[i]>>W[i];


		memset(dp, -1, sizeof(dp));

		ll ans = modifiedKnapsack(P,W,f,n);

		if(ans < 0)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
	}
}