/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
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
#define MAXM 10005

struct node{
	ll st;
	ll dur;
	ll price;
};

node arr[MAXM];

bool accompare(node a, node b)
{
	if(a.st < b.st)
		return true;
	return false;
}

ll find(ll n, ll val)
{
	if(arr[n-1].st < val)
		return n;
	ll low = 0, high = n-1;
	while(low < high)
	{
		ll mid = low + (high-low)/2;

		if(arr[mid].st >= val)
			high = mid;
		else
			low = mid+1;
	}
	return high;
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
		loop(i,0,n-1)
			cin>>arr[i].st>>arr[i].dur>>arr[i].price;
		sort(arr, arr+n, accompare);
		
		ll dp[n+1];
		dp[n] = 0;

		for(ll i=n-1; i>=0 ;i--){
			//cout<<find(n,arr[i].st + arr[i].dur)<<endl;
			dp[i] = max(dp[i+1], dp[find(n, arr[i].st + arr[i].dur)] + arr[i].price);
			//cout<<dp[i]<<endl;
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}