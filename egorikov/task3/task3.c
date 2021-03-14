#include <stdio.h>

#define SIGN(num) num > 0 ? 1 : num == 0 ? 0 : -1

static int chain_fraction(int dividend, int divider);

int main(void)
{
    int a, b;
    printf("Enter a, b: "); scanf("%d%d", &a, &b);
	if ( chain_fraction(a, b) > 0 )
		printf("Divide by zero\n");
	return 0;
}

static int chain_fraction(int dividend, int divider)
{
	if ( divider == 0 )
		return 1;

    int remainder = 0;
	dividend = dividend * (SIGN(dividend));
	divider = divider * (SIGN(divider));

	printf("[ ");

	while ( dividend > 1 ) {
		printf("%d ", dividend / divider);
		remainder = dividend % divider;

		if ( remainder == 0 )
			break;
		
		dividend = divider;
		divider = remainder;
	}

	printf("]\n");

	return 0;
}
