#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >

//����������� ������ 2
//������� ��� ��������� �����������, 3 ���� ��������� �Ͳ��, �����
//������ 2
// 1)	�������������� ���� �� �������� ��������� ������ ������������� ����������� ���� 
//      ����, ����� 2^(0) + 2^(1) + 2^(2) + ... + 2^(N-1) (����� N �������� ��������� � 
//		���������). �������� ��������� � ����� �.
// 
// 
// 2)	�������� �������� ����� � ���������� ��������� �������� 2^(N)-1.�������� ��������� � ����� �.
// 
// 
// 3)	������� �� ����� �������� ������ � �� �.
// 
// 
// 4)	�������������� ������� ��������, �������� �������� �����.���� � = � �������
//      �� ����� ����� �����������, ���� � > � � ����� �����, � < � � ����� �����.
// 
// 
// 5)	��������� ������ ������ ��������.��������� ���� � ������ 1, �������������� �������� 
//      goto: �������
//		����� :
//		��� �����;
//		if (�����) goto ����;�
// 
// 
// 6)	���������������� ������ �������� ���������.

// ճ� ������:
int main()
{
	// 1)	�������������� ���� �� �������� ��������� ������ ������������� ����������� ���� 
	//      ����, ����� 2^(0) + 2^(1) + 2^(2) + ... + 2^(N-1) (����� N �������� ��������� � 
	//		���������). �������� ��������� � ����� �.
	int N;
	printf_s ("Enter an integer N:\t"); 
	scanf_s("%i", &N);
	int A = 0;


	// ���� ��� ��������� ��� �������(����� � ������� ���������)
	for (int i = N-1; i >= 0; i--) 
	{
		// ������������ ����� ��� ������ ���� � ������� (����� � �����
		//������� ���� 0 �� 1) � ��� ������ ���� �������� temp ���� ������������� 2
		int temp = 2; 


		// ���� � = 0, �� ������ �� �� 2^(0) = 1, ���� ������ �� ������ �� �������� ������ ������ 1 �� ����� �
		if (i == 0) 
		{
			A += 1;
		}
		// ������� 2^(1) = 2, ���� ������ ������ 2
		else if (i == 1)
		{
			A += 2;
		}
		else {
			// � �� ���������� ���� ���� ���� �� ������� ��������� � 2^(2) � �� 2^(N-1) �������
			for (int q = i; q > 1; q--) 
			{
				temp *= 2;
			}
			// ������ ����� ���� �� ������� ����� � � ���� ����� ��������
			// ��� � ������� - temp ����� ���� = 2, � � ���� �������� ����� �� ���� ������ ��������
			A += temp;
		}
	}


	// 2)	�������� �������� ����� � ���������� ��������� �������� 2^(N)-1.�������� ��������� � ����� �.
	// 
	// 
	//��������� ���� ����� � �� ����������� � ��������� 1, 
	//�� ������ ��� ������� ������� ����� �� �� � ����� ����
	//��� ����� ����'������ ��������� ��������, � ���� 1 ��� �������� �� �� �� �� ������
	int B = 1; 
	// ���� ����, �� ������ ������� 2^(N)-1
	for (int w = N; w > 0; w--)
	{
		B *= 2;
	}
	B -= 1;


	//3)	������� �� ����� �������� ������ � �� �.
	printf_s(" A = %i, B = %i\n", A, B);



	// 4)	�������������� ������� ��������, �������� �������� �����.���� � = � �������
	//      �� ����� ����� �����������, ���� � > � � ����� �����, � < � � ����� �����.
	if (A>B)
	{
		printf_s(" A > B\n");
	}
	else if (A == B)
	{
		printf_s(" A = B\n");
	}
	else 
	{
		printf_s(" A < B\n");
	}


	// 5)	��������� ������ ������ ��������.��������� ���� � ������ 1, �������������� �������� 
	//      goto: �������
	//		����� :
	//		��� �����;
	//		if (�����) goto ����;�


	//	��� ������ ��� �� ����������� �� ����������������, � ������ ������ ����� ���� � �� ������������ ���������, 
	//	��� ���� ��������� ������ ���� ������, ����� ������ � ������������ ���� �� ����� �������������� ��� ������
	
	int N2;
	printf_s("Enter another integer N2: \t");
	scanf_s("%i", &N2);
	int A2 = 0;
	int temp2 = 2;
	int B2 = 1;
	int r = N2;



cycle:
	//���� ��������, ���� N2 = 2, �� ������ ������ 3
	if (N2 == 2)
	{
		A2 += 3;
		goto secondstep;
	}
	// ���� �� ����� �� ����� �������, ��� N>2 , ���� �������� �������� ���� ���� ���������� 2^(N-1)
	else {
		for (int e = N2 - 1; e > 1; e--)
		{
			temp2 *= 2;
		}
		// ������ �� � ����� ������ �������� ��������� �� ������ � ���������� ��� ������
		A2 += temp2;
		temp2 = 2;
		N2--;
		goto cycle;
	}
	
	// � ����� �� ��� ������ ���� ����, �� ������ ������� 2^(N)-1
secondstep:

	for (int p = r; p > 0; p--)
	{
		B2 *= 2;
	}
	B2 -= 1;


	printf_s(" A2 = %i, B2 = %i\n", A2, B2);

	if (A2 > B2)
	{
		printf_s(" A2 > B2\n");
	}
	else if (A2 == B2)
	{
		printf_s(" A2 = B2\n");
	}
	else
	{
		printf_s(" A2 < B2\n");
	}

}

