#include <iostream>
#include <vector>
#include <cstring>
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
    void insert(const string& w) {
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
    bool find(const string& w) {
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
    //Added string data type instead of 2-D char array.
    //Added string instead of char pointer
    Trie t;
    vector<string> words {"a", "hello", "not", "news", "apple"};
    string w;
    cout << "Enter a word to search in Trie data structure: " << '\n';
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
