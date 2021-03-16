#include <filesystem>
#include <string>
#include <vector>
using namespace std;
vector<string> list_files(filesystem::path&paths);
vector<string> list_files(string& paths);
vector<string> list_paths(filesystem::path&paths);
vector<string> list_paths(string& paths);