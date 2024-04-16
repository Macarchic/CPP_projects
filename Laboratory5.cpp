
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >




/*Лабораторна робота 2
Виконав Кот Олександр Анатолійович, 3 курс бакалавра ННІВТ, біолог.
Варіант 2

1)	Визначити структурований тип даних, який описує раціональне число(задаючи його чисельник та знаменник).
2) 	Створити функцію, аргументом якої є згаданий тип даних, і яка переводить це число у форму з плаваючою крапкою.
3) 	Створити функції які обчислюють суму, різницю, добуток та частку описаних вище раціональних чисел.
4) 	Створити функції яка виводить на екран раціональне число у вигляді відношення чисельника до знаменника(наприклад, «123 / 456»).
5) 	Створити два довільних раціональних числа, виконати з ними операції, вказані у пунктах 2) та 3) та вивести результати на екран з відповідними коментарями.
6)	Впорядкувати отримані в попередніх пунктах 6 раціональних чисел за зростанням їх чисельника та вивести результат на екран.
7)	 Результати роботи продемонструвати викладачу.*/

//1)	Визначити структурований тип даних, який описує раціональне число(задаючи його чисельник та знаменник).
struct RationalNumber {
    int numerator;
    int denominator;
};
//2) 	Створити функцію, аргументом якої є згаданий тип даних, і яка переводить це число у форму з плаваючою крапкою.
float RationalToFloat(  struct RationalNumber  rational) {
    return (float)rational.numerator / rational.denominator;
}
//3) 	Створити функції які обчислюють суму, різницю, добуток та частку описаних вище раціональних чисел.
//Сума
struct RationalNumber Add(struct RationalNumber a, struct RationalNumber b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//Віднімання
struct RationalNumber Subtract(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//Добуток
struct RationalNumber Multiply(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//Різниця
struct RationalNumber Divide(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}

//4) 	Створити функції яка виводить на екран раціональне число у вигляді відношення чисельника до знаменника(наприклад, «123 / 456»).
void PrintRationalNumber(  struct RationalNumber  rational) {
    printf_s("%d/%d", rational.numerator, rational.denominator);
}

int compareNumerator(const void* a, const void* b) {
    return ((struct RationalNumber*)a)->numerator - ((struct RationalNumber*)b)->numerator;
}

int main() {
    //5) 	Створити два довільних раціональних числа, виконати з ними операції, вказані у пунктах 2) та 3) та вивести результати на екран з відповідними коментарями.
    
    // Об'явлення раціоанльних чисел
    struct RationalNumber firstNumber;
    struct RationalNumber secondNumber;

    // Запит на введення раціональних чисел з клавіатури
    printf_s("Enter the first rational number after the pattern \"numerator/denominator\":\t");
    scanf_s("%d/%d", &firstNumber.numerator, &firstNumber.denominator);
    printf_s("Enter the second rational number after the pattern \"numerator, denominator\":\t");
    scanf_s("%d/%d", &secondNumber.numerator, &secondNumber.denominator);
    printf_s("\n");

    // Конвертуємо ці числа у тип флоат та виводимо у консоль
    printf_s("First number as float: %f\n", RationalToFloat( firstNumber));
    printf_s("Second number as float: %f\n", RationalToFloat( secondNumber));
    printf_s("\n");

    // Сумуємо, віднімаємо, множимо та ділимо ці раціональні числа, а результати записуємо у відповідні змінні
    struct RationalNumber sumResult = Add( firstNumber,  secondNumber);
    struct RationalNumber subtractionResult = Subtract( firstNumber,  secondNumber);
    struct RationalNumber multiplicationResult = Multiply( firstNumber,  secondNumber);
    struct RationalNumber divisionResult = Divide( firstNumber,  secondNumber);

    //Виводимо результати
    printf_s("Sum: ");
    PrintRationalNumber( sumResult);
    printf_s("\n");

    printf_s("Subtraction: ");
    PrintRationalNumber( subtractionResult);
    printf_s("\n");

    printf_s("Multiplication: ");
    PrintRationalNumber( multiplicationResult);
    printf_s("\n");

    printf_s("Division: ");
    PrintRationalNumber( divisionResult);
    printf_s("\n");
    printf_s("\n");


    //6)	Впорядкувати отримані в попередніх пунктах 6 раціональних чисел за зростанням їх чисельника та вивести результат на екран.
    struct RationalNumber numbers[] = { firstNumber, secondNumber, sumResult, subtractionResult, multiplicationResult, divisionResult };
    int n = sizeof(numbers) / sizeof(numbers[0]);
    //  qsort це функція в стандартній бібліотеці С, яка використовується для сортування масиву. Тому і вирішив її використовувати
    qsort(numbers, n, sizeof(struct RationalNumber), compareNumerator);
    // А compareNumerator це необхідна функція порівняння яка віднімає одне значення від одного і повертає потрібне значення. Її я розписав вище
    printf_s("Sorted by numerator: ");
    for (int i = 0; i < 6; ++i) {
        PrintRationalNumber( numbers[i]);
        if (i < 5)
        {
            printf_s(", ");
        }
        
    }
    printf_s("\n");

    return 0;
}
