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

ll lcs(string s, ll len, string rev)
{
	ll dp[len+1][len+1];

	for(ll i=0;i<=len;i++)
	{
		for(ll j=0;j<=len;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}

	for(ll i=1;i<=len;i++)
	{
		for(ll j=1;j<=len;j++)
		{
			if(s[i-1]==rev[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[len][len];
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;
		string rev = "";

		for(ll i=s.size()-1;i>=0;i--)
			rev += s[i];

		cout<<s.size() - lcs(s,s.size(),rev)<<endl;
	}
}