#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char data) {
        this->data = data;
        terminal = false;
    }
};

class Trie
{
    Node *root;
    int count;
    public:
    Trie() {
        root = new Node('\0');
        count = 0;
    }
    void insert(char *w) {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if (temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
    bool find(char *w) {
        Node* temp = root;
        for (int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if (temp->children.count(ch) == 0) {
                return false;
            }
            else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};
int main()
{
    Trie t;
    char words[][15] = {"a", "hello", "not", "news", "apple"};
    char w[10];
    cout << "Enter a word to search!" << '\n';
    cin >> w;
    for (int i = 0; i < 5; i++) {
        t.insert(words[i]);
    }
    if (t.find(w)) {
        cout << "Word is present!" << '\n';
    }
    else cout << "Word is not present" << '\n';

    return 0;
}
