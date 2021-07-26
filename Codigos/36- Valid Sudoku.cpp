//Fonte: https://leetcode.com/problems/valid-sudoku/
//Autor: Bruno Harlis
//Data: 26/07/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Determine se uma placa de Sudoku 9 x 9 � v�lida. Apenas as c�lulas preenchidas precisam ser 
* validadas de  acordo com as seguintes regras :
* 
* Cada linha deve conter os d�gitos  1-9 sem repeti��o.
* Cada coluna deve conter os d�gitos  1-9 sem repeti��o.
* Cada uma das nove subcaixas 3 x 3 da grade deve conter os d�gitos 1-9 sem repeti��o.
* 
* Observa��o:
* Um tabuleiro de Sudoku (parcialmente preenchido) pode ser v�lido, mas n�o � necessariamente solucion�vel.
* Apenas as c�lulas preenchidas precisam ser validadas de acordo com as regras mencionadas.
* 
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 16 ms
* Mem�ria Usada: 20.6 MB
* *****************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
	vector<vector<char>> bloco{ {},{},{},{},{},{},{},{},{} };

	for (int i{ 0 }; i < 9; ++i)
	{
		vector<int> nLinhas(58);
		vector<int> nColunas(58);

		for (int j{ 0 }; j < 9; ++j)
		{
			// Ver se repete numero nas colunas
			if (board[j][i] >= 48 && board[j][i] <= 58)
			{
				nColunas[board[j][i]]++;
				if (nColunas[board[j][i]] > 1) return false;
			}

			// Ver se repete algum numero em alguma linha
			if (board[i][j] >= 48 && board[i][j] <= 58)
			{
				nLinhas[board[i][j]]++;
				if (nLinhas[board[i][j]] > 1) return false;

				// Ver se repete no bloco
				int idx = (i / 3) * 3 + j / 3;
				auto encontrado{ find(bloco[idx].begin(), bloco[idx].end(), board[i][j]) };

				if (encontrado == bloco[idx].end())
					bloco[idx].push_back(board[i][j]);
				else
					return false;
			}
		}
	}

	return true;
}

int main()
{
	vector <vector<char>> board
	{ { '5','3','9','.','7','.','.','.','.'}
	, { '6','.','.','1','9','5','.','.','.'}
	, { '.','.','8','.','.','.','.','6','.'}
	, { '8','.','.','.','6','.','.','.','3'}
	, { '4','.','.','8','.','3','.','.','1'}
	, { '7','.','.','.','2','.','.','.','6'}
	, { '.','6','.','.','.','.','2','8','.' }
	, { '.','.','.','4','1','9','.','.','5' }
	, { '.','.','.','.','8','.','.','7','9' } };

	if (isValidSudoku(board))
		cout << "VALIDO";
	else
		cout << "INVALIDO";
}