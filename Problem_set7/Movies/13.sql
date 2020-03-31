SELECT DISTINCT name FROM people
WHERE id IN (
SELECT person_id
FROM stars WHERE stars.movie_id IN (
SELECT stars.movie_id
FROM stars JOIN people ON stars.person_id = people.id 
WHERE name = "Kevin Bacon" AND birth = 1958
)) 
AND id NOT IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958) 




