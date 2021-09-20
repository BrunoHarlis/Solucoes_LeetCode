/*
# Fonte: https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Name: Bruno Harlis
# Data: 20/09/2021


A tabela Employee contém todos os funcionários, incluindo seus gerentes.
Cada funcionário possui um Id, e também há uma coluna para o Id do gerente.

+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+

Dada a tabela Employee, escreva uma consulta SQL que descubra os funcionários
que ganham mais do que seus gerentes. Para a tabela acima, Joe é o único 
funcionário que ganha mais do que seu gerente.

+----------+
| Employee |
+----------+
| Joe      |
+----------+
*/

SELECT e.Name AS Employee
FROM Employee e
JOIN Employee m ON e.ManagerId = m.Id
WHERE m.Salary < e.Salary