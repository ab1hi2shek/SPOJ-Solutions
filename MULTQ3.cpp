/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

/*
	THIS CODE WILL GIVE TLE ON THE SPOJ. JUST FOR LEARNING PURPOSE
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

ll arr[MAXM];

ll segArr[4*MAXM+1];

void update(ll qlow, ll qhigh, ll low, ll high, ll pos, ll value)
{
	if(low == high && qlow <= low && qhigh >= low )
	{
		arr[low] += value;
		segArr[pos] = (arr[low] % 3 == 0);
		return;
	}

	if(qlow > high || qhigh < low)
		return;
	ll mid = low + (high-low)/2;
	update(qlow, qhigh, low, mid, 2*pos, value);
	update(qlow, qhigh, mid+1, high, 2*pos+1, value);

	segArr[pos] = segArr[2*pos] + segArr[2*pos+1];	

}

ll query(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
	if(qlow <= low && qhigh >= high)
		return segArr[pos];
	ll mid = low + (high-low)/2;

	if(qlow > mid)
		return query(qlow, qhigh, mid+1, high, 2*pos+1);
	if(qhigh <= mid)
		return query(qlow, qhigh, low, mid, 2*pos);

	ll x = query(qlow, qhigh, low, mid, 2*pos);;
	ll y = query(qlow, qhigh, mid+1, high, 2*pos+1);

	ll res;
	return res = x + y;
}

void buildTree(int low, int high, int pos)
{
	if(low == high)
	{
		segArr[pos] = (arr[low] % 3 == 0);
		return;
	}

	int mid = low + (high-low)/2;
	buildTree(low, mid, 2*pos);
	buildTree(mid+1, high, 2*pos+1);

	segArr[pos] = segArr[2*pos] + segArr[2*pos + 1];
}


int main()
{
	std::ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;

	memset(arr,0,sizeof(arr));
	buildTree(0, n-1, 1);
	while(k--)
	{
		ll a,b,c;
		cin>>a>>b>>c;

		if(a==0)
			update(b, c, 0, n-1, 1, 1);
		else
			cout<<query(b, c, 0, n-1, 1)<<endl;
	}
	return 0;
}