// #ifndef _MY_QUICK_SORT_
// #define _MY_QUICK_SORT_

// #include <vector>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <assert.h>

// const int BOUNDARY_SIZE = 10; // sort directly using insertion sort if the input size is smaller than BOUNRARY_SIZE

// // Checks if an array is sorted
// // a: input array to be checked
// // reverse: if set true, check for descending order; otherwise ascending order
// template <typename Comparable>
// bool IsSorted( std::vector<Comparable> & a, bool reverse = false)
// {
//   if(a.size() <= 1) return true;
//   bool sorted = true;
//   for(size_t i = 0; i < a.size() - 1; ++ i)
//   {
//     if((a[i] > a[i + 1] && !reverse) || (a[i] < a[i + 1] && reverse))
//     {
//       sorted = false;
//       std::cout << "Out of order: Positions: " << i << " : " << a[i] << "  " << a[i + 1] << std::endl;
//       break;
//     }
//   }
//   return sorted;
// }

// // Prints the array
// // a: the array to be printed
// template <typename Comparable>
// void PrintArray( std::vector<Comparable> & a)
// {
//   for(size_t i = 0; i < a.size(); ++ i)
//   {
//     std::cout << a[i] << " ";
//   }
//   //std::cout << std::endl;
//   //std::cout << "Done";
//   return;
// }

// // Finds the median among three elements: a[x], a[y], and a[z]
// // a: the array
// // x, y, z: the three indexes in the array
// // returns the index that corresponds to the median of the three


// template <typename Comparable>
// void ArrayMedian3( std::vector<Comparable> & a, const size_t x, const size_t y, const size_t z)
// {
// //std::cout << "In Median" << std::endl;
// //CODE BEGINS
// // if(((a[x] <= a[y]) && (a[x]>= a[z])) || (a[x] <= a[z]) && (a[x]>= a[y])){
// //   return x;
// // }
// // else if(((a[y] <= a[x]) && (a[y]>= a[z])) ||((a[y] <= a[z]) && (a[y]>= a[x]))){
// //   return y;
// // }
// // else{return z;}

//   std::swap(a[y],a[z-1]);
//   if(a[x] > a[z-1]){
//     std::swap(a[x],a[z-1]);
//   }
//   if(a[x] > a[z]){
//     std::swap(a[z],a[x]);
//   }
//   if(a[z-1] > a[z]){
//     std::swap(a[z],a[z-1]);
//   }

//   // CODE ENDS

// }
// // The insertion sort algorithm:
// // a: the input array
// // left and right: the left and end indexes of the range of the elements to be sorted, inclusive
// // reverse: if set true, sort in descending order. Default: false
// template <typename Comparable>
// void InsertionSort( std::vector<Comparable> & a , int left, int right, bool reverse = false)
// {
//   // CODE BEGINS
//   //std::cout << "In IS"  << std::endl;
//   // for (int i =left+1; i< right+1; i++){
//   //   int key = a[i];
//   //   int j = i;
//   // if(!reverse){
//   // while (j> left && a[j-1]>key){
//   //   a[j] = a[j-1];
//   //   j--; 
//   // }
//   // }
//   // else{
//   //   while (j>left && a[j-1]<key){
//   //   a[j] = a[j-1];
//   //   j--; 
//   // }
//   // }
//   // a[j] = key;
//   // }
//   for(int i = left+1; i<=right ; i++){
//     Comparable x = a[i];
//     int j = i - 1;
//     for(; j>=left && ((a[j] > x && !reverse) || (a[j] < x && reverse))  ; j--)
//       a[j+1] = a[j];
//     a[j+1] = x;
//   }
//   // CODE ENDS
// }



// template <typename Comparable>
// int partition(std::vector<Comparable> & a, int left, int right, bool reverse){

//   int l = left;
//   int r = right;
//   int part = a[right];

//   if (right<= left){return left;}

//   while(true){
//     while (a[l] < part){l++;}
//     while( (part < a[r]) && l<r){r--;}

//     if (l>=r) {break;}
//     std::swap(a[l],a[r]);
//     l++;
//     r--; 
//   }
//   std::swap(a[l],a[right]);
//   return l;
//   }


// // The recursive quick sort function
// // a: the array to be sorted
// // left and right: the indexes for the range to be sorted, inclusive
// // reverse: if set true, sort in descending order; otherwise in ascending order
// template <typename Comparable>
// void Quicksort( std::vector<Comparable> & a, int left, int right, bool reverse = false)
// {
//   //std::cout << "In QS2" << std::endl;
//   // CODE BEGINS

//   if(right-left <= BOUNDARY_SIZE){
//     InsertionSort(a, left,right,reverse);
//     return;
//   }
//     ArrayMedian3(a, left , (right+left)/2, right);
//     int pivot = partition(a, left+1, right-1, reverse);
//     Quicksort(a, left, pivot-1, reverse);
//     Quicksort(a, pivot+1, right, reverse);

// }
//   // CODE ENDS


// // The driver quicksort function
// template <typename Comparable>
// void Quicksort( std::vector<Comparable> & a, bool reverse = false)
// {
//   //std::cout << "In QS1" << std::endl;
//   Quicksort( a, 0, a.size( ) - 1, reverse);

// }


// #endif

/*
Mohammed Misbah Zarrar
3104796
*/

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

template <typename Comparable>
void PrintArray( std::vector<Comparable> & a, int left, int right)
{
  for(size_t i = left; i <= right; ++ i)
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
  // CODE BEGINS

  for(int i = left+1; i<=right ; i++){
    Comparable x = a[i];
    int j = i - 1;
    for(; j>=left && ((a[j] > x && !reverse) || (a[j] < x && reverse))  ; j--)
      a[j+1] = a[j];
    a[j+1] = x;
  }

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
  if ((a[x] >= a[y] && a[x] <= a[z]) || (a[x] <= a[y] && a[x] >= a[z]))
    return x;
  else if ((a[y] >= a[x] && a[y] <= a[z]) || (a[y] <= a[x] && a[y] >= a[z]))
    return y;
  else
    return z;
  // CODE ENDS

}




template <typename Comparable>
void swap(Comparable &a, Comparable &b)
{
  Comparable temp = a;
  a = b;
  b = temp;
}

template <typename Comparable>
int Partition( std::vector<Comparable> & a, int left, int right, bool reverse = false)
{
  // CODE BEGINS
  int pivot_idx = ArrayMedian3(a, left, right, (left+right)/2);
  Comparable pivot = a[pivot_idx];
  swap(a[pivot_idx], a[right]);
  pivot_idx = right;
  
  //std::cout<<"Pivot: "<<pivot<< std::endl;

  
  int i = left -1;
  for(int j = left ; j < right ; j++){
    if(  (a[j] <= pivot && !reverse) ||  (a[j] >= pivot && reverse)  ){
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i+1], a[pivot_idx]);

  //std::cout<<"Sorted: ";
  //PrintArray(a, left, right);

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
  if(a.size() < BOUNDARY_SIZE)
    InsertionSort(a, left, right, reverse);
  
  if(left < right){
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
  Quicksort( a, 0, a.size( ) - 1, reverse);
}


#endif