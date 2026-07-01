# Write your MySQL query statement below
select p.machine_id, ROUND(AVG(t.timestamp - p.timestamp),3) as processing_time
from Activity p
join Activity t
on p.machine_id = t.machine_id and p.process_id = t.process_id
where t.activity_type = 'end' and p.activity_type = 'start'
group by p.machine_id;