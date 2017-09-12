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

ll dp[105][505];
 
ll knapsack01(vi &wt, vi &val, ll n, ll W)
{
  for (ll i = 0; i <= n; i++)
   {
       for (ll w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               dp[i][w] = 0;
           else if (wt[i-1] <= w)
                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
           else
                 dp[i][w] = dp[i-1][w];
       }
   }
 
   return dp[n][W];
}


int main()
{
	std::ios::sync_with_stdio(false);

	while(1)
	{
		ll W,n;
		cin>>W>>n;

		if(W==0 && n==0)
			break;

		vi wt(n);
		vi val(n);
		for(ll i=0;i<n;i++)
			cin>>wt[i]>>val[i];

		ll ans = knapsack01(wt,val,n,W);

		int wtSum=0;
		for(ll i=0;i<=W;i++)
		{
			if(dp[n][i]==ans)
			{
				wtSum=i;
				break;
			}
		}

		cout<<wtSum<<" "<<ans<<endl;
	}
	return 0;
}