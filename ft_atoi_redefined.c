#include "libft.h"
#include "stdio.h"

int elevated(int number)
{
    int i;
    int result;

    i = 0;
    result = 1;
    while(i < (number - 1))
    {
        result *= 10;
        i++;
    }
    return (result);
}

int calculate_int(int str_length,char *str)
{
    int result;
    int counter;

    counter = 0;
    result = 0;
    while(counter <= str_length && ft_isdigit(str[counter])){
        result += (str[counter] - '0')*elevated(str_length);
        str_length--;
        counter++;
    }
    return (result);
}

int ft_atoi_redefined(char *string_number)
{
    int str_length;
    int result;
    char *str;
    char *str2;

    result = 0;
    if (string_number[0] == '-')
        str = string_number + 1;
    else
        str = string_number;
    str_length = ft_strlen(str);
    result = calculate_int(str_length, str);
    // while(counter <= str_length && ft_isdigit(str[counter])){
    //     result += (str[counter] - '0')*elevated(str_length);
    //     str_length--;
    //     counter++;
    // }
    if(counter < str_length)
    {
        // int a = 0;
        result = calculate_int(counter, str);
        // while(a <= counter && ft_isdigit(str[a])){
        //     result += (str[a] - '0')*elevated(counter);
        //     counter--;
        //     a++;
        // }
    }

    if (string_number[0] == '-')
        result *= -1;
    return result;
}

int main()
{
	printf("%i\n",ft_atoi_redefined("12"));
	printf("%i\n",atoi("12"));
	return (0);
}