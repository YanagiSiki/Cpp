#include "template.h"
//測試程式和 main 如下，不可修改

//移除之前先把最後一個元素輸出
template <class T>
void testVector(Vector<T> &theVector, // reference to Vector<T>
                T value,     // initial value to push，新增的初始值
                T increment, // increment for subsequent values，新增值每一次增加的量
                int push_count, // # of push，要新增幾個元素
                int pop_count,  // # of pop，要移除幾個元素
                const string vectorName){ // name of the Vector<T> object，此 vector的名字
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
