#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >
#include <stdlib.h>


// ����������� ������ 6
// ������� ��� ��������� �����������, 3 ���� ��������� �Ͳ��, �����
/*������ 2
1)	�������� 2 ������:
�) ������ ����� � ���������� ����� � ������ �, ���� ������ �� �� �����, ������� ��������� ���������_³������_�������.._������(��� ���� ��� ����� �����, �� ��������, ��������������� ��������� ����).�������� ����� �������������� �������� new[].
�) ������ ����� ���������� � ����� ����� �� 0 �� 23, ��������� � ������������� malloc().
2) 	���������� �������, ��� ���� �������� � ������ �������� ������� ��������� ����� ����� �������(����� �enable� �� �disable�) �� ���� �������, �������������� ��� ��������� �� �������� ������ ��������� �� ������� ������.�������, �� ������� ������ ��������� � �������� � �0� ����� � ����� �disable� � ���� ������� ��������� �� ����������� ���� 5 �����.��� ����� ������ ����� ��� ����� ���������� � ������� ������, ������ ����� ���������� � ������� ������.
������� ������ �������� :
� ������ ������ :
�������� enable[0.00:5.00], disable[5.00:10.00], �� enable[20.00:1.00]
³������ disable[1.00:6.00], enable[6.00:10.00], �� enable[21.00:3.00]
��
3)	���������� �������, ��� �� ��������� � ��������� ��������� ���� ������� ���� � ������, �� ������������ � ������.� ����, ����� ���������� ������ ����� �� ���� �������.�������:
� ������ ������� ����� �� ���������� ����
2, disable

�������� disable[2.00:7.00]  enable[7.00:12.00] �� enable[22.00:3.00]
��
4)	�������� �������� ��������� ������.
5)	�������� ������ ����������.
*/


int DAYS_IN_WEEK = 7;
int  HOURS_IN_DAY = 24;
int  HOUR_INTERVAL = 5;


/*
2) 	���������� �������, ��� ���� �������� � ������ �������� ������� ��������� ����� ����� �������(����� �enable� �� �disable�) �� ���� �������,
�������������� ��� ��������� �� �������� ������ ��������� �� ������� ������.�������, �� ������� ������ ��������� � �������� � �0� ����� �
����� �disable� � ���� ������� ��������� �� ����������� ���� 5 �����.��� ����� ������ ����� ��� ����� ���������� � ������� ������, ������ �����
���������� � ������� ������.
������� ������ �������� :
� ������ ������ :
�������� enable[0.00:5.00], disable[5.00:10.00], �� enable[20.00:1.00]
³������ disable[1.00:6.00], enable[6.00:10.00], �� enable[21.00:3.00]
��
*/
void displaySchedule(char* daysOfWeek[], int* hours) {
    printf_s("Work schedule:\n");
    printf_s("\n");
    // ����� ����� ����� ���� ���������, ��� ���� ����� �������� �� ������ ��������
    int hour;
    // ����� �� ���� �������� �������� ��� ��� ���������� ����� ���� ��������� ��� ���������� ���
    int moment = 0;
    // ����� �� ���� ������������ �� ������: "enable �� disable"
    int enable = 1;
    // ���� ��� ��������� ��� �����
    for (int day = 0; day < DAYS_IN_WEEK; ++day) {
        printf_s("%s ", daysOfWeek[day]);
        // ���� ��� ��������� ���� �� enable �� disable
        for (hour = moment; hour < HOURS_IN_DAY; hour += HOUR_INTERVAL) {
            int startHour = hour;
            // ������������ % HOURS_IN_DAY ��� ��� �������� ��� � ��� ���������� �� ����� 25 �� 26, � �� �������: 1 �� 2 ����
            int endHour = (hour + HOUR_INTERVAL) % HOURS_IN_DAY;
            if (enable == 1)
            {
                printf_s("enable [%d.00:%d.00], ", startHour, endHour);
                enable = 0;
            }
            else
            {
                printf("disable [%d.00:%d.00], ", startHour, endHour);
                enable = 1;
            }
        }
        moment = hour % HOURS_IN_DAY;
        printf_s("\n");
    }
    printf_s("\n");
}


/* 3)	���������� �������, ��� �� ��������� � ��������� ��������� ���� ������� ���� � ������,
�� ������������ � ������.� ����, ����� ���������� ������ ����� �� ���� �������.�������:
� ������ ������� ����� �� ���������� ����
2, disable

�������� disable[2.00:7.00]  enable[7.00:12.00] �� enable[22.00:3.00]
��*/
void modifySchedule(char* daysOfWeek[], int* hours) {
    int startHour;
    char state[10];
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! �������� ������ ����� ������ ���� ���, �� ���������: ����� ���� � �������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    printf_s("Enter the start of the countdown and the initial state (hour, enable/disable): ");

    scanf_s("%d, %s", &startHour, state, sizeof(state));
    printf_s("\n");
    int hour;
    int enable;
    // ��������, �� ������� �����������: enable �� disable
    if (state[0] == 'd' || state[0] == 'D')
    {
        enable = 0;
    }
    else {
        enable = 1;
    }

    // ���� ��� ��������� ���
    for (int day = 0; day < DAYS_IN_WEEK; ++day) {
        printf("%s ", daysOfWeek[day]);
        // ���� ��� ��������� ����
        for (hour = startHour; hour < HOURS_IN_DAY; hour += HOUR_INTERVAL) {
            int startHour = hour;
            int endHour = (hour + HOUR_INTERVAL) % HOURS_IN_DAY;
            if (enable == 1)
            {
                printf("enable [%d.00:%d.00], ", startHour, endHour);
                enable = 0;
            }
            else
            {
                printf("disable [%d.00:%d.00], ", startHour, endHour);
                enable = 1;
            }
        }
        startHour = hour % HOURS_IN_DAY;
        printf("\n");
    }

}

// 4) �������� �������� ��������� ������.
void freeArrays(char* daysOfWeek[], int* hours) {
    free(daysOfWeek);
    free(hours);
}



int main() {
    /*1)	�������� 2 ������:
    �) ������ ����� � ���������� ����� � ������ �, ���� ������ �� �� �����, ������� ��������� ���������_³������_�������.._������
    (��� ���� ��� ����� �����, �� ��������, ��������������� ��������� ����).�������� ����� �������������� �������� new[].
    */

    char** daysOfWeekArray = new char* [DAYS_IN_WEEK];

    const char* dayNames[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    // �������� ���'�� �� ��������� �����
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        daysOfWeekArray[i] = _strdup(dayNames[i]);
    }

    // �) ������ ����� ���������� � ����� ����� �� 0 �� 23, ��������� � ������������� malloc().
    int* hoursArray = (int*)malloc(HOURS_IN_DAY * sizeof(int));

    // ����������� �����
    for (int i = 0; i < HOURS_IN_DAY; ++i) {
        hoursArray[i] = i;
        i++;
    }

    // ��������� ����������� ������� ������ �������
    displaySchedule(daysOfWeekArray, hoursArray);

    // ����������� ������� ������ ������� �� ��������� ����
    modifySchedule(daysOfWeekArray, hoursArray);

    // ��������� �������� ������
    freeArrays(daysOfWeekArray, hoursArray);

    return 0;
}

