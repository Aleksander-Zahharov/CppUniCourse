#ifndef MYARRAY_H
#define MYARRAY_H

#include <stdexcept>
#include <algorithm>

/**
 * @brief Template class representing a dynamic array.
 * 
 * @tparam T The type of the elements in the array.
 */
template<class T>
class MyArray {
public:
    /**
     * @brief Default constructor. Initializes an empty array.
     */
    MyArray() : content(nullptr), size(0) {}

    /**
     * @brief Copy constructor. Performs deep copy of the array.
     * 
     * @param a The array to copy.
     */
    MyArray(const MyArray &a) : content(nullptr), size(0) {
        if (a.size > 0) {
            content = new T[a.size];
            std::copy(a.content, a.content + a.size, content);
            size = a.size;
        }
    }

    /**
     * @brief Assignment operator. Performs deep copy of the array.
     * 
     * @param a The array to assign.
     * @return Reference to the current object.
     */
    MyArray& operator=(const MyArray &a) {
        if (this != &a) {
            delete[] content;
            content = nullptr;
            size = 0;
            if (a.size > 0) {
                content = new T[a.size];
                std::copy(a.content, a.content + a.size, content);
                size = a.size;
            }
        }
        return *this;
    }

    /**
     * @brief Destructor. Frees the allocated memory.
     */
    ~MyArray() {
        delete[] content;
    }

    /**
     * @brief Returns the number of elements in the array.
     * 
     * @return The size of the array.
     */
    unsigned int getSize() const {
        return size;
    }

    /**
     * @brief Adds an element to the end of the array.
     * 
     * @param element The element to add.
     */
    void addElement(T element) {
        T *newContent = new T[size + 1];
        if (content) {
            std::copy(content, content + size, newContent);
            delete[] content;
        }
        newContent[size] = element;
        content = newContent;
        ++size;
    }

    /**
     * @brief Returns the element at the specified index.
     * 
     * @param i The index of the element.
     * @return Reference to the element at index i.
     * @throws std::out_of_range if the index is invalid.
     */
    T& elementAt(unsigned int i) {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return content[i];
    }

    T *content; ///< Pointer to the array content (publicly visible).

private:
    unsigned int size; ///< Number of elements in the array (not publicly visible).
};

#endif // MYARRAY_H