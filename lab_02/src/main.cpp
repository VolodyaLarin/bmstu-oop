#include <iostream>

#include "./inc/list.h"

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    int n = 5;
    List<int> list_from_arr(arr, n);
    List<int> list_ord;
    List<int> list_initializer{0, 1, 2, 3, 4};
    List<const double> list_initializer_c{0.1, 1, 2, 3, 4};


    for (int i = 0; i < 5; ++i) {
        list_ord.push_back(i);
    }
    std::cout << list_from_arr;
    std::cout << list_ord;
    std::cout << list_initializer;

    for (auto i : list_initializer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto i : list_initializer_c) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    List<double> some = {1,2,3.4,5};
    some.reverse();
    std::cout << some;

    auto start = some.begin();
    some.remove(start);
    std::cout << some;

    some = {1,2,3, 4, 5, 6,7,8,9,10};
    start = some.begin();
    auto second = some.begin() + 5;
    some.remove(start, second);
    std::cout << some;

    List<double> some2 = {1,2,3.};

    some.push_front(some2);

    std::cout << some;


    List<int> list_some = {1,2,3,5};
    List<int> list_some2 = {-1,1,-1,1,-1,1,-1,1};

    list_some2.insert(list_some2.begin() + 4, list_some.begin() + 1, list_some.begin() + 3);
    std::cout << list_some2;


    return 0;
}