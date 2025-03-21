#include <iostream>
#include <map>
int main() {
    std::map<int,std::string> mp;
    mp.insert({1,"AIshu"});
    mp.insert({2,"Isni"});
    mp.insert({3,"gana"});

    for(auto& pair:mp)
        std::cout<<pair.first<<" : "<<pair.second<<std::endl;
}