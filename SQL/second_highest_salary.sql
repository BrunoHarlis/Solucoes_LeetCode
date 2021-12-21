/*
# Fonte: https://leetcode.com/problems/second-highest-salary/
# Name: Bruno Harlis
# Data: 21/12/2021


Table: Employee

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id é a coluna da chave primária para esta tabela.
Cada linha desta tabela contém informações sobre o salário de um funcionário.

Escreva uma consulta SQL para relatar o segundo maior salário da Employeetabela. Se não houver o segundo maior salário, a consulta deve relatar null.

O formato do resultado da consulta está no exemplo a seguir.



Exemplo 1:

Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

Exemplo 2:

Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
*/


SELECT IFNULL(
(SELECT Employee.salary 
 FROM Employee 
 GROUP BY Employee.salary 
 ORDER BY Employee.salary desc 
 LIMIT 1, 1), null) AS SecondHighestSalary;