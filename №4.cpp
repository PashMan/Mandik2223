#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {
protected:
    double x;
    double y;

public:
    Vector2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double getLength() const {
        return sqrt(x * x + y * y);
    }

    void print() const {
        cout << "Vector2D: (" << x << ", " << y << "), Length: " << getLength() << endl;
    }
};

class Vector3D : public Vector2D {
private:
    double z;

public:
    Vector3D(double xCoord, double yCoord, double zCoord) : Vector2D(xCoord, yCoord), z(zCoord) {}

    double getLength() const {
        return sqrt(x * x + y * y + z * z);
    }

    void print() const {
        cout << "Vector3D: (" << x << ", " << y << ", " << z << "), Length: " << getLength() << endl;
    }
};

int main() {
    Vector2D v2D(3.0, 4.0);
    v2D.print();

    Vector3D v3D(1.0, 2.0, 3.0);
    v3D.print();

    Vector2D* basePtr = &v3D;
    basePtr->print();

    return 0;
}
