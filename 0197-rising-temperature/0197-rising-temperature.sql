# Write your MySQL query statement below
select w.id from Weather w 
join Weather w2 on w.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY) 
where w.temperature > w2.temperature;