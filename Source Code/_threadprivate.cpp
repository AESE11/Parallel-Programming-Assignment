#include <iostream>
#include <omp.h>
int localCounter = 0;
#pragma omp threadprivate(localCounter)
int main()
{
#pragma omp parallel
{
localCounter += 5;
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " Counter = "
<< localCounter
<< '\n';
}
return 0;
}