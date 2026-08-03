# Write your MySQL query statement below
with temp as(
    select e.id, e.name, e.salary, e.departmentId, d.name as deptname
    from Employee e
    join Department d
    on e.departmentId = d.id
)

select deptname as Department, name as Employee, salary as Salary from (
    select *, dense_rank() over (partition by deptname order by salary desc) as rnp from temp
) as mt
where rnp < 4;
