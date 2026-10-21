#include <bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

vector<string> loadDocuments(const string& directory){
    vector<string> documents;
    error_code ec;
    fs::directory_iterator it(directory, ec);
    if(ec){
        cout<<"The directory \""<<directory<<"\" could not be opened"<<endl;
        return documents;
    }
    for(const auto& entry : it){
        if (!entry.is_regular_file()) continue;
        ifstream file(entry.path(), ios::in);
        if(file.fail()){
            cout<<"The file \""<<entry.path()<<"\" could not be opened"<<endl;
            continue;
        }
        string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        documents.push_back(content);
    }
    return documents;
}
