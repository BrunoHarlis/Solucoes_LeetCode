//Fonte: https://leetcode.com/problems/search-in-rotated-sorted-array/
//Autor: Bruno Harlis
//Data: 12/07/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* H� uma matriz de inteiros nums classificada em ordem crescente (com valores distintos ).
* Antes de ser passado para sua fun��o, nums � girado em um �ndice din�mico desconhecido 
* k( 0 <= k < nums.length) de forma que a matriz resultante seja [nums[k], nums[k+1], ...,
* nums[n-1], nums[0], nums[1], ..., nums[k-1]]( indexada em 0 ). Por exemplo, [0,1,2,4,5,6,7]
* pode ser girado no �ndice piv� 3 e se tornar [4,5,6,7,0,1,2].
* 
* Dado o array nums ap�s a rota��o e um inteiro target, retorna o �ndice de targetse ele est� 
* em nums, ou -1 se n�o est� em nums .
* Voc� deve escrever um algoritmo com  O(log n)complexidade de tempo de execu��o.
*
* Exemplo:
* Entrada: nums = [4,5,6,7,0,1,2], alvo = 0
* Sa�da: 4
*
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 4 ms
* Mem�ria Usada: 11.2 MB
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