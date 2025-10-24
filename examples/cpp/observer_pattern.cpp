#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(double value) = 0;
};

class Subject {
public:
    void attach(std::shared_ptr<Observer> observer) { observers.push_back(observer); }
    void set_state(double value) {
        state = value;
        notify();
    }

private:
    void notify() {
        for (auto &observer : observers) {
            observer->update(state);
        }
    }

    std::vector<std::shared_ptr<Observer>> observers;
    double state = 0.0;
};

class ThresholdObserver : public Observer {
public:
    explicit ThresholdObserver(std::string label) : label(std::move(label)) {}
    void update(double value) override {
        if (value > 50.0) {
            std::cout << label << " alert: " << value << '\n';
        }
    }

private:
    std::string label;
};

int main() {
    Subject subject;
    subject.attach(std::make_shared<ThresholdObserver>("CPU"));
    subject.attach(std::make_shared<ThresholdObserver>("Memory"));
    subject.set_state(42.0);
    subject.set_state(78.5);
}
