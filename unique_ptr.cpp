
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
    
using namespace std;

class mystring : public std::string {
public:
    mystring() {
        cout << "constuctor mystring" <<  endl;
    }

    ~mystring() {
        cout << "deconsructor mystring" <<  endl;
    }
};


//auto deconsructor when exit function
void test1() {
    unique_ptr<mystring> m(new mystring());
}




//auto deconsructor fd when exit function
int open_file(string file) {
    int fd = open(file.c_str(), (O_WRONLY | O_APPEND) | O_CREAT, 0644);
    cout << "open file" << endl;
    return fd;
}

int close_file(int *fd) {
    return close(*fd);
}


auto del = [] (int *p) {
  close(*p);
  delete p;
  cout << "delete file" << endl;
};


void test2() {
    unique_ptr<int, decltype(del)> m(new int, del);
    *m = open_file("hello");

}


struct raii_file {
public:
    int fd;
    raii_file(string file) {
        fd = open(file.c_str(), (O_WRONLY | O_APPEND) | O_CREAT, 0644);
        assert(fd >= 0);
    }

    ~raii_file() {
        close(fd);
        cout << "close file" << endl;
    }
};

void test3() {
    string buf = "hello world";
    raii_file rf("world.txt");

    write(rf.fd, buf.c_str(), buf.size());
}




int	main(int argc, char **argv) {
    
    test1();
    test2();
    test3();

    


    return 0;
}
