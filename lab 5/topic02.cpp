#include<bits/stdc++.h>
using namespace std;
class Circuit{
private:
    float real;
    float img;
public:
    Circuit(float r, float i)
    {
        real = r;
        img = i;
    }
    Circuit operator+(Circuit &other)
    {
        Circuit t(real + other.real, img + other.img);
        return t;
    }
    Circuit operator*(Circuit &other)
    {
        int REAL = (real * other.real) - (img * other.img);
        int IMG = (real * other.img) + (img * other.real);

        Circuit t(REAL, IMG);
        return t;
    }
    Circuit operator/(Circuit &other){
        float REAL = ((real * other.real) + (img * other.img)) / (1.0 * ((other.real * other.real) + (other.img * other.img)));
        float IMG = ((img * other.real) - (real * other.img)) / (1.0 * ((other.real * other.real) + (other.img * other.img)));
        Circuit t(REAL, IMG);
        return t;
    }

    void display()
    {
        cout << "(" << real << ")"<< " + "<< "(" << img << ")"<< "j"<<endl;
    }
};

int main()
{
    Circuit z1(3, 4);
    Circuit z2(4, -3);
    Circuit z3(0, 6);

    Circuit z2z3 = z2 * z3;
    Circuit z1z3 = z1 * z3;
    Circuit z1z2 = z1 * z2;

    Circuit topPart = z1 * z2 * z3;

    Circuit bottomPart = z1z3 + z2z3 + z1z2;

    Circuit totalImpedance = topPart / bottomPart;

    Circuit inputVoltage(100, 50);

    cout << "Total Impedance: ";
    totalImpedance.display();
    cout << "Input Voltage: ";
    inputVoltage.display();

    Circuit current = inputVoltage / totalImpedance;
    cout << "Current: ";
    current.display();

    return 0;
}
