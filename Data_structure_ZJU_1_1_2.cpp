#include <iostream>
using namespace std;
void printN1(int N)
{
    for(int i=0;i<N;i++)
    cout<<i<<endl;
}
void printN2(int N)
{
    if(N)
    printN2(N-1);
    cout<<N<<endl;
}
int main()
{
    printN1(1000);
    //printN2(1000);
}