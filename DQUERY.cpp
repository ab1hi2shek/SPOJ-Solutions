/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 17/09/2017
	Logic -	MO's Algorithm
	Category - Medium
	Platform - SPOJ
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
#define MAXN 30005
#define MAXELE 1000005
#define MAXQ 200005

int arr[MAXN], freq[MAXELE], ans[MAXQ];
int bucketSize;

struct node
{
	int index;
	int left;
	int right;
};

bool accompare(node a, node b)
{
	int x1 = a.left/bucketSize;
	int x2 = b.left/bucketSize;

	if(x1 != x2)
		return x1 < x2;
	return a.right < b.right;
}

node query[MAXQ];

int main()
{
	std::ios::sync_with_stdio(false);
	//memset(hash,0,sizeof(hash));
	int n;
	cin>>n;

	bucketSize = ceil(sqrt(n));

	loop(i,0,n-1)
		cin>>arr[i];

	int q;
	cin>>q;

	loop(i,0,q-1)
	{
		int x,y;
		cin>>x>>y;
		query[i].index = i;
		query[i].left = x;
		query[i].right = y; 
	}

	sort(query, query+q, accompare);

	loop(i,0,q-1)
		cout<<query[i].left<<" "<<query[i].right<<endl;

	int start=0, end = 0;
	int sum = 0;
	loop(i,0,q-1)
	{
		while (start < query[i].left)
        {
            --freq[arr[start]];
            if (freq[arr[start]] == 0)
                sum--;
            ++start;
        }
        while (end > query[i].right)
        {
            --freq[arr[end]];
            if (freq[arr[end]] == 0)
                sum--;
            --end;
        }
 
        while (start > query[i].left)
        {
            --start;
            ++freq[arr[start]];
            if (freq[arr[start]] == 1)
                sum++;
        }
        while (end < query[i].right)
        {
            ++end;
            ++freq[arr[end]];
            if (freq[arr[end]] == 1)
                sum++;
        }
 
        ans[query[i].index] = sum;
	}

	loop(i,0,q-1)
		cout<<ans[i]<<endl;

}