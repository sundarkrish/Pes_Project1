/**
 * @file asciiclassifier.c
 * @brief Contains implementation for the header asciiclassifier.h
 * @author Sundar Krishnakumar
 */
#include <stdio.h>
#include <asciiclassifier.h>

// Check if valid ascii equivalent decimal : 0 -> 127
uint8_t is_ascii(const uint8_t * val)
{
    if ( (*val >= 0) && (*val <= 127) )
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// Classify ascii based oon decimal equivalent and return its type
// Classifications : Whitespace,Upper Case,Lower Case,Digit,Special character
// Not fully implemented.Application must handle other characters.
uint8_t classifier(const uint8_t * val)
{

    if ( ((*val >= 8) && (*val <= 13)) || (*val == 0) || (*val == 32))
    {
        return WHITESPACE;
        
    }
    else if ( (*val >= 65) && (*val <= 90) )
    {
        return UPPER_CASE;
        
    }
    else if ( (*val >= 97) && (*val <= 122) )
    {
        return LOWER_CASE;
        
    }
    else if ( (*val >= 48) && (*val <= 57) )
    {
        return DIGIT;
        
    }
    else if ( ((*val >= 33) && (*val <= 47)) || ((*val >= 58) && (*val <= 64)) 
                || ((*val >= 91) && (*val <= 96)) || ((*val >= 123) && (*val <= 126)))
    {
        return SPECIAL_CHARACTER;
        

    }        

    return 0;

}
