# Write your MySQL query statement below

# select max(salary) as SecondHighestSalary from Employee where salary < (select max(salary) from employee);

select( 
    select distinct salary from employee order by salary desc limit 1,1 
)
as SecondHighestSalary;

# select IFNULL( (select disctinct salary from employee order by desc limit(1,1)),NULL)
# as SecondHighestSalary

# select IFNULL(distinct salary as SecondHighestSalary from employee e1 where 1  = 
# (
#     select count(distinct e2.salary) from employee e2 where e2.salary > e1.salary
# ),NULL)
# as SecondHighestSalry
