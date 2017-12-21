#include<string>
#include<iostream>
#include "sorting.h"
#include<fstream>
#include<cstdlib>
#include<math.h>
#include<cmath>
using namespace std;

//constructor
Sorting::Sorting()
{
  numElements = 0;
}
//deconstructor
Sorting::~Sorting()
{
  delete array;
  cout<<"Object Deleted"<<endl;
}

//calculates the number of elements being sorted from the input file
void Sorting::countElements(string nameOfFile)
{
  ifstream outputFile;
  outputFile.open(nameOfFile);

  int count = -1;
  double current = 0.0;

  if(!outputFile.is_open())
  {
    exit(EXIT_FAILURE);
  }
  while(outputFile.good())
  {
    outputFile>>current;
    count++;
  }
  numElements = count;

  outputFile.close();
}

//returns the number of elements being sorted
int Sorting::getNumElements()
{
  return numElements;
}

//fills up array with data from input file
void Sorting::setArray(string nameOfFile)
{

  array = new double[numElements];
  unsortedArray = new double[numElements];
  ifstream outputFile;
  outputFile.open(nameOfFile);
  double number = 0.0;
  for(int i = 0; i < numElements; ++i)
  {
    outputFile>>number;
    unsortedArray[i] = number;
  }
  outputFile.close();
}

//prints out array to cout
void Sorting::printArray()
{
  for(int i = 0; i < numElements; ++i)
  {
    cout<<array[i]<<" ";
  }
}

//makes array a copy of unsortedArray
void Sorting::copyArray()
{
  for(int i = 0; i < numElements; ++i)
  {
    array[i] = unsortedArray[i];
  }
}

void Sorting::bubbleSort()
{
  double swap = 0.0;
  for (int c = 0 ; c < numElements-1; ++c)
  {
    for (int d = 0 ; d < numElements-c-1; ++d)
    {
      if (array[d] > array[d+1])
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
}

void Sorting::insertionSort()
{
  for(int i = 0; i < numElements; ++i)
  	{
  		int j = i;
  		while(j > 0 && array[j] < array[j-1])
  		{
  			double temp = array[j];
  			array[j] = array[j-1];
  			array[j-1] = temp;
  			--j;
  		}
  	}
}

//part of quicksort algorithm, calculates for partitionIndex
int Sorting::partition(int start, int end)
{
  int pivot = array[end];
  int partitionIndex = start;
  double temp;
  for(int i = start; i < end; ++i)
  {
    if(array[i] < pivot)
    {
      temp = array[i]; //swapping i and pivot values
			array[i] = array[partitionIndex];
			array[partitionIndex] = temp;
      ++partitionIndex;
    }
  }
  temp = array[partitionIndex]; //swapping i and pivot values
  array[partitionIndex] = array[end];
  array[end] = temp;
  return partitionIndex;
}

void Sorting::quickSort(int start, int end)
{
  if (start < end)
  {
    int partitionIndex = partition(start, end);
    quickSort(start, partitionIndex - 1);
    quickSort(partitionIndex+1, end);
  }
}

//more efficient form of bubbleSort
void Sorting::cocktailSort()
{
  int ready;
  double temp;

  do
  {
    ready = 0;
    for(int i = getNumElements() - 1; i > 0; --i)
    {
      if(array[i-1] > array[i])
      {
        temp = array[i-1];
        array[i-1] = array[i];
        array[i] = temp;
        ready = 1;
      }
    }
    for(int i = 1; i < getNumElements(); ++i)
    {
      if(array[i-1] > array[ i ])
      {
        temp = array[i-1];
        array[i-1] = array[i];
        array[i] = temp;
        ready = 1;
      }
    }
  } while(ready);

}
