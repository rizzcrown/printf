#include <stdio.h>
#include <stdarg.h>

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
                char* str = putchar(va_arg(arg, char*));
                for(int j = 0; str[j] != '\0'; j++ ){
                    putchar(str[j]);
                }count ++;
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
