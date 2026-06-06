#include <iostream>
#include <omp.h>
int main()
{
int sharedValue;
#pragma omp parallel private(sharedValue)
{
#pragma omp single copyprivate(sharedValue)
{
sharedValue = 999;
}
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " Received "
<< sharedValue
<< '\n';
}
return 0;
}