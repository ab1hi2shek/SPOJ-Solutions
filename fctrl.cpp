#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
int main()
{
	std::ios::sync_with_stdio(false);
	
	ll n,m,k;
	cin>>n>>m>>k;

	vector<ll> v(n);
	for(ll i=0;i<n;i++)	cin>>v[i];

	
	vector<pair<ll,ll>> hash;
	
	ll prev = -1
	for(ll i=0;i<n;i++)
	{
		if(v[i]==1)
		{
			if(prev==-1)
				hash.push_back(make_pair(i,i));
			else
				hash.push_back(make_pair(i-prev, i));
			prev = i;
		}
	}

	sort(hash.begin(), hash.end());

	for(int i=0;i<hash.size();i++)
		cout<<v[i].first<" "<<v[i].second<<endl;
	return 0;
}