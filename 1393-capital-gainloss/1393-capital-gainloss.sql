# Write your MySQL query statement below
with buy as (
    select stock_name , sum(price) as spent
    from stocks
    where operation = "buy"
    group by stock_name
),

sell as (
    select stock_name , sum(price) as gained
    from stocks
    where operation = "sell"
    group by stock_name
)

select s.stock_name , s.gained - b.spent as capital_gain_loss
from buy b join sell s
on b.stock_name = s.stock_name
group by s.stock_name