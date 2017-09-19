/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	13/09/2017
	Logic - Dynamic Pogramming
	Category - Easy-Medium
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
#define MOD 1000000007

ll distinctSubSequences( string s)
{
	vector<int> hash(256,-1);
	ll len = s.size();
	ll dp[len+1];
	dp[0] = 1;

	for(ll i=0; i<len; i++)
	{
		dp[i+1] = (2*dp[i]%MOD)%MOD;

		if(hash[s[i]] != -1)
			dp[i+1] = (dp[i+1]%MOD - dp[hash[s[i]]] % MOD + MOD)%MOD;
		hash[s[i]] = i;
	}

	return dp[len] % MOD;
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

		cout<< distinctSubSequences(s)<<endl;

	}
}