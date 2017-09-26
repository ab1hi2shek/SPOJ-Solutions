/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
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

struct node{
	ll zero;
	ll one;
	ll two;
};

node segArr[4*MAXM + 1];
ll lazy[4*MAXM+1];

void buildTree(ll low, ll high, ll pos)
{
	if(low == high)
	{
		segArr[pos].zero = 1;
		segArr[pos].one = segArr[pos].two = 0;
		return;
	}

	int mid = low + (high-low)/2;
	buildTree(low, mid, 2*pos);
	buildTree(mid+1, high, 2*pos+1);

	segArr[pos].zero = segArr[2*pos].zero + segArr[2*pos+1].zero;
}

void propogate(ll pos, ll low, ll high)
{
	if(low != high)
	{
		lazy[2*pos] = (lazy[2*pos] + lazy[pos]) % 3;
		lazy[2*pos+1] = (lazy[2*pos+1] + lazy[pos]) % 3;
	}

	if(lazy[pos] == 1)
	{
		ll a = segArr[pos].zero;
		ll b = segArr[pos].one;
		ll c = segArr[pos].two;
		segArr[pos].zero = c;
		segArr[pos].one = a;
		segArr[pos].two = b;
	}

	if(lazy[pos] == 2)
	{
		ll a = segArr[pos].zero;
		ll b = segArr[pos].one;
		ll c = segArr[pos].two;
		segArr[pos].zero = b;
		segArr[pos].one = c;
		segArr[pos].two = a;
	}
	lazy[pos] = 0;
}

void update(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
	// if any remaining update
	if(lazy[pos] != 0)
		propogate(pos, low, high);
	// if out of range
	if(qlow > high || qhigh < low)
		return;
	//if the update range overlaps any of the node, we will set node as lazy
	if(low >= qlow && high <= qhigh)
	{
		lazy[pos] = 1;
		propogate(pos, low, high);
		return;
	}

	int mid = low + (high - low)/2;
	update(qlow, qhigh, low, mid, 2*pos);
	update(qlow, qhigh, mid+1, high, 2*pos+1);

	segArr[pos].zero = segArr[2*pos].zero + segArr[2*pos+1].zero;
	segArr[pos].one = segArr[2*pos].one + segArr[2*pos+1].one;
	segArr[pos].two = segArr[2*pos].two + segArr[2*pos+1].two;
}

ll query(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
	// if any remaining update
	if(lazy[pos] != 0)
		propogate(pos, low, high);
	//if total overlap
	if(qlow <= low && qhigh >= high)
		return segArr[pos].zero;
	//finding mid point
	int mid = low + (high-low)/2;

	if(qlow > mid)
		return query(qlow, qhigh, mid+1, high, 2*pos+1);
	if(qhigh <= mid)
		return query(qlow, qhigh, low, mid, 2*pos);

	//adding the count from its children
	ll x = query(qlow, qhigh, low, mid, 2*pos);
	ll y = query(qlow, qhigh, mid+1, high, 2*pos+1);
	return x+y;
}

int main()
{
	std::ios::sync_with_stdio(false);

	ll n,k;
	cin>>n>>k;
	memset(lazy, 0, sizeof(lazy));

	buildTree(0, n-1, 1);

	while(k--)
	{
		ll a,b,c;
		cin>>a>>b>>c;

		if(a==0)
			update(b,c,0,n-1,1);
		else
			cout<<query(b,c,0,n-1,1)<<endl;
	}
	return 0;
}