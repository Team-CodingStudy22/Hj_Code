#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
void reverse_string(char* str, int s, int e)
{ 
	char temp;
	if (s == e/2+1)
		return;
	
	else {
		temp = str[s];
		str[s] = str[e - s];
		str[e - s] = temp;
		reverse_string(str, s+1, e);
	}
}


int main() { 
	char str[100];

	printf("Enter any string:");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;

}