/*
 * hw1.c
 *
 *  Created on: Mar 30, 2018
 *      Author: Jeremy Manandic
 */

#include<stdio.h>
#include<math.h>
float convertFloat(char[], int);
void convertBinary(float);
int main(void)	{
	char binary1[50] = {'\0'};
	char binary2[50] = {'\0'};
	char operator;
	int sizeBin1;
	float float1;
	float float2;
	float answer;

	setvbuf (stdout, NULL, _IONBF, 0); //buffer for eclipse.

	do	{
		printf("Enter an expression using binary numbers or Q to quit: ");
		scanf("%s", binary1);
		if (binary1[0] != 'q' && binary1[0] != 'Q'){
				scanf(" %c", &operator);
				scanf(" %s", binary2);
				sizeBin1 = sizeof(binary1);
				float1 = convertFloat(binary1, sizeBin1);
				float2 = convertFloat(binary2, sizeBin1);
				switch(operator)	{
				case '+':
					answer = float1 + float2;
					break;
				case '-':
					answer = float1 - float2;
					break;
				case '*':
					answer = float1 * float2;
					break;
				case '/':
					answer = float1 / float2;
					break;
				}
				printf("%f %c %f = %f\n", float1, operator, float2, answer);
				printf("%s %c %s = ", binary1, operator, binary2);
				convertBinary(answer);
			}
	} while (binary1[0] != 'q' && binary1[0] != 'Q');

	return 0;
}

float convertFloat(char binary1[], int size)	{
	float floatNum = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int endArray = 0;
	int dotLocation = 0; //location in array where the point is if any
	int exponent = 0;
	int numElements = 0;

	for (i = 0; i < size - 1; i++){
		if(binary1[i] == '.')	{
			dotLocation = i;
		}
		if(binary1[i])	{
			numElements++;
		}
	}

	exponent = -1;

	if(dotLocation == 0)	{
		endArray = numElements - 1;
	} else {
		endArray = dotLocation - 1;
		for(k = endArray + 2; k < size - 1; k++)	{
			if(binary1[k] == '1')	{
				floatNum += pow(2, exponent);
				//printf("floatNum: %f\n", floatNum);
			}
			exponent--;
		}
	}

	exponent = 0;

	for(j = endArray; j > -1; j--){
		if(binary1[j] == '1')	{
			floatNum += pow(2, exponent);
		}
		exponent++;
	}
	return floatNum;
}

void convertBinary(float answer){
	char binaryAnswer[50] = {'\0'};
	float pow2 = 1.0;
	float div2 = 2.0;
	int c = 0; //array counter
	while(answer > pow2){
		pow2 += pow2;
	}

	pow2 = pow2 / div2;

	while(pow2 != .5)	{
		//printf("pow2 = %f\n", pow2);
		if(answer - pow2 >= 0.0)	{
			//printf("1 put in.\n");
			binaryAnswer[c] = '1';
			c++;
			answer = answer - pow2;
			//printf("answer now: %f\n", answer);
		} else	{
			//printf("0 put in.\n");
			binaryAnswer[c] = '0';
			c++;
		}
		pow2 = pow2 - (pow2/2);
	}

	//printf("second loop done.");



	if(answer > 0)	{
		binaryAnswer[c] = '.';
		c++;
		//printf("inserted the dot");
	}

	while(answer > 0){
		if(answer - pow2 >= 0.0){
			binaryAnswer[c] = '1';
			c++;
			answer = answer - pow2;
		} else	{
			binaryAnswer[c] = '0';
			c++;
		}
		pow2 = pow2 - (pow2/2);
	}

	printf("%s\n", binaryAnswer);
}


