#include <bits/stdc++.h>

using namespace std;

#define TAM 1001

bool tudo_apagado( bool v[], int N )
{
	for ( int k = 1; k <=N; k++ )
		if ( v[k] == true ) return false;
	return true;
}

void inicializar_painel( int painel[TAM][TAM], bool lampada[], bool est_inicial[] )
{
	for ( int x = 0; x < TAM; x++ )
	{
		est_inicial[x] = lampada[x] = false;
		for ( int j = 0; j < TAM; j++ )
			painel[x][j] = 0;
	}
}

bool vetores_iguais( bool x[], bool y[], int M )
{
	for( int h = 1; h <= M; h++)
		if ( x[h] != y[h] ) return false;
	return true;
}

int main()
{
	int painel[TAM][TAM], M, N, qtd_lamp, id_lamp, qtd_acesas, cont = 0;
	bool sucesso = false, lampada[TAM], est_inicial[TAM];

	inicializar_painel( painel, lampada, est_inicial );

	cin>>N>>M>>qtd_acesas;
	// Inicializa as lâmpadas acesas
	for ( int i = 0; i < qtd_acesas; i++ )
	{
		cin>>id_lamp;
		est_inicial[id_lamp] = lampada[id_lamp] = true;
	}

	// Realiza conexão interruptor - lâmpada
	for ( int k = 1; k <= N; k++ )
	{
		cin>>qtd_lamp;
		for ( int j = 1; j <= qtd_lamp; j++ )
		{
			cin>> id_lamp;
			painel[k][id_lamp] = 1;
		}
	}

	// Realiza sequência teste
	do
	{
		for ( int id_int = 1; id_int <= N; id_int++ )
		{
			for ( id_lamp = 1; id_lamp <= M; id_lamp++ )
			{
				if ( painel[id_int][id_lamp] )
					lampada[id_lamp] = !lampada[id_lamp];
			}

			cont++;
			
			if ( tudo_apagado( lampada, M ) ) 
			{	
				sucesso = true;
				break;
			}
		}

	} while ( !vetores_iguais( lampada, est_inicial, M) && !sucesso );

	if ( !sucesso ) cont = -1;

	cout<<cont<<endl;

	return 0;
}