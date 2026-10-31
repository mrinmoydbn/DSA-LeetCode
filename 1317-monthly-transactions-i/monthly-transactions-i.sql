select date_format(trans_date , '%Y-%m') as month, 
# %y → Two-digit year (e.g. 18-12)
#%Y → Four-digit year (e.g. 2018-12)
    country,
    count(*) as trans_count,
    count(
        case when state = 'approved' then 1 end
        ) as approved_count,
    sum(amount) as trans_total_amount,
    sum(
        case when state = 'approved' then amount else 0 end
    ) as approved_total_amount 
from Transactions 
group by month, country;