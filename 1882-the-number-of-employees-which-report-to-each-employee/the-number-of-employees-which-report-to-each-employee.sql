# Write your MySQL query statement below
select t.employee_id, t.name, count(m.employee_id) as reports_count, round(sum(m.age)/count(m.employee_id)) as average_age
from Employees m
join Employees t
on m.reports_to = t.employee_id 
group by (t.employee_id)
order by t.employee_id;
