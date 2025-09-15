#include <iostream>
#include <string>
using namespace std;

struct Node {
    string prompt;
    Node* next;
    Node(string p) : prompt(p), next(nullptr) {}
};

class PromptHistory {
    Node* head = nullptr;

public:
    void add(string prompt) {
        Node* newNode = new Node(prompt);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (!head) { cout << "No prompt history.\n"; return; }
        Node* temp = head; int i = 1;
        while (temp) {
            cout << i++ << ". " << temp->prompt << endl;
            temp = temp->next;
        }
    }

    void del(int pos) {
        if (!head) return;
        if (pos == 1) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp || !temp->next) return;
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void clear() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    ~PromptHistory() { clear(); }
};

int main() {
    PromptHistory ph;
    int ch, pos; string input;
    do {
        cout << "\n1.Add 2.Display 3.Delete 4.Clear 0.Exit: ";
        cin >> ch; cin.ignore();
        if (ch == 1) {
            cout << "Enter prompt: ";
            getline(cin, input);
            ph.add(input);
        } else if (ch == 2) ph.display();
        else if (ch == 3) {
            cout << "Enter position to delete: ";
            cin >> pos;
            ph.del(pos);
        } else if (ch == 4) ph.clear();
    } while (ch != 0);
}
