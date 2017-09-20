/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -   20092017 { in format DDMMYYYY}
	Logic - [3] { 1. Very Easy, 2.Easy, 3.Medium, 4.Hard, 5.Very Hard}
	Category - Learning Suffix Array + LCP Array
	Platform - SPOJ
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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define mem(x,val) memset(x, val, sizeof(x))
#define nline cout<<endl
#define MOD 1000000007
#define MAXM 100005

struct node
{
	int index;
	int rank[2];
};

ll suffixArr[MAXM];
ll lcp[MAXM];


bool accompare(node a, node b)
{
	if(a.rank[0] < b.rank[0])
		return true;
	if(a.rank[0] == b.rank[0] && a.rank[1] < b.rank[1])
		return true;
	return false;
}

//function to build the suffixArr of a given string
void buildSuffixArray(string s, ll n)
{
	// to store the suffix ranks and their indices
	node suffix[n];

	//storing the initial indices and rank of the suffixes int the structure
	for(ll i=0; i<n; i++)
	{
		suffix[i].index = i;
		suffix[i].rank[0] = s[i] - 'a';
		suffix[i].rank[1] = i+1 < n ? s[i+1] - 'a' : -1;
	}

	sort(suffix, suffix+n, accompare);

	//it is to store the current indices of the suffix array so that in the next
	//step we can retrieve these indices
	ll ind[n];

	//here k indicates that the we re sorting th suffixes on the basis of first k characters.
	for(ll k=4; k<2*n; k*=2)
	{
		ll rank = 0;
		ll prev_rank = suffix[0].rank[0];	//to store the previous rank
		suffix[0].rank[0] = rank;
		ind[suffix[0].index] = 0;

		//Assigning ranks to suffixes from [1 .. n]
		for(ll i=1; i<n;i++)
		{

			//if the rank and the prev_rank of the current suffix is equal to
			//the previous suffix the we will asiign it the same rank as of the previous
			if(suffix[i].rank[0] == prev_rank && suffix[i].rank[1] == suffix[i-1].rank[1])
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = rank;
			}
			//otherwise increment the rank by 1 and assign it to the current suffix
			else
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = ++rank;
			}

			//filling the ind[] array with the indices of the current position of suffix array
			ind[suffix[i].index] = i;
		}

		//we have assigned the rank to the suffixes. Now it's turn t assign the next_rank to all the suffixes
		//Remember at the Kth step, we are assigning the next rank on the basis of k/2th index.
		for(ll i=0;i<n;i++)
		{
			//for each suffix array we will find the index position of that suffix array and then we will find the
			//find the k/2th index from that position.
			ll nextindex = suffix[i].index + k/2;
			suffix[i].rank[1] = nextindex < n ? suffix[ind[nextindex]].rank[0] : -1;
		}

		sort(suffix, suffix+n, accompare);
	}

	//now filling the suffixArray with the help of suffix structure
	for(ll i=0;i<n;i++)
		suffixArr[i] = suffix[i].index;
}

//function to build the lcp array from the suffix array using kasai algorithm. lcp array is the length of the longest
//common prefix of the two consecutive values from the suffix array
//lcp of "aaab" and "aabc" is "aa" and hence it's length is 2.

//Now kasai algorithm states that if we have lcp of length K b/w ith and (i+1)th indices of the suffix array. Now let's
//delete one character from ith suffix. Now if we delete one character, the remaining string will also be the one of the
//suffix of our original string and i's indices will be present in the suffix array. Let's say that the indices of the
//string after deleting a character is j. Now if we try to find the lcp of the strings in the sufix array at indices 
//j and j+1 , then its lcp will be  atleast K-1.

void kasai(string s, ll n)
{
	//n is the size of the string == size of suffix array
	//this invSuff array stores the inverse of the suffix array. What i mean is let's say suffix array is 
	// [3,5,0,1,2,4] then invSuff = [2,3,4,0,5,1]
	//Let's analyze like this - In suffix array 0 is at which index, it's at 2, so invSuff[0] = 2
	//similarly, ! is at which index, it's 3, hnce invSuff[1] = 3 .... and so on ....
	ll invSuff[n];
	mem(invSuff, 0); 

	for(ll i=0;i<n;i++)
		invSuff[suffixArr[i]] = i;

	ll k = 0; //it stores the length of the previous lcp, initializing it with 0.

	for(ll i=0;i<n;i++)
	{
		// If the invSuff[i] == n-1 , this means that the i is at the last of the suffix array hence we will not have
		//any next suffix value to find lcp b/w i and i+1, i.e i+1 is not defined.
		//One thing to note that in suffixArray[i], i denotes the substring of the original string starting from 
		//index i and ending at n-1. While in SuffArray, SuffixArra[i] denotes the same.
		if(invSuff[i] == n-1)
			continue;
		//j contains index of the next substring to be considered to compare with the present substring, 
		//i.e., next string in suffix array.
		ll j = suffixArr[invSuff[i] + 1];

		//Now we have the indices i and j. Again remember that i means substring of original string starting at index
		//i and j means substring starting at j. Now, we will keep comparing the value of both substrings while
		//A. we found an unmatch
		//B. index i or j goes out of bound.
		while(i+k<n && j+k<n && s[i+k] == s[j+k])
			k++;

		// now at this point k denotes the longest common prefix of the invSuff[i] and invSuff[i]+1.
		lcp[invSuff[i]] = k;

		//this is the important step. k-- means we are deleting one character as we have already discussed that
		//if lcp(i,i+1) = k the lcp(j,j+1) = atleast k-1 where j is the indices after deleting 1 character from i.
		//generalising this
		//lcp(j,j+1) = atleast k-n where j is formed by deleting first n characters from i and k-n >0
		//here we have found lcp as k, now for the next lcp, we will say that it's value will be atleast k-1
		//and hence we will skip the first k comparision for the next lcp.
		if(k>0)
			k--;
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	
	string s;
	cin>>s;

	ll n = s.length();
	buildSuffixArray(s,n);

	loop(i,0,n-1)
		cout<<suffixArr[i]<<" ";
	cout<<endl;

	kasai(s,n);

	loop(i,0,n-1)
		cout<<lcp[i]<<" ";
	cout<<endl;


}