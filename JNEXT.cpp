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
#define MAXM 1000005

int arr[MAXM];

int binary(vector<int> &v, int low, int high, int val)
{
	while(low < high)
	{
		int mid = low + (high-low)/2;
		if(v[mid] >	val)
			high = mid;
		else
			low = mid+1;
	}
	return high;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		loop(i,0,n-1)
			cin>>arr[i];

		vector<int> v;
		int ans = -1, i = n-1;

		while(arr[i] >= ans)
		{
			v.push_back(arr[i]);
			ans = arr[i];
			i--;
		}

		if(v.size() == n)
		{
			cout<<"-1"<<endl;
			continue;
		}

		sort(all(v));

		int index = binary(v,0,v.size()-1, arr[i]);

		int temp = arr[i];
		arr[i] = v[index];
		v[index] = temp;

		sort(all(v));

		loop(k,0,i)
			cout<<arr[k];
		loop(i,0,v.size()-1)
			cout<<v[i];
		cout<<endl;

	}
	return 0;
}