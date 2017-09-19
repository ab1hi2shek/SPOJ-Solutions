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
#define MAXM 100005

struct node{
	int maxVal;
	int sum;
};

int arr[MAXM];

node merge(node left, node right)
{
	node temp;
	temp.maxVal = max(left.maxVal, right.maxVal);
	temp.sum = max(left.maxVal + right.maxVal, max( left.sum, right.sum));

	return temp;
}

node segArr[4*MAXM + 1];

 void buildTree(int low, int high, int pos)
 {
 	if(low == high)
 	{
 		segArr[pos].maxVal = arr[low];
 		segArr[pos].sum = arr[low];
 		return;
 	}

 	int mid = low + (high-low)/2;
 	buildTree(low,mid,2*pos);
 	buildTree(mid+1,high,2*pos+1);

 	segArr[pos] = merge(segArr[2*pos], segArr[2*pos+1]);
 }

 node query(int qlow, int qhigh, int low, int high, int pos)
 {
 	if( qlow <= low && qhigh >= high)
 		return segArr[pos];

 	int mid = low + (high-low)/2;

 	if(qlow > mid)
 		return query(qlow, qhigh, mid+1, high, 2*pos+1);
 	if(qhigh <= mid)
 		return query(qlow, qhigh, low, mid, 2*pos);

 	node x = query(qlow, qhigh, low, mid, 2*pos);
 	node y = query(qlow, qhigh, mid+1, high, 2*pos+1);

 	node result;
 	return result = merge(x,y);
 }

 void update(int pos, int indexToModify, int low, int high, int newVal)
 {
 	if( low == high && low == indexToModify)
 	{
 		segArr[pos].maxVal = newVal;
 		segArr[pos].sum = newVal;
 		return;
 	}

 	int mid = low + (high-low)/2;

 	if(indexToModify <= mid)
 		update(2*pos, indexToModify, low, mid, newVal);
 	if(indexToModify > mid)
 		update(2*pos+1, indexToModify, mid+1, high, newVal);

 	segArr[pos] = merge(segArr[2*pos], segArr[2*pos+1]);

 }

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;

	loop(i,0,n-1)
		cin>>arr[i];
	buildTree(0, n-1, 1);

	int q;
	cin>>q;

	while(q--)
	{
		char a;
		int b,c;
		cin>>a>>b>>c;

		if(a == 'Q')
			cout<<query(b-1, c-1, 0, n-1, 1).sum<<endl;
		else
			update(1, b-1, 0, n-1, c);
	}
}