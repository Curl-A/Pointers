#include<iostream>
template<typename T>
class unique_ptr {
    private:
        T* ptr;

    public:
        //parameterized constructor for normal data types
        unique_ptr(T n) : ptr(new T(n)) { std::cout<<"Constructor1 called\n" ;}

        //parameterized constructor for pointer data types
        unique_ptr(T* p) : ptr(p) { std::cout<<"Constructor for pointer is called\n";}
        
        //delete copy constructor
        unique_ptr(const unique_ptr& other) = delete;

        //move constructor to transfer ownership
        unique_ptr(unique_ptr&& uptr) {
            ptr= uptr.ptr;
            uptr.ptr=nullptr;
        }
        
        ~unique_ptr(){ 
            std::cout<<"Destructor called\n";
            delete ptr;
        }
        // deferencing pointer
        T& operator*() { return *ptr;}

        //Arrow operator to allow unique_ptr to access
        
        T* operator->() { return ptr;}
};
//make_unique implementation, safer way to create unique pointer
template<typename T, typename... Args>
unique_ptr<T> make_unique(Args... args){
    return unique_ptr<T>(T(std::forward<Args>(args)...));
}

class Hello {
    public:
        void sayHello(){
            std::cout<<"Hello Aishwarya\n";
        }
};
int main() {
    unique_ptr<int> uptr(10);
    std::cout<<"Value of uptr: "<<*uptr;
    std::cout<<"\nTransferring ownership to uptr1\n";
    unique_ptr<int> uptr1(std::move(uptr));
    *uptr1=20;

    std::cout<<"after changing value of uptr1: "<<*uptr1<<std::endl;

    //creating object of class Hello using unique_ptr
    unique_ptr<Hello> hello(new Hello());
    hello->sayHello();

    //creating unique pointer using make_unique function
    unique_ptr<int> uptr3= make_unique<int>(10);

}