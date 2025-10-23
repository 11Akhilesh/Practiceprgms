#include <array>
#include <iostream>

template <typename T, size_t Capacity>
class RingBuffer {
public:
    bool push(const T &value) {
        if (full()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % Capacity;
        ++count;
        return true;
    }

    bool pop(T &value) {
        if (empty()) {
            return false;
        }
        value = data[head];
        head = (head + 1) % Capacity;
        --count;
        return true;
    }

    bool empty() const { return count == 0; }
    bool full() const { return count == Capacity; }

private:
    std::array<T, Capacity> data{};
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;
};

int main() {
    RingBuffer<int, 5> buffer;
    for (int i = 0; i < 5; ++i) {
        buffer.push(i * 3);
    }
    int value;
    while (buffer.pop(value)) {
        std::cout << value << '\n';
    }
}
