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
#define MAXM 100005

struct node{
	int length;
	int breadth;
	int height;
};

bool accompare(node a, node b)
{
	ll x = a.length * a.breadth;
	ll y = b.length * b.breadth;

	return x > y;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;

	while(1)
	{
		cin>>n;

		if(n==0)	break;

		node arr[3*n];
		ll p = 0;
		loop(i,0,n-1)
		{
			ll temp[3];
			cin>>temp[0]>>temp[1]>>temp[2];
			sort(temp, temp+3);

			arr[p].length = temp[2];
			arr[p].breadth = temp[1];
			arr[p].height = temp[0];
			p++;
			arr[p].length = temp[2];
			arr[p].breadth = temp[0];
			arr[p].height = temp[1];
			p++;
			arr[p].length = temp[1];
			arr[p].breadth = temp[0];
			arr[p].height = temp[2];
			p++;
		}

		sort(arr, arr+3*n, accompare);

		ll maxH[3*n];
		for(ll i=0;i<3*n;i++)
			maxH[i] = arr[i].height;

		for(ll i=1;i<3*n;i++)
		{
			for(ll j=0;j<i;j++)
			{
				if(arr[j].length > arr[i].length && arr[j].breadth > arr[i].breadth && maxH[i] < maxH[j] + arr[i].height)
					maxH[i] = maxH[j] + arr[i].height;
			}
		}

		ll maxm = maxH[0];
		loop(i,1,3*n-1)
			maxm = max(maxm, maxH[i]);

		cout<<maxm<<endl;

	}
}