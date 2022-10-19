# Write your MySQL query statement below
select name as Employee
from Employee as E
where salary > (
select salary
 from Employee as M
 where M.id = E.managerId
)