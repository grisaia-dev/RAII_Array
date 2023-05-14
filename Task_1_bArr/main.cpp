#include <iostream>

class smart_array {
private:
    int* p_arr = nullptr;
    unsigned int size = 0;
public:
    smart_array(const int& size_array) {
        size = size_array;
        p_arr = new int[size];
        std::cout << "Array created!" << std::endl;
    }

    void add_element(const int& var) {
        for (unsigned int i=0; i < size; i++) {
            if (p_arr[i] == 0) {
                p_arr[i] = var;
                break;
            }
            if (i >= size-1)
                throw std::string{"Cannot add more element to array because array is full!!!"};
        }
    }

    int get_element(const int& index) {
        if (index > size-1)
            throw std::string{"Index greater than size array!!!"};
        return p_arr[index];
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
        std::cout << arr.get_element(2) << std::endl;
    } catch (const std::string& error_message) {
        std::cout << error_message << std::endl;
    }

    return 0;
}
