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

double Pi=3.14159265358979323846264338327950;

bool find(long double val, long double arr[], ll n, ll f)
{
	ll countm = 0;
	if(!val)
		return false;
	loop(i,0,n-1)
		countm += int(arr[i]/val);

	if(countm >= f)
		return true;
	else
		return false;
}

int main()
{
	//std::ios::sync_with_stdio(false);
	ll t;
	scanf("%lld", &t);

	while(t--)
	{
		ll n,f;
		scanf("%lld%lld", &n, &f);
		f++;

		long double arr[n];
		loop(i,0,n-1)
		{
			ll a;
			scanf("%lld", &a);
			arr[i] = Pi*a*a;
		}

		sort(arr, arr+n);

		long double low = 0, high = arr[n-1];
		while(high - low >= 1e-6)
		{
			long double mid = low + (high - low)/2;

			if(find(mid, arr,n,f))
				low = mid;
			else
				high = mid;
		}
		printf("%.4Lf\n", low);
	}
	return 0;
}