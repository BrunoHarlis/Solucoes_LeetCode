//fonte: https://leetcode.com/problems/two-sum/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dado um array de números inteiros e um alvo inteiro, retorne os índices dos dois
* números de forma que eles se somam ao alvo.
* Você pode presumir que cada entrada teria exatamente uma solução e não pode usar o mesmo
* elemento duas vezes.
* Você pode retornar a resposta em qualquer ordem.
*
* Exemplo:
* Entrada: nums = [2,7,11,15], alvo = 9
* Saída: [0,1]
* Saída: porque nums[0] + nums[1] == 9, retornamos [0, 1].
*
* SOLUÇÃO
* Na primeira solução, usei como parâmetro de entrada um vector e um inteiro como referência
* para não fazer cópias, tornando o programa mais eficiente e com menor consumo de memória.
*
* Também eh preferível o uso de pre-incremento do "int i" (++i) do loop for para melhor eficiência.
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 4 ms
* Memória Usada: 10 MB
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
* O problema também pode ser solucionado da forma abaixo, porém eh menos eficiente.
* Mesmo que consuma menos memória que a solução anterior, ele ainda eh 11 vezes mais lento.
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 44 ms
* Memória Usada: 8.7 MB
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