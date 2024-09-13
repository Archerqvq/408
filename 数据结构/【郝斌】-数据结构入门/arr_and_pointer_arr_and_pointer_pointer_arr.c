#include <stdio.h>

void str_test(char str_arr[], char *p_str_arr)
{

}

void pointer_arr_test(char *p[], char **pp)
{}

int main(int argc, char **argv)
{
	// char str_arr[5];
	char *p_str_arr[3] = {"hello", "nihao", "konnichiwa"};
	printf("%s, %s, %s \n", p_str_arr[0], p_str_arr[1], p_str_arr[2]);
	printf("%s, %s, %s \n", *p_str_arr, *(p_str_arr + 1), *(p_str_arr + 2));

	// int i = p_str_arr;

	// str_test(1, 1);

	// pointer_arr_test(1, 1);

	return 0;
}
