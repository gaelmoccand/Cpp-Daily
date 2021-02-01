#include <map>
#include <algorithm>
#include <iostream>
#include <experimental/map>

template <typename C>
void disp(const C& cont) {

    for (const auto& elem : cont){
        std::cout << elem.first << " : ";
        std::cout << elem.second << "\n";
    }

}

int main() {

    using namespace std;

    map<int,int> mymap {{1,10},{2,20},{3,30},{4,40}};
    cout << "mymap" << "\n";
    disp(mymap);
    
    auto predEvenKey = [](auto const& elem){ auto const [key, val] = elem; return key % 2 == 0;};

    // trick to remove evenKey using loop < C++20
    cout << "for loop" << "\n";
    for(auto it = mymap.begin(); it != mymap.end(); /*not increament here*/) {
        if(predEvenKey(*it)) {
            it = mymap.erase(it); // erase returns the iter. following the removed elements
        }
        else {
            ++it;
        }

    }
    disp(mymap);

    // remove evenKey using erase_if C++20
    cout << "erase_if(mymap,evenKey)" << "\n";
    std::experimental::erase_if(mymap, predEvenKey);
    disp(mymap);
    

}