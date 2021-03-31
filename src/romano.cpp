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
    char ANT_1 = ' ';
    char ANT_2 = ' ';

    for (AUX = 0; AUX < STRING_ROMANA_.length(); AUX++) {
        if ( islower(STRING_ROMANA_[AUX]) ) {
            return -1;
        } else if ( isdigit(STRING_ROMANA_[AUX]) ) {
            return -1;
        } else if ( STRING_ROMANA_.length() > 30 ) {
            return -1;
        } else if ( STRING_ROMANA_.length() < 2 ) {
            for (VAL = 0; VAL <= 7; VAL++) {
                if ( STRING_ROMANA_[AUX] == ROMAN_STRING_[VAL] ) {
                    return ARABIC_NUMBER_[VAL];
                }
            }
        } else {
            LETTER = STRING_ROMANA_[AUX];
            for ( CONT = 0; CONT <= 7; CONT++ ) {
                if ( LETTER == ROMAN_STRING_[CONT] ) {
                    if ( CONT >= 1 && STRING_ROMANA_.length() >= 2 )
                    {
                        if ( ((STRING_ROMANA_[AUX - 1] == STRING_ROMANA_[AUX + 1]) && (STRING_ROMANA_[AUX] != STRING_ROMANA_[AUX - 1] && STRING_ROMANA_[AUX] != STRING_ROMANA_[AUX + 1])) )
                        {
                                return -1;
                        } 
                    }
                    else if (CONT >= 2)
                    {
                        switch (LETTER) {
                            case 'V':
                                if ( (STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I') )
                                {
                                    return -1;
                                }
                                break;
                            case 'X':
                                if ( (STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I' || 'V') )
                                {
                                    return -1;
                                }
                                break;
                            case 'L':
                                if ((STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I' || 'V' || 'X'))
                                {
                                    return -1;
                                }
                                break;
                            case 'C':
                                if ((STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I' || 'V' || 'X' || 'L'))
                                {
                                    return -1;
                                }
                                break;
                            case 'D':
                                if ((STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I' || 'V' || 'X' || 'L' || 'C'))
                                {
                                    return -1;
                                }
                                break;
                            case 'M':
                                if ((STRING_ROMANA_[CONT - 1] && STRING_ROMANA_[CONT - 2]) == ('I' || 'V' || 'X' || 'L' || 'C' || 'D'))
                                {
                                    return -1;
                                }
                                break;
                            default:
                                break;
                            }   
                    }
                    SUM = SUM + ARABIC_NUMBER_[CONT];
                    if ( PREV < (ARABIC_NUMBER_[CONT]) ) {
                        SUM = SUM - PREV * 2;
                        PREV = ARABIC_NUMBER_[CONT];
                    }
                }
            }
        }
    }
    if (SUM > 3000) {
        return -1;
    } else {
        return SUM;
    }
}
