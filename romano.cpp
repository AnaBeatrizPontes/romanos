// Copyright [2021] <Ana Beatriz>

#include "../include/romano.hpp"
#define NUM_MAX 3000;

int convert_number(std::string STRING_ROMANA_) {
    int ARABIC_NUMBER_[8] = { 0, 1, 5, 10, 50, 100, 500, 1000 };
    char ROMAN_STRING_[8] = { '0', 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

    int CONT = 0;
    int AUX = 0;
    int PREV = 0;
    int SUM = 0;
    int NUM = 0;
    char LETTER = ' ';
    int VAL = 0;    

    for (AUX = 0; AUX <= STRING_ROMANA_.length(); AUX++) {
        if (islower(STRING_ROMANA_[AUX]))
        {
            return -1;
        }
        else if ( STRING_ROMANA_.length() < 2 ) {
            for (VAL = 0; VAL <= 7; VAL++)
            {
                if ( STRING_ROMANA_.at(AUX) == ROMAN_STRING_[VAL] )
                {
                    return ARABIC_NUMBER_[VAL];
                }
                else {
                    AUX++;
                }
            }
        }
        else {
            LETTER = STRING_ROMANA_[AUX];
            for ( CONT = 0; CONT <= 7; CONT++ ) {
                if ( LETTER == ROMAN_STRING_[CONT] ) {
                    SUM = SUM + ARABIC_NUMBER_[CONT];
                    if ( PREV < (ARABIC_NUMBER_[CONT]) ) {
                        SUM = SUM - PREV * 2;
                        PREV = ARABIC_NUMBER_[CONT];
                    }
                }
            }
        }
    }
    return SUM;
}
