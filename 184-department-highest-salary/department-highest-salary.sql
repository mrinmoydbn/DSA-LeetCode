# Write your MySQL query statement below
select department, employee, salary
from (
    select d.name as Department, e.name as Employee, e.salary as Salary,
    max(e.salary) over (partition by e.departmentId) as max_salary
    from Employee e
    join Department d
        on e.departmentId = d.id
) t
where salary = max_salary;