//
// Created by liushuai on 2020/11/4.
//
#include "find_files.h"
/*获取当前路径下的所有文件*/
vector<string> list_files(filesystem::path&paths){
    vector<string> files;
    filesystem::path current_path;
    if(!paths.is_absolute())
        current_path = filesystem::absolute(paths);
    else
        current_path = paths;
    for (const auto &entry : filesystem::directory_iterator(current_path)){
        
        if(!entry.is_directory())
            files.push_back(filesystem::absolute(entry.path()).string());
    }
    return files;
}
vector<string> list_files(string& paths){
    filesystem::path current_path = filesystem::path(paths);
    return list_files(current_path);
}

vector<string> list_paths(filesystem::path& root_path){
    vector<string> paths;
    filesystem::path current_path;
    current_path = root_path.is_relative()? filesystem::absolute(root_path):root_path;
    for(const auto&entry:filesystem::directory_iterator(current_path)){
        if(entry.is_directory())
            paths.push_back(entry.path().string());
    }
    return paths;
}
vector<string> list_paths(string& root_path){
    filesystem::path path=filesystem::path(root_path);
    return list_paths(path);
};