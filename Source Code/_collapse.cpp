#include <iostream>
#include <omp.h>
int main()
{
const int rows = 4;
const int cols = 5;
int matrix[rows][cols];
#pragma omp parallel for collapse(2)
for(int i=0;i<rows;i++)
{
for(int j=0;j<cols;j++)
{
matrix[i][j] = i + j;
}
}
std::cout
<< "Matrix filled successfully\n";
return 0;
}