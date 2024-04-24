#include "InvertedIndex.hpp"


void inverted_index::display_node() const{
    std::vector<species> cur_group = root->right->group;

    for (species a : cur_group){
        std::cout<<a.title<<std::endl;
    }
}

void inverted_index::handle_data(const std::vector<std::vector<std::string>>& data){
    species cur_species;

    for (size_t i=0; i<data.size(); i++){
        cur_species.title = data[i][0];

        for(int j=0; j<num_attr; j++){
            if (data[i][j+1] == "Yes"){
                cur_species.features[j] = true;
            }
            else{
                cur_species.features[j] = false;
            }
        }
        all_species.push_back(cur_species);
    }
}

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
    double match = similar_traits/num_attr;
    return match;
}


inverted_index::inverted_index(const std::vector<std::vector<std::string>>& data){
        // function for populating inverted index called here// 
        handle_data(data);
        root = new tree_node;
        root->group = all_species;
        construct_tree(all_species, root, 0);
    }

void inverted_index::construct_tree(const std::vector<species> &subgroup, tree_node *subroot, int attr){

    if (subgroup.size()<=0){
        subroot = nullptr;
    }
    else{
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

        if (attr+1<=num_attr){
            construct_tree(cur->left->group, cur->left, attr+1);
            construct_tree(cur->right->group, cur->right, attr+1);
        }
    }
}

void inverted_index::createDotFile(std::ofstream &dotFile){
    // if (!root) return;

    std::queue<tree_node*> q;
    q.push(root);

    while (!q.empty()) {
        tree_node* node = q.front();
        q.pop();

        std::string data = node->group[0].title;
        for (int x=1; x<node->group.size(); x++){
            data += ", ";
            data += node->group[x].title;
        }

        if (node)
            dotFile << data << " [label=\"" << data << "\"];\n";

        if (node->left) {
            dotFile << data << " -> " << node->left->group.size()<< ";\n";
            q.push(node->left);
        }
        if (node->right) {
            dotFile << data << " -> " << node->right->group.size() << ";\n";
            q.push(node->right);
        }
    }
}