#include <bits/stdc++.h>

using namespace std;

int main()
{
	string crib, palavra;
	int qtd_pos = 0, tam_crib, tam_pal, i,j ;

	cin>>palavra>>crib;

	tam_crib = crib.size();
	tam_pal = palavra.size();

	for ( i = 0; i <= tam_pal - tam_crib; i++ )
	{
		for ( j = 0; j < tam_crib; j++ )
			if ( palavra[i+j] == crib[j] ) break;

		if ( j == tam_crib ) qtd_pos++;

	}

	cout<<qtd_pos<<endl;
	return 0;	
}
