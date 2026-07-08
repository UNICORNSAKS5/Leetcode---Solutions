# Write your MySQL query statement below
SELECT 
e.name,
b.bonus
FROM Employee e
LEFT JOIN Bonus b 
ON e.empID = B.empId
WHERE b.bonus < 1000
OR b.bonus IS NULL;