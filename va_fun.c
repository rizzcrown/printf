#include <stdio.h>
#include <stdarg.h>
#include "main.h"


int _printf(const char* format, ...);

int _printf(const char* format, ...){
    va_list arg;
    int count = 0;

    va_start(arg, format);
    for(int i = 0; format[i] != '\0';i++){
        if(format[i] == '%'){
            i++;
            if(format[i] == 'c'){
                putchar(va_arg(arg, int));
                count ++;
            }else if(format[i] == 's'){
                char* str = va_arg(arg, char*);
                /*for(int j = 0; str[j] != '\0'; j++ ){
                    printf("%c",str[j]);
                }*/
                fputs(str, stdout);
                count ++;
            }else if(format[i] == '%'){
                putchar('%');
                count ++;
            }
        }else{
            putchar(format[i]);
            count ++;
        }
    }
    va_end(arg);
    return count;
}

/*int main(){
    char name[] = "Jason";
    char briv ='O';
    int store =_printf("My name is %s.%c\n",name, briv);
    printf("The number of characters printed is: %d.\n",store);
    return 0;
}*/
