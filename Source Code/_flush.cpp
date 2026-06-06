#include <iostream>
#include <omp.h>
int main()
{
int flag = 0;
#pragma omp parallel sections shared(flag)
{
#pragma omp section
{
flag = 1;
#pragma omp flush(flag)
}
#pragma omp section
{
int temp;
do
{
#pragma omp flush(flag)
temp = flag;
}
while(temp == 0);
std::cout
<< "Flag updated successfully\n";
}
}
return 0;
}