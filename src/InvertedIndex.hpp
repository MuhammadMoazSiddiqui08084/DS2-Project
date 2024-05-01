#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>



struct species {
    std::string title;
    bool features[11]; 
    //flat_nails, olfactory, collarbone, bipedaism, sit_up, walk_up, moist nose, placenta, toothcomb, nostril, big_eyes;
};


struct tree_node {
    std::vector<species> group;
    tree_node *left = nullptr;
    tree_node *right = nullptr;
};


class inverted_index {
    int num_attr = 11;
    std::vector<species> all_species;
    
    tree_node *root;
    
    public:
    // Empty constructor to initialize an empty inverted index
    inverted_index(const std::vector<std::vector<std::string>>& data);

    //function for forming the species data into an inverted index
    void handle_data(const std::vector<std::vector<std::string>>& data);

    // Function to add a new species to the index
    void add_species(const species& new_species);

    // Function to compare two species and return their similarity score
    double compare_species(const species& species1, const species& species2) const ;

    //function for constructing a tree
    void construct_tree(const std::vector<species>& subgroup, tree_node *subroot, int cur_attr);

    //function for displaying a particular group
    void display_node() const;

    void createDotFile(std::ofstream& dotFile);
};

