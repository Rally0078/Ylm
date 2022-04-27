#include "ylm.h"

unsigned int factorial(unsigned int num)
{
    if(num == 0u || num == 1u)
        return 1u;
    long product = 1l;
    while(num!=0)
    {
        product = product * num;
        --num;
    }
    return product;
}
std::complex<double> Ylm(unsigned int n, unsigned int m, double theta, double phi)
{
    double Pnm;
    Pnm = std::assoc_legendre(n, m, std::cos(theta));
    std::complex<double> result;
    std::complex<double> phase = std::complex<double>(std::cos(m*phi),std::sin(m*phi));
    result = Pnm * std::sqrt((2*n+1)/(4.0*std::numbers::pi) * double(factorial(n-m))/double(factorial(n+m))) * phase;
    if(m%2!=0)
        result = result * -1.0;
    return result;
}
