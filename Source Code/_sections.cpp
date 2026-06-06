#include <iostream>
#include <omp.h>
void TaskA()
{
std::cout << "Task A executed\n";
}
void TaskB()
{
std::cout << "Task B executed\n";
}
void TaskC()
{
std::cout << "Task C executed\n";
}
int main()
{
#pragma omp parallel
{
#pragma omp sections
{
#pragma omp section
TaskA();
#pragma omp section
TaskB();
#pragma omp section
TaskC();
}
}
return 0;
}