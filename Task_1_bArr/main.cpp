#include <iostream>
#include <vector>

class smart_array {
private:
    int* p_arr = nullptr;
    unsigned int size = 0;
    unsigned int count = 0;
public:
    smart_array(const int& size_array) {
        this->size = size_array;
        this->p_arr = new int[size];
        std::cout << "Array created!" << std::endl;
    }

    int get_array_size() { 
        const unsigned int array_size = size;
        return array_size;
    }

    void add_element(const int& var) {
        if (this->count > this->size-1)
            throw std::string{"Can't add more elements in array because array is full!!!"};
        p_arr[this->count] = var;
        this->count += 1;
    }

    int get_element(const int& index) {
        if (index > this->size-1)
            throw std::string{"Index greater than size array!!!"};
        return p_arr[index];
    }

    ~smart_array() {
        delete [] this->p_arr;
        std::cout << "Array deleted!" << std::endl;
    }
};

int main(void) {
    try {
        smart_array arr(5);
        arr.add_element(43);
        arr.add_element(15);
        arr.add_element(60);
        arr.add_element(0);
        arr.add_element(1);
        std::cout << "arr: ";
        for (unsigned int i=0; i < arr.get_array_size(); i++)
            std::cout << arr.get_element(i) << " ";
        std::cout << std::endl;
    } catch (const std::string& error_message) {
        std::cout << error_message << std::endl;
    }

    return 0;
}
