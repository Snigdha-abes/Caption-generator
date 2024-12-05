#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Transition {
    char present_state;
    char next_state;
    char input;
    char output;
};

void analyzeTransitions(const vector<Transition>& transitions) {
    map<pair<char, char>, char> transition_map;
    set<char> states;
    string sequence;

    for (const auto& t : transitions) {
        transition_map[{t.present_state, t.input}] = t.next_state;
        states.insert(t.present_state);
        states.insert(t.next_state);
    }

    char current_state = transitions[0].present_state;
    bool has_output_one = false;

    for (const auto& t : transitions) {
        if (t.present_state == current_state) {
            sequence += t.input;
            current_state = t.next_state;
            if (t.output == '1') {
                has_output_one = true;
            }
        }
    }

    bool is_overlapping = false;

    for (const auto& t : transitions) {
        if (t.output == '1') {
            is_overlapping = true;
            break;
        }
    }

    cout << sequence << endl;
    if (is_overlapping) {
        cout << "Overlapping Sequence Detector" << endl;
    } else {
        cout << "Non Overlapping Sequence Detector" << endl;
    }
}

int main() {
    vector<Transition> transitions;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) break;
        Transition t;
        sscanf(line.c_str(), "%c %c %c %c", &t.present_state, &t.next_state, &t.input, &t.output);
        transitions.push_back(t);
    }

    analyzeTransitions(transitions);

    return 0;
}