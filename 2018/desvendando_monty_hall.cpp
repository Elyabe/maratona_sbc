#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, x, qtd_win;

	cin>>N;
	qtd_win = N;
	for ( int i = 0; i < N; i++ )	
	{	
		cin>>x;
		if ( x == 1 ) qtd_win--;
	}
	cout<<qtd_win<<endl;
	return 0;

}
