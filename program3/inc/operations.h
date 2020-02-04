/**
 * 
 * @file operations.h
 * @brief Contains function prototypes for specific tasks on 16bit integer value.
 * 
 * The abstractions in this header file can be used to do tasks like
 * byte order reversal, rotating bits, 
 * displaying the value in hexadecimal and binary formats.
 * The test function verifies whether 3 of the last 4 bits in the 16 bit binary are ON.
 * 
 * @author Sundar Krishnakumar
 * 
 */
#ifndef __OPERATIONS__H_
#define __OPERATIONS__H_

#define MAX 16

typedef short int16_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef uint8_t bool;

void print_hex(uint16_t *);
void reverse_byte_order(uint16_t *);
void rotate_bits_left(uint8_t, uint16_t *);
void rotate_bits_right(uint8_t, uint16_t *);
void dec_2_bin(uint16_t *, uint8_t * );
void print_bin_val(uint8_t *);
bool test(uint16_t * );

#endif /*__OPERATIONS__H_*/