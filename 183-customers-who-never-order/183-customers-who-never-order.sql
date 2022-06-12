# Write your MySQL query statement below
select Customers.name as 'Customers' from Customers
where Customers.id NOT IN 
(Select Orders.customerId from Orders);