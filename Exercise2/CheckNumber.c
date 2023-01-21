
// file: CheckNumber.c
// Author(s): Pavel Kaljunen, Sebastian Sopola
// Discription: Check user input


// load necessare libaries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main () {
	int num;
	int num2;

	// Get user input as integers
	printf("Give number:\n");
	if (scanf("%d", &num) == 1 ) {

		printf("Give another number:\n");
		if (scanf("%d", &num2) == 1 ) {
			printf("Your first number is %d and second %d. \n", num, num2);

			// Check which number is greater
			if ( num > num2 ) {
				printf("First number is greater than second\n");
			} else if ( num == num2 ) {
				printf("Numbers are equal\n");
			}
			else {
				printf("Second number is greater than first\n");
			}


			// Make calculations

			int sum = num + num2;
			int difference = num - num2;
			int product = num*num2;
			float division = 0.00;
			float average  =( num + num2 )/2;
			int power = pow( num, num2);
			// generate random number
			int random_number;
			int random () {
				srand(time(NULL));
				random_number = rand() % 100 + 0;

				return 0;
			}
			random(rand() % 100 + 0);


			if ( num == 0 || num2 == 0 ) {
				printf("Can't divide by 0");
			} else {
				division = num/num2;
			}
			// Check whether randpm number is odd or even
			if (random_number != 0 ) {
				if ( random_number % 2 != 0 ) {
					printf("random number is odd \n");
				} else if ( random_number % 2 == 0) {
					printf("random number is even \n");
				}
			}
			// check whether divisible by both 4 and 7
			int number = random_number;
			int division1 = number/4;
			int division2 = number/7;
			if ( division1 % 2 == 0) {
				if ( division2 % 2 == 0) {
					printf("random number is divisible by both 4 and 7 \n");
				}
			} else {
				printf("Random number is not divisible by both 4 and 7 \n");
			}
			// hard code array

			const int array[10] = {1,2,3,4,5,6,7,8,9,10};
			for (int i = 0; i < 10; i++ ) {
				printf("%d \n", array[i]);
			}

			for (int i = 9; i <= 10 && i != -1; i=i-1) {
				printf("%d \n", array[i]);
			}

			// check whether random number is in the array
			for ( int i = 0; i < 10; i++) {
				if ( random_number == array[i] ) {
					printf("Jippii! Our random number is in the array \n");
				}
			}


			// print bunch of information
			printf("sum: %d difference: %d product: %d division: %.2f average: %.2f power: %d random number: %d", 
			sum, difference, product, division, average, power, random_number);

		} else {
		printf("Not a number");
		}
	} else {
	printf("Not a number");
	}

	return 0;

}





