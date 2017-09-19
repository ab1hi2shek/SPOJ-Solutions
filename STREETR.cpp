/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
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

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll arr[n];

	loop(i,0,n-1)
		cin>>arr[i];

	if(n==1)
	{
		cout<<"0"<<endl;
		return 0;
	}

	sort(arr, arr+n);

	ll count = 1;
	ll gcdVal = arr[1] - arr[0];

	for(ll i=2; i<n; i++)
	{
		count++;
		gcdVal = gcd(arr[i] - arr[i-1], gcdVal);
	}

	gcdVal = (arr[n-1] - arr[0]) / gcdVal;
	cout<<gcdVal - count<<endl;
}