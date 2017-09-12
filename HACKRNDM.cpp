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

bool binary(int arr[], int low, int high, int val)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;

		if(arr[mid] == val)
			return true;
		else if(arr[mid] > val)
			high = mid-1;
		else
			low = mid+1;
	}
	return false;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;

	int arr[n];
	loop(i,0,n-1)
		cin>>arr[i];

	sort(arr,arr+n);

	int count = 0;
	for(int i=0;i<n-1;i++)
	{
		if(binary(arr,i+1, n-1, arr[i]+k))
			count++;
	}
	cout<<count<<endl;
}