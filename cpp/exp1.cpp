#include <iostream>
#include <vector>
using namespace std;

//拉格朗日插值多项式
vector<double> lag1(vector<double> &x0, vector<double> &y0, vector<double> &x)
{
    vector<double> y;
    int n = x0.size();
    int m = y0.size();
    for (int i = 0; i < m; i++)
    {
        double z = x[i];
        double s = 0.0;
        for (int k = 0; k < n; k++)
        {
            double p = 1.0;
            for (int j = 0; j < n; j++)
            {
                if (j != k)
                {
                    p *= (z - x0[j]) / (x0[k] - x0[j]);
                }
            }
            s += p * y0[k];
        }
        y.push_back(s);
    }
    return y;
}

vector<double> newton(vector<double> &X, vector<double> &Y, vector<double> &x)
{
    int n = X.size();
    int m = Y.size();
    for (int i = 0; i < x.size(); i++)
    {
        
    }
}

int main()
{
    vector<double> x1 = {0.2, 0.4, 0.6, 0.8, 1.0};
    vector<double> y1 = {0.98, 0.92, 0.81, 0.64, 0.38};
    vector<double> x2 = {0, 1, 11, 10};
    for (int i = 0; i < x2.size(); i++)
    {
        x2[i] = 0.2 + 0.08 * x2[i];
    }
    vector<double> y2 = lag1(x1, y1, x2);
    for (int i = 0; i < y2.size(); i++)
    {
        cout << y2[i] << " ";
    }
    cout << endl;
    return 0;
}