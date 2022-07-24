#include <bits/stdc++.h>
using namespace std;
void perm(string a, int l, int r)
{
	if (l == r)
		cout<<a<<endl;
	else
	{
		for (int i = l; i <= r; i++)
		{
		    swap(a[l], a[i]);
			perm(a, l+1, r);
            swap(a[l], a[i]);
		}
	}
}
int main()
{
	string s = "ABC";
	int n = s.size();
	perm(s, 0, n-1);
	return 0;
}
