# Write your MySQL query statement below
select m.name #Because we need to find manager names
from Employee e
join Employee m
    on e.managerId = m.id #Employees have manager so e.managerId
group by m.name, m.id
having count(*) >= 5; 