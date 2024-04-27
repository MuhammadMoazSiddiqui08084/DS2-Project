#include "InvertedIndex.hpp"
#include "InvertedIndex.cpp"
#include "InputHandling.cpp"


int main() {
    
    std::string csv_filename = "Primate Data - Sheet1.csv"; //csv filename containing all species data

    std::vector<std::vector<std::string>> csv_data;
    csv_input(csv_filename, csv_data); //arranging species data

    bool csv_method = false; //obtain data through csv_file

    inverted_index primate_data(csv_data);

    if (!csv_method){
        //flat_nails, olfactory, collarbone, bipedaism, sit_up, walk_up, nose, placenta, toothcomb, nostril, big_eyes;
        std::string entry1[12] = {"Preuss's Monkey", "Yes", "Yes", "Yes", "Yes", "Yes", "No", "No", "No", "Yes", "No", "No"};
        std::string entry2[12] = {"Human", "Yes", "Yes", "Yes", "Yes", "Yes", "Yes", "No","No", "No", "Yes", "No"};
        std::string entry3[12] = {"White faced Saki", "Yes", "Yes", "Yes", "Yes", "Yes", "No", "No", "No", "No", "No", "No"};
        std::string entry4[12] = {"Angolan dwarf golago", "Yes", "No", "Yes", "Yes", "Yes", "No", "Yes", "Yes", "No", "No", "No"};


        std::vector<vector<string>> data;
        std::vector<string> entry;

        data.push_back(entry);
        for (int i=0; i<12; i++){
            data[0].push_back(entry1[i]);
        }

        data.push_back(entry);
        for (int i=0; i<12; i++){
            data[1].push_back(entry2[i]);
        }

        data.push_back(entry);
        for (int i=0; i<12; i++){
            data[2].push_back(entry3[i]);
        }

        data.push_back(entry);
        for (int i=0; i<12; i++){
            data[3].push_back(entry4[i]);
        }
        primate_data = inverted_index(data);
    
    }
        
    primate_data.display_node();
    
    // if (!csv_method){
    //     ofstream dotFile("binary_tree.dot");
    //     if (!dotFile) {
    //         cerr << "Error: Unable to create DOT file." << endl;
    //         return 1;
    //     }

    //     dotFile << "digraph BinaryTree {" << endl;
    //     primate_data.createDotFile(dotFile);
    //     dotFile << "}" << endl;
    //     dotFile.close();

    //     // Use Graphviz to generate image
    //     system("dot -Tpng binary_tree.dot -o binary_tree.png");

    //     std::cout << "Binary tree visualization generated as binary_tree.png" << endl;
    // }
    return 0;
}
