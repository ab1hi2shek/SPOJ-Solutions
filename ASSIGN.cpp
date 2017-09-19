/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 13/09/2017
	Logic -	Dynamic Programing
	Category - Medium
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
#define MAX 25

ll arr[MAX][MAX];
ll hashs[MAX];

ll assignments(ll index, ll n)
{
	if(index < 0 )
		return 1;

	ll count = 0;
	for(ll i=0; i<n; i++)
	{
		if(arr[index][i] == 1 && hashs[i] == 0)
		{
			hashs[i] = 1;
			 count += assignments(index-1, n);

			hashs[i] = 0;
		}
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(hashs,0,sizeof(hashs));
		ll n;
		cin>>n;

		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}

		cout<<assignments(n-1,n)<<endl;
		//cout<<ans<<endl;
	}
}