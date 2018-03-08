#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

#define ALPHABET_SIZE 26

using namespace std;

struct TrieNode {
    bool is_end;
    int freq;
    // Array
    struct TrieNode* children[ALPHABET_SIZE];
};

struct TrieNode* init(void) {
    struct TrieNode* pNode = new TrieNode;
    pNode->is_end = false;
    pNode->freq = 0;
    for (int i = 0; i < ALPHABET_SIZE ; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode* root, string word) {
    struct TrieNode* pCur = root;
    for (int i = 0; i < word.length(); i++) {
        int index = (int)word[i] - (int)'a';
        // if children[i] is NULL
        if (!pCur->children[index]) {
            pCur->children[index] = init();
        }
        //move pointer & update
        pCur = pCur->children[index];
        pCur->freq += 1;
    }
    pCur->is_end = true;
}
bool startWith(struct TrieNode* root, string prefix) {
    struct TrieNode* pCur = root;
    for (int i = 0; i < prefix.length(); i++) {
        int index = (int)prefix[i]- (int)'a';
        if (!pCur->children[index])
            return false;
        pCur = pCur->children[index];
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root = init();
    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }
    cout << startWith(root, "x") << endl;
    return 0;
}