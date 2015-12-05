#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array
{
public:
  
  Array():
    m_length(0),
    m_data(nullptr)
  {}

  Array(int length)
  {
    m_length = length;
    m_data = new T[length];
  }
  ~Array()
  {
    delete[] m_data;
  }

  int GetLength();

  T& operator[](int index)
  {
    return m_data[index];
  }

private:
  int m_length;
  T* m_data;

};

template<typename T>
int Array<T>::GetLength()
{
  return m_length;
}

#endif /* ARRAY_H */