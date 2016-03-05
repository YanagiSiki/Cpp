#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <typename T>
class Vector {
public:
    // default constructor (size 5)
    // �w�]�j�p�O5�A�]�i�H�ھڶǶi�Ӫ��Ѽưt�m�Ŷ��j�p
    Vector(int = 5);

    // �R���t�m�������Ŷ�
    ~Vector();

    //Adds a new element at the end of the vector,
    // after its current last element.
    // �b�̫᭱�s�W�[�@�Ӥ����A�@�}�l�b�� 0 �ӪŶ��C
    // �Y�[�J��Ŷ��ݨD�W�L�غc�l�@�}�l�t�m���Ŷ��j�p�A
    // �h�������s�t�m��j���Ŷ��A�j�p�� size+resize�Aresize���D�]�w�� 5 �C
    void push_back (const T &);

    //Removes the last element in the vector.
    //�����̫�@�Ӥ���
    bool pop_back(T &);

    //Returns whether the vector is empty (size is 0).
    bool isEmpty() const;

    //Returns a reference to the last element in the vector.
    //�^�ǳ̫�@�Ӥ����C
    bool back(T &) const;
private:
    // # of resize
    // �Y�[�J��Ŷ��ݨD�W�L�غc�l�@�}�l�t�m���Ŷ��j�p�A
    // �h���s�t�m�s�W�j�p�� resize ���D�]�w�� 5
    static const int resize=5;

    // # of elements
    // �ثevector �Ŷ��j�p
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


