#include <iostream>
using namespace std;
bool isPrime(int N)
{
    for(int i=2; i*i<=N; i++)
        if(N%i==0)
            return false;
    return true;
}
int F(int N)
{
    if(N==1)
        return 0;
    else if(isPrime(N))
        return N-1+F(N-1);
    else
        for(int i=2; i<N; i++)
            if(N%i==0)
                return F(i)+F(N/i);
}
int main()
{
    int N;
    cin>>N;
    cout<<F(N)<<endl;
    return 0;
}