# Write your MySQL query statement below
with temp as(
    select product_id, max(change_date) as final_date
    from Products 
    where change_date <= '2019-08-16'
    group by product_id
)

select p.product_id, coalesce(pr.new_price, 10) as price
from(
    select distinct product_id 
    from Products
) p
left join temp t
on p.product_id = t.product_id
left join Products pr
on pr.product_id = t.product_id and pr.change_date = t.final_date;


