SELECT title,rating FROM movies,ratings  WHERE year = 2010 AND movies.id = ratings.movie_id ORDER BY rating desc , title asc;
