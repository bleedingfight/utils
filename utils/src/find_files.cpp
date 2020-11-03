//
// Created by liushuai on 2020/11/4.
//
#include "find_files.h"
vector<string> list_files(filesystem::path&paths){
    vector<string> files;
    filesystem::path current_path;
    if(!paths.is_absolute())
        current_path = filesystem::absolute(paths);
    else
        current_path = paths;
    for (const auto &entry : filesystem::directory_iterator(current_path)){
        files.push_back(filesystem::absolute(entry.path()).string());
    }
    return files;
}
vector<string> list_files(string& paths){
    filesystem::path current_path = filesystem::path(paths);
    return list_files(current_path);
}