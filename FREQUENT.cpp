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

ll arr[MAXM];
struct node{
	ll prefFreq;	//stores the prefix frequency[1,2,2,2,2,5,5] prefFreq = 1 (as 1 occurs single time)->means from beginning 
	ll sufFreq;	// store the suffix frequency		suffFreq = 2 ( 5 occurs 2 times )
	ll maxFreq;		//stores the max frequency			maxFreq = 4 (as 2 occurs 4 times) 
};

node segArr[4*MAXM + 1];

node merge(ll low, ll high, ll mid, node a, node b)
{
	node temp;
	if(arr[mid] == arr[mid+1])
	{
		temp.prefFreq = a.prefFreq + b.prefFreq * (arr[low] == arr[mid]);
		temp.sufFreq = b.sufFreq + a.sufFreq * (arr[mid+1] == arr[high]);
		temp.maxFreq = max(a.sufFreq + b.prefFreq , max(a.maxFreq, b.maxFreq));
	}
	else
	{
		temp.prefFreq = a.prefFreq;
		temp.sufFreq = b.sufFreq;
		temp.maxFreq = max(a.maxFreq, b.maxFreq);
	}

	return temp;
}

void buildTree(ll low, ll high, ll pos)
{
	if(low == high)
	{
		segArr[pos].prefFreq = segArr[pos].sufFreq = segArr[pos].maxFreq = 1;
		return;
	}

	ll mid = low + (high-low)/2;
	buildTree(low, mid, 2*pos);
	buildTree(mid+1, high, 2*pos+1);

	segArr[pos] = merge(low, high, mid, segArr[2*pos], segArr[2*pos + 1]);
}

node query(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
	if(qlow <= low && qhigh >= high)
		return segArr[pos];

	ll mid = low + (high-low)/2;
	if(qlow > mid)
		return query(qlow, qhigh, mid+1, high, 2*pos+1);
	if(qhigh <= mid)
		return query(qlow, qhigh, low, mid, 2*pos);

	node a = query(qlow, qhigh, low, mid, 2*pos);
	node b = query(qlow, qhigh, mid+1, high, 2*pos+1);

	node res;
	return res = merge(low, high, mid, a, b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	ll n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;

		ll q;
		cin>>q;

		loop(i,0,n-1)
			cin>>arr[i];
		buildTree(0,n-1,1);
		// loop(i,1,15)
		// 	cout<<segArr[i].prefFreq<<" "<<segArr[i].sufFreq<<" "<<segArr[i].maxFreq<<endl;
		// cout<<endl;
		while(q--)
		{
			ll a,b;
			cin>>a>>b;

			cout<<query(a-1,b-1, 0, n-1, 1).maxFreq<<endl;
		}

	}
	return 0;
}