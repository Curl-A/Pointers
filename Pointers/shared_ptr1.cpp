// shared pointer implementation
#include<iostream>
template<typename T>
class shared_ptr {
    private:
        T* ptr;
        int* ref_count=0;

    public:
    //Constructor
    shared_ptr(T n):ptr(new T(n)),ref_count(new int(1)){
        std::cout<<"Constructor to create object with value "<<n<<" is called\n";
        ++(*ref_count);
    }

    //Copy Constructor
    shared_ptr(const shared_ptr& other){
        std::cout<<"Object copied\n";
        ptr=other.ptr;        //creating pointer with existing pointer value so that it can point to same mem loc
        ref_count = other.ref_count;
        ++(*ref_count);
    }

    ~shared_ptr(){
        std::cout<<"Destuctor called\n";
        if(--(*ref_count)==1){
            std::cout<<"Pointer "<<ptr<<" deleted\n";
            delete ptr;
            delete ref_count;
        }
    }
};
int main() {
    shared_ptr<int> sptr(10);

    //shallow copy
    shared_ptr<int> sptr1(sptr);

    shared_ptr<int> sptr2(30);

}
