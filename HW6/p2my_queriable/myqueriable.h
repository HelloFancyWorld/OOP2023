#include <vector>
using namespace std;

template<typename T>
class MyQueriable
{
    private:
        vector<T> data;
    public:
        size_t size() {
            return data.size();
        }
        T& operator[](int i)
        {
            return data[i];
        }
        void push_back(T newdata)
        {
            data.push_back(newdata);
        }
        MyQueriable<T> where(bool(*func)(int))
        {
            MyQueriable temp;
            for (int i = 0; i < data.size(); i++)
            {
                if((*func)(data[i]))
                {
                    temp.push_back(data[i]);
                }
            }
            return temp;
        }
        template<typename S>
        MyQueriable<T> where(S func)
        {
            MyQueriable temp;
            for (int i = 0; i < data.size(); i++)
            {
                if(func(data[i]))
                {
                    temp.push_back(data[i]);
                }
            }
            return temp;
        }
        MyQueriable<T> apply(T (*func)(T))
        {
            MyQueriable<T> temp;
            for (int i = 0; i < data.size(); i++)
            {
                temp.push_back((*func)(data[i]));
            }
            return temp;
        }
        template<typename S>
        MyQueriable<T> apply(S func)
        {
            MyQueriable<T> temp;
            for (int i = 0; i < data.size(); i++)
            {
                temp.push_back(func(data[i]));
            }
            return temp;
        }

        T sum()
        {
            T temp = 0;
            for (int i = 0; i < data.size(); i++)
            {
                temp += data[i];
            }
            return temp;
        }
};

template<typename T>
MyQueriable<T> from(vector<T> arr)
{
    MyQueriable<T> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
    }
    return temp;
}
