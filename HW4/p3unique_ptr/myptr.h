#include <iostream>
using namespace std;

template <class T>
class my_ptr
{
    private:
        T *ptr;
        static T *protect;

    public:
        my_ptr(T* _ptr) : ptr(std::move(_ptr))
        {
            cout << "my_ptr constructed." << endl;
        }
        my_ptr() : ptr(nullptr) 
        {
            cout << "my_ptr constructed." << endl;
        }
        ~my_ptr()
        {
            if(ptr != nullptr)
                delete ptr;
            cout << "my_ptr destructed." << endl;
        }
        my_ptr(const my_ptr<T>&)
        {
            ptr = new T();
            cout << "Copying of my_ptr is forbidden!" << endl;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr& operator = (const my_ptr&)
        {
            cout << "Copying of my_ptr is forbidden!" << endl;
            cout << "my_ptr updated." << endl;
            return *this;
        }
        T * operator->() const
        {
            if(this->ptr == nullptr)
            {
                cout << "Do not attempt to read a nullptr!" << endl;
                return protect;
            }
            return this->ptr;
        }
        T& operator*() const
        {
            if(this->ptr == nullptr)
            {
                cout << "Do not attempt to read a nullptr!" << endl;
                return *protect;
            }
            return *this->ptr;
        }
        my_ptr(my_ptr&& move)
        {
            delete ptr;
            ptr = move.ptr;
            move.ptr = nullptr;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr& operator=(my_ptr&& move)
        {
            delete ptr;
            ptr = move.ptr;
            move.ptr = nullptr;
            cout << "my_ptr updated." << endl;
            return *this;
        }
};


template <class T>
T *my_ptr<T>::protect = new T();