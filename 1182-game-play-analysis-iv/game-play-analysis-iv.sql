# Write your MySQL query statement below
with temp as (
    select player_id as id, min(event_date) as date
    from Activity 
    group by player_id
)

select round(count(a.player_id)/count(t.id), 2) as fraction
from temp t
left join Activity a
on t.id = a.player_id and DATEDIFF(a.event_date, t.date) = 1;