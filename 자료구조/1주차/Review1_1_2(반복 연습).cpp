#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
void reverse_string(char* str, int s, int e) {
	char temp;
	for (; s <= e / 2; s++) {
		temp = str[s];
		str[s] = str[e - s];
		str[e - s] = temp;
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