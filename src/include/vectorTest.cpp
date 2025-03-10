#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        if (new_capacity <= capacity) return;

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector() : size(0), capacity(0), data(nullptr) {}

    explicit Vector(size_t initial_capacity) : size(0), capacity(initial_capacity) {
        data = new T[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vector<int> vec2;

    for (size_t i = 0; i < vec.get_size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}