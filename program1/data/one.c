/**
 * 
 * @file one.c
 * @brief Application file for program one
 * @author Sundar Krishnakumar
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conversions.h>
  
void start(data_typedef *);
void max_min_init(data_typedef *);
void display_4(data_typedef *);
void display_8(data_typedef *);
void display_16(data_typedef *);
void display_b(int *, uint8_t *, uint8_t *);
bool isRadix(uint8_t *);
bool isOpsize(uint8_t *);

int main(void)
{     
    // give list of inputs here
    int inp[][3] = {{-7, 10, 4}, {-7, 9, 4}, {-7, 10, 5}, {-10, 10, 4}, 
                      {236, 10, 8}, {0354, 8, 8}, {0xEB, 16, 8}, {-125, 10, 8}, 
                       {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16}};
    
    // Computing size of input array
    uint8_t size = sizeof(inp)/(sizeof(int) * 3);
    printf("No. of inputs:%d\n", size);
    data_typedef data;


    for (int i = 0; i < size; i++)
    {
        data.val = inp[i][0];
        data.uval = abs(data.val);
        data.radix = inp[i][1];
        data.opsize = inp[i][2];
        // Check for valid radix 
        if (isRadix(&(data.radix)) && isOpsize(&(data.opsize)))
        {
            start(&data);
        }
        else
        {
            printf("\n");
            display_b(&(data.val), &(data.radix), &(data.opsize));
            printf("Allowed radix options: 8,10,16\n");
            printf("Allowed operand sizes: 4,8,16\n\n");
        }        
        
    }

    return 0;
}

// Displays the value,radix and operand size.
// Value is formatted to given radix.
void display_b(int * val, uint8_t * radix, uint8_t * opsize)
{

    if (*radix == 8)
    {
        printf("\nValue:0%o%2sRadix:%d%2sOperand Size:%d\n", *val, "", *radix, "", *opsize);
    }
    else if (*radix == 10)
    {
        printf("\nValue:%d%2sRadix:%d%2sOperand Size:%d\n", *val, "", *radix, "", *opsize);
    }
    else if (*radix == 16)
    {
        printf("\nValue:0x%x%2sRadix:%d%2sOperand Size:%d\n", *val, "", *radix, "", *opsize);
    }
    else
    {
        printf("\nValue:%s%2sRadix:%d%2sOperand Size:%d\n", "-", "", *radix, "", *opsize);
    }
    
}

// Checks whether radix is allowed or not
// Invalid radix returns a 0 while valid ones return 1
bool isRadix(uint8_t * radix){
    
    if ((*radix == 8) || (*radix == 10)
         || (*radix == 16))
    {
        
        return 1;
    }
    else
    {
        return 0;
    }
    
}

// Checks whether opsize is valid
// Invalid opsize returns a 0 while valid ones return 1
bool isOpsize(uint8_t * opsize){
    
    if ((*opsize == 4) || (*opsize == 8)
         || (*opsize == 16))
    {
        
        return 1;
    }
    else
    {
        return 0;
    }
    
}

// Populates the maximum and minimum variables
void max_min_init(data_typedef * data)
{

    /* un-signed maxmimum & minimum value for given operand size  */
    data->uval_max = pow(2, data->opsize) - 1;
    data->uval_min = 0;

    /* signed maxmimum & minimum value for given operand size  */
    data->val_max_soc = (pow(2, data->opsize) / 2) - 1;
    data->val_min_soc = -((pow(2, data->opsize) / 2) - 1);
    data->val_max_stc = (pow(2, data->opsize) / 2) - 1;
    data->val_min_stc = -(pow(2, data->opsize) / 2) ;
    data->val_max_sm = (pow(2, data->opsize) / 2) - 1;
    data->val_min_sm = -((pow(2, data->opsize) / 2) - 1);

}

// Start the conversion process
// Calls display function
void start(data_typedef * data)
{
    memset(data->uarr, 0, sizeof(data->uarr));

    memset(data->uarr_min, 0, sizeof(data->uarr_min));
    memset(data->uarr_max, 1, sizeof(data->uarr_max));

    memset(data->arr_max, 0, sizeof(data->uarr_max));

    memset(data->arr_min_soc, 1, sizeof(data->arr_min_soc));
    memset(data->arr_min_stc, 1, sizeof(data->arr_min_stc));
    memset(data->arr_min_sm, 1, sizeof(data->arr_min_sm));

    memset(data->arr_sm, 0, sizeof(data->arr_sm)); 
    
    display_b(&(data->val), &(data->radix), &(data->opsize));

    max_min_init(data);
    dec_2_bin(data); 
    signed_ones_comp(data);
    signed_twos_comp(data);
    signed_magnitude(data);

    if (data->opsize == 4)
    {
        display_4(data);
    }
    else if (data->opsize == 8)
    {
        display_8(data);
    }
    else if (data->opsize == 16)
    {
        display_16(data);
    }

}

// Display function for 4 bit operand size
void display_4(data_typedef * data)
{
    
    printf("%-42sMaximum%-8sMinimum\n", "", "");
    
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Binary%-20s0b", "");
        display_binary(&(data->opsize), data->uarr);
        printf("%-10s0b","");
    }
    else
    {
        printf("Binary%-20s%s", "", "Error");
        printf("%-10s0b","");

    }       
    

    
    display_binary(&(data->opsize), data->uarr_max);

    printf("%-10s0b","");
    display_binary(&(data->opsize), data->uarr_min);
 
    printf("\n");
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Decimal%-19s%d%-15s", "", data->uval, ""); 
    }
    else
    {
        printf("Decimal%-19s%s%-10s", "", "Error", ""); 
    }
    
    printf("%d%-14s%d\n", data->uval_max,"", data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Octal%-21s0%o%-14s", "", data -> uval, ""); 
    }
    else
    {
        printf("Octal%-21s%s%-10s", "", "Error", ""); 
    }
    
    printf("0%o%-13s%o\n", data -> uval_max, "", data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Hexadecimal%-15s0x%x%-13s", "", data->uval, "");
    }
    else
    {
        printf("Hexadecimal%-15s%s%-10s", "", "Error", "");
    }
    
    printf("0x%x%-13s0x%x\n", data->uval_max, "", data->uval_min);
    

    if ( (data->val >= data->val_min_soc) && (data->val <= data->val_max_soc))
    {
        printf("Signed one's complement%-3s0b", "");
        display_binary(&(data->opsize), data->arr_soc);
        printf("%-10s0b","");
    }
    else
    {
        printf("Signed one's complement%-3s%s", "", "Error");
        printf("%-10s0b","");

    }
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%-10s0b","");
    display_binary(&(data->opsize), data->arr_min_soc);

    printf("\n");
    

    if ( (data->val >= data->val_min_stc) && (data->val <= data->val_max_stc))
    {
        printf("Signed two's complement%-3s0b", "");
        display_binary(&(data->opsize), data->arr_stc);
        printf("%-10s0b","");
    }
    else
    {
        printf("Signed two's complement%-3s%s", "", "Error");
        printf("%-10s0b","");

    }

    display_binary(&(data->opsize), data->arr_max);

    printf("%-10s0b","");
    display_binary(&(data->opsize), data->arr_min_stc);

    printf("\n");

    

    if ( (data->val >= data->val_min_sm) && (data->val <= data->val_max_sm))
    {
        printf("Signed magnitude%-10s0b", "");
        display_binary(&(data->opsize), data->arr_sm);
        printf("%-10s0b","");
    }
    else
    {
        printf("Signed magnitude%10s%s", "", "Error");
        printf("%-10s0b","");

    }    
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%-10s0b","");
    display_binary(&(data->opsize), data->arr_min_sm);

    printf("\n");
    printf("\n");
}

// Display function for 8 bit operand size
void display_8(data_typedef * data)
{

    
    printf("%42sMaximum%8sMinimum\n", "", "");
    
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Binary%20s0b", "");
        display_binary(&(data->opsize), data->uarr);
        printf("%5s0b","");
    }
    else
    {
        printf("Binary%20s%s", "", "Error");
        printf("%10s0b","");

    }       
    

    
    display_binary(&(data->opsize), data->uarr_max);

    printf("%5s0b","");
    display_binary(&(data->opsize), data->uarr_min);
 
    printf("\n");
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Decimal%19s%d%15s", "", data->uval, ""); 
    }
    else
    {
        printf("Decimal%19s%s%10s", "", "Error", ""); 
    }
    
    printf("%d%12s%d\n", data->uval_max,"", data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Octal%21s0%o%14s", "", data -> uval, ""); 
    }
    else
    {
        printf("Octal%21s%s%10s", "", "Error", ""); 
    }
    
    printf("0%o%11s%o\n", data -> uval_max, "", data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Hexadecimal%-15s0x%x%-14s", "", data->uval, "");
    }
    else
    {
        printf("Hexadecimal%-15s%s%-10s", "", "Error", "");
    }
    
    printf("0x%x%-11s0x%x\n", data->uval_max, "", data->uval_min);
    

    if ( (data->val >= data->val_min_soc) && (data->val <= data->val_max_soc))
    {
        printf("Signed one's complement%3s0b", "");
        display_binary(&(data->opsize), data->arr_soc);
        printf("%5s0b","");
    }
    else
    {
        printf("Signed one's complement%3s%s", "", "Error");
        printf("%10s0b","");

    }
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%5s0b","");
    display_binary(&(data->opsize), data->arr_min_soc);

    printf("\n");
    

    if ( (data->val >= data->val_min_stc) && (data->val <= data->val_max_stc))
    {
        printf("Signed two's complement%3s0b", "");
        display_binary(&(data->opsize), data->arr_stc);
        printf("%5s0b","");
    }
    else
    {
        printf("Signed two's complement%3s%s", "", "Error");
        printf("%10s0b","");

    }

    display_binary(&(data->opsize), data->arr_max);

    printf("%5s0b","");
    display_binary(&(data->opsize), data->arr_min_stc);

    printf("\n");

    

    if ( (data->val >= data->val_min_sm) && (data->val <= data->val_max_sm))
    {
        printf("Signed magnitude%10s0b", "");
        display_binary(&(data->opsize), data->arr_sm);
        printf("%5s0b","");
    }
    else
    {
        printf("Signed magnitude%10s%s", "", "Error");
        printf("%10s0b","");

    }    
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%5s0b","");
    display_binary(&(data->opsize), data->arr_min_sm);

    printf("\n");
    printf("\n");
}

// Display function for 16 bit operand size
void display_16(data_typedef * data)
{   
    
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("%50sMaximum%15sMinimum\n", "", "");
        printf("Binary%-20s0b", "");
        display_binary(&(data->opsize), data->uarr);
        printf("%-5s0b","");
    }
    else
    {
        printf("%50sMaximum%8sMinimum\n", "", "");
        printf("Binary%20s%s", "", "Error");
        printf("%10s0b","");

    }       
    

    
    display_binary(&(data->opsize), data->uarr_max);

    printf("%-5s0b","");
    display_binary(&(data->opsize), data->uarr_min);
 
    printf("\n");
    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Decimal%19s%-30d", "", data->uval); 
    }
    else
    {
        printf("Decimal%19s%s%19s", "", "Error", ""); 
    }
    
    printf("%-20d%d\n", data->uval_max, data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Octal%21s0%-28o", "", data -> uval); 
    }
    else
    {
        printf("Octal%21s%s%18s", "", "Error", ""); 
    }
    
    printf("0%-10o%-10s%o\n", data -> uval_max, "", data->uval_min);

    if ( (data->uval >= data->uval_min) && (data->uval <= data->uval_max))
    {
        printf("Hexadecimal%15s0x%-27x", "", data->uval);
    }
    else
    {
        printf("Hexadecimal%15s%s%19s", "", "Error", "");
    }
    
    printf("0x%-18x0x%-20x\n", data->uval_max, data->uval_min);
    

    if ( (data->val >= data->val_min_soc) && (data->val <= data->val_max_soc))
    {
        printf("Signed one's complement%-3s0b", "");
        display_binary(&(data->opsize), data->arr_soc);
        printf("%-5s0b","");
    }
    else
    {
        printf("Signed one's complement%-3s%s", "", "Error");
        printf("%-10s0b","");

    }
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%-5s0b","");
    display_binary(&(data->opsize), data->arr_min_soc);

    printf("\n");
    

    if ( (data->val >= data->val_min_stc) && (data->val <= data->val_max_stc))
    {
        printf("Signed two's complement%3s0b", "");
        display_binary(&(data->opsize), data->arr_stc);
        printf("%-4s0b","");
    }
    else
    {
        printf("Signed two's complement%3s%s", "", "Error");
        printf("%-10s0b","");

    }

    display_binary(&(data->opsize), data->arr_max);

    printf("%-5s0b","");
    display_binary(&(data->opsize), data->arr_min_stc);

    printf("\n");

    

    if ( (data->val >= data->val_min_sm) && (data->val <= data->val_max_sm))
    {
        printf("Signed magnitude%-10s0b", "");
        display_binary(&(data->opsize), data->arr_sm);
        printf("%-5s0b","");
    }
    else
    {
        printf("Signed magnitude%-10s%s", "", "Error");
        printf("%-10s0b","");

    }    
    
    display_binary(&(data->opsize), data->arr_max);

    printf("%5s0b","");
    display_binary(&(data->opsize), data->arr_min_sm);

    printf("\n");
    printf("\n");
    
}
