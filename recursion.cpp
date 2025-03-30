#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "Level2.h"

int exponential(int base, int power) {
	if (power == 0) {
		return 1;
	}
	return base * exponential(base, power - 1);
}

void prt20n(int n) {
	if (n == 0) {
		printf("%d", n);
		return;
	}
	printf("%d ", n);
	prt20n(n - 1);
}

void prt02n(int n) {
	if (n == 0) {
		printf("%d ",n);
		return;
}
	prt02n(n - 1);
	printf("%d ", n);
	
	
}

int countdigits(int n) {
	if (n<10) {
		return 1;
	}
	return 1 + countdigits(n/10);
	// can't have counter bc counter resets every time the stack is called - so it is useless
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a % b);
}

int sum(int n) {
	if (n == 0) {
		return 0;
	}
	return n + sum(n - 1);
}
// This function performs different calculations based on the value of y - kind of like a power function but to the power of 1 less
int func(int x, int y) {
	if (y == 0) {
		return 1;
	}
	if (y > 0) {
		return x * func(x, y);
	}
	return 1 / func(x, -y);
}


void drawTriangle(int n) {
	if (n == 0) {
		return;
	}
	drawTriangle(n - 1);
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n");
}

void drawTriangleUpsideDown(int n) {
	if (n == 0) {
		return;
	}
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n");
	drawTriangleUpsideDown(n - 1);
}
int
recursion1work()
{
	int options;
	printf("You are in Recursion 1\n");
	printf("Here are the options you can run: \n\n");
	printf("Enter 1: Calculating the exponential value of a base\n");
	printf("Enter 2: Print numbers from n to 0\n");
	printf("Enter 3: Print numbers from 0 to n\n");
	printf("Enter 4: Counting the digits in a number\n");
	printf("Enter 5: Finding the greatest common factor of 2 numbers\n");
	printf("Enter 6: Finding the sum of numbers until n\n");
	printf("Enter 7: Unique power function\n");
	printf("Enter 8: Drawing a triangle\n");
	printf("Enter 9: Drawing a triangle upside down\n");
	printf("After reading the options, enter a number (1-9) to choose what function you want to call: ");
	scanf("%d", &options);

	switch (options)
	{
	case 1:
	{
		exponential(2, 3);
		break;
	}
	case 2:
	{
		prt20n(20);
		break;
	}
	case 3:
	{
		prt02n(6);
		break;
	}
	case 4:
	{
		countdigits(5);
		break;
	}
	case 5:
	{
		gcd(10, 5);
		break;
	}
	case 6:
	{
		sum(5);
		break;
	}
	case 7:
	{
		func(3, 2);
		break;
	}
	case 8:
	{
		drawTriangle(5);
		break;
	}
	case 9:
	{
		drawTriangleUpsideDown(5);
		break;
	}
	}
	return 0;
}