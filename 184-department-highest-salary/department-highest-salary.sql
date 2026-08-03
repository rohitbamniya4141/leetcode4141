# Write your MySQL query statement below
With max_sal as(
    select e.departmentId, d.name as deptname, max(e.salary) as ms
    from Employee e
    join Department d
    on e.departmentId = d.id
    group by d.name
)

select m.deptname as Department, e.name as Employee, e.salary as Salary
from Employee e
join max_sal m
on e.departmentId = m.departmentId
where e.salary = m.ms;
