#include <iostream>
#include <omp.h>
int main()
{
int counter = 0;
#pragma omp parallel
{
int localValue = omp_get_thread_num() * 100;
std::cout
<< "Local Value = "
<< localValue
<< '\n';
#pragma omp atomic
counter++;
}
std::cout
<< "Threads executed = "
<< counter
<< '\n';
return 0;
}