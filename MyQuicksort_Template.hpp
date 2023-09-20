// Nyamtulla Shaik - 3106558
#ifndef _MY_QUICK_SORT_
#define _MY_QUICK_SORT_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>

const int BOUNDARY_SIZE = 10; // sort directly using insertion sort if the input size is smaller than BOUNRARY_SIZE

// Checks if an array is sorted
// a: input array to be checked
// reverse: if set true, check for descending order; otherwise ascending order
template <typename Comparable>
bool IsSorted( std::vector<Comparable> & a, bool reverse = false)
{
  if(a.size() <= 1) return true;
  bool sorted = true;
  for(size_t i = 0; i < a.size() - 1; ++ i)
  {
    if((a[i] > a[i + 1] && !reverse) || (a[i] < a[i + 1] && reverse))
    {
      sorted = false;
      std::cout << "Out of order: Positions: " << i << " : " << a[i] << "  " << a[i + 1] << std::endl;
      break;
    }
  }
  return sorted;
}

// Prints the array
// a: the array to be printed
template <typename Comparable>
void PrintArray( std::vector<Comparable> & a)
{
  for(size_t i = 0; i < a.size(); ++ i)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return;
}


// The insertion sort algorithm:
// a: the input array
// left and right: the left and end indexes of the range of the elements to be sorted, inclusive
// reverse: if set true, sort in descending order. Default: false
template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a , int left, int right, bool reverse = false)
{
  //std::cout <<"IN IS";
  // CODE BEGINS
  for (int i =left+1; i<=right; i++){
    Comparable key = a[i];
    int j = i-1;

  while (j>=left && ((a[j] > key && !reverse) || (a[j] < key && reverse))){
    a[j+1] = a[j];
     j--; 
  }
  a[j+1] = key;
  }
// for(int i = left+1; i<=right ; i++){
//     Comparable x = a[i];
//     int j = i - 1;
//     for(; j>=left && ((a[j] > x && !reverse) || (a[j] < x && reverse))  ; j--)
//       a[j+1] = a[j];
//     a[j+1] = x;
//   }
  // CODE ENDS
}


// Finds the median among three elements: a[x], a[y], and a[z]
// a: the array
// x, y, z: the three indexes in the array
// returns the index that corresponds to the median of the three
template <typename Comparable>
const size_t ArrayMedian3( std::vector<Comparable> & a, const size_t x, const size_t y, const size_t z)
{

  // CODE BEGINS
  if ((a[x] >= a[z] && a[x] <= a[y]) || (a[x] <= a[z] && a[x] >= a[y]))
    return x;
  else if ((a[y] >= a[x] && a[y] <= a[z]) || (a[y] <= a[x] && a[y] >= a[z]))
    return y;
  else
    return z;
  // CODE ENDS

}


template <typename Comparable>
int Partition( std::vector<Comparable> & a, int left, int right, bool reverse = false)
{
  // CODE BEGINS
  //std::cout <<"In P";
  int pivot_idx = ArrayMedian3(a, left, (left+right)/2, right);
  std::swap(a[pivot_idx], a[right]);
  Comparable pivot = a[right];
  
  int i = left -1;
  for(int j = left ; j < right ; j++){
    if(  (a[j] <= pivot && !reverse) ||  (a[j] >= pivot && reverse)  ){
      i++;
      std::swap(a[i], a[j]);
    }
  }

  std::swap(a[i+1], a[right]);


  return i + 1;
  // CODE ENDS
}


// The recursive quick sort function
// a: the array to be sorted
// left and right: the indexes for the range to be sorted, inclusive
// reverse: if set true, sort in descending order; otherwise in ascending order
template <typename Comparable>
void Quicksort( std::vector<Comparable> & a, int left, int right, bool reverse = false)
{
  // CODE BEGINS
 
  if( (right-left+1) < BOUNDARY_SIZE){
    InsertionSort(a, left, right, reverse);
    return;
  }
  else if(left < right){
    int pivot_idx = Partition(a, left, right, reverse);
    Quicksort(a, left, pivot_idx - 1, reverse);
    Quicksort(a, pivot_idx + 1, right, reverse);
  }
  // CODE ENDS
}




// The driver quicksort function
template <typename Comparable>
void Quicksort( std::vector<Comparable> & a, bool reverse = false)
{
  if(a.size() < BOUNDARY_SIZE)
    InsertionSort(a,0, a.size( ) - 1, reverse);
  else
  Quicksort( a, 0, a.size( ) - 1, reverse);
}


#endif