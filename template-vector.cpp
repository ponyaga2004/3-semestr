#include <iostream>
#include <stdexcept>

/////////////////////////////////////////////
/// Class Vector
/////////////////////////////////////////////

// Шаблонный класс вектора
template <typename T>
class vector {
public:
    // конструктор с умолчательным размером == 10
    explicit vector(unsigned int size = 10);
    // деструктор
    ~vector();

    // получение размера
    unsigned int size() const;
    // индексация для изменения
    T& operator[](unsigned int index);
    // индексация для чтения
    const T& operator[](unsigned int index) const;

private:
    // размер
    unsigned int size_;
    // сами данные
    T* data_;
};

// конструктор
template<typename T>
vector<T>::vector(unsigned int size) : size_(size), data_(new T[size]) {
}

// деструктор
template<typename T>
vector<T>::~vector() {
    delete[] data_;
}

// получение размера
template<typename T>
unsigned int vector<T>::size() const {
    return size_;
}

// индексация для изменения
template<typename T>
T& vector<T>::operator[](unsigned int index) {
    if (index >= size_) {
        // проверка на выход за пределы массива
        throw std::out_of_range("index is out of bound");
    }
    return data_[index];
}

// индексация для чтения
template<typename T>
const T& vector<T>::operator[](unsigned int index) const {
    if (index >= size_) {
        // проверка на выход за пределы массива
        throw std::out_of_range("index is out of bound");
    }
    return data_[index];
}

// вывод в `cout`
template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T> const& v) {

    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << " ";
    }
    return os;
}

/////////////////////////////////////////////
/// test
/////////////////////////////////////////////

// шаблонный тест
template <typename T>
void test(const char* type) {
    std::cout << "----------------------" << std::endl;
    std::cout << "test for type `" << type << "`" << std::endl;

    // создаем ветор на 4 элемента
    vector<T> v1(4);
    std::cout << "vector size is " << v1.size() << std::endl;
    std::cout << "vector content is " << v1 << std::endl;

    // изменяем содержимое
    v1[0] = 10;
    v1[1] = 11;
    v1[2] = 12;
    v1[3] = 13;
    std::cout << "updated vector content is " << v1 << std::endl;

    // доступ к 100-ому элементу должен порождать исключение
    try {
        v1[100];
    } catch(std::exception& ex) {
        std::cout << "expected exception `" << ex.what() << "`" << std::endl;
    }

    // создаем вектор с размером по умолчанию
    vector<T> v2;
    std::cout << "default vector size is " << v2.size() << std::endl;
}

/////////////////////////////////////////////
/// main
/////////////////////////////////////////////

int main()
{
    // настройка cout для вывода дробных чисел с знаком после запятой
    std::cout.setf(std::ios::fixed, std:: ios::floatfield);
    std::cout.precision(1);
\
    // вызов теста для 3-х разных типов
    test<int>("int");
    test<float>("float");
    test<double>("double");

    return 0;
}
