/**
 * @file two.c
 * @brief Application file for program two
 * @author Sundar Krishnakumar
 */
#include <stdio.h>
#include <asciiclassifier.h>

void display_result(uint8_t *);

int main(void)
{        
    // Place list of input here
    uint8_t arr[] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};
    uint8_t size = sizeof(arr)/sizeof(uint8_t);

     
    for (int i = 0; i < size; i++)
    {
        display_result((arr + i));
    }
    
    
    return 0;
}

// Display the result from 'classifier' function for every valid ascii characters.
// Unidentified valid ascii characters are displayed as 'Others'.
void display_result(uint8_t * code)
{

uint8_t result = 0;

    // Check for valid ascii here
    if (is_ascii(code))
    {

        result = classifier(code);
        switch (result)
        {
            case WHITESPACE:

                printf("Code:%2d%3sType:Whitespace%3sCharacter:%2c\n", *code, "", "", *code);
            break;

            case UPPER_CASE:

                printf("Code:%2d%3sType:Uppercase%3sCharacter:%2c\n", *code, "", "", *code);
            break;

            case LOWER_CASE:

                printf("Code:%2d%3sType:Lowercase%3sCharacter:%2c\n", *code, "", "", *code);
            break;

            case DIGIT:

                printf("Code:%2d%3sType:Digit%3sCharacter:%2c\n", *code, "", "", *code);
            break;

            case SPECIAL_CHARACTER:

                printf("Code:%2d%3sType:Specialcharacters%3sCharacter:%2c\n", *code, "", "", *code);
            break;

            default:
                printf("Code:%2d%3sType:Others%3sCharacter:%2c\n", *code, "", "", *code);
            break;

        }

    }
    else
    {
        printf("Enter a valid ASCII code\n");        

    }   
    

}
