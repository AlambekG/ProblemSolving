select p.lastName, p.firstname , a.city,a.state
from person p left join address a on p.personId = a.personId