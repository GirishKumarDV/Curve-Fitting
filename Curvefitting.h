#ifndef CURVEFIT
#define CURVEFIT

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CurveFitting
{
    double x[10], y[10], a, b, c, count, sx;

public:
    void getData()
    {
        int i;
        cout << "Enter value of 'n' : ";
        cin >> count;
        cout << "Enter values of x\n";
        for (i = 0; i < count; i++)
            cin >> x[i];
        cout << "Enter values of y\n";
        for (i = 0; i < count; i++)
            cin >> y[i];
    }
    void straightLine();
    void parabola();
    void exponential();
    void solve()
    {
        int choice;
        cout << "\nDo you want to solve above equation for a given value of x?\nPress 1 for 'yes' and 0 for 'no : " << endl;
        cin >> choice;
        if (choice)
        {
            cout << "Enter value of x : ";
            cin >> sx;
        }
    }
};

void CurveFitting::straightLine()
{
    CurveFitting sl;
    sl.getData();
    int i;
    //Print Table for Straight line with fields ( x, y, x^2, xy)
    cout << "------------Table for Straight line-----------\n\n";
    cout << "x\t\ty\t\tx^2\t\t\txy\n\n";
    for (i = 0; i < sl.count; i++)
    {
        cout << sl.x[i] << "\t\t" << sl.y[i] << "\t\t" << (sl.x[i] * sl.x[i]) << "\t\t\t" << (sl.x[i] * sl.y[i]) << endl;
    }
    //Equatious to solve
    /*
aSUMx + nb = SUMy               (SUM = Summation symbol)
aSUMx2 + bSUMx = SUMxy
*/
    //Calculate all required data
    double SUMx = 0, SUMy = 0, SUMx2 = 0, SUMxy = 0;

    for (i = 0; i < sl.count; i++)
    {
        SUMx += sl.x[i];
        SUMy += sl.y[i];
        SUMx2 += (pow(sl.x[i],2.0));
        SUMxy += (sl.x[i] * sl.y[i]);
    }
    cout << "\nNormal Equations : \n"
         << endl;
    cout << SUMx << "a + " << sl.count << "b = " << SUMy << endl; //EQ 1
    cout << SUMx2 << "a + " << SUMx << "b = " << SUMxy << endl;   //EQ 2

    //TODO: Determine a, b

    sl.a = ((SUMy * SUMx) - (SUMxy * sl.count)) / ((SUMx * SUMx) - (sl.count * SUMx2));
    sl.b = ((SUMx * SUMxy) - (SUMy * SUMx2)) / ((SUMx * SUMx) - (sl.count * SUMx2));

    // FINAL EQUATION

    cout << "\nEquation of Straight Line : " << endl;
    cout << "\ny = " << setprecision(4)<<sl.a << "x + " << sl.b << setprecision(4) << endl;

    // Solve for given x
    sl.solve();
    cout << "\ny = " << ((sl.a * sl.sx) + sl.b) << endl
         << endl;

    //Refresh Summation values

    SUMx = SUMy = SUMx2 = SUMxy = 0;
}

void CurveFitting ::parabola()
{
    CurveFitting p;
    p.getData();
    int i;

    //Prepare Parabola Table

    cout << "\n------------Parabola Table------------\n\n";
    cout << "x\ty\tx^2\tx^3\tx^4\txy\tx^2y\n\n";
    for (i = 0; i < p.count; i++)
    {
        cout << p.x[i] << "\t" << p.y[i] << "\t" << setprecision(4) << pow(p.x[i], 2) << "\t" << setprecision(4) << pow(p.x[i], 3) << "\t" << setprecision(4) << pow(p.x[i], 4) << "\t" << setprecision(4) << (p.x[i] * p.y[i]) << "\t" << setprecision(4) << (p.y[i] * (p.x[i]*p.x[i])) << endl;
    }

    //Calculate required data and print normal equations
    /*
    Normal equations for parabola ( y = ax2 + bx +c) 
    -- SUMy = aSUMx2 + bSUMx + nC
    -- SUMxy = aSUMx3 + bSUMx2 + cSUMx
    -- SUMx2y = aSUMx4 + bSUMx3 + cSUMx2
    */
    double SUMx = 0, SUMy = 0, SUMx2 = 0, SUMx3 = 0, SUMx4 = 0, SUMxy = 0, SUMx2y = 0;
    for (i = 0; i < p.count; i++)
    {
        SUMx += p.x[i];
        SUMy += p.y[i];
        SUMx2 += pow(p.x[i], 2.0);
        SUMx3 += pow(p.x[i], 3.0);
        SUMx4 += pow(p.x[i], 4.0);
        SUMxy += (p.x[i] * p.y[i]);
        SUMx2y += (p.y[i] * (p.x[i] * p.x[i]));
    }
    //Normal equations
    cout << "\nNormal Equations : \n\n";
    cout << setprecision(4) << SUMx2 << "a + " << setprecision(4) << SUMx << "b + " << p.count << "c = " << setprecision(4) << SUMy << endl;
    cout << setprecision(4) << SUMx3 << "a + " << setprecision(4) << SUMx2 << "b + " << setprecision(4) << SUMx << "c = " << setprecision(4) << SUMxy << endl;
    cout << setprecision(4) << SUMx4 << "a + " << setprecision(4) << SUMx3 << "b + " << setprecision(4) << SUMx2 << "c = " << setprecision(4) << SUMx2y << endl;

    //TODO: Determine a,b,c;

    double D = (SUMx2 * ((SUMx2 * SUMx2) - (SUMx * SUMx3))) - (SUMx * ((SUMx3 * SUMx2) - (SUMx4 * SUMx))) + (p.count * ((SUMx3 * SUMx3) - (SUMx4 * SUMx2)));
    double Dx = (SUMy * ((SUMx2 * SUMx2) - (SUMx3 * SUMx))) - (SUMx * ((SUMxy * SUMx2) - (SUMx2y * SUMx))) + (p.count * ((SUMxy * SUMx3) - (SUMx2y * SUMx2)));
    double Dy = (SUMx2 * ((SUMxy * SUMx2) - (SUMx2y * SUMx))) - (SUMy * ((SUMx3 * SUMx2) - (SUMx4 * SUMx))) + (p.count * ((SUMx3 * SUMx2y) - (SUMx4 * SUMxy)));
    double Dz = (SUMx2 * ((SUMx2 * SUMx2y) - (SUMx3 * SUMxy))) - (SUMx * ((SUMx3 * SUMx2y) - (SUMx4 * SUMxy))) + (SUMy * ((SUMx3 * SUMx3) - (SUMx4 * SUMx2)));

    p.a = Dx / D;
    p.b = Dy / D;
    p.c = Dz / D;

    //Final Equation
    cout << "\nEquation of Parabola : ";
    cout << "y = " << setprecision(5) << p.a << "x^2 + " << setprecision(5) << p.b << "b + " << setprecision(5) << p.c << endl;

    //Final value
    p.solve();
    cout << "y = " << ((p.a * pow(p.sx, 2) + (p.b * p.sx) + p.c)) << endl;

    //Refresh summation values
    SUMx = SUMy = SUMx2 = SUMx3 = SUMx4 = SUMx2y = SUMxy = 0;
}

void CurveFitting ::exponential()
{
    CurveFitting e;
    e.getData();
    int i;
    //Create Table for exponential curve
    cout << "\n----------Exponential curve Table--------------" << endl;
    cout << "x\ty\tX(log x)\t\tY(log y)\t\tX2\t\tXY\n"
         << endl;
    for (i = 0; i < e.count; i++)
    {
        cout << e.x[i] << "\t" << e.y[i] << "\t" << setprecision(4) << log(e.x[i]) << "\t\t" << setprecision(4) << log(e.y[i]) << "\t\t" << setprecision(4) << pow(log(e.x[i]), 2) << "\t\t" << setprecision(4) << (log(e.x[i]) * log(e.y[i])) << endl;
    }

    /*
    Calculate required Data and print normal equations:
    y = ax^b
    log y = log a + b log x
    Y = A + bX
    Normal Equations:
    --- nA + bSUMX = SUMY
    --- ASUMX + bSUMX2 = SUMXY
    */
    double SUMX = 0, SUMY = 0, SUMX2 = 0, SUMXY = 0;
    for (i = 0; i < e.count; i++)
    {
        SUMX += log(e.x[i]);
        SUMY += log(e.y[i]);
        SUMX2 += (pow(log(e.x[i]), 2));
        SUMXY += (log(e.x[i]) * log(e.y[i]));
    }

    cout << "\nNormal Equations: \n"
         << endl;
    cout << e.count << "A + " << setprecision(4) << SUMX << "b = " << setprecision(4) << SUMY << endl;
    cout << setprecision(4) << SUMX << "A + " << setprecision(4) << SUMX2 << "b = " << setprecision(4) << SUMXY << endl;

    /*
   TODO: Solve for A and b
   A = log a
   a = e^A
   Substitute a and b in: y = ax^b
   */
    double A = ((SUMY * SUMX2) - (SUMX * SUMXY)) / ((e.count * SUMX2) - (SUMX * SUMX));
    e.b = ((e.count * SUMXY) - (SUMY * SUMX)) / ((e.count * SUMX2) - (SUMX * SUMX));
    e.a = exp(A);

    //FINAL EQUATION
    cout << "\nExponential Equation: " << endl;
    cout << "\ny = " << setprecision(4) << e.a << "x ^ " << setprecision(4) << e.b << endl;

    //Solve for given x
    e.solve();
    cout << "y = " << (e.a * pow(e.sx, e.b));

    //Refresh Summation values
    SUMX = SUMY = SUMXY = SUMX2 = 0;
}

#endif
