#include <filesystem>
#include <string>
#include <iostream>
#include "find_files.h"
using namespace std;
int main(){
    string filename = "..";
    auto path = filesystem::current_path().parent_path();
    auto parent_path = filesystem::current_path().parent_path();
    auto files = list_paths(path);
    for(auto e:files)
        cout<<e<<endl;
//    filesystem::exists('f')
}