#include <iostream>
#include <string>

enum class State { Idle, Processing, Completed, Error };

class Workflow {
public:
    void signal(const std::string &event) {
        switch (state) {
            case State::Idle:
                if (event == "start") {
                    state = State::Processing;
                    std::cout << "Workflow started" << '\n';
                }
                break;
            case State::Processing:
                if (event == "success") {
                    state = State::Completed;
                    std::cout << "Workflow completed" << '\n';
                } else if (event == "failure") {
                    state = State::Error;
                    std::cout << "Workflow failed" << '\n';
                }
                break;
            case State::Completed:
            case State::Error:
                if (event == "reset") {
                    state = State::Idle;
                    std::cout << "Workflow reset" << '\n';
                }
                break;
        }
    }

private:
    State state = State::Idle;
};

int main() {
    Workflow workflow;
    workflow.signal("start");
    workflow.signal("success");
    workflow.signal("reset");
    workflow.signal("start");
    workflow.signal("failure");
}
