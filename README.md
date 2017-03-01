# Median
This software is focused on providing a running median of a stream. It's based on the 
strategy pattern. Every algorithm exibits a specific sort of behaviour.

##STLPrioQFinderBehaviour
Based on a Priority Queue. It's based on the implementation of 2 heaps.
The complexity of finding a median is O(1), while the complexity of inserting O(log(N)),
while popping is O(2*log(N))

##BHFinderBehaviour
Same as, STLPrioQFinderBehaviour, except it's based on the implementation of STLPrioQFinderBehaviour

##FastMedianFinderBehaviour
Based on the implementation of 2 black red trees (self balancing). The complexity of finding the
median is O(1) (since we keep pointers to max and min elements of trees) + inserting an element is
O(log(N)).

## Suggestion: sorting a vector
Rather a crude approach : complexity of inserting and element and finding a median are both O(1).
Sorting the array with std::sort (quicksort, as used by Visual Studio) is  O(N log(N)) 
