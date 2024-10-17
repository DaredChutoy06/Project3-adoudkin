#include <iostream>
#include <fstream>
#include <vector>

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "HeartAttack.h"
#include "SplayTree.h"
#include "algorithm"
#include "random"
using namespace std;

int main() {
    std::ofstream avl_tree_file, bs_tree_file, splay_tree_file, avl_tree_rand_file, bs_tree_rand_file,
                    splay_tree_rand_file, avl_tree_ha_file, bs_tree_ha_file, splay_tree_ha_file, splay_tree_d5_file;
    std::string avl_tree_depth_file_name = "avl_tree_depth";
    std::string bs_tree_depth_file_name = "bs_tree_depth";
    std::string splay_tree_depth_file_name = "splay_tree_depth";

    std::string avl_tree_rand_file_name = "avl_tree_rand_file";
    std::string bs_tree_rand_file_name = "bs_tree_rand_file";
    std::string splay_tree_rand_file_name = "splay_tree_rand_file";

    std::string avl_tree_ha_file_name = "avl_tree_ha_file";
    std::string bs_tree_ha_file_name = "bs_tree_ha_file";
    std::string splay_tree_ha_file_name = "splay_tree_ha_file";

    std::string splay_tree_d5_file_name = "splay_tree_d5_file";

    avl_tree_file.open(avl_tree_depth_file_name, std::ofstream::out | std::ofstream::trunc);
    bs_tree_file.open(bs_tree_depth_file_name,std::ofstream::out | std::ofstream::trunc);
    splay_tree_file.open(splay_tree_depth_file_name,std::ofstream::out | std::ofstream::trunc);

    avl_tree_rand_file.open(avl_tree_rand_file_name,std::ofstream::out | std::ofstream::trunc);
    bs_tree_rand_file.open(bs_tree_rand_file_name,std::ofstream::out | std::ofstream::trunc);
    splay_tree_rand_file.open(splay_tree_rand_file_name,std::ofstream::out | std::ofstream::trunc);

    avl_tree_ha_file.open(avl_tree_ha_file_name, std::ofstream::out | std::ofstream::trunc);
    bs_tree_ha_file.open(bs_tree_ha_file_name,std::ofstream::out | std::ofstream::trunc);
    splay_tree_ha_file.open(splay_tree_ha_file_name,std::ofstream::out | std::ofstream::trunc);

    splay_tree_d5_file.open(splay_tree_d5_file_name,std::ofstream::out | std::ofstream::trunc);

    AVLTree<int> avlt;
    BinarySearchTree<int> bst;
    SplayTree<int> st;
    int depth = 0;

    AVLTree<int> avlt_rand;
    BinarySearchTree<int> bst_rand;
    SplayTree<int> st_rand;
    std::vector<int> temp_vect;



    for (int i = 1; i <= 100; i++) {
        avlt.add(i);
        bst.add(i);
        st.add(i);
        temp_vect.push_back(i);
    }
    auto rng = std::default_random_engine();
    std::shuffle(std::begin(temp_vect), std::end(temp_vect),rng);

    for (int i = 1; i <= 100; i++) {
        avlt_rand.add(temp_vect.at(i-1));
        bst_rand.add(temp_vect.at(i-1));
        st_rand.add(temp_vect.at(i-1));
    }


    for (int i = 1; i <= 105; i++) {
        if(avlt.find(i,depth)) {
            avl_tree_file << i << " "<< depth << " " << std::endl;
        };
        depth = 0;
        if(bst.find(i,depth)) {
            bs_tree_file << i << " "<< depth << " " << std::endl;
        }
        depth = 0;
        if(st.find(i,depth)) {
            splay_tree_file << i << " "<< depth << " " << std::endl;
        }
    }

    for (int i = 1; i <= 105; i++) {
        if(avlt_rand.find(i,depth)) {
            avl_tree_rand_file << i << " "<< depth << " " << std::endl;
        };
        depth = 0;
        if(bst_rand.find(i,depth)) {
            bs_tree_rand_file << i << " "<< depth << " " << std::endl;
        }
        depth = 0;
        if(st_rand.find(i,depth)) {
            splay_tree_rand_file << i << " "<< depth << " " << std::endl;
        }
    }





    std::vector<HeartAttack> heart_attacks;
    std::string fn = "../new_heart_attack_dataset.csv";

    //loads information from the csv file
    if (loadFromFile(fn, heart_attacks)) {
        AVLTree<HeartAttack> avl_tree_ha;
        BinarySearchTree<HeartAttack> bs_tree_ha;
        SplayTree<HeartAttack> splay_tree_ha;

        for (int i = 0; i < heart_attacks.size(); i++) {
            avl_tree_ha.add(heart_attacks.at(i));
            bs_tree_ha.add(heart_attacks.at(i));
            splay_tree_ha.add(heart_attacks.at(i));
        }
        std::cout << " avl: " << avl_tree_ha.getSize()
                  << " bs: " << bs_tree_ha.getSize()
                  << " splay: " << splay_tree_ha.getSize() << std::endl;

        std::cout << "entries: " << heart_attacks.size() << std::endl;

        for (int i = 0; i < heart_attacks.size() ; i++) {
            if(avl_tree_ha.find(heart_attacks.at(i),depth)) {
                avl_tree_ha_file << heart_attacks.at(i).getID()<< " "<< depth << " " << std::endl;
            };
            depth = 0;
            if(bs_tree_ha.find(heart_attacks.at(i),depth)) {
                bs_tree_ha_file << heart_attacks.at(i).getID() << " "<< depth << " " << std::endl;
            }
            depth = 0;
            if(splay_tree_ha.find(heart_attacks.at(i),depth)) {
                splay_tree_ha_file << heart_attacks.at(i).getID() << " "<< depth << " " << std::endl;
            }
        }

        SplayTree<HeartAttack> splay_tree_d5;

        for(int i = 0; i < heart_attacks.size(); i++) {
            splay_tree_d5.add(heart_attacks.at(i));
        }

        for(int i = 0; i < heart_attacks.size(); i++) {
            for(int j = 0; j < 5; j++) {
                depth = 0;
                if(splay_tree_d5.find(heart_attacks.at(i),depth)) {
                    splay_tree_d5_file << heart_attacks.at(i).getID() << " "<< depth << " " << std::endl;
                }
            }

        }
    }else {
        std::cout << "Something went wrong." << std::endl;
    }


    avl_tree_file.close();
    bs_tree_file.close();
    splay_tree_file.close();
    avl_tree_rand_file.close();
    bs_tree_rand_file.close();
    splay_tree_rand_file.close();
    avl_tree_ha_file.close();
    bs_tree_ha_file.close();
    splay_tree_ha_file.close();
    splay_tree_d5_file.close();

}
