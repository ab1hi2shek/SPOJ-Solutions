#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXM 100005

ll fenwick[MAXM];
ll arr[MAXM];

void update(ll index, ll val, ll n)
{
	index += 1;

	while(index <= n)
	{
		fenwick[index] += val;
		index += (index & -index);
	}
}

ll search(ll index)
{
	index += 1;
	ll sum = 0;
	while(index > 0)
	{
		sum += fenwick[index];
		index -= (index & -index);
	}
	return sum;
}

void buildTree(ll n)
{
	for(ll i=1; i<=n ;i++)
		fenwick[i] = 0;
	for(ll i=0; i<=n; i++)
		update(i, arr[i],n);
}

int main()
{
	ll n;
	cin>>n;

	for(ll i=0;i<n;i++)
		cin>>arr[i];

	buildTree(n);

	ll q;
	cin>>q;

	while(q--)
	{
		ll x,y,z;
		cin>>x>>y>>z;

		if(x==1)
			update(y,z,n);
		else
			cout<<search(z) - search(y-1)<<endl;
	}
	return 0;
}