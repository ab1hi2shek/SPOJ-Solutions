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

ll lcs(vector<ll> &agnee, vector<ll> &tom)
{
	ll s1 = agnee.size();
	ll s2 = tom.size();

	ll dp[s1+1][s2+1];

	for(ll i=0;i<=s1;i++)
	{
		for(ll j=0;j<=s2;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(agnee[i] == tom[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[s1][s2];
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		vi agnee;
		while(1)
		{
			ll a;
			cin>>a;

			if(a==0)
				break;
			else
				agnee.push_back(a);
		}

		vector<vector<ll> > tom;
		vector<ll> temp;
		while(1)
		{
			temp.clear();
			ll x;
			cin>>x;
			if(x==0)
				break;
			else
				temp.push_back(x);
			while(1)
			{
				ll y;
				cin>>y;
				if(y==0)
					break;
				else
					temp.push_back(y);
			}
			tom.push_back(temp);
		}

		ll ans = INT_MIN;
		for(ll i=0;i<tom.size();i++)
			ans = max(ans, lcs(agnee, tom[i]));
		cout<<ans<<endl;

	}
}