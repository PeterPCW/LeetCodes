class TrieNode { // Have to declare the node class for the Trie
    public:
        bool is_end; // Flag for if this node is the end of the word
        unordered_map<char, TrieNode*> children; // Map of characters to their child nodes
        TrieNode() { // Constructor for a new node
            is_end = false;
        }
        ~TrieNode() { // Destructor for a node, deletes all child nodes as well
            for (auto it : children) {
                delete it.second;
            }
        }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* node = root; // Start the insert check at the root of the Trie
            for (char c : word) { // Loop through all characters in the word to add
                if (node->children.find(c) == node->children.end()) { // Look for the character to already exist as a child...
                    node->children[c] = new TrieNode(); // And add it if it doesn't (.find() index was .end())
                }
                node = node->children[c]; // Move to the next TrieNode before iterating to the next character
            }
            node->is_end = true; // Set the last TrieNode created/checked as the end of a word
        }
        
        bool search(string word) {
            TrieNode* node = root; // Start the search at the root of the Trie
            for (char c : word) { // Use the same looping...
                if (node->children.find(c) == node->children.end()) { // And the same check...
                    return false; // False if the character is not found
                }
                node = node->children[c]; // Move to the next TrieNode before iterating to the next character
            }
            return node->is_end; // If you make it through the whole check then the current node will be an end of a word if that word is already in the Trie
        }
        
        bool startsWith(string prefix) {
            TrieNode* node = root; // Start the search at the root of the Trie
            for (char c : prefix) { // Use the same looping again...
                if (node->children.find(c) == node->children.end()) { // And the same check...
                    return false; // It's even still false if the character is not found
                }
                node = node->children[c]; // Move to the next TrieNode before iterating to the next character
            }
            return true; // The only difference is that completing the word is always true, end of current word or not
        }

        ~Trie() { // Trie destructor
            delete root;
        }
    private:
        TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Source: https://leetcode.com/problems/implement-trie-prefix-tree/ 

/*
Explanation:
The TrieNode class represents a node in the trie, with a boolean flag indicating if a word ends at that node, and an unordered map of child characters to their corresponding child nodes.
The Trie class contains a root TrieNode and has methods to insert a string into the trie, search for a string in the trie, and check if there is a previously inserted string that has a given prefix.
The insert method traverses the trie from the root, creating new child nodes as necessary for each character in the input word. At the end of the traversal, it sets the isEnd flag of the final node to true to indicate that a word ends at that node.
The search method also traverses the trie from the root, following the child nodes corresponding to each character in the input word. If it reaches a node where the corresponding character does not have a child node, it immediately returns false. Otherwise, it returns the isEnd flag of the final node to indicate whether a word ends at that node.
The startsWith method is similar to search, but does not need to check the isEnd flag of the final node. Instead, it returns true as soon as it has successfully traversed the trie for all characters in the input prefix.
*/