#include <iostream>
#include "Curvefitting.h"

int main(void)
{
    CurveFitting t1;
    int choice;
    while (1)
    {
        cout << "\n\n---MOD4 (CURVE FITTING)----\n1. Fit a Straight line (y = ax + b)\n2. Fit a Parabola (y = ax^2 + bx + c)\n3. Fit exponential curve ( y = ax^b)\n4. Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t1.straightLine();
            break;
        case 2:
            t1.parabola();
            break;
        case 3:
            t1.exponential();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "INVALID ENTRY!" << endl;
        }
    }
}