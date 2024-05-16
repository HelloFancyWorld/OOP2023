#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

#define protected public
#define private public

template<class T>
class Data
{
protected:
    int length;
public:
    Data(int _length) : length(_length) {}
    virtual const T& get(int index) = 0;
};

template<class T>
class DataEmpty : public Data<T>
{
public:
    DataEmpty<T>(): Data<T>(0) {};
    const T& get(int index) {
        assert(0); // No data in DataEmpty
    }
};

template<class T>
class DataPushBackDecorator : public Data<T>
{
    T x;
    // Implement a Decorator for push_back operation
    DataPushBackDecorator<T>(Data<T>* data,T& value):data(data){
        length++;
        x = vlaue;
    }
};

template<class T>
class DataSetDecorator : public Data<T>
{
    // Implement a Decorator for set operation
};


template<class T>
class PVector
{
public:
    Data<T>* data;
    PVector<T>() {
        data = new DataEmpty<T>();
        // when to delete??
    }
    PVector<T>(Data<T>* _data): data(_data) { }
    PVector<T> push_back(const T &value) const{
        return PVector<T>(new DataPushBackDecorator<T>(data, value));
    }
    PVector<T> set(int index, const T &value) const{
        return PVector<T>(new DataSetDecorator<T>(data, index, value));
    }

    const T& operator[](int index){
        return data->get(index);
    }
};



bool a = 1;
template<class T>
ostream& operator<<(ostream& out, PVector<T>& a){

}