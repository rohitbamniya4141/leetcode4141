# Write your MySQL query statement below
select m.name as Employee
from Employee m
join Employee t
on m.managerId = t.id
where m.salary > t.salary;