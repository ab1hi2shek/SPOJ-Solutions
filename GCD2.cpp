#include <iostream>
using namespace std;
 
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--)
	{
		int a;
		string b;

		cin>>a>>b;

		if(a==0)
		{
			cout<<b<<endl;
			continue;
		}

		int temp = 0, i= 0;
		while(i<b.length())
		{
			temp = temp*10 + (b[i] - '0');
			temp = temp%a;
			i++;
		}
		cout<<gcd(a,temp)<<endl;
	}

}