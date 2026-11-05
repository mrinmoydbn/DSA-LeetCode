select max(num) as num
from(
    select max(num) as num
    from MyNumbers
    group by num
    having count(num) = 1
) as t;
