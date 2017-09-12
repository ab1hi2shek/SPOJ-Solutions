/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/9/2017
	Logic -	ADHOC - logic
	Category - Easy
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

ll arr[10] = {55,45,36,28,21,15,10,6,3,1};
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	ll dp[65];
	dp[0] = 0;
	dp[1] = 10;
	dp[2] = 55;
	for(ll i=3;i<=64;i++)
	{	
		ll sum = arr[9];
		for(ll j=8;j>=0;j--)
		{
			sum += arr[j];
			arr[j] += arr[j+1];
		}
		dp[i] = sum;
	}
	while(t--)
	{
		ll k,n;
		cin>>k>>n;

		cout<<k<<" "<<dp[n]<<endl;
	}
}