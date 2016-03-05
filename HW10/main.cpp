#include "template.h"
//���յ{���M main �p�U�A���i�ק�

//�������e����̫�@�Ӥ�����X
template <class T>
void testVector(Vector<T> &theVector, // reference to Vector<T>
                T value,     // initial value to push�A�s�W����l��
                T increment, // increment for subsequent values�A�s�W�ȨC�@���W�[���q
                int push_count, // # of push�A�n�s�W�X�Ӥ���
                int pop_count,  // # of pop�A�n�����X�Ӥ���
                const string vectorName){ // name of the Vector<T> object�A�� vector���W�r
                    int i;
                    T tmp_value=value;
                    cout<<"Pushing elements onto "<<vectorName<<endl;

                    for(i=0;i<push_count;i++){
                        tmp_value=tmp_value+increment;
                        theVector.push_back(tmp_value);
                    }
                    //cout<<"*"<<endl;
                    for(i=0;i<pop_count;i++){
                        if(theVector.isEmpty()==1){
                            cout<<"Vector is empty. Cannot pop"<<endl;
                            break;
                        }
                        //theVector.back(tmp_value);
                        theVector.pop_back(tmp_value);
                        cout<<tmp_value<<endl;
                    }



                }


int main() {
    Vector <double> v1(3);
    Vector <int> v2(3);
    double x1=1.25, inc1=1.0;
    int x2=3, inc2=2;
    testVector(v1, x1, inc1, 6, 7, "double");
    testVector(v2, x2, inc2, 7, 8, "int");

    return 0;
}
