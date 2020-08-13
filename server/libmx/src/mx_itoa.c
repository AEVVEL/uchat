#include "libmx.h"

char *mx_itoa(int number){
	int count = mx_digit_count(number);
	char *res = mx_strnew(count);
	int min = 0;
	//int hres = 0;
	if (number == -2147483648) {
		res[0] = '-';
		res[1] = '2';
		min += 2;
		number += 2000000000;
		number *= -1;
	}
	if (number < 0)
		{
			res[0] = '-';
			min++;
			number *= -1;
		}

	for(int i = count - 1; i >=min; i--) {
		res[i] = (number % 10) + '0';
		number = number / 10;
	}
	return res;
}
