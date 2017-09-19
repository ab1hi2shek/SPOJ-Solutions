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

struct node
{
	int sum;
	int minsum;
};

node segArr[4*MAXM+1];
string arr;

node merge(node a, node b)
{
	node temp;
	temp.sum = a.sum + b.sum;
	temp.minsum = min(a.minsum, a.sum + b.minsum);
	return temp;
}

void buildTree(int low, int high, int pos)
{
	if(low == high)
	{
		segArr[pos].sum = arr[low] == '('?1:-1;
		segArr[pos].minsum = arr[low] == '('?1:-1;
		return;
	}
	int mid = low + (high-low)/2;
	buildTree(low,mid,2*pos);
	buildTree(mid+1, high, 2*pos+1);
	segArr[pos] = merge(segArr[2*pos], segArr[2*pos+1]);
}

//node query(int qlow, int qhigh, int low, int high, int pos)
bool query()
{
	if( segArr[1].sum == 0 && segArr[1].minsum == 0)
		return true;
	else
		return false;
}

void update(int pos, int indexToModify, int low, int high)
{
	if(low == high && low == indexToModify)
	{
		segArr[pos].minsum = -segArr[pos].sum;
		segArr[pos].sum = -segArr[pos].sum;
		return;
	}

	int mid = low + (high-low)/2;

	if(indexToModify <= mid)
		update(2*pos, indexToModify, low, mid);
	if(indexToModify > mid)
		update(2*pos+1, indexToModify, mid+1, high);

	segArr[pos] = merge(segArr[2*pos], segArr[2*pos+1]);
} 


int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	ll p = 1;
	while(cin>>n)
	{
		cin>>arr;
		buildTree(0,n-1,1);
		cout<<"Test "<<p++<<":"<<endl;
		int q;
		cin>>q;
		while(q--)
		{
			int a;
			cin>>a;

			if(a==0)
			{
				if(query())
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else
				update(1,a-1,0,n-1);
		}
	}
	return 0;
}