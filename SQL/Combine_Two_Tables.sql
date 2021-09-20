/*
# Fonte: https://leetcode.com/problems/combine-two-tables/
# Name: Bruno Harlis
# Data: 20/09/2021

Tabela: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId é a coluna de chave primária desta tabela.

Tabela: Address
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId é a coluna de chave primária desta tabela.
 

Escreva uma consulta SQL para um relatório que forneça as seguintes informações
para cada pessoa na tabela Person, independentemente de haver um endereço para 
cada uma dessas pessoas:

FirstName, LastName, City, State
*/

SELECT P.FirstName, P.LastName, S.City, S.State
FROM Person P
LEFT JOIN Address S ON P.PersonId = S.PersonId