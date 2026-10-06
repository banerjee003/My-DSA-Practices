/* Write your T-SQL query statement below */
select
customer_id from
(select
customer_id,
count(distinct product_key) c
from Customer
group by customer_id
having count(distinct product_key) = (select
    count(product_key)
    from Product)
)t2
