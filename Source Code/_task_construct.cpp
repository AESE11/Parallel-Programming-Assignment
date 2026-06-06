#include <iostream>
#include <omp.h>
void Work(int value)
{
std::cout
<< "Task "
<< value
<< " executed by thread "
<< omp_get_thread_num()
<< '\n';
}
int main()
{
#pragma omp parallel
{
#pragma omp single
{
for(int i=1;i<=5;i++)
{
#pragma omp task firstprivate(i)
Work(i);
}
}
}
return 0;
}