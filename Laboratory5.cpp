
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >




/*����������� ������ 2
������� ��� ��������� �����������, 3 ���� ��������� �Ͳ��, �����.
������ 2

1)	��������� �������������� ��� �����, ���� ����� ����������� �����(������� ���� ��������� �� ���������).
2) 	�������� �������, ���������� ��� � �������� ��� �����, � ��� ���������� �� ����� � ����� � ��������� �������.
3) 	�������� ������� �� ���������� ����, ������, ������� �� ������ �������� ���� ������������ �����.
4) 	�������� ������� ��� �������� �� ����� ����������� ����� � ������ ��������� ���������� �� ����������(���������, �123 / 456�).
5) 	�������� ��� �������� ������������ �����, �������� � ���� ��������, ������ � ������� 2) �� 3) �� ������� ���������� �� ����� � ���������� �����������.
6)	������������ ������� � ��������� ������� 6 ������������ ����� �� ���������� �� ���������� �� ������� ��������� �� �����.
7)	 ���������� ������ ���������������� ���������.*/

//1)	��������� �������������� ��� �����, ���� ����� ����������� �����(������� ���� ��������� �� ���������).
struct RationalNumber {
    int numerator;
    int denominator;
};
//2) 	�������� �������, ���������� ��� � �������� ��� �����, � ��� ���������� �� ����� � ����� � ��������� �������.
float RationalToFloat(  struct RationalNumber  rational) {
    return (float)rational.numerator / rational.denominator;
}
//3) 	�������� ������� �� ���������� ����, ������, ������� �� ������ �������� ���� ������������ �����.
//����
struct RationalNumber Add(struct RationalNumber a, struct RationalNumber b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//³�������
struct RationalNumber Subtract(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//�������
struct RationalNumber Multiply(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
//г�����
struct RationalNumber Divide(  struct RationalNumber  a,   struct RationalNumber  b) {
    struct RationalNumber result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}

//4) 	�������� ������� ��� �������� �� ����� ����������� ����� � ������ ��������� ���������� �� ����������(���������, �123 / 456�).
void PrintRationalNumber(  struct RationalNumber  rational) {
    printf_s("%d/%d", rational.numerator, rational.denominator);
}

int compareNumerator(const void* a, const void* b) {
    return ((struct RationalNumber*)a)->numerator - ((struct RationalNumber*)b)->numerator;
}

int main() {
    //5) 	�������� ��� �������� ������������ �����, �������� � ���� ��������, ������ � ������� 2) �� 3) �� ������� ���������� �� ����� � ���������� �����������.
    
    // ��'������� ������������ �����
    struct RationalNumber firstNumber;
    struct RationalNumber secondNumber;

    // ����� �� �������� ������������ ����� � ���������
    printf_s("Enter the first rational number after the pattern \"numerator/denominator\":\t");
    scanf_s("%d/%d", &firstNumber.numerator, &firstNumber.denominator);
    printf_s("Enter the second rational number after the pattern \"numerator, denominator\":\t");
    scanf_s("%d/%d", &secondNumber.numerator, &secondNumber.denominator);
    printf_s("\n");

    // ���������� �� ����� � ��� ����� �� �������� � �������
    printf_s("First number as float: %f\n", RationalToFloat( firstNumber));
    printf_s("Second number as float: %f\n", RationalToFloat( secondNumber));
    printf_s("\n");

    // ������, �������, ������� �� ����� �� ���������� �����, � ���������� �������� � ������� ����
    struct RationalNumber sumResult = Add( firstNumber,  secondNumber);
    struct RationalNumber subtractionResult = Subtract( firstNumber,  secondNumber);
    struct RationalNumber multiplicationResult = Multiply( firstNumber,  secondNumber);
    struct RationalNumber divisionResult = Divide( firstNumber,  secondNumber);

    //�������� ����������
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


    //6)	������������ ������� � ��������� ������� 6 ������������ ����� �� ���������� �� ���������� �� ������� ��������� �� �����.
    struct RationalNumber numbers[] = { firstNumber, secondNumber, sumResult, subtractionResult, multiplicationResult, divisionResult };
    int n = sizeof(numbers) / sizeof(numbers[0]);
    //  qsort �� ������� � ���������� �������� �, ��� ��������������� ��� ���������� ������. ���� � ������ �� ���������������
    qsort(numbers, n, sizeof(struct RationalNumber), compareNumerator);
    // � compareNumerator �� ��������� ������� ��������� ��� ����� ���� �������� �� ������ � ������� ������� ��������. �� � �������� ����
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
