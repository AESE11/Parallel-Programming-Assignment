#include <iostream>
#include <omp.h>
int main()
{
int balance = 1000;
omp_set_num_threads(5);
#pragma omp parallel
{
int id = omp_get_thread_num();
if(id % 2 == 0)
{
#pragma omp atomic
balance += 25;
}
else
{
#pragma omp atomic
balance -= 10;
}
}
std::cout
<< "Final Balance = "
<< balance
<< '\n';
return 0;
}