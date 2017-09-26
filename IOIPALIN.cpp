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
#define MAXM 5005

ll lcs(ll n, string s1, string s2)
{
	ll dp[n+1][n+1];

	for(ll i=0; i<=n; i++)
	{
		for(ll j=0; j<=n; j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);			
		}
	}

	return dp[n][n];
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	string s1,s2;
	cin>>s1;

	for(ll i= s1.size()-1; i>=0; i--)
		s2 += s1[i];
	
	cout<<n - lcs(n,s1,s2)<<endl;

	return 0;
}