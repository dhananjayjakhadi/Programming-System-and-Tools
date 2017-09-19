#include <stdio.h>
#include <assert.h>
#include <math.h>

int findNextMultiple(int number1, int number2){
    int next_multiple = ((number1 + number2) - (number1 % number2));
    return (next_multiple);

}

float convertFtoC(float fahrenheit){
    float celsius = (fahrenheit - 32) / 1.8;
    return(celsius);
}

int castToInt(long num){
int large_num_as_int = (int)num;
//printf("\n\n\tcast to int output %d\t\n\n", large_num_as_int);
return(large_num_as_int);
}


double castToDouble(long num){
double large_num_as_double = (double) num;
//printf("\n\n\tcastTo Double :: %lf \t\n\n",large_num_as_double);
return(large_num_as_double);
}

char castToChar(long num){
char large_num_as_char = (char)num;
//printf("\n\n\tcast to char %c \t\n\n", large_num_as_char);
return(large_num_as_char);
}


int fibonacci(int n)
{
   int first=0, second=1,next,i;
   for(i=0;i<n;i++)
   {
       next=first+second;
        first=second;
        second=next;
        printf("%d\t", next);
   }
    return next;
}
int main()
{
    printf("\n\n\t\t Hello World\t\n\n");

    printf("\n\t=======================================\n");
	printf("\t=                   PART A          =\n");
	printf("\t=======================================\n\n");

	printf("\n\t=========Starting Expression Conversion Tests===========\n");

    float x=2.5;
    float result=0;
    result=3*pow(x,3)-5*pow(x,2)+6;
	printf(" \n\t\tThe value of 1st Expresson is:%.3f\n",result);
	assert(result==21.625);

	result=0;
	result=ceil((3*pow(10,8)+2*pow(10,-7))/(7*pow(10,-6)+2*pow(10,8)));
	printf("\n\t\tThe Value of 2nd Expression is:%.1f\n",result);
    assert(result==2.0);

    printf("\n\t\t....Converting Expressions Tests Passed\n");

    printf("\n\t=========Starting Next Multiple Tests===========\n");


    int number1 = 365, number2 = 7;
    int next_multiple = findNextMultiple(number1,number2);
	assert(371 == findNextMultiple(number1,number2));
	//printf("\n\n\t\t\t%d\n\n",next_multiple);

	number1 = 12258; number2 = 28;
	next_multiple = findNextMultiple(number1,number2);
	assert(12264 == findNextMultiple(number1,number2));
	//printf("\n\n\t\t\t%d\n\n",next_multiple);

	number1 = 996; number2 = 4;
	next_multiple = findNextMultiple(number1,number2);
	assert(1000 == findNextMultiple(number1,number2));
	//printf("\n\n\t\t\t%d\n\n",next_multiple);

	printf("\n\t\t....Next Multiple Tests Passed\n");

	printf("\n\t=========Starting Fahrenheit to Celsius Tests===========\n");

	float fahrenheit = 95;
	float celsius = convertFtoC(fahrenheit);
	assert(35.0 == celsius);
	//printf("\n\n\t\t\t%f\n\n",celsius);

	fahrenheit = 32;
	celsius = convertFtoC(fahrenheit);
	assert(0.0 == celsius);
	//printf("\n\n\t\t\t%f\n\n",celsius);

	fahrenheit = -40;
	celsius = convertFtoC(fahrenheit);
	assert(-40.0 == celsius);
	//printf("\n\n\t\t\t%f\n\n",celsius);
	printf("\n\t\t....Fahrenheit to Celsius Tests Passed\n");


	printf("\n\t=============================\n");
	printf("\t=           PART B          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Casting Tests===========\n");

//Testing our Casting and how its loses values for wrong casting
	long num = 9223372036854775617;
	int large_num_as_int = castToInt(num);
	assert(-191 == large_num_as_int);
	double large_num_as_double = castToDouble(num);
	assert(9223372036854775808.0 == large_num_as_double);
	char large_num_as_char = castToChar(num);
	assert('A' == large_num_as_char);

	printf("\n\t\t....Casting Tests Passed\n");

	printf("\n\t=========Starting Fibonacci Tests===========\n");
	//finding fibonacci series for first 20 numbers
	int n;
    printf("0 \t 1 \t");

	assert(4181 == fibonacci(18));

	printf("\n\t\t....Fibonacci Tests Passed\n");

	printf("\n\t=========ALL TESTS PASSED===========\n");

    return 0;
}



