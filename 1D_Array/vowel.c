#include<stdio.h>
int main()
{
	char character;
	printf("print a character");
	scanf("%c",&character);
	switch(character)
	{
		case 'a':
			printf("vowel");break;
		case 'e':
			printf("vowel");break;
		case 'i':
			printf("vowel");break;
		case 'o':
			printf("vowel");break;
		case 'u':
			printf("vowel");break;
		default:
			printf("consonant");break;
	}
}
