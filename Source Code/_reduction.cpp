#include <iostream>
#include <omp.h>
int main()
{
const int SIZE = 1000;
long long total = 0;
#pragma omp parallel for reduction(+:total)
for(int i = 1 ; i <= SIZE ; i++)
{
total += i;
}
std::cout
<< "Sum = "
<< total
<< '\n';
return 0;
}