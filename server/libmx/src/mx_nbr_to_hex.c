#include "libmx.h"

 char *mx_nbr_to_hex(unsigned long nbr) 
{    
	char *hexaDeciNum = mx_strnew(100);  
      
    // counter for hexadecimal number array 
    int i = 0; 
    while(nbr!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = nbr % 16; 
          
        // check if temp < 10 
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
        	hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        nbr = nbr/16;
      	
    } 
    return hexaDeciNum;
} 
