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
#define MAXM 1005

struct node{
	ll len;
	ll brd;
};

node arr[MAXM];
ll dp[MAXM][MAXM];

ll recFun(ll len, ll n, ll prevBrd)
{
	//countm++;
	if(n == 0)
		return 0;
	 if(dp[n][prevBrd] != -1)
	  	return dp[n][prevBrd];

	ll a = arr[n-1].len + 2*arr[n-1].brd  - 2*min(arr[n-1].brd, prevBrd);
	ll b = arr[n-1].brd + 2*arr[n-1].len  - 2*min(arr[n-1].len, prevBrd);

	if(n==1 || n==len)
	{
		a -= arr[n-1].brd;
		b -= arr[n-1].len;
	}

	ll x = a + recFun(len, n-1, arr[n-1].brd);
	ll y = b + recFun(len, n-1, arr[n-1].len);
	return dp[n][prevBrd] = max(x,y);
}

// ll fun()
// {
// 	ll dp[n];
// 	dp[0] = min(arr[0].len, arr[0].brd);

// 	ll prevBrd1 = 0, prevBrd2 = 0;
// 	loop(i,1,n-1)
// 	{
// 		ll a1 = arr[i].len + 2*arr[i].brd  - 2*min(arr[i].brd, prevBrd);
// 		ll b1 = arr[i].brd + 2*arr[i].len  - 2*min(arr[i].len, prevBrd);
// 		ll a2 = arr[i].len + 2*arr[i].brd  - 2*min(arr[i].brd, prevBrd1);
// 		ll b2 = arr[i].brd + 2*arr[i].len  - 2*min(arr[i].len, prevBrd1);

// 		if(n==1 || n==len)
// 		{
// 			a -= arr[i].brd;
// 			b -= arr[i].len;
// 		}

// 		ll x = a + dp[i-1];// arr[n-1].len, arr[n-1].brd);
// 		ll y = b + dp[i-1]; //recFun(len, n-1, arr[n-1].brd, arr[n-1].len);
// 		dp[i] = max(x,y);
// 	}
// }

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	loop(i,0,n-1)
		cin>>arr[i].len>>arr[i].brd;

	if(n==1)
		cout<<max(arr[0].len, arr[0].brd)<<endl;
	else
		cout<<recFun(n,n,0)<<endl;
	return 0;
}