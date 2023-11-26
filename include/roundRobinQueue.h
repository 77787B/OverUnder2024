#ifndef ROUNDROBINQUEUE_H_
#define ROUNDROBINQUEUE_H_

// use to simulate one round-robin queue for the data that calculate with cycles
// you can't change data with the access of brackets. in order to add data, use the function 'push()'

template <typename T>
class RoundRobinQueue{
public:
    RoundRobinQueue();
    RoundRobinQueue(int size);
    const T& operator[](int index);
    const T& getStart();
    int getstartIndex(){return _startIndex;}
    int getcurrentIndex(){return _currentIndex;}
    int size(){ return _size; }
    int validSize(){ return _validSize; }
    int cycle(){ return _cycle; }
    void push(const T& t);
    void clear();
    void renew();
private:
    long long _cycle;
    long _size;
    long _validSize;
    long _currentIndex;
    long _startIndex;
    T* pointer;
};

template<typename T>
inline RoundRobinQueue<T>::RoundRobinQueue():_cycle(0),_size(10),_validSize(0),_currentIndex(9),_startIndex(1),pointer(nullptr){
    pointer = new T[_size];
}

template<typename T>
inline RoundRobinQueue<T>::RoundRobinQueue(int size):_size(size),_currentIndex(size-1),_startIndex(1),_validSize(0),pointer(nullptr),_cycle(0){
    pointer = new T[_size];
}

template<typename T>
const T& RoundRobinQueue<T>::operator[](int index){
    return pointer[(( index % _size ) + _size + _currentIndex ) % _size];
}

template<typename T>
void RoundRobinQueue<T>::push(const T& t){
    _currentIndex =(_currentIndex+1)%_size;
    if(_startIndex>-_size) _startIndex--;
    if(_validSize < _size) _validSize++;
    _cycle++;
    pointer[_currentIndex] = t;
}
template<typename T>
void RoundRobinQueue<T>::clear(){
    _validSize=0;
    _currentIndex=_size-1;
    _startIndex=1;
}
template<typename T>
void RoundRobinQueue<T>::renew(){
    _currentIndex=10;
    _startIndex=-10;
}
template<typename T>
const T& RoundRobinQueue<T>::getStart(){
    return pointer[(( _startIndex % _size ) + _size + _currentIndex ) % _size];
}
#endif
