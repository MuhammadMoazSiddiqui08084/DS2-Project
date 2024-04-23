// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>

// using namespace std;

// // Structure to represent a node in the binary tree
// struct TreeNode {
//     string attribute;
//     TreeNode* left;
//     TreeNode* right;
//     vector<string> entries;

//     TreeNode(string attr) : attribute(attr), left(nullptr), right(nullptr) {}
// };

// // Function to create a binary tree from the inverted index
// TreeNode* createBinaryTree(const unordered_map<string, vector<vector<bool>>>& invertedIndex, const vector<string>& attributes) {
//     if (attributes.empty()) return nullptr;

//     string attribute = attributes[0];
//     TreeNode* root = new TreeNode(attribute);

//     vector<string> leftAttrs;
//     vector<string> rightAttrs;

//     // Partition the attributes based on the presence or absence of the current attribute
//     for (size_t i = 1; i < attributes.size(); ++i) {
//         bool presentInAll = true;
//         bool absentInAll = true;
//         const string& attr = attributes[i];

//         for (const auto& entry : invertedIndex.at(attr)) {
//             if (entry[0]) absentInAll = false;
//             else presentInAll = false;

//             if (!presentInAll && !absentInAll) break; // No need to check further
//         }

//         if (presentInAll) {
//             root->entries.push_back(attr); // Add entry at leaf node
//         } else if (absentInAll) {
//             // Do nothing, continue to the next attribute
//         } else {
//             // Attribute is not consistent for all entries, partition it
//             if (entry[0]) leftAttrs.push_back(attr);
//             else rightAttrs.push_back(attr);
//         }
//     }

//     // Recursively create left and right subtrees
//     root->left = createBinaryTree(invertedIndex, leftAttrs);
//     root->right = createBinaryTree(invertedIndex, rightAttrs);

//     return root;
// }

// // Function to print the binary tree in preorder traversal
// void printTree(TreeNode* root, int depth = 0) {
//     if (!root) return;

//     for (int i = 0; i < depth; ++i) {
//         cout << "  ";
//     }
//     cout << root->attribute << endl;

//     for (const auto& entry : root->entries) {
//         for (int i = 0; i < depth + 1; ++i) {
//             cout << "  ";
//         }
//         cout << "-> " << entry << endl;
//     }

//     printTree(root->left, depth + 1);
//     printTree(root->right, depth + 1);
// }

// int main() {
//     // Sample inverted index (mapping attribute to vector of boolean traits)
//     unordered_map<string, vector<vector<bool>>> invertedIndex = {
//         {"A", {{true, true}, {true, false}, {false, true}, {false, false}}},
//         {"B", {{true, true}, {true, false}, {false, true}, {false, false}}},
//         {"C", {{true, true}, {true, false}, {false, true}, {false, false}}}
//     };

//     // Extract attributes from inverted index
//     vector<string> attributes;
//     for (const auto& entry : invertedIndex) {
//         attributes.push_back(entry.first);
//     }

//     // Create binary tree
//     TreeNode* root = createBinaryTree(invertedIndex, attributes);

//     // Print binary tree
//     cout << "Binary Tree:" << endl;
//     printTree(root);

//     return 0;
// }
