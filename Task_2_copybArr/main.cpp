#include <iostream>

class smart_array {
private:
    int* p_arr = nullptr;
    unsigned int size = 0;
public:
    smart_array(const int &size_array) {
        this->size = size_array;
        this->p_arr = new int[size];
        std::cout << "Array created!" << std::endl;
    }

    void add_element(const int &var) {
        for (unsigned int i=0; i < get_array_size(); i++) {
            if (p_arr[i] == 0) {
                p_arr[i] = var;
                break;
            }
            if (i >= size-1)
                throw std::string{"Cannot add more element to array because array is full!!!"};
        }
    }

    int get_element(const int &index) {
        if (index > size-1)
            throw std::string{"Index greater than size array!!!"};
        return p_arr[index];
    }

    int get_array_size() {
        const unsigned int result = size;
        return result;
    }

    smart_array &operator=(const smart_array &source) {
        if (this != &source) {
            size = source.size;
            delete [] p_arr;
            p_arr = new int[size];
            for (unsigned int i=0; i < size; i++)
                p_arr[i] = source.p_arr[i];
        }
        return *this;
    }

    ~smart_array() {
        delete [] p_arr;
        std::cout << "Array deleted!" << std::endl;
    }
};

int main(void) {
    try {
        smart_array arr(5);
        arr.add_element(43);
        arr.add_element(15);
        arr.add_element(60);
        arr.add_element(23);
        arr.add_element(1);
        std::cout << "arr: ";
        for (unsigned int i=0; i < arr.get_array_size(); i++)
            std::cout << arr.get_element(i) << " ";
        std::cout << std::endl << std::endl;

        smart_array new_array(2);
        new_array.add_element(2);
        new_array.add_element(1);
        std::cout << "new_array: ";
        for (unsigned int i=0; i < new_array.get_array_size(); i++)
            std::cout << new_array.get_element(i) << " ";
        std::cout << std::endl << std::endl;

        arr = new_array;
        std::cout << "arr copy new_array\narr: ";
        for (unsigned int i=0; i < arr.get_array_size(); i++)
            std::cout << arr.get_element(i) << " ";
        std::cout << std::endl << std::endl;
    } catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return 0;
}