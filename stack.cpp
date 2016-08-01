#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class Stack
{
private:
    size_t _size;   //数据个数
    size_t _capacity;//容量
    T* _data;       //指向数据的指针
public:
    Stack()
        :_size(0)
         ,_capacity(3)
         ,_data(new T[_capacity])
    {}

    ~Stack()
    {
        if(_data)
        {
            delete [] _data;
        }
    }

    Stack& operator =(const Stack<T>& s)
    {
        if(this != &s)
        {
            _data = new T[s.Size()];
            for(int i=0;i<s.Size();i++)
            {
                _data[i] = s._data[i];
            }
        }
        return *this;
    }
public:
    void Push(const T&x)
    {
        _CheckCapacity();
        _data[_size++] = x;
    }

    void Pop()
    {
        assert(_size > 0);
        --_size;
    }

    const T& Top()
    {
        assert(_size > 0);
        return _data[_size-1];
    }

    size_t Size() const
    {
        return _size;
    }

    void Print()
    {
        for(int i = 0;i < _size; ++i)
        {
            cout<<_data[i]<<"->";
        }
    }

    void _CheckCapacity()
    {
        if(_capacity == _size)
        {
            _capacity *= 2;
            T* tmp = new T[_capacity];
            //如果T是自定义类型考虑深浅拷贝问题
            //当T为string等类型时，得用operrator =
            //为何这块不能使用memcpy();
            for(int i = 0;i < _size;++i)
            {
                tmp[i] = _data[i];
            }
            delete[] _data;
            _data = tmp;
        }
    }
};

void Test()
{
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);

    cout<<s.Top()<<endl;
    s.Pop();
    
    cout<<s.Top()<<endl;
    s.Pop();
    
    cout<<s.Top()<<endl;
    s.Pop();
    
    cout<<s.Top()<<endl;
    s.Pop();
    
    cout<<s.Top()<<endl;
    s.Pop();
    
    cout<<s.Top()<<endl;
    s.Pop();
    s.Print();
}
int main()
{
    Test();
    return 0;
}
