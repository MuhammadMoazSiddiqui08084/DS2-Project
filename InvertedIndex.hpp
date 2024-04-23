#pragma once
#include <string>
#include <vector>
#include <memory>
// #include <unordered_map>
// #include <set>


struct species {
    std::string title;
    bool features[10] = {false, false, false, false, false, false, false, false, false, false}; 
    //flat_nails, olfactory, collarbone, bipedaism, sit_up, walk_up, placenta, toothcomb, nostril, big_eyes;
};

struct tree_node {
    std::vector<species> group;
    tree_node *left = nullptr;
    tree_node *right = nullptr;
};


class inverted_index {
    int num_attr = 10;
    std::vector<species> all_species;
    tree_node *root;

    
    public:
    // Empty constructor to initialize an empty inverted index
    inverted_index();

    // Function to add a new species to the index
    void add_species(const species& new_species);

    // Function to compare two species and return their similarity score
    double compare_species(const species& species1, const species& species2) const ;

    void construct_tree(const std::vector<species>& subgroup, tree_node *subroot, int cur_attr);
    // if (species1.flat_nails==species2.flat_nails)
    //     similar_traits++;
    
    // if (species1.olfactory==species2.olfactory)
    //     similar_traits++;
    
    // if (species1.collarbone==species2.collarbone)
    //     similar_traits++;
    
    // if (species1.bipedaism==species2.bipedaism)
    //     similar_traits++;

    // if (species1.sit_up==species2.sit_up)
    //     similar_traits++;

    // if (species1.walk_up==species2.walk_up)
    //     similar_traits++;

    // if (species1.placenta==species2.placenta)
    //     similar_traits++;
    
    // if (species1.toothcomb==species2.toothcomb)
    //     similar_traits++;
    
    // if (species1.nostril==species2.nostril)
    //     similar_traits++;
    
    // if (species1.big_eyes==species2.big_eyes)
    //     similar_traits++;
    // }
};

// class SpeciesGraph {
//  public:
//   // Empty constructor to initialize an empty graph
//   SpeciesGraph() {}

//   // Function to add a node (species) to the graph
// //   void add_node(const std::string& species_title) {
// //     nodes.insert(species_title);
// //   }

// //   // Function to add an edge between two nodes (species)
// //   void add_edge(const std::string& species1, const std::string& species2) {
// //     edges_[species1].insert(species2);
// //     edges_[species2].insert(species1);  // Undirected graph
// //   }

//   // Function to get the connected species for a given node
//   const std::unordered_map<std::string>& get_connected_species(const std::string& species_title) const {
//     return edges_.at(species_title);
//   }

//  private:
//   std::unordered_set<std::string> nodes_;
//   std::unordered_map<std::string, std::unordered_set<std::string>> edges_;
// };