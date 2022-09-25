#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

int palindrome(char str[])
{
	StackType s;
	s.top = -1;
	
	for (int i = 0; str[i]!='\0'; i++)
		s.data[++(s.top)] = str[i];

	for (int i = 0; str[i] != '\0'; i++) {
		if (s.data[(s.top)] != str[i])
			return 0;
		else
			s.data[(s.top)--];
	}
	return 1;
}

int main(void)
{
	char word[MAX_STRING];
	
	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome 입니다.\n");
	else
		printf("palindrome이 아닙니다.\n");
}