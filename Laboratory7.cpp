#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>


/*Лабораторна робота 7
* Виконав Кот Олександр
Варіант 2
1)	Створити клас з ім’ям Auto. В даному класі створити поля, в яких міститься назва (марка) машини, об’єм палива у баку (від 50 до 100 літрів) та базова витрата палива на одиницю шляху (від 5 до 10 л/100 км).
2)	Задати конструктор та деструктор класу.
3)	В класі реалізувати функцію-метод, яка визначає відстань, яку може проїхати машина без додаткової заправки. 
4)	На основі класу Auto створити два класи-нащадки: легковий автомобіль (Car) та вантажівка (Truck). В класі Car додати поле, де буде вказана кількість пасажирів (від 0 до 5), в класі Truck – поле, де буде вказана вага вантажу (від 0 до 10 тон).
5)	В обох класах перевантажити функцію розрахунку відстані, вважаючи, що кожен пасажир збільшує базову витрату палива на 5%, а кожна тонна ваги – на 10%. 
6)	Створити і заповнити дані для 3 об’єктів класу Car та 3 об’єктів класу Truck. Назва та кількість пасажирів чи вага вантажу вводяться з клавіатури, об’єм палива у баку та базова витрата палива генеруються випадковим чином за допомогою функції rand()так, щоб вони потрапляли у вказані в пункті 1) інтервали. 
7)	Створити текстовий файл з назвою «Laba7.txt» та перенести в нього всю інформацію про всі об’єкти класів Car та Truck. Відформатувати дані в зручному для читання вигляді.
8)	Порядок розташування записів в текстовому файлі має відповідати пройденій машиною відстані, від найменшої до найбільшої.
9)	Продемонструвати програму та створений файл викладачу*/



//1)	Створити клас з ім’ям Auto. В даному класі створити поля, в яких міститься назва (марка) машини, об’єм палива у баку (від 50 до 100 літрів) та базова витрата палива на одиницю шляху (від 5 до 10 л/100 км).


class Auto {
public:
    std::string brand;
    int volume;
    int efficiency;
    //2)	Задати конструктор та деструктор класу.
    Auto(std::string brand, int volume, int efficiency)
        : brand(brand), volume(volume), efficiency(efficiency) {}
    //3)	В класі реалізувати функцію-метод, яка визначає відстань, яку може проїхати машина без додаткової заправки. 
    virtual double distance_limit() const {
        return volume / efficiency;
    }

    virtual void writeOut(std::ofstream& file) const {
        file << "Brand:" << brand << "\tVolume: " << volume;
    }
    //2)	Задати конструктор та деструктор класу.
    ~Auto() {
    
    }
};


//4)	На основі класу Auto створити два класи-нащадки:
//5)	В обох класах перевантажити функцію розрахунку відстані, вважаючи, що кожен пасажир збільшує базову витрату палива на 5%, а кожна тонна ваги – на 10%. 
// Легковий автомобіль (Car)
class Car : public Auto {
public:
    // В класі Car додати поле, де буде вказана кількість пасажирів (від 0 до 5)
    int passangers;
    Car(std::string brand, int volume, int efficiency, int passangers)
        : Auto(brand, volume, efficiency), passangers(passangers) {}
    //Пасажир збільшує базову витрату палива на 5 %
    double newefficiency = efficiency + passangers * 0.05;
    double distance_limit() const override {
        return volume / newefficiency;
    }
    double distance = volume/newefficiency;
    void writeOut(std::ofstream& file) const override {
        Auto::writeOut(file);
        file << ",\tEfficiency: " << newefficiency;
        file << ",\tPassengers: " << passangers;
        file << ",\tDistance: " << distance;
    }
};



//Вантажівка (Truck)
class Truck : public Auto {
public:
    // додати в класі Truck поле, де буде вказана вага вантажу(від 0 до 10 тон).
    int weight;
    Truck(std::string brand, int volume, int efficiency, int weight)
        : Auto(brand, volume, efficiency), weight(weight) {}
    //Кожна тонна ваги збільшує витрати палива на 10%
    double newefficiency = efficiency + weight * 0.1;
    double distance_limit() const override {
        return volume / newefficiency;
    }
    double distance = volume / newefficiency;
    void writeOut(std::ofstream& file) const override {
        Auto::writeOut(file);
        file << ",\tEfficiency: " << newefficiency;
        file << ",   \tWeight: " << weight;
        file << ",\tDistance: " << distance;
    }
};

void Autossort(Car* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].distance_limit() < array[j + 1].distance_limit()) {
                // Обмін елементів, якщо потрібно
                Car temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void Autossort(Truck* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].distance_limit() < array[j + 1].distance_limit()) {
                // Обмін елементів, якщо потрібно
                Truck temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int weight;
    //7)	Створити текстовий файл з назвою «Laba7.txt» та перенести в нього всю інформацію про всі об’єкти класів Car та Truck.Відформатувати дані в зручному для читання вигляді.
    std::ofstream file("Laba7.txt");  // Відкриваємо файл для запису

    if (!file.is_open()) {
        std::cout << "Unable to open file for writing." << std::endl;
        return 1;
    }

    std::string brand;
    int passangers;
    //6)	Створити і заповнити дані для 3 об’єктів класу Car та 3 об’єктів класу Truck.
    //      Назва та кількість пасажирів чи вага вантажу вводяться з клавіатури, 
    //      об’єм палива у баку та базова витрата палива генеруються випадковим чином 
    //      за допомогою функції rand()так, щоб вони потрапляли у вказані в пункті 1) інтервали.
    std::cout << "Enter brand and passangers for Car1:\t";
    std::cin >> brand >> passangers;
    Car first_car(brand, rand() % 100 + 50, rand() % 5 + 1, passangers);

    std::cout << "Enter brand and passangers for Car2:\t";
    std::cin >> brand >> passangers;
    Car second_car(brand, rand() % 100 + 50, rand() % 5 + 1, passangers);

    std::cout << "Enter brand and passangers for Car3:\t";
    std::cin >> brand >> passangers;
    Car third_car(brand, rand() % 100 + 50, rand() % 5 + 1, passangers);

    std::cout << "Enter brand and weight for Truck1:\t";
    std::cin >> brand >> weight;
    Truck first_truck(brand, rand() % 100 + 50, rand() % 10 + 1, weight);

    std::cout << "Enter brand and weight for Truck2:\t";
    std::cin >> brand >> weight;
    Truck second_truck(brand, rand() % 100 + 50, rand() % 10 + 1, weight);

    std::cout << "Enter brand and weight for Truck3:\t";
    std::cin >> brand >> weight;
    Truck third_truck(brand, rand() % 100 + 50, rand() % 10 + 1, weight);

    Car car_array[3] = { first_car, second_car, third_car };
    Truck truck_array[3] = { first_truck, second_truck, third_truck };


    //8)	Порядок розташування записів в текстовому файлі має відповідати пройденій машиною відстані, від найменшої до найбільшої.
    //Тут я викликаю раніше реалізовану функцію для сортування окремо car та truck. І якщо я правильно зрозумів, 
    // то знизу у файлі має бути найменше значення пройденого шляху, а зверху найбільше. 
    // Але головне це показати алгоритм я так поняв, тому там якщо треба то можна просто один знак змінити і все.
    Autossort(car_array, 3);
    Autossort(truck_array, 3);


    // А тут я вже порівнюю можливо пройдену максимальну дистанцію між елементами різних масивів і вивожу потрібні дані.
    int q = 0;
    int w = 0;
    while (q < 3 && w < 3) {
        double check1 = car_array[q].distance;
        double check2 = truck_array[w].distance;
        if (check1 >= check2) {
            car_array[q].writeOut(file);
            q++;
        }
        else {
            truck_array[w].writeOut(file);
            w++;
        }
        file << '\n';
    }

    // Вивід залишкових елементів, якщо є
    while (q < 3) {
        car_array[q].writeOut(file);
        file << '\n';
        q++;
    }

    while (w < 3) {
        truck_array[w].writeOut(file);
        file << '\n';
        w++;
    }

    //9)	Продемонструвати програму та створений файл викладачу
    file.close();  
    return 0;
}

/*
Mercedes, 5
Toyota, 3
BMW, 1
Audi, 4
Lada, 7
Shkoda, 9
*/
