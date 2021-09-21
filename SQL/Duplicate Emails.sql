/*
# Fonte: https://leetcode.com/problems/combine-two-tables/
# Name: Bruno Harlis
# Data: 20/09/2021


Escreva uma consulta SQL para localizar todos os e-mails duplicados em 
uma tabela chamada Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

Por exemplo, sua consulta deve retornar o seguinte para a tabela acima:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

*/

SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1