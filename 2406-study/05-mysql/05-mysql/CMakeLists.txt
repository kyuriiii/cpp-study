cmake_minimum_required(VERSION 3.10)

project(cppmysql)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# MySQL Connector C++ 라이브러리 경로 설정
include_directories(/usr/local/mysql-connector-c++-8.3.0/include)
link_directories(/usr/local/mysql-connector-c++-8.3.0/lib64)

add_executable(cppmysql main.cpp)

target_link_libraries(cppmysql mysqlcppconn)
