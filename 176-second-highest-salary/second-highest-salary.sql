# Write your MySQL query statement below
with m_sal as(
    select max(salary) as m_salary from Employee
)

select max(salary) as SecondHighestSalary from Employee
where salary < (select m_salary from m_sal);