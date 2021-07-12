//Fonte: https://leetcode.com/problems/search-in-rotated-sorted-array/
//Autor: Bruno Harlis
//Data: 12/07/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Há uma matriz de inteiros nums classificada em ordem crescente (com valores distintos ).
* Antes de ser passado para sua função, nums é girado em um índice dinâmico desconhecido 
* k( 0 <= k < nums.length) de forma que a matriz resultante seja [nums[k], nums[k+1], ...,
* nums[n-1], nums[0], nums[1], ..., nums[k-1]]( indexada em 0 ). Por exemplo, [0,1,2,4,5,6,7]
* pode ser girado no índice pivô 3 e se tornar [4,5,6,7,0,1,2].
* 
* Dado o array nums após a rotação e um inteiro target, retorna o índice de targetse ele está 
* em nums, ou -1 se não está em nums .
* Você deve escrever um algoritmo com  O(log n)complexidade de tempo de execução.
*
* Exemplo:
* Entrada: nums = [4,5,6,7,0,1,2], alvo = 0
* Saída: 4
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 4 ms
* Memória Usada: 11.2 MB
* *****************************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	unsigned long l{ nums.size() - 1 };
	if (nums[l] == target) return l;

	bool odd = (nums.size() % 2) ? true : false;

	for (unsigned long f{ 0 }; f < l; ++f)
	{
		if (nums[f] == target) return f;
		if (nums[l] == target) return l;
		else
			--l;
	}

	if (odd)
		if (nums[l] == target) return l;

	return -1;
}

int main()
{
	vector<int> nums{ 4,5,6,7,0,1,2 };
	int target{ 5 };

	cout << search(nums, target) << endl;

	return 0;
}