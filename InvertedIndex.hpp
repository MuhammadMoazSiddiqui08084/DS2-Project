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
    //flat_nails, olfactory, collarbone, bipedaism, sit_up, walk_up, placenta, toothcomb, nostril, big_eyes;
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
    // const int MAX = num_attr+10;
    tree_node* tree[25];

    
    public:
    // Empty constructor to initialize an empty inverted index
    inverted_index(const std::vector<std::vector<std::string>>& data);

    void handle_data(const std::vector<std::vector<std::string>>& data);

    // void tree_array();

    // Function to add a new species to the index
    void add_species(const species& new_species);

    // Function to compare two species and return their similarity score
    double compare_species(const species& species1, const species& species2) const ;

    void construct_tree(const std::vector<species>& subgroup, tree_node *subroot, int cur_attr);

    void display_tree() const;

    void createDotFile(std::ofstream& dotFile);



};

