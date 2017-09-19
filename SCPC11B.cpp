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
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	while(1)
	{
		cin>>n;

		if(n==0)
			break;

		ll arr[n];
		loop(i,0,n-1)
			cin>>arr[i];

		sort(arr,arr+n);

		ll flag = 1;
		if(arr[0] > 200 || 2844 - 2*arr[n-1] > 200)
			flag = 0;
		loop(i,1,n-1)
		{
			if(arr[i] - arr[i-1] > 200)
			{
				flag = 0;
				break;
			}
		}

		if(flag==0)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<"POSSIBLE\n";
	}
	return 0;
}