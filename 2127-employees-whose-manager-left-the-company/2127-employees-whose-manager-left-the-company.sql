# Write your MySQL query statement below
-- select employee_id from Employees 
-- where salary < 30000 and manager_id is not null 
-- and manager_id not in (select distinct employee_id from Employee) 
-- order by employee_id;

# Write your MySQL query statement below
SELECT employee_id FROM Employees
WHERE salary < 30000 AND manager_id IS NOT NULL 
    AND manager_id NOT IN (SELECT employee_id FROM Employees) 
ORDER BY employee_id;