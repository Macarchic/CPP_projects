
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >

//����������� ������ 3
//������� ��� ��������� �����������, 3 ���� ��������� �Ͳ��, �����
//������ 2
/*1)	������ ����� � ��� ������ ����� �����, �� ���������� � 10 �������� �������� � ����� � �������� ������, �� ��������� �� ���������.
2)	���������� �������, ��� �������� �� ����� �������� ������ �, � ���� �����, ��������� �������� ������. 
3)	�������� �������, ��� ���� �������� ����� x �� ������� ����� �, � �� ��� ���������: ����� ����� x �� ���� �. ��� ����� �� ������������� �������� �� ���������� �� ����� �2�.
4)	�������������� ������� � ������ 3), ����������� �������� �� ������� �������� ������ �� ��������� �1[n]=log(n+2)�[n] � ������� ��������� �� �����.
5)	��������� ������������ �� ��������� �� �������� ������ �1 �� ����������� ��.
6)	³���������� �������� ������ �1 �� ���������� �� ������� ��������� �� �����. 
7)	�������� �������, ��� �������� �� ����������� ������ �� ���� ������� ���� � ���� � ����� ������ �� ������� ��������� �� �����.   
8)	���������������� ������ �������� ���������.*/




//2)	���������� �������, ��� �������� �� ����� �������� ������ �, � ���� �����, ��������� �������� ������.
void printArray(int *array) {
	for (int i = 0; i < 10; i++)
	{
		printf_s("%i", array[i]);
		if (i < 9)
		{
			printf_s(", ");
		}
	}
	printf_s("\n");
	return;
}

void printArray(double* array) {
	for (int i = 0; i < 10; i++)
	{
		printf_s("%f", array[i]);
		if (i < 9)
		{
			printf_s(", ");
		}
	}
	printf_s("\n");
	return;
}



/*3)	�������� �������, ��� ���� �������� ����� x �� ������� ����� �, � �� ��� ��������� : ����� ����� x �� ���� �.
��� ����� �� ������������� �������� �� ���������� �� ����� �2�.*/

//������ �������������� �������


double calculateLog(int A, double x) {
	int base = A;
	int number = x;
	if (base <= 0 || number <= 0)
	{
		return -1;
	}
	else {
		double result = log(number) / log(base);
		return result;
	}
}



/*7)	�������� �������, ��� �������� �� ����������� ������ �� ���� ������� ���� � ���� � ����� ������ �� ������� ��������� �� �����. */
double *insertValueInArray(double *array, double newValue) {
		double* newArray = new double[11];
	for (int i = 0; i < 10; i++)
	{
		newArray[i] = array[i];
	}
	newArray[10] = newValue;
	return newArray;
}



int main() {
	//1)	������ ����� � ��� ������ ����� �����, �� ���������� � 10 �������� �������� � ����� � �������� ������, �� ��������� �� ���������.
	printf_s("write 10 elements for array with size 10: \n");
	int M[10];
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%i", &M[i]);
	}


	// ������ ������� ��� ������ ��� �������� ������
	printf_s("Here are elements of array M:\n");
	printArray(M);
	printf_s("\n");

	/*4)	�������������� ������� � ������ 3), ����������� �������� �� ������� �������� ������ �� ��������� �1[n]=log(n+2)�[n] � ������� ��������� �� �����.*/
	double M1[10];


	for (int i = 0; i < 10; i++)
	{
		M1[i] = calculateLog(i+2, M[i]);
	}
	printf_s("Here is your M1 array\n");
	printArray(M1);
	printf_s("\n");

	//5)	��������� ������������ �� ��������� �� �������� ������ �1 �� ����������� ��.
	double max = M1[0];
	double min = M1[0];

	for (int i = 1; i < 10; i++)
	{
		if (M1[i] > max)
		{
			max = M1[i];
		}
		if (M1[i] < min)
		{
			min = M1[i];
		}
	}
	printf_s("max = %lf, min = %lf\n", max, min);
	printf_s("\n");



	//6)	³���������� �������� ������ �1 �� ���������� �� ������� ��������� �� �����. 
	for (int i = 1; i < 10; i++)
	{
		if (M1[i] > M1[i-1])
		{
			double key = M1[i];
			int index = i;
			while (index > 0 && key > M1[index-1]) {
				M1[index] = M1[index-1];
				index--;
			}
			M1[index] = key;
		}
	}

	printf_s("Here is sorted array:\n");
	printArray(M1);
	printf_s("\n");

	


	//7)	�������� �������, ��� �������� �� ����������� ������ �� ���� ������� ���� � ���� � ����� ������ �� ������� ��������� �� �����.
	float number;
	printf_s("Enter a number: ");
	scanf_s("%f", &number);
	printf_s("\n");
	double* newArray = insertValueInArray(M1, number);
	printf_s("Here is you array with 11 elements:\n");
	for (int i = 0; i < 11; i++)
	{
		printf_s("%f", newArray[i]);
		if (i < 10)
		{
			printf_s(", ");
		}
	}
	printf_s("\n");
	free(newArray);
	delete[](newArray);
	delete[](M1);
}





