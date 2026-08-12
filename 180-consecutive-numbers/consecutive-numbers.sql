# Write your MySQL query statement below
with temp as (
    select id, num,
    lead(num, 1) over(order by id) as n1,
    lead(num, 2) over(order by id) as n2
 from Logs )

select distinct num as ConsecutiveNums from
temp where
num = n1 and num = n2;