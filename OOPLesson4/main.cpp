#include <iostream>
#include <cassert> // для assert()

class ArrayInt
{
private:
    int m_length;
    int* m_data;

    int Partition(int low, int high)
    {
        int pivot = m_data[high];    // pivot 
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            //if current element is smaller than pivot, increment the low element
            //swap elements at i and j
            if (m_data[j] <= pivot)
            {
                i++;    // increment index of smaller element 
                swap(&m_data[i], &m_data[j]);
            }
        }
        swap(&m_data[i + 1], &m_data[high]);
        return (i + 1);
    }

public:
    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0) {
            m_data = new int[length];
        }
        else {
            m_data = nullptr;
        }
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length) {
            return;
        }

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0) {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int* data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index = 0; index < elementsToCopy; ++index) {
                data[index] = m_data[index];
            }
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int* data = new int[m_length + 1];

        // Копируем все элементы до index-а
        for (int before = 0; before < index; ++before) {
            data[before] = m_data[before];
        }

        // Вставляем новый элемент в новый массив
        data[index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after = index; after < m_length; ++after) {
            data[after + 1] = m_data[after];
        }

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    void __fastcall swap(int index)
    {
        int temp = m_data[index];
        m_data[index] = m_data[index + 1];
        m_data[index + 1] = temp;
    }

    void __fastcall swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void pop_back()
    {
        resize(getLength() - 1);
    }

    void pop_front()
    {
        for (size_t i = 0; i < getLength() - 1; i++)
        {
            swap(i);
        }
        resize(getLength() - 1);
    }

    void Print()
    {
        for (size_t i = 0; i < getLength(); i++)
        {
            std::cout << m_data[i] << " ";
        };
        std::cout << std::endl;
    }

    void QuickSort(int low, int high) //https://www.softwaretestinghelp.com/quick-sort/#:~:text=Quicksort%20is%20a%20widely%20used,the%20right%20of%20the%20list. взято отсюда
    {
        if (low < high)
        {
            //partition the array 
            int pivot = Partition(low, high);

            //sort the sub arrays independently 
            QuickSort(low, pivot - 1);
            QuickSort(pivot + 1, high);
        }
    }

    int CountUnique() //https://www.geeksforgeeks.org/count-distinct-elements-in-an-array/
    {
        int n = getLength();
        int res = 0;
        for (size_t i = 0; i < n; i++)
        {
            while (i < n - 1 && m_data[i] == m_data[i + 1])
            {
                i++;
            }
            res++;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    ArrayInt arrayInt;
    arrayInt.push_back(9);
    arrayInt.push_back(12);
    arrayInt.push_back(9);
    arrayInt.push_back(2);
    arrayInt.push_back(17);
    arrayInt.push_back(1);
    arrayInt.push_back(6);
    //arrayInt.pop_back();
    //arrayInt.pop_front();
    arrayInt.Print();
    arrayInt.QuickSort(0, arrayInt.getLength() - 1);
    arrayInt.Print();
    std::cout << "unique values: " << arrayInt.CountUnique() << std::endl;
    return 0;
}