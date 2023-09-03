// Table.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<class T>
class Table
{
public:
    Table(int rows, int columns) : rows_(rows), columns_(columns)
    {
        arr = new T*[rows_];
        for (int i = 0; i < rows_; i++)
        {
            arr[i] = new T [columns_];
        }
    }
    ~Table()
    {
        for (int i = 0; i < rows_; i++)
        {
            delete[] arr[i];
        }
        delete[]arr;
    }
    Table(const Table& a) = delete;
    Table& operator = (const Table& a) = delete;
    T* operator[](int index) { return arr[index]; }
    const T* operator[] (const int index) const { return arr[index]; }   
    int size_table()const { return rows_ * columns_; }
private:
    T** arr = nullptr;
    int rows_ = 0;
    int columns_ = 0;
};

int main()
{
    auto test = Table<int>(2, 3);
    test[0][0] = 3;
    std::cout << test[0][0] << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
