/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -   { in format DDMMYYYY}
	Logic - [] { 1. Very Easy, 2.Easy, 3.Medium, 4.Hard, 5.Very Hard}
	Category - 
	Platform - SPOJ
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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define mem(x,val) memset(x, val, sizeof(mem))
#define nline cout<<endl
#define MOD 1000000007
#define MAXM 1000005

ll arr[MAXM];
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;

	if(k==0)
		k++;

	ll sum = 0;
	loop(i,0,n-1)
	{
		cin>>arr[i];
		sum += arr[i];
	}

	ll low = 0, high = sum;
	while(low <= high)
	{
		ll mid = low + (high-low)/2;

		ll cnt = 0;
		for(ll i=0;i<n;i++)
		{
			if(arr[i] > mid)
				cnt += (arr[i]-mid);
		}

		if(cnt == k)
		{
			cout<<mid<<endl;
			return 0;
		}

		else if( cnt < k)
			high = mid-1;
		else
			low = mid+1;
	}
	cout<<low-1<<endl;
	return 0;
}