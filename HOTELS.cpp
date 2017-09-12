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
	ll n,m;
	cin>>n>>m;

	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];

	ll low = 0, high = 0;
	ll sum = arr[0];
	ll maxm = INT_MIN;
	while(1)
	{
		if(sum==m)
		{
			maxm = sum;
			break;
		}
		if(sum + arr[high+1] <= m)
		{
			high++;
			if(high >= n)
				break;
			sum += arr[high];
		}

		else
		{
			if(low==high)
			{
				sum -= arr[low];
				low++;
				high++;
				if(high >=n)
					break;
				sum += arr[low];
			}
			else if(low!=high)
			{
				sum -= arr[low];
				low++;
			}
		}
		if(sum <= m)
			maxm = max(maxm, sum);
	}
	cout<<maxm<<endl;
}