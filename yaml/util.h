//
// Created by waxz on 18-11-16.
//

#ifndef MINI_YAML_UTIL_H
#define MINI_YAML_UTIL_H
#include "Yaml.hpp"
#include <string>

using std::string;
namespace Yaml {

    inline Node readFile(string filename) {
        Node root;
        Parse(root, filename.c_str());
        return root;
    }
}
#endif //MINI_YAML_UTIL_H
