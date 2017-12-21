#include<string>
using namespace std;

class Sorting
{
  private:
    int numElements;
    double* array;
    double* unsortedArray;
  public:
    Sorting();
    ~Sorting();
    void countElements(string nameOfFile);
    int getNumElements();
    void setArray(string nameOfFile);
    void copyArray();
    void printArray();
    void bubbleSort();
    void insertionSort();
    int partition(int start, int end);
    void quickSort(int start, int end);
    void cocktailSort();

};
