#include <iostream>
using namespace std;


int main()
{
    double n;
    cin >> n;
    double l = -10000;
    double r = 10000;
    while(r - l > 1e-8)
    {
       double mid = (r+l) / 2;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%lf\n",l);
}