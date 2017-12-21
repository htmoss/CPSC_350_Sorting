#include<string>
#include<iostream>
#include<fstream>
#include "Sorting.h"
#include<cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
  string f = argv[1];

  if ( argc != 2 )
  {
    cout<<"usage: "<< argv[0] <<" <filename>\n";
  }
  else
  {
    Sorting sort;
    //opening file
    string nameOfFile = argv[1];
    ofstream outputFile(nameOfFile);
    for(int i = 0; i < 1000; ++i)//amount of numbers wanted to be sorted
    {
      double a = (rand() / (RAND_MAX + 1.0))*1000;
      outputFile<<a<<' ';
    }
    outputFile.close();

    sort.countElements(nameOfFile);

    sort.setArray(nameOfFile);
    sort.copyArray();

    //cout<<"\n\noriginal array:\n";
    //sort.printArray();

    //BUBBLE SORT
    clock_t startTime = clock();
    sort.bubbleSort();
    clock_t endTime = clock();
    cout<<"\n\nTime for bubble sort: "<<((endTime-startTime)/(double)CLOCKS_PER_SEC)<<" seconds"<<endl;
    //cout<<"Sorted List of Doubles:"<<endl;
    //sort.printArray();
    sort.copyArray(); //makes array unsorted again

    //INSERTION SORT
    startTime = clock();
    sort.insertionSort();
    endTime = clock();
    cout<<"\n\nTime for insertion sort: "<<((endTime-startTime)/(double)CLOCKS_PER_SEC)<<" seconds"<<endl;
    //cout<<"Sorted List of Doubles:"<<endl;
    //sort.printArray();
    sort.copyArray(); //makes array unsorted again

    //QUICK SORT
    startTime = clock();
    sort.quickSort(0, sort.getNumElements()-1);
    endTime = clock();
    cout<<"\n\nTime for quick sort: "<<((endTime-startTime)/(double)CLOCKS_PER_SEC)<<" seconds"<<endl;
    //cout<<"Sorted List of Doubles:"<<endl;
    //sort.printArray();
    sort.copyArray(); //makes array unsorted again

    //COCKTAIL SORT
    startTime = clock();
    sort.cocktailSort();
    endTime = clock();
    cout<<"\n\nTime for cocktail sort: "<<((endTime-startTime)/(double)CLOCKS_PER_SEC)<<" seconds"<<endl;
    //cout<<"Sorted List of Doubles:"<<endl;
    //sort.printArray();

    return 0;
  }
}
