#include <iostream>
using namespace std;

class Rectange_Parralel {
private:
    double a;  
    double b;  
    double H;  

public:

    Rectange_Parralel(double sideA, double sideB, double height) {
        a = sideA;
        b = sideB;
        H = height;
    }

    double getSideA() {
        return a;
    }

    double getSideB() {
        return b;
    }

    double getHeight() {
        return H;
    }

 
    double calculateBaseArea() {
        return a * b;
    }


    double calculateSideArea() {
        return 2 * a * H;
    }


    double calculateTotalArea() {
        double baseArea = calculateBaseArea();
        double sideArea = calculateSideArea();
        return 2 * baseArea + sideArea;
    }


    double calculateVolume() {
        return a * b * H;
    }
};

int main() {
    setlocale(0, "Ru");
    Rectange_Parralel parallelepiped(3.0, 4.0, 5.0);
    double baseArea = parallelepiped.calculateBaseArea();
    double sideArea = parallelepiped.calculateSideArea();
    double totalArea = parallelepiped.calculateTotalArea();
    double volume = parallelepiped.calculateVolume();

    cout << "Исходный параллелепипед:" << endl;
    cout << "Площадь основания: " << baseArea << endl;
    cout << "Площадь боковой поверхности: " << sideArea << endl;
    cout << "Полная площадь: " << totalArea << endl;
    cout << "Объем: " << volume << endl;


    Rectange_Parralel doubledParallelepiped(2 * parallelepiped.getSideA(), 2 * parallelepiped.getSideB(), 2 * parallelepiped.getHeight());

    double doubledBaseArea = doubledParallelepiped.calculateBaseArea();
    double doubledSideArea = doubledParallelepiped.calculateSideArea();
    double doubledTotalArea = doubledParallelepiped.calculateTotalArea();
    double doubledVolume = doubledParallelepiped.calculateVolume();

    cout << "Новый параллелепипед (удвоенные параметры):" << endl;
    cout << "Площадь основания: " << doubledBaseArea << endl;
    cout << "Площадь боковой поверхности: " << doubledSideArea << endl;
    cout << "Полная площадь: " << doubledTotalArea << endl;
    cout << "Объем: " << doubledVolume << endl;

    return 0;
}
