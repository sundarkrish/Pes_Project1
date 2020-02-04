/**
 * 
 * @file three.c
 * @brief Application file for program three
 * @author Sundar Krishnakumar
 * 
 */
#include <stdio.h>
#include <operations.h>

void display_result(uint16_t *, uint8_t *);

int main(void)
{
    // Decimal value of 0xFACE
    uint16_t val = 64206;
    uint8_t arr[16] ={0};

    // Operation 1
    display_result(&val, arr);

    // Operation 2
    reverse_byte_order(&val);
    display_result(&val, arr);

    // Operation 3
    rotate_bits_left(6, &val);
    display_result(&val, arr);

    // Operation 4
    rotate_bits_right(4, &val);
    display_result(&val, arr);

    return 0;

}

// Displays the combined result
// This function also performs the test by calling the 'test' function.
void display_result(uint16_t * val, uint8_t *arr)
{

    print_hex(val);
    dec_2_bin(val, arr);
    printf("Binary value:");
    print_bin_val(arr);
    printf("\t");
    printf("Test:%s", (test(val) ? "True" : "False"));
    printf("\n");

}