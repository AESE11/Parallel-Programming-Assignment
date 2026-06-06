#include <iostream>
#include <omp.h>
int main()
{
int startValue = 10;
#pragma omp parallel firstprivate(startValue)
{
startValue += omp_get_thread_num();
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " Value = "
<< startValue
<< '\n';
}
std::cout
<< "Original Value = "
<< startValue
<< '\n';
return 0;
}