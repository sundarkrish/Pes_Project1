/**
 * 
 * @file conversions.c
 * @brief Implementation file for conversions.h
 * @author Sundar Krishnakumar
 * 
 */
#include <stdio.h>
#include <conversions.h>

// Does Decimal to Binary conversion
void dec_2_bin(data_typedef * data)
{

    unsigned int i = 0;    
    int8_t index_limit = data->opsize - 1;
    
    for (i = data->uval; (i > 0) && (index_limit >= 0); i = i/2,index_limit--)
    {
        
      data->uarr[index_limit] = i % 2;
        
    }   

}

// Creates the  signed one's complement component
void signed_ones_comp(data_typedef * data)
{
    
    unsigned int i = 0;    
    int8_t index_limit = data->opsize - 1;    

    // Signed one's complement for the given value
    // Check whether the given value is +ve or -ve here
    // Negative zeros and positive zeros are equal
    if ( data->val < 0 )
    {
        for (i = 0; i <= index_limit; i++)
        {
            data->arr_soc[i] = ! (data->uarr[i]);
        
        }

    }
    else if ( data->val >= 0)
    {
        for (i = 0; i <= index_limit; i++)
        {
            data->arr_soc[i] = data->uarr[i];
        
        }

    }  

    index_limit = data->opsize - 1;

    // Signed one's complement for max value
    for (i = data->val_max_soc; (i > 0) && (index_limit >= 0); i = i/2,index_limit--)
    {
      
      data->arr_max[index_limit] = i % 2;
        
    }  

    index_limit = data->opsize - 1;

    // Signed one's complement for min value
    for (i = 0; i <= index_limit; i++)
    {
        data->arr_min_soc[i] = ! (data->arr_max[i]);
        
    }    

}

/* Creates the signed two's complement component 
 * Check whether the given value is +ve or -ve here
 * Negative zeros and positive zeros are equal
 * Signed two's complement = Signed ones's complement for maximum value.
 * So not calculated here
 */
void signed_twos_comp(data_typedef * data)
{
    int8_t i = 0;
    uint8_t carry = 1;    
    int8_t index_limit = data->opsize - 1;

    if ( data->val < 0 )
    {
        /* Signed Two's complement for given value */
        for(i = index_limit; i >= 0; i--)
        {
            if(data->arr_soc[i] == 1 && carry == 1)
            {
                data->arr_stc[i] = 0;
            }
            else if(data->arr_soc[i] == 0 && carry == 1)
            {
                data->arr_stc[i] = 1;
                carry = 0;
            }
            else
            {
                data->arr_stc[i] = data->arr_soc[i];
            }
        }
        


    }
    else if ( data->val >= 0)
    {

        for (i = 0; i <= index_limit; i++)
        {
            data->arr_stc[i] = data->uarr[i];
        
        }  

    }

    carry = 1;

    /* Signed Two's complement for min value */
    for (i = 0; i <= index_limit; i++)
    {
        data->arr_min_stc[i] = data->arr_min_soc[i];
    
    } 
    
}

/* Creates the signed magnitude component
 * Signed magnitude = Signed ones's complement for maximum value.
 * Signed magnitude = 'All ones' for minimum value
 * Not calculated here
 */
void signed_magnitude(data_typedef * data)
{
    unsigned int i = 0;    
    int8_t index_limit = data->opsize - 1;
    

    for (i = data->uval; (i > 0) && (index_limit >= 0); i = i/2,index_limit--)
    {
        
      data->arr_sm[index_limit] = i % 2;
        
    }  

    if (data -> val < 0)
        data->arr_sm[0] = 1;
    
}

// Displays the binary value 
void display_binary(uint8_t * opsize, uint8_t * arr)
{
    for (int i = 0; i < *opsize; i++)
    {
        printf("%d", arr[i]);
    }

}

