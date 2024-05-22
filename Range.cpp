#include <iostream>
template <class T> class Range {
private:
  T Low;
  T High;

public:
  Range() {}
  Range(const T &low, const T &high) : Low(low), High(high) {}
  T low() const { return Low; }
  void low(const T &low) { Low = low; }
  T high() const { return High; }
  void high(const T &high) { High = high; }
  int contains(const T &value) const;
  int contains(const Range<T> &range) const;
  int operator==(const Range<T> &range) const;
};
// Definition of the contains function for checking if a value is within the range.
template <class T> 
int Range<T>::contains(const T &value) const
{
    // Returns true (1) if the value is greater than or equal to Low and less than or equal to High.
    return ((value >= Low) && (value <= High));
}

// Definition of the contains function for checking if another range is fully contained within the current range.
template <class T> 
int Range<T>::contains(const Range<T> &range) const
{
    // Returns true (1) if the low value of the given range is greater than or equal to Low,
    // and the high value of the given range is less than or equal to High.
    return ((range.low() >= Low) && (range.high() <= High));
}

// Definition of the equality operator for comparing two ranges for equality.
template <class T> 
int Range<T>::operator==(const Range<T> &range) const
{
    // Returns true (1) if both the low and high values of the given range are equal to the low and high values of the current range, respectively.
    return ((range.low() == Low) && (range.high() == High));
}


int main(){
    int low = 2;
    int high = 4;
    Range<int> Range1(low,high);
    Range<int> Range2(low,high);
    std::cout<<(Range1==Range2);
    // std::cout<<Range1.low()<<"\n";
    // std::cout<<Range1.high();

    return 0;
}