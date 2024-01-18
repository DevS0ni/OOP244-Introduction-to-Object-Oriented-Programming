#define SDDS_MOVIE_H // Compilation Safe Guards for the header files.
#ifndef SDDS_MOVIE_H // refer to a technique to guard against multiple inclusion of header files.
#include "File.h"
namespace sdds{
struct Movie {
   char m_title[128];
   int m_year;
   char m_rating[6];
   int m_duration;
   char m_genres[10][11];
   float m_consumerRating;
};

    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);
}

#endif