#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>


/*����������� ������ 7
* ������� ��� ���������
������ 2
1)	�������� ���� � ���� Auto. � ������ ���� �������� ����, � ���� �������� ����� (�����) ������, �ᒺ� ������ � ���� (�� 50 �� 100 ����) �� ������ ������� ������ �� ������� ����� (�� 5 �� 10 �/100 ��).
2)	������ ����������� �� ���������� �����.
3)	� ���� ���������� �������-�����, ��� ������� �������, ��� ���� ������� ������ ��� ��������� ��������. 
4)	�� ����� ����� Auto �������� ��� �����-�������: �������� ��������� (Car) �� ��������� (Truck). � ���� Car ������ ����, �� ���� ������� ������� �������� (�� 0 �� 5), � ���� Truck � ����, �� ���� ������� ���� ������� (�� 0 �� 10 ���).
5)	� ���� ������ ������������� ������� ���������� ������, ��������, �� ����� ������� ������ ������ ������� ������ �� 5%, � ����� ����� ���� � �� 10%. 
6)	�������� � ��������� ��� ��� 3 �ᒺ��� ����� Car �� 3 �ᒺ��� ����� Truck. ����� �� ������� �������� �� ���� ������� ��������� � ���������, �ᒺ� ������ � ���� �� ������ ������� ������ ����������� ���������� ����� �� ��������� ������� rand()���, ��� ���� ���������� � ������ � ����� 1) ���������. 
7)	�������� ��������� ���� � ������ �Laba7.txt� �� ��������� � ����� ��� ���������� ��� �� �ᒺ��� ����� Car �� Truck. ³������������ ��� � �������� ��� ������� ������.
8)	������� ������������ ������ � ���������� ���� �� ��������� �������� ������� ������, �� �������� �� ��������.
9)	���������������� �������� �� ��������� ���� ���������*/



//1)	�������� ���� � ���� Auto. � ������ ���� �������� ����, � ���� �������� ����� (�����) ������, �ᒺ� ������ � ���� (�� 50 �� 100 ����) �� ������ ������� ������ �� ������� ����� (�� 5 �� 10 �/100 ��).


class Auto {
public:
    std::string brand;
    int volume;
    int efficiency;
    //2)	������ ����������� �� ���������� �����.
    Auto(std::string brand, int volume, int efficiency)
        : brand(brand), volume(volume), efficiency(efficiency) {}
    //3)	� ���� ���������� �������-�����, ��� ������� �������, ��� ���� ������� ������ ��� ��������� ��������. 
    virtual double distance_limit() const {
        return volume / efficiency;
    }

    virtual void writeOut(std::ofstream& file) const {
        file << "Brand:" << brand << "\tVolume: " << volume;
    }
    //2)	������ ����������� �� ���������� �����.
    ~Auto() {
    
    }
};


//4)	�� ����� ����� Auto �������� ��� �����-�������:
//5)	� ���� ������ ������������� ������� ���������� ������, ��������, �� ����� ������� ������ ������ ������� ������ �� 5%, � ����� ����� ���� � �� 10%. 
// �������� ��������� (Car)
class Car : public Auto {
public:
    // � ���� Car ������ ����, �� ���� ������� ������� �������� (�� 0 �� 5)
    int passangers;
    Car(std::string brand, int volume, int efficiency, int passangers)
        : Auto(brand, volume, efficiency), passangers(passangers) {}
    //������� ������ ������ ������� ������ �� 5 %
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



//��������� (Truck)
class Truck : public Auto {
public:
    // ������ � ���� Truck ����, �� ���� ������� ���� �������(�� 0 �� 10 ���).
    int weight;
    Truck(std::string brand, int volume, int efficiency, int weight)
        : Auto(brand, volume, efficiency), weight(weight) {}
    //����� ����� ���� ������ ������� ������ �� 10%
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
                // ���� ��������, ���� �������
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
                // ���� ��������, ���� �������
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
    //7)	�������� ��������� ���� � ������ �Laba7.txt� �� ��������� � ����� ��� ���������� ��� �� �ᒺ��� ����� Car �� Truck.³������������ ��� � �������� ��� ������� ������.
    std::ofstream file("Laba7.txt");  // ³�������� ���� ��� ������

    if (!file.is_open()) {
        std::cout << "Unable to open file for writing." << std::endl;
        return 1;
    }

    std::string brand;
    int passangers;
    //6)	�������� � ��������� ��� ��� 3 �ᒺ��� ����� Car �� 3 �ᒺ��� ����� Truck.
    //      ����� �� ������� �������� �� ���� ������� ��������� � ���������, 
    //      �ᒺ� ������ � ���� �� ������ ������� ������ ����������� ���������� ����� 
    //      �� ��������� ������� rand()���, ��� ���� ���������� � ������ � ����� 1) ���������.
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


    //8)	������� ������������ ������ � ���������� ���� �� ��������� �������� ������� ������, �� �������� �� ��������.
    //��� � �������� ����� ���������� ������� ��� ���������� ������ car �� truck. � ���� � ��������� �������, 
    // �� ����� � ���� �� ���� �������� �������� ���������� �����, � ������ ��������. 
    // ��� ������� �� �������� �������� � ��� �����, ���� ��� ���� ����� �� ����� ������ ���� ���� ������ � ���.
    Autossort(car_array, 3);
    Autossort(truck_array, 3);


    // � ��� � ��� ������� ������� �������� ����������� ��������� �� ���������� ����� ������ � ������ ������ ���.
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

    // ���� ���������� ��������, ���� �
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

    //9)	���������������� �������� �� ��������� ���� ���������
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
