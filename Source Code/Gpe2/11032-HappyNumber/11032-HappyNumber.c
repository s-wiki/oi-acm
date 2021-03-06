#include <stdio.h>
#include <string.h>
#define MAX 730
int a[MAX];
int b[] = {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 
103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 203, 208, 219, 226, 230, 236, 
239, 262, 263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 326, 329, 331, 338, 356, 362, 
365, 367, 368, 376, 379, 383, 386, 391, 392, 397, 404, 409, 440, 446, 464, 469, 478, 487, 
490, 496, 536, 556, 563, 565, 566, 608, 617, 622, 623, 632, 635, 637, 638, 644, 649, 653, 
655, 656, 665, 671, 673, 680, 683, 694, 700, 709, 716};
int c[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int Sum2(char * s)
{
	int i;
	int n = strlen(s);
	int rs = 0;
	
	for (i = 0; i < n; i++)
	{
		rs += c[s[i] - '0'];
	}
	
	return rs;
}

void Init(int n)
{
	int i;
	
	for (i  = 0; i < 103; i++)
	{
		a[b[i]] = 1;
	}
}

int main()
{
	int i, n;
	char s[10];
	
	Init(MAX);
	scanf("%d", &n);
	n++;
	
	for(i = 1; i < n; i++)
	{
		scanf("%s", &s);
		
		if (a[Sum2(s)] == 1)
			printf("Case #%d: %s is a Happy number.\n", i, s);
		else
			printf("Case #%d: %s is an Unhappy number.\n", i, s);
	}
	
	return 0;
}
