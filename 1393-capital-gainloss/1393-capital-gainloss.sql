# Write your MySQL query statement below
select b.stock_name, s.gained - b.spent  as  capital_gain_loss
from (select stock_name, sum(price) as spent from stocks where operation = "buy" group by stock_name) b join (select stock_name, sum(price) as gained from stocks where operation = "sell" group by stock_name) s
on b.stock_name = s.stock_name
group by stock_name; 