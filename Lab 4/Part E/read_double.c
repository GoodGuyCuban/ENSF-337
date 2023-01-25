#include "read_input.h"
#include <math.h>

int read_real(char* digits, int n, double *num){
  int x = get_string(digits, n);

  if(x == EOF)
    return EOF;

  if(is_valid_double(digits) == 0)
    return 0;

  *num = convert_to_double(digits);

  return 1;
}

int is_valid_double(const char* digits){
    int i = 0;
    int decimal = 0;
    if(digits[0] == '-')
        i++;

    else if(digits[0] == '+')
        i++;

    for(; digits[i] != '\0'; i++){
        if(digits[i] == '.'){
            if(decimal == 1)
            return 0;
            decimal = 1;
        }
        else if(digits[i] < '0' || digits[i] > '9'){
            return 0;
        }
        
    }
    
    return 1;
}

double convert_to_double(const char* digits){
    int i = 0;
    int decimal = 0;
    double num = 0;
    int sign = 1;

    if(digits[0] == '-'){
        sign = -1;
        i++;
    }
    
    else if(digits[0] == '+'){
        i++;
    }
    
    for(; digits[i] != '\0'; i++){
        if(digits[i] == '.'){
            decimal = 1;
            i++;
        }
        if(decimal == 0){
            num = num * 10 + (digits[i] - '0');
        }
        else{
            
            num = num + (digits[i] - '0') * pow(10, -decimal);
            decimal++;
        }
    }

    return num * sign;
}