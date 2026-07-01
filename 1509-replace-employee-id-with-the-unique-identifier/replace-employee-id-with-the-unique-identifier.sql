# Write your MySQL query statement below
select t.unique_id, p.name
from Employees p
left join EmployeeUNI t
on t.id = p.id;