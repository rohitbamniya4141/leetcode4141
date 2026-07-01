# Write your MySQL query statement below
select p.name
from Employee p
join Employee t
on p.id = t.managerId
group by p.name, p.id
having count(*)>4;
