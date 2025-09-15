#include <iostream>
#include <string>
using namespace std;

// Node structure for singly linked list
struct Node {
    string prompt;
    Node* next;

    Node(string data) {
        prompt = data;
        next = nullptr;
    }
};

class PromptHistory {
private:
    Node* head;

public:
    PromptHistory() {
        head = nullptr;
    }

    // Add a new prompt at the end
    void addPrompt(string prompt) {
        Node* newNode = new Node(prompt);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Prompt added successfully!\n";
    }

    // Display all prompts
    void displayHistory() {
        if (head == nullptr) {
            cout << "No prompt history found.\n";
            return;
        }
        Node* temp = head;
        int count = 1;
        cout << "\nChatGPT Prompt History:\n";
        while (temp != nullptr) {
            cout << count++ << ". " << temp->prompt << "\n";
            temp = temp->next;
        }
    }

    // Delete a prompt by position
    void deletePrompt(int position) {
        if (head == nullptr) {
            cout << "History is empty.\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Prompt deleted at position 1.\n";
            return;
        }

        Node* prev = head;
        for (int i = 1; i < position - 1 && prev != nullptr; i++) {
            prev = prev->next;
        }

        if (prev == nullptr || prev->next == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        Node* delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;

        cout << "Prompt deleted at position " << position << ".\n";
    }

    // Count total prompts
    int countPrompts() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Clear entire history
    void clearHistory() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All prompt history cleared.\n";
    }

    ~PromptHistory() {
        clearHistory();
    }
};

// ----------- MAIN FUNCTION ------------
int main() {
    PromptHistory history;
    int choice;
    string prompt;
    int pos;

    do {
        cout << "\n----- ChatGPT Prompt History -----\n";
        cout << "1. Add Prompt\n";
        cout << "2. Display History\n";
        cout << "3. Delete Prompt by Position\n";
        cout << "4. Count Prompts\n";
        cout << "5. Clear All History\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch (choice) {
            case 1:
                cout << "Enter your ChatGPT prompt:\n";
                getline(cin, prompt);
                history.addPrompt(prompt);
                break;
            case 2:
                history.displayHistory();
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                history.deletePrompt(pos);
                break;
            case 4:
                cout << "Total prompts: " << history.countPrompts() << "\n";
                break;
            case 5:
                history.clearHistory();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
