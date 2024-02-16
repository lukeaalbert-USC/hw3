#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <iostream> //delete me
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  /**
   * @brief helper function to push
   * 
   */
  void trickleUp(int loc);
  void trickleDown(int loc);
  int findBest(int loc);

  /**
   * @brief Vector to hold data
   * 
   */
  std::vector<T> data;

  size_t _m;
  PComparator _c;
};


/**
 * --------------------------------------------------------
 * --------------------------------------------------------
 * --------------------------------------------------------
 * --------------------------------------------------------
 */

//trickle it up!
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
  int parent = (loc - 1)/_m; //assuming this works...

  while (loc >= 1 && _c(data[loc],data[parent]) ) //ASSUMING SECOND PARAMETER WORKS!
  {
    std::swap(data[loc], data[parent]);
    loc = parent;
    parent = (loc - 1)/_m;
  }
  std::cout << "parent after trickleup: " << data[0] << std::endl;
}

//trickle it DOWNNNN!
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc)
{
  int child = findBest(loc);
  while (child != -1 && _c(data[child], data[loc]))
  {
    std::swap(data[loc], data[child]);
    loc = child;
    child = findBest(loc);
  }
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::findBest(int loc)
{ 
  int bestChild = -1;
  int startChild = _m * loc + 1;
  int endChild = std::min(static_cast<size_t>(startChild + _m), data.size());
  for (int i = startChild; i < endChild; ++i)
  {
    if (bestChild == -1 || _c(data[i], data[bestChild]))
    {
      bestChild = i;
    }
  }

  return bestChild;
}

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): _m(m), _c(c) {}

//deconstructor (no work needed)
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}


//PUSH IT!
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  if (size() == 1) {return;}
  trickleUp(size() - 1); //impliment trickle Up
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::out_of_range("Heap is empty.");
  }
  return data[0];
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::out_of_range("Cannot pop from empty heap.");
  }

  if (size() == 1) {data.pop_back(); return;}
  std::swap(data[0], data[size() -1]); //swap (at least 2 items to swap)

  std::cout << "back element (about to be popped): " << data[size() -1] << std::endl;
  data.pop_back();

  if (size() == 1) {return;} //No need to trickle. Only 1 item left.

  trickleDown(0); //0 indicates first index of data.
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}

#endif

