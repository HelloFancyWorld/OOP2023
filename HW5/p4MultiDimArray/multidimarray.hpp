#pragma once
#include <vector>
using namespace std;
vector<int> dimensions;

template <typename T1, int dimension>
class MultiDimArray
{
    private:
        int d_size;
        MultiDimArray<T1, dimension - 1> *lower_dim;
    public:
    MultiDimArray(vector<int> _dimensions)
    {
        dimensions = _dimensions;
        d_size = dimensions[0];
        lower_dim = new MultiDimArray<T1, dimension - 1>[d_size];
    }
    MultiDimArray()
    {
        d_size = dimensions[dimensions.size() - dimension];
        lower_dim = new MultiDimArray<T1, dimension - 1>[d_size];
    }
    MultiDimArray<T1, dimension - 1> &operator[](int i)
    {
        return lower_dim[i];
    }
    MultiDimArray<T1, dimension> &operator=(const MultiDimArray<T1, dimension> &origin)
    {
        delete[] lower_dim;
        d_size = origin.d_size;
        this->lower_dim = new MultiDimArray<T1, dimension - 1>[d_size];
        for (int i = 0; i < d_size; i++)
        {
            this->lower_dim[i] = origin.lower_dim[i];
        }
        return *this;
    }
    MultiDimArray<T1, dimension> &operator=(MultiDimArray<T1, dimension> &&origin)
    {
        delete[] lower_dim;
        d_size = origin.d_size;
        this->lower_dim = new MultiDimArray<T1, dimension - 1>[d_size];
        for (int i = 0; i < d_size; i++)
        {
            this->lower_dim[i] = origin.lower_dim[i];
        }
        delete []origin.lower_dim;
        origin.lower_dim = nullptr;
        origin.d_size = 0;
        return *this;
    }
    ~MultiDimArray()
    {
        delete[] lower_dim;
    }
};

template <typename T1>
class MultiDimArray<T1, 1>
{
    private:
    int d_size;
    T1 *lowest_dim;
    public:
    MultiDimArray()
    {
        d_size = dimensions[dimensions.size() - 1];
        lowest_dim = new T1[d_size];
    }
    T1 &operator[](int i)
    {
        return lowest_dim[i];
    }
    MultiDimArray<T1, 1> &operator=(const MultiDimArray<T1, 1> &origin)
    {
        delete[] lowest_dim;
        d_size = origin.d_size;
        this->lowest_dim = new T1[d_size];
        for (int i = 0; i < d_size; i++)
        {
            lowest_dim[i] = origin.lowest_dim[i];
        }
        return *this;
    }
    MultiDimArray<T1, 1> &operator=(MultiDimArray<T1, 1> &&origin)
    {
        delete[] lowest_dim;
        d_size = origin.d_size;
        this->lowest_dim = new T1[d_size];
        for (int i = 0; i < d_size; i++)
        {
            lowest_dim[i] = origin.lowest_dim[i];
        }
        delete[] origin.lowest_dim;
        origin.lowest_dim = nullptr;
        origin.d_size = 0;
        return *this;
    }
    ~MultiDimArray()
    {
        delete[] lowest_dim;
    }
};
