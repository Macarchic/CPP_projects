#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include < stdio.h >
#include <stdlib.h>


// Лабораторна робота 6
// Виконав Кот Олександр Анатолійович, 3 курс бакалавра ННІВТ, біолог
/*Варіант 2
1)	Створити 2 масиви:
а) перший масив – символьний рядок у форматі С, який містить всі дні тижня, записані послідовно «Понеділок_Вівторок_Середа….._Неділя»(для назв днів тижня можна, за бажанням, використовувати англійську мову).Створити масив використовуючи оператор new[].
б) другий масив складається з цілих чисел від 0 до 23, створений з використанням malloc().
2) 	Реалізувати функцію, яка буде будувати в консолі графічну таблицю доступних станів певної системи(стани «enable» та «disable») на весь тиждень, використовуючи для звернення до елементів масивів вказівники на відповідні масиви.Вважати, що система починає працювати з понеділка з «0» годині зі стану «disable» і стан системи змінюється на протилежний кожні 5 годин.При виводі тексту назви днів тижня зчитуються з першого масиву, номери годин зчитуються з другого масиву.
Приклад роботи програми :
« Графік роботи :
Понеділок enable[0.00:5.00], disable[5.00:10.00], …… enable[20.00:1.00]
Вівторок disable[1.00:6.00], enable[6.00:10.00], …… enable[21.00:3.00]
…»
3)	Реалізувати функцію, яка за введеними з клавіатури командами буде вносити зміни в графік, що відображається в консолі.А саме, змінює початковий момент відліку та стан системи.Приклад:
« Введіть початок відліку та початковий стан
2, disable

Понеділок disable[2.00:7.00]  enable[7.00:12.00] …… enable[22.00:3.00]
…»
4)	Коректно виконати видалення масивів.
5)	Показати роботу викладачеві.
*/


int DAYS_IN_WEEK = 7;
int  HOURS_IN_DAY = 24;
int  HOUR_INTERVAL = 5;


/*
2) 	Реалізувати функцію, яка буде будувати в консолі графічну таблицю доступних станів певної системи(стани «enable» та «disable») на весь тиждень,
використовуючи для звернення до елементів масивів вказівники на відповідні масиви.Вважати, що система починає працювати з понеділка з «0» годині зі
стану «disable» і стан системи змінюється на протилежний кожні 5 годин.При виводі тексту назви днів тижня зчитуються з першого масиву, номери годин
зчитуються з другого масиву.
Приклад роботи програми :
« Графік роботи :
Понеділок enable[0.00:5.00], disable[5.00:10.00], …… enable[20.00:1.00]
Вівторок disable[1.00:6.00], enable[6.00:10.00], …… enable[21.00:3.00]
…»
*/
void displaySchedule(char* daysOfWeek[], int* hours) {
    printf_s("Work schedule:\n");
    printf_s("\n");
    // роблю змінну трішки більш доступною, щоб була змога зберігати її останнє значення
    int hour;
    // змінна що буде зберігати потрібний час для наступного циклу який почнеться для наступного дня
    int moment = 0;
    // змінна що буде контролювати що писати: "enable чи disable"
    int enable = 1;
    // цикл для написання днів тижня
    for (int day = 0; day < DAYS_IN_WEEK; ++day) {
        printf_s("%s ", daysOfWeek[day]);
        // цикл для написання часу та enable чи disable
        for (hour = moment; hour < HOURS_IN_DAY; hour += HOUR_INTERVAL) {
            int startHour = hour;
            // використовую % HOURS_IN_DAY щоб при закінченні дня в нас виводилось не умовні 25 та 26, а їх залишок: 1 чи 2 тощо
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


/* 3)	Реалізувати функцію, яка за введеними з клавіатури командами буде вносити зміни в графік,
що відображається в консолі.А саме, змінює початковий момент відліку та стан системи.Приклад:
« Введіть початок відліку та початковий стан
2, disable

Понеділок disable[2.00:7.00]  enable[7.00:12.00] …… enable[22.00:3.00]
…»*/
void modifySchedule(char* daysOfWeek[], int* hours) {
    int startHour;
    char state[10];
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Уведення тексту треба робити саме так, як попросили: через кому з пробілом!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    printf_s("Enter the start of the countdown and the initial state (hour, enable/disable): ");

    scanf_s("%d, %s", &startHour, state, sizeof(state));
    printf_s("\n");
    int hour;
    int enable;
    // перевірка, що написав користвувач: enable чи disable
    if (state[0] == 'd' || state[0] == 'D')
    {
        enable = 0;
    }
    else {
        enable = 1;
    }

    // цикл для виведення днів
    for (int day = 0; day < DAYS_IN_WEEK; ++day) {
        printf("%s ", daysOfWeek[day]);
        // цикл для виведення часу
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

// 4) Коректно виконати видалення масивів.
void freeArrays(char* daysOfWeek[], int* hours) {
    free(daysOfWeek);
    free(hours);
}



int main() {
    /*1)	Створити 2 масиви:
    а) перший масив – символьний рядок у форматі С, який містить всі дні тижня, записані послідовно «Понеділок_Вівторок_Середа….._Неділя»
    (для назв днів тижня можна, за бажанням, використовувати англійську мову).Створити масив використовуючи оператор new[].
    */

    char** daysOfWeekArray = new char* [DAYS_IN_WEEK];

    const char* dayNames[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    // Виділення пам'яті та копіювання рядків
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        daysOfWeekArray[i] = _strdup(dayNames[i]);
    }

    // б) другий масив складається з цілих чисел від 0 до 23, створений з використанням malloc().
    int* hoursArray = (int*)malloc(HOURS_IN_DAY * sizeof(int));

    // Ініціалізація годин
    for (int i = 0; i < HOURS_IN_DAY; ++i) {
        hoursArray[i] = i;
        i++;
    }

    // Виведення початкового графіку роботи системи
    displaySchedule(daysOfWeekArray, hoursArray);

    // Модифікація графіку роботи системи та виведення його
    modifySchedule(daysOfWeekArray, hoursArray);

    // Звільнення виділених масивів
    freeArrays(daysOfWeekArray, hoursArray);

    return 0;
}

