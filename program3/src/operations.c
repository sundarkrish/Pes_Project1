/**
 * 
 * @file operations.c
 * @brief Contains implementation for the operations.h header file
 * @author Sundar Krishnakumar
 * 
 */
#include <stdio.h>
#include <string.h>
#include <operations.h>

// Prints the 2 byte value in hexadecimal format
void print_hex(uint16_t * val)
{
    printf("Hexadecimal value:0x%x\n", *val);
}

// Left bit rotation for 16 bit binary
void rotate_bits_left(uint8_t n, uint16_t * val)
{
    uint8_t carry = 0;
    for (int i = 0; i < n; i++)
    {
        carry = (*val >> (MAX - 1)) & 1;
        *val = (*val << 1) | carry;

    }

}

// Right bit rotation for 16 bit binary
// Unsigned 16 bit integer type is used for storing the value.
// The incoming MSB is always zero on a right shift operation.
// So clearing the new MSB on right shift is not required here.
void rotate_bits_right(uint8_t n, uint16_t * val)
{
    uint8_t carry = 0;
    for (int i = 0; i < n; i++)
    {
        carry = *val & 1;
        *val = (*val >> 1) | (carry << (MAX - 1));

    }

}

// Does byte order reversal for 16 bit binary
void reverse_byte_order(uint16_t * val)
{
    uint16_t tmp = 65280; // Mask value 0xFF00
    tmp = (tmp & *val);
    tmp = tmp >> (MAX/2);
    *val = *val << (MAX/2);
    *val = *val | tmp;

}

// Decimal to binary conversion.
// Clear the previously stored binary values before next conversion.
void dec_2_bin(uint16_t * val, uint8_t * arr)
{
    
    int8_t index_limit = MAX - 1; 
    memset(arr, 0, sizeof(uint8_t) * MAX);
    for (int i = *val; (i > 0) && (index_limit >= 0); i = i/2,index_limit--)
    {
        
      arr[index_limit] = i % 2;
        
    } 
}

// Verify true/false whether 3 of the last 4 bits are ON(i.e. 1)
bool test(uint16_t * val)
{
    uint8_t tmp = *val & 15; // Mask value 0x000F

    // 7 -> 0111 , 11 -> 1011, 13 -> 1101, 14 -> 1110
    if ((tmp == 7) || (tmp == 11) || (tmp == 13) || (tmp == 14))
    {
        return 1;
    }
    else
    {
       return 0; 
    }    

}

// Display function for the 16 bit binary value.
void print_bin_val(uint8_t * arr)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d", arr[i]);
    }
}

