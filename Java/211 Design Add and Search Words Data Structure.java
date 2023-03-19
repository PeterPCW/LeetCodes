class WordDictionary {
    private TrieNode root; // Initialize the root node of the trie
    public WordDictionary() { // Constructor
        root = new TrieNode(); // Call the TrieNode constructor to build children and isEnd at the root
    }
    
    public void addWord(String word) {
        TrieNode node = root; // Start at the root of the trie
        for (char c : word.toCharArray()) { // Loop through every character in the new word
            node.children.putIfAbsent(c, new TrieNode()); // Create a new child node if the character isn't already a child of the current node
            node = node.children.get(c); // Move the node to the current character child for the next iteration
        }
        node.isEnd = true; // Mark the end of the word after the for loop exits
    }
    
    public boolean search(String word) {
        return searchHelper(word.toCharArray(), 0, root); // Use the recursive search by character array below
    }

    private boolean searchHelper(char[] word, int i, TrieNode node) {
        if (i == word.length) { // When the end of the word is reached
            return node.isEnd; // It exists if the current node is already marked as an end of a word
        }
        if (word[i] == '.') { // This character is a period which counts as a wildcard for search
            for (char c : node.children.keySet()) { // Try all possible characters already stored as children
                if (searchHelper(word, i + 1, node.children.get(c))) { // Continue the word recursively
                    return true; // Return true if the recursive check kept being true through the end of the word
                }
            }
        } else {
            if (node.children.get(word[i]) != null && searchHelper(word, i + 1, node.children.get(word[i]))) { // As long as there is a child node for the current character, continue recursively
                return true; // Return true if the recursive check kept being true through the end of the word
            }
        }
        return false; // Never found the word
    }
}

class TrieNode {
    Map<Character, TrieNode> children;
    boolean isEnd;
    TrieNode() { // TrieNode constructor
        children = new HashMap<>(); // Start a hashmap for the children from the current node
        isEnd = false; // Default to not being the end of a word so that can be set by the addWord function
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */

// Source: https://leetcode.com/problems/design-add-and-search-words-data-structure/ 

/*
Explanation:
A Trie is a tree-like data structure that stores a collection of strings, with each node representing a character in a string. The TrieNode class represents a node in the Trie. Each node has a map of child nodes and a boolean value indicating whether it marks the end of a word.
The WordDictionary class initializes the Trie with an empty root node in the constructor.
The addWord() method adds a word to the Trie by iterating over the characters in the word and adding a child node for each character if it does not exist already. The last node of the word is marked as the end of the word.
The search() method searches for a word in the Trie by recursively searching the Trie from the root node to the last character of the word.
The searchHelper() method is a recursive function that takes the word (in character array form), the current index, and the current node in the Trie as input.
Before starting/continuing recursion it checks of the current character is the end of the word and then if the node is marked as the end as well then the word is found.
If the current character is a '.', which is used as a wildcard, we iterate over all the child nodes of the current node and search recursively for the remaining characters in the word.
Otherwise, we check if the child node corresponding to the current character exists and search recursively for the remaining characters in the word. If we cannot find a match, the function returns false.
*/