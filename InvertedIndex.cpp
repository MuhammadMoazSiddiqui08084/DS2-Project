#include "InvertedIndex.h"
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <string>

// using namespace std;

void inverted_index::add_species(const species &new_species){
    all_species.push_back(new_species);
}

double inverted_index::compare_species(const species& species1, const species& species2) const {
    int similar_traits = 0;

    for (int i=0; i<10; i++){
        if (species1.features[i]==species2.features[i]){
            similar_traits++;
        }
    }
    double match = similar_traits/10.0;
    return match;
}


inverted_index::inverted_index(){
    // function for populating inverted index called here//
    root = new tree_node;
    root->group = all_species;
    construct_tree(all_species, root, 0);
}

void inverted_index::construct_tree(const std::vector<species>& subgroup, tree_node *subroot, int attr){
    tree_node *cur = subroot;

    cur->left = new tree_node;
    cur->right = new tree_node;

    for (species a : subgroup){
        if (a.features[attr]==true){
            cur->right->group.push_back(a);
        }
        else{
            cur->left->group.push_back(a);
        }
    }

    if (2*attr+1<=num_attr){
        construct_tree(cur->left->group, cur->left, 2*attr+1);
    }
    else if(2*attr+2<=num_attr){
        construct_tree(cur->right->group, cur->right, 2*attr+2);
    }
}


// // Structure to hold animal attributes
// struct species {
//   string species; // Added species to identify primate type
//   unordered_map<string, string> attributes;
// };

// // Inverted index using unordered_map
// unordered_map<string, AnimalAttributes> inverted_index;

// // Function to add a primate to the index
// void add_primate(const string& name, const string& species, const unordered_map<string, string>& attributes, int document_id) {
//   AnimalAttributes& animal_data = inverted_index[name];
//   animal_data.species = species;
//   for (const auto& attribute : attributes) {
//     animal_data.attributes[attribute.first] = attribute.second;
//   }
// }

// // Function to search for primates by attribute
// vector<string> search_primates(const string& attribute, const string& value) {
//   vector<string> results;
//   for (const auto& animal_data : inverted_index) {
//     // Check if animal is a primate
//     if (animal_data.second.species.find("primate") != string::npos &&
//         animal_data.second.attributes.count(attribute) > 0 &&
//         animal_data.second.attributes[attribute] == value) {
//       results.push_back(animal_data.first);
//     }
//   }
//   return results;
// }
