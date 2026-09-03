# Write your MySQL query statement below
with categories as(
    select 'Low Salary' as category
    union all
    select 'Average Salary'
    union all
    select 'High Salary'
),
temp as(
    select account_id, case
                            when income < 20000 then 'Low Salary'
                            when income > 50000 then 'High Salary'
                            else 'Average Salary'
                        end as category
    from Accounts
)



select c.category, count(t.account_id) as accounts_count
from categories c
left join temp t
on c.category = t.category
group by category;

