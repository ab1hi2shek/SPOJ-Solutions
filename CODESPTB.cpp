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

ll merge(ll arr[], ll low, ll mid, ll high)
{
	//cout<<"low = "<<low<<" mid = "<<mid<<" high = "<<high<<endl;
	ll temp[high-low+1];

	ll i=low, j = mid+1;
	ll p = 0;
	ll count = 0;
	while(i<=mid || j<=high)
	{
		if(i>mid)
			temp[p++] = arr[j++];
		else if(j>high)
			temp[p++] = arr[i++];
		else if(arr[i] <= arr[j])
			temp[p++] = arr[i++];
		else
		{
			temp[p++] = arr[j++];
			count += mid-i+1;
		}
	}

	p = 0;
	loop(i,low,high)
		arr[i] = temp[p++];
	//	cout<<count<<endl;
	return count;
}

ll mergeSort(ll arr[], int low, int high)
{
	if(low >= high)
		return 0;

	ll mid = low + (high-low)/2;
	ll x = 0;
	x += mergeSort(arr, low, mid);
	x += mergeSort(arr, mid+1, high);
	x += merge(arr,low,mid,high);
	return x;
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

		ll arr[n];
		loop(i,0,n-1)
			cin>>arr[i];

		ll ans = mergeSort(arr, 0, n-1);
		// loop(i,0,n-1)
		// 	cout<<arr[i]<<" ";
		// cout<<endl;

		cout<<ans<<endl;

	}
}