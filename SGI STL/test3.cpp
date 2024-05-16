// stl\Stl_vector.h
template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, const _Tp &__x)
{
    // 如果此时还有备用空间
    if (_M_finish != _M_end_of_storage)
    {
        // 在备用空间起始处构造一个元素，并以vector最后一个元素值为初始值
        construct(_M_finish, *(_M_finish - 1));
        ++_M_finish; // 调整水位
        _Tp __x_copy = __x;
        copy_backward(__position, _M_finish - 2, _M_finish - 1);
        *__position = __x_copy;
    }
    else
    { // 此时没有备用空间
        // 计算原vector的大小
        const size_type __old_size = size();
        // 如果原大小为0，则配置1个元素
        // 如果原大小不为0，则配置原大小的2倍
        const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
        iterator __new_start = _M_allocate(__len);
        iterator __new_finish = __new_start;
        __STL_TRY
        {
            // 将原vector的内容拷贝到新vector
            // uninitialized_copy定义在下面
            __new_finish = uninitialized_copy(_M_start, __position, __new_start);
            // 为新元素设定初始值为x
            construct(__new_finish, __x);
            // 调整水位
            ++__new_finish;
            // 将原vector的备用空间中的内容也拷贝到新vector中
            __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
        }
        __STL_UNWIND((destroy(__new_start, __new_finish),
                      _M_deallocate(__new_start, __len)));
        // 析构并释放原vector
        // destroy定义在下面
        destroy(begin(), end());
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        // 调整迭代器，指向新vector
        _M_start = __new_start;
        _M_finish = __new_finish;
        _M_end_of_storage = __new_start + __len;
    }
}