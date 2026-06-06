#include <iostream>
#include <omp.h>
int main()
{
#pragma omp parallel
{
int id = omp_get_thread_num();
std::cout << "Thread " << id
<< " is working\n";
#pragma omp master
{
std::cout
<< "\nMaster Thread = "
<< id
<< "\nPreparing final report...\n";
}
}
return 0;
}