#include <iostream>
#include <utility> // std::move
#include <cstddef> // size_t

class DynamicArray {
private:
    float* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
       // TODO 1: Allocate a new Heap array of size 'newCapacity'
        // TODO 2: Copy existing elements (0 to size - 1) into the new array
        // TODO 3: delete[] the old 'data' array
        // TODO 4: Point 'data' to the new array and update 'capacity = newCapacity'
    void grow() {
        size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
        float* newData = new float[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;          
        capacity = newCapacity;
        std::cout << "[Resized] New capacity: " << capacity << "\n";
    }

public:
    // Constructor
    DynamicArray(size_t initialCapacity = 2) : size(0), capacity(initialCapacity) {
        data = new float[capacity];
    }

    // Destructor (RAII)
    ~DynamicArray() {
        // TODO 5: Free 'data' with delete[]
        delete[] data;
    }

    // Copy Constructor (Deep Copy)
    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
        // TODO 6: Allocate a new buffer of 'capacity' and copy 'other.data' elements
        float* newData = new float[capacity];
        for(size_t i =0;i<size;i++){
            newData[i] = other.data[i];
        }
        data = newData;
    }

    // Move Constructor (Steal Pointer)
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        // TODO 7: Leave 'other' in an empty, safe state (nullptr and zeros)
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0; 
    }

    void push_back(float value) {
        if (size == capacity) {
            grow();
        }
        data[size] = value;
        size++;
    }

    float& operator[](size_t index) { return data[index]; }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
};

int main() {
    DynamicArray speeds(2);
    speeds.push_back(50.0f);
    speeds.push_back(65.5f);
    speeds.push_back(80.0f); 
    speeds.push_back(90.0f);
    speeds.push_back(110.0f); 

    for (size_t i = 0; i < speeds.getSize(); ++i) {
        std::cout << "Speed[" << i << "] = " << speeds[i] << " km/h\n";
    }

    DynamicArray movedSpeeds = std::move(speeds);
    std::cout << "Moved size: " << movedSpeeds.getSize() 
              << " | Old size: " << speeds.getSize() << "\n";

    return 0;
}