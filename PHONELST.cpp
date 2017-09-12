#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
#define SIZE 10

struct trie{
	trie *child[SIZE];
	bool isLeaf;
};

trie* getNode()
{
	trie* root = new trie;
	root->isLeaf = false;

	for(int i=0;i<SIZE;i++)
		root->child[i] = NULL;
	return root;
}

int insert(trie *root, string s)
{
	trie *temp = root;
	ll flag = 0;

	for(ll i=0;i<s.size();i++)
	{
		ll index = s[i]-'0';
		//cout<<" index = "<<index<<endl;

		if(!temp->child[index])
		{
			temp->child[index] = getNode();
			flag = 1;
		}
		else
		{
			if(temp->child[index]->isLeaf)
				return 0;
		}

		temp = temp->child[index];
	}
	temp->isLeaf = true;

	return flag;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		trie *root = getNode();
		ll n;
		cin>>n;

		bool ans = true;
		for(ll i=0;i<n;i++)
		{
			string s;
			cin>>s;

			//cout<<s<<endl;

			 if(ans && !insert(root,s))
			 	ans = false;
			// cout<<insert(root,s)<<endl;
			// if(insert(root,s) == false)
			// 	break;
		}

		if(!ans)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}