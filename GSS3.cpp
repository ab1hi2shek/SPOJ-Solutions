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
#define MAXM 50005

struct node{
	int sum;
	int prefixSum;
	int suffixSum;
	int bestSum;
};

node segNode[4*MAXM + 1]; 
int arr[MAXM];

void initialize(int pos, int val)
{
	segNode[pos].sum = val;
	segNode[pos].prefixSum = val;
	segNode[pos].suffixSum = val;
	segNode[pos].bestSum = val;
}

node merge(node left, node right)
{
	node temp;
	temp.sum = left.sum + right.sum;
	temp.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
	temp.suffixSum = max(right.suffixSum, left.suffixSum + right.sum);
	temp.bestSum = max(left.suffixSum + right.prefixSum, max(left.bestSum, right.bestSum));

	return temp;
}

void buildTree(int low, int high, int pos)
{
	if(low == high)
	{
		initialize(pos, arr[low]);
		return;
	}

	int mid = low + (high-low)/2;
	buildTree(low, mid, 2*pos);
	buildTree(mid+1, high, 2*pos+1);

	segNode[pos] = merge(segNode[2*pos], segNode[2*pos + 1]);
}

node query(int qlow, int qhigh, int low, int high, int pos)
{
	//cout<<"quey = "<<low<<" "<<high<<endl;
	if(qlow <= low && qhigh >= high)
		return segNode[pos];

	int mid = low + (high-low)/2;

	if(qlow > mid)
		return query(qlow,qhigh,mid+1,high,2*pos+1);
	if(qhigh <= mid)
		return query(qlow,qhigh,low,mid,2*pos);

	node x = query(qlow, qhigh, low, mid, pos*2);
	node y = query(qlow, qhigh, mid+1, high, pos*2+1);
	node result;
	result = merge(x,y);
	return result;
}

void update(int pos, int indexToModify, int low, int high, int newVal)
{
	//cout<<" upadate karbi = "<<low<<" "<<high<<" "<<pos<<endl;
	if(high == low && low == indexToModify)
	{
		initialize(pos, newVal);
		return;
	}

	int mid = low + (high-low)/2;
	if(indexToModify <= mid)
		update(2*pos, indexToModify, low, mid, newVal);
	else if(indexToModify > mid)
		update(2*pos+1, indexToModify, mid+1, high, newVal);

	segNode[pos] = merge(segNode[2*pos], segNode[2*pos+1]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	loop(i,0,n-1)
		cin>>arr[i];

	buildTree(0,n-1,1);

	// for(ll i=0;i<10;i++)
	// 	cout<<segNode[i].prefixSum<<" "<<segNode[i].suffixSum<<" "<<segNode[i].sum<<" "<<segNode[i].bestSum<<endl;

	int m;
	cin>>m;

	while(m--)
	{
		ll a,x,y;
		cin>>a>>x>>y;

		if(a==0){
			update(1, x-1, 0, n-1, y);
			// for(ll i=0;i<10;i++)
			// cout<<segNode[i].prefixSum<<" "<<segNode[i].suffixSum<<" "<<segNode[i].sum<<" "<<segNode[i].bestSum<<endl;

		}
		else
			cout<<query(x-1, y-1, 0, n-1, 1).bestSum<<endl;
	}
}