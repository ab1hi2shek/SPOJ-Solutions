/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/9/2017
	Logic -	BInary search
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

ll binary(ll arr[], ll low, ll high, ll val)
{
	while(low<high)
	{
		ll mid = low + (high-low)/2;
		if(arr[mid] <= val)
			low = mid+1;
		else
			high = mid;
	}
	return low;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	
	while(1)
	{
		ll n;
		cin>>n;

		if(n==0)
			break;
		ll arr[n];
		loop(i,0,n-1)	
			cin>>arr[i];
		sort(arr, arr+n);

		ll count = 0;
		for(ll i=0;i<n-2;i++)
		{
			for(ll j=i+1;j<n-1;j++)
			{
				ll sum = arr[i] + arr[j];
				ll indx = n;
				if(arr[n-1] > sum)
					indx = binary(arr,j+1,n-1,sum);
				count += n-indx;
			}
		}
		cout<<count<<endl;
	}
}