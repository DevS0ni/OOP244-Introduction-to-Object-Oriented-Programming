#define SDDS_FILE_H // Compilation Safe Guards for the header files.
#ifndef SDDS_FILE_H // refer to a technique to guard against multiple inclusion of header files.

namespace sdds{
    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
}

#endif