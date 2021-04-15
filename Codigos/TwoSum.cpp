//fonte: https://leetcode.com/problems/two-sum/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dado um array de n�meros inteiros e um alvo inteiro, retorne os �ndices dos dois
* n�meros de forma que eles se somam ao alvo.
* Voc� pode presumir que cada entrada teria exatamente uma solu��o e n�o pode usar o mesmo
* elemento duas vezes.
* Voc� pode retornar a resposta em qualquer ordem.
*
* Exemplo:
* Entrada: nums = [2,7,11,15], alvo = 9
* Sa�da: [0,1]
* Sa�da: porque nums[0] + nums[1] == 9, retornamos [0, 1].
*
* SOLU��O
* Na primeira solu��o, usei como par�metro de entrada um vector e um inteiro como refer�ncia
* para n�o fazer c�pias, tornando o programa mais eficiente e com menor consumo de mem�ria.
*
* Tamb�m eh prefer�vel o uso de pre-incremento do "int i" (++i) do loop for para melhor efici�ncia.
*
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 4 ms
* Mem�ria Usada: 10 MB
*****************************************************************************************/

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int& target)
    {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(target - nums[i]) == m.end())
            {
                m[nums[i]] = i;
            }
            else
            {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};


/*****************************************************************************************
* O problema tamb�m pode ser solucionado da forma abaixo, por�m eh menos eficiente.
* Mesmo que consuma menos mem�ria que a solu��o anterior, ele ainda eh 11 vezes mais lento.
*
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 44 ms
* Mem�ria Usada: 8.7 MB
*****************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        for (int i{ 0 }; i < nums.size(); ++i)
        {
            for (int j{ i + 1 }; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }

        }

        return result;
    }
};