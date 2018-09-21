#include <bits/stdc++.h>


using namespace std;


int main()
{
	int piano[100001], N, Q, T1, T2, f[9], i_mf;
	vector<int> x;
	

	cin>>N>>Q;

	for ( int t = 0; t < N; t++ )
		piano[t] = 1;

	for ( int ac = 0; ac < Q; ac++ )
	{
		cin>>T1>>T2;
		
		i_mf = piano[T1];
		memset( f, 0, sizeof(f) );
		for ( int t = T1; t <= T2; t++ )
		{	
			f[ piano[t] ]++;
			if ( f[ piano[t] ] > f[ i_mf ] || (f[piano[t]] == f[i_mf] && piano[t] > i_mf ) ) 
					i_mf = piano[t];
		}
			
		for ( int t = T1; t <= T2; t++ )
			piano[t] = (piano[t] + i_mf)%9;

	}
		for ( int i = 0; i < N; i++ )
			cout<<piano[i]<<endl;

	return 0;
}