#include "InvertedIndex.hpp"
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <string>

// using namespace std;


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