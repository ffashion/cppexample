#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    // 插入元素
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(2);

    if (!mySet.insert(2).second) {
        std::cout << "insert error\n";
        // return -1;
    }


    // 遍历集合
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (mySet.find(2) != mySet.end()) {
        std::cout << "2 is found in the set" << std::endl;
    }

    // 删除元素
    mySet.erase(3);

    // 输出集合大小
    std::cout << "Size of set: " << mySet.size() << std::endl;

    return 0;
}
