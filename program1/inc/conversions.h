/**
 * 
 * @file conversions.h
 * @brief Contains abstraction for data representation components
 * @author Sundar Krishnakumar
 * 
 */
#ifndef __CONVERSIONS_H__
#define __CONVERSIONS_H__
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char bool;

typedef struct 
{
    uint8_t uarr[16];
    uint8_t uarr_max[16];        
    uint8_t uarr_min[16];
    uint8_t arr_soc[16];
    uint8_t arr_stc[16];
    uint8_t arr_sm[16];
    uint8_t arr_max[16];        
    uint8_t arr_min_soc[16];
    uint8_t arr_min_stc[16];       
    uint8_t arr_min_sm[16];
    unsigned int uval;
    int val;
    uint8_t  radix;
    uint8_t opsize;

    // Upper and lower limits Limits
    uint16_t uval_max;
    uint8_t uval_min;

    uint16_t val_max_soc;
    int16_t val_min_soc;
    uint16_t val_max_stc;
    int16_t val_min_stc;
    uint16_t val_max_sm;
    int16_t val_min_sm;

}data_typedef;

void dec_2_bin(data_typedef *);
void signed_ones_comp(data_typedef * data);
void signed_twos_comp(data_typedef * data);
void signed_magnitude(data_typedef * data);
void display_binary(uint8_t *, uint8_t *);

#endif  /*__CONVERSIONS_H__*/