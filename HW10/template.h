#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <typename T>
class Vector {
public:
    // default constructor (size 5)
    // 預設大小是5，也可以根據傳進來的參數配置空間大小
    Vector(int = 5);

    // 刪除配置的元素空間
    ~Vector();

    //Adds a new element at the end of the vector,
    // after its current last element.
    // 在最後面新增加一個元素，一開始在第 0 個空間。
    // 若加入後空間需求超過建構子一開始配置的空間大小，
    // 則必須重新配置更大的空間，大小為 size+resize，resize本題設定為 5 。
    void push_back (const T &);

    //Removes the last element in the vector.
    //移除最後一個元素
    bool pop_back(T &);

    //Returns whether the vector is empty (size is 0).
    bool isEmpty() const;

    //Returns a reference to the last element in the vector.
    //回傳最後一個元素。
    bool back(T &) const;
private:
    // # of resize
    // 若加入後空間需求超過建構子一開始配置的空間大小，
    // 則重新配置新增大小為 resize 此題設定為 5
    static const int resize=5;

    // # of elements
    // 目前vector 空間大小
    int size;
    int top;  // location of the top element (-1 empty)
    T* ptr;  // pointer to internal representation
};




template <typename T>
Vector< T > ::Vector(int x){
    size=x;
    top=-1;
    ptr=new T[size];
}

template <typename T>
Vector< T > ::~Vector(){
    delete []ptr;
}

template <typename T>
void Vector< T > ::push_back (const T &push_value){
    if(top==size-1){
        size=size+resize;
    }
    top++;
    ptr[top]=push_value;
}
template <typename T>
bool Vector< T > ::pop_back(T &back_value){
    cout<<"1 ";
    if(isEmpty()==0){
        back_value=ptr[top];
        top--;
        return 1;
    }
    return 0;
}
template <typename T>
bool Vector< T > ::isEmpty() const{
    if(top==-1)return 1;
    return 0;
}
template <typename T>
bool Vector< T > ::back(T &back_value) const{
    if(isEmpty()==0){
        back_value=ptr[top];
        return 1;
    }
    return 0;
}


