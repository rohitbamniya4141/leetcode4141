# Write your MySQL query statement below
with temp as(
    select p.product_id, p.price, u.units
    from Prices p
    left join UnitsSold u
    on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date
)

select product_id, round(coalesce((sum(units*price)/sum(units)),0),2) as average_price
from temp
group by product_id;