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

ll bitReverse(ll a)
{
	ll out = 0;
	ll i=0;
	while(a != 0)
	{
		ll temp = a%2;
		out = out*2 + temp;
		a = a/2;
	}
	return out;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	ll arr[t];

	loop(i,0,t-1)
		cin>>arr[i];

	loop(i,0,t-1)
	{
		if(arr[i]%2==0)
			arr[i] = bitReverse(arr[i]);
	}

	loop(i,0,t-1)
		cout<<arr[i]<<endl;
}