
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >

//Лабораторна робота 3
//Виконав Кот Олександр Анатолійович, 3 курс бакалавра ННІВТ, біолог
//Варіант 2
/*1)	Задати змінну М для масиву цілих чисел, що складається з 10 елементів Записати у змінну М елементи масиву, які вводяться із клавіатури.
2)	Реалізувати функцію, яка виводить на екран елементи масиву М, в один рядок, розділяючи елементи комами. 
3)	Записати функцію, яка рахує логарифм числа x по довільній основі А, і має два аргументи: дійсне число x та ціле А. При цьому за замовчуванням логарифм має рахуватися по основі «2».
4)	Використовуючи функцію з пункту 3), розрахувати логарифм від кожного елемента масиву за принципом М1[n]=log(n+2)М[n] і вивести результат на екран.
5)	Визначити максимальний та мінімальний із елементів масиву М1 та надрукувати їх.
6)	Відсортувати елементи масиву М1 за зменшенням та вивести результат на екран. 
7)	Створити функцію, яка вставляє до початкового масиву ще один елемент того ж типу в кінець масиву та вивести результат на екран.   
8)	Продемонструвати роботу програми викладачу.*/




//2)	Реалізувати функцію, яка виводить на екран елементи масиву М, в один рядок, розділяючи елементи комами.
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



/*3)	Записати функцію, яка рахує логарифм числа x по довільній основі А, і має два аргументи : дійсне число x та ціле А.
При цьому за замовчуванням логарифм має рахуватися по основі «2».*/

//Зробив перевантаження функції


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



/*7)	Створити функцію, яка вставляє до початкового масиву ще один елемент того ж типу в кінець масиву та вивести результат на екран. */
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
	//1)	Задати змінну М для масиву цілих чисел, що складається з 10 елементів Записати у змінну М елементи масиву, які вводяться із клавіатури.
	printf_s("write 10 elements for array with size 10: \n");
	int M[10];
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%i", &M[i]);
	}


	// Виклик функції для виводу усіх елементів масиву
	printf_s("Here are elements of array M:\n");
	printArray(M);
	printf_s("\n");

	/*4)	Використовуючи функцію з пункту 3), розрахувати логарифм від кожного елемента масиву за принципом М1[n]=log(n+2)М[n] і вивести результат на екран.*/
	double M1[10];


	for (int i = 0; i < 10; i++)
	{
		M1[i] = calculateLog(i+2, M[i]);
	}
	printf_s("Here is your M1 array\n");
	printArray(M1);
	printf_s("\n");

	//5)	Визначити максимальний та мінімальний із елементів масиву М1 та надрукувати їх.
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



	//6)	Відсортувати елементи масиву М1 за зменшенням та вивести результат на екран. 
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

	


	//7)	Створити функцію, яка вставляє до початкового масиву ще один елемент того ж типу в кінець масиву та вивести результат на екран.
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





