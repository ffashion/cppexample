#include <iostream>
#include <set>

int main() {
    std::multiset<int> myMultiset;

    // 插入元素
    myMultiset.insert(3);
    myMultiset.insert(1);
    myMultiset.insert(4);
    myMultiset.insert(2);
    myMultiset.insert(2); // 允许重复元素

    // 遍历multiset
    for (const auto& elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 查找元素
    auto it = myMultiset.find(2);
    if (it != myMultiset.end()) {
        std::cout << "2 is found in the multiset" << std::endl;
    }

    // 删除元素
    myMultiset.erase(3);

    // 输出multiset大小
    std::cout << "Size of multiset: " << myMultiset.size() << std::endl;

    return 0;
}
