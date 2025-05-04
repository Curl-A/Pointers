// shared pointer implementation which shows memory leak
#include<iostream>
template<typename T>
class shared_ptr {
    private:
        T* ptr;

    public:
    static int ref_count; // static variable can be declared,we need to define & initialize outside of class

    //Constructor
    shared_ptr(T n):ptr(new T(n)){
        std::cout<<"Constructor to create object with value "<<n<<" is called\n";
        ref_count++;
    }

    //Copy Constructor
    shared_ptr(const shared_ptr& other){
        std::cout<<"Object copied\n";
        ptr=other.ptr;        //creating pointer with existing pointer value so that it can point to same memory location
        ref_count++;
    }

    ~shared_ptr(){
        std::cout<<"Destuctor called\n";
        if(ref_count==1){
            std::cout<<"Pointer "<<ptr<<" deleted\n";
            delete ptr;
        }
        ref_count--;
    }
};
template<typename T>
int shared_ptr<T>::ref_count=0;
int main() {
    shared_ptr<int> sptr(10);
    //shallow copy
    shared_ptr<int> sptr1(sptr);
    shared_ptr<int> sptr2(30);

    // memory layout
    
    // objects sptr, sptr1, sptr2 will be stored on stack, these are just variables
    // values 10 and 30 will be stored on heap memory
    
    // Here sptr(10) means it will create object "sptr" of shared_ptr class which will be stored on stack, 
    // which in turn, creates a pointer (will be stored on stack) that points to the value 10 stored on heap memory.

}
