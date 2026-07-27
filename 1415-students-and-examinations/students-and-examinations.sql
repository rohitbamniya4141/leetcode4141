# Write your MySQL query statement below
select t.student_id, t.student_name, sub.subject_name, count(e.subject_name) as attended_exams
from Students t
cross join Subjects sub
left join Examinations e
on t.student_id = e.student_id and sub.subject_name = e.subject_name
group by t.student_id, sub.subject_name
order by t.student_id, sub.subject_name;
