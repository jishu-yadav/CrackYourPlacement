# Write your MySQL query statement below
# select t1.id from Weather t1 join weather t2 on (t1.id = t2.id+1) where t1.temperature >t2.temperature

# select a.id from Weather a
# where a.temperature > (select b.temperature from weather b where b.recorddate = a.recorddate-1)

SELECT
    weather.id as 'ID'
FROM
    weather
        JOIN
    weather w on DATEDIFF(weather.recordDate, w.recordDate) = 1
        AND weather.Temperature > w.Temperature
;