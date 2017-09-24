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
#define MAXM 100005

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	ll p =1;
	while(1)
	{
		cin>>n;

		if(n==-1)
			break;
		cout<<"Case "<<p++<<":\n";
		ll arr[n+1];
		loop(i,0,n)
			cin>>arr[i];

		ll t;
		cin>>t;

		while(t--)
		{
			ll x;
			cin>>x;
			ll ans = arr[0];
			loop(i,1,n)
				ans = ans*x + arr[i];
			cout<<ans<<endl; 

		}
	}
	return 0;
} 