cmake_minimum_required(VERSION 3.22)
project(BankManagement)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/Node_1.cpp src/Node.cpp src/Hashtable.cpp src/BST_Node.cpp src/BST_Tree.cpp  src/main.cpp
        include/Node_1.h include/Node.h include/Hashtable.h include/BST_Node.h include/BST_Tree.h include/admin.h include/staff.h include/customer.h)
add_executable(BankManagement ${SOURCES})

target_include_directories(BankManagement PUBLIC include)
target_include_directories(BankManagement PUBLIC src)




