#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
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
#define MAX 26;

/*
	function for trie implementation
*/
/*
struct trie{

	unordered_map<char,trie*> children;
	//bool isLeaf;
};

trie* getNode()
{
	trie* root = new trie;
	//root->isLeaf = false;
	return root;
}

void insert( trie* &root, string s)
{
	if(!root)
		root = getNode();
	trie* pCrawl = root;

	for(ll i=0; i<s.length(); i++)
	{
		char ch = s[i];
		
		if(pCrawl->children.find(ch) == pCrawl->children.end())
			pCrawl->children[ch] = getNode();

		pCrawl = pCrawl->children[ch];
	}
	//pCrawl->isLeaf = true;
}

ll countNodes(trie* root)
{
	if(!root)
		return 0;
	ll count = 0;
	unordered_map<char,trie*>::iterator it;

	for(it = root->children.begin(); it!= root->children.end(); it++){
		//cout<<(it->first)<<endl;
		count += countNodes(it->second);
	}

	return 1 + count;
}
*/

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	/*
		This is a brute force approach for this question. Althought this gives th correct answer but it will get TLE on spoj
		We have to make our solution faster
	*/

	/*
	set<string> unique;

	while(t--)
	{
		string s;
		cin>>s;

		ll len = s.length();

		for(ll i=0;i<len;i++)
		{
			string temp = "";
			temp += s[i];
			unique.insert(temp); 
			for(ll j=i+1;j<len;j++)
			{
				temp += s[i];
				unique.insert(temp);
			}
		}

		cout<<unique.size()<<endl;
		unique.clear();
	}
	*/

	/*
		This a tree based approach - we are creating a suffix trie and then number of nodes in the trie will give you the
		answer. Link - http://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-trie/
		It also gives the correct answer but will show TLE on SPOJ.
	*/

	/*
	while(t--)
	{
		string s;
		cin>>s;

		trie* root = NULL;

		for(ll i=0;i<s.length(); i++)
		{
			string tmp = "";
			for(ll j=i; j<s.length(); j++)
			{
				tmp += s[j];
				insert(root, tmp);
			}

		}

		ll ans = countNodes(root);
		cout<<ans-1<<endl;

	}
	*/

}