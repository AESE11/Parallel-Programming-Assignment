#include <iostream>
#include <omp.h>
int main()
{
#pragma omp parallel
{
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " entered region\n";
#pragma omp single
{
std::cout
<< "\nOnly one thread loads data\n";
}
}
return 0;
}