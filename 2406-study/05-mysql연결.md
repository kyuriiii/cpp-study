## MacOS에서 MySQL 설치하기

1. `brew install mysql` 을 입려해 mysql 설치
    1. 특정 버전의 설치가 필요한 경우에는 `brew install mysql@버전`으로 입력한다.
2. `mysql_secure_installation` 을 이용해 mysql 설정 마무리

**Error!** Error: Can't connect to local MySQL server through socket '/tmp/mysql.sock' (2)

→ 위의 에러가 나올 경우, `brew uninstall mysql` 로 최종 삭제 이후 공홈에서 다시 다운로드

1. https://dev.mysql.com/downloads/mysql/ 공식 홈페이지로 이동 후 `mac OS 14(ARM, 64-bit), DMG Archive` 다운로드

**최종 방식**

1. `brew install mysql`
2. mysql 서비스 시작 `brew services start mysql`
3. 설치 후 password 등록
    1. `mysql_secure_installation`
    2. VALIDATE PASSWORD PLUGIN 설치여부 질문이 나올 시 N을 선택하고, 나머지는 모두 Y를 선택
4. `mysql -u root -p` 로 접속 테스트

## ~~실패. [homebrew] C++ MySQL 연결하기~~

1. `brew install mysql-connector-c++` 명령어를 통해 c++ mysql 연결 라이브러리 설치
2. homebrew를 통해서 설치된 라이브러리가 존재하는 디렉토리로 이동
    1. `cd /opt/homebrew/Cellar`
    2. `ls -l | grep mysql`
        
        ![스크린샷 2024-06-14 오후 10.20.49.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/d42612ab-abf9-4850-a064-7a052856160e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_10.20.49.png)
        
    3. 버전 위치로 이동 후 추후 컴파일 시 옵션으로 작성해야 하는 include와 lib 폴더 확인
        
        ![스크린샷 2024-06-14 오후 10.23.15.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/65775d45-922a-4810-92ef-8f0541816fe9/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_10.23.15.png)
        
3. Compiler Check
    1. Mysql에서 아래와 같이 스키마에 접속해 테스트 테이블 생성
        
        ```sql
        CREATE TABLE cpp_test (
        	seq INT AUTO_INCREMENT PRIMARY KEY,
        	rand_key INT NOT NULL
        );
        ```
        
    2. c++ 프로젝트 생성 후 아래 코드 작성
        
        ```cpp
        #include <iostream>
        #include <mysqlx/xdevapi.h>
        
        using namespace std;
        
        int main(){
            try {
                // mysql의 호스트명, 포트, 계정명, 계정비밀번호
                mysqlx::Session session("localhost",3306,"root","1234"):
                
                // Use testdb database
                mysqlx::Schema db = session.getSchema("cpp");
                mysqlx::Table table = db.getTable("cpp_test");
                
                // CREATE: Insert data
                table.insert("rand_key").values(25).execute();
            } catch( const std::exception& e) {
                cerr << "Error : " << e.what() << endl;
            }
        }
        ```
        
    3. 터미널에서 컴파일을 하기 위해 아래 shell명령어 입력
        
        ```cpp
        // 소스코드
        // /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/main.cpp
        // 컴파일된 결과 이름
        // /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/compiler.cpp
        
        //실제예시
        /usr/bin/g++ -fdiagnostics-color=always -g -std=c++17
        /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/main.cpp -o /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/compiler.cpp
        -I/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/include
        -L/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/lib
        -lmysqlcppconn8
        ```
        

## [mysql공홈] C++ MySQL 연결

1. https://downloads.mysql.com/archives/c-cpp/ 사이트에서 macOS 14 (ARM, 64-bit), DMG Archive 다운로드 후 설치
2. 설치 위치에 `jdbc.h` 파일이 존재하는지 확인하기
    
    ![스크린샷 2024-06-14 오후 10.55.31.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/a11510ef-2789-48f8-b917-eef2dfece436/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_10.55.31.png)
    
3. c++ 코드 작성

```cpp
#include <iostream>
#include <string>
#include <mysql/jdbc.h>

using std::cout;
using std::endl;

int main()
{
    try {
        // MySQL Connector/C++ 초기화
        sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
        con->setSchema("cpp"); // 데이터베이스 선택

        // 데이터베이스 쿼리 실행
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM cpp_test");

        // 결과 출력
        while (res->next()) {
            cout << res->getString("seq") << endl; // id 컬럼 출력하겠다.
        }

        // MySQL Connector/C++ 정리
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "MySQL error: " << e.getErrorCode() << " " << e.what() << endl;
    }

    return 0;
}

```

### **실패. 방법 1. Visual Studio Code 설정**

1. Visual Studio Code에서 `c_cpp_properties` 파일 수정
    1. `cmd + shift + P` 를 눌러 명령팔레트 오픈
    2. `>c/c++: edit configurations (json)` 를 검색 후 json 파일 오픈
    3. includePath 부분을 아래와 같이 수정
        
        ```cpp
        "includePath": [
          "${workspaceFolder}/**",
          "/usr/local/mysql-connector-c++-8.3.0/include"
        ],
        ```
        
2. 환경 변수 추가 및 확인
    
    **환경 변수 추가하기**
    
    1. 홈 디렉토리로 이동
        
        ```bash
        cd ~
        ```
        
    2.  .bash_profile 파일을 연다. (.bash_profile 안 될 경우 .zshrc로)
        
        ```bash
        vi .bash_profile
        ```
        
    3. 환경 변수를 추가한다.
        
        ```bash
        DYLD_LIBRARY_PATH=/usr/local/mysql-connector-c++-8.3.0/lib64
        export DYLD_LIBRARY_PATH
        ```
        
    4. 변경된 환경 변수를 적용한다.
        
        ```bash
        source .bash_profile
        ```
        
    
    **환경 변수 확인하는 법**
    
    ```bash
    echo $DYLD_LIBRARY_PATH
    ```
    
3. build 후 실행해보기
    1. includePath에 경로를 추가해줬지만, 컴파일 할 때 컴파일러에게도 경로를 따로 알려줘야 한다.
        
        `-I /usr/local/mysql-connector-c++-`8.3.0`/include`
        
        ```bash
        g++ -std=c++17 -I /usr/local/mysql-connector-c++-8.3.0/include -L /usr/local/mysql-connector-c++-8.3.0/lib64 -l mysqlcppconn main.cpp -o main
        ```
        
        ![스크린샷 2024-06-15 오전 9.13.08.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/d02432c2-98b5-4be6-ab1e-094d596a06b5/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-15_%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB_9.13.08.png)
        
4. Error! `Library not loaded: @rpath/libmysqlcpconn.9.dylib`
    
    ![스크린샷 2024-06-15 오전 9.22.30.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/ab849070-cb77-4266-83a1-71703752f211/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-15_%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB_9.22.30.png)
    
    1. ~~해결방법 1. **실패**~~
        1. 컴파일 시 `@rpath` 추가할 것.
            
            ```cpp
            g++ -std=c++17 -I /usr/local/mysql-connector-c++-8.3.0/include -L /usr/local/mysql-connector-c++-8.3.0/lib64 -l mysqlcppconn main.cpp -o main -Wl,-rpath,/usr/local/mysql-connector-c++-8.3.0/lib64 main.cpp
            ```
            

### **실패. 방법2. XCode 설정**

1. XCode에서 프로젝트 파일 선택 후 Build Settings 탭으로 이동
    
    ![스크린샷 2024-06-14 오후 11.18.06.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/a124bdcd-cdc7-402b-b82c-5209445c175a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.18.06.png)
    
2. Build Settings 탭의 Header Search Path 항목을 찾아 아래 경로를 추가
    
    ```cpp
    /usr/local/mysql-connector-c++-8.3.0/include
    ```
    
    ![스크린샷 2024-06-14 오후 11.20.04.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/07c0c331-69ad-46e1-bd27-bac2f6f15f7a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.20.04.png)
    
3. Build Settings 탭의 Library Search Paths 항목을 찾아 아래의 라이브러리 경로 설정
    
    ```cpp
    /usr/local/mysql-connector-c++-8.3.0/lib64
    ```
    
    ![스크린샷 2024-06-14 오후 11.23.01.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6f01d0d0-2e35-421f-ba74-61266e3fbd7e/f0782f11-4c57-4cd2-824d-429fb4e77317/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2024-06-14_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.23.01.png)
    
4. Build Phases 탭으로 이동해 Link Binary With Libraries 섹션을 찾아 +를 누르고 팝업 창에서 `Add Others...` 를 선택하고 `/usr/local/mysql-connector-c++-8.3.0/lib64/libmysqlcppconn8.dylib` 파일 추가 
    
    이때, 파일을 찾는 게 어렵다면 아래와 같이 진행
    
    ```cpp
    나타나는 파일 선택 창에서 아무 위치나 클릭한 상태에서 Cmd+Shift+G (Command + Shift + G) 키를 눌러 Go to the folder 창을 엽니다.
    경로 입력 창에 /usr/local/mysql-connector-c++-8.3.0/lib64를 입력하고 Go를 클릭합니다.
    ```
    

### **성공. 방법 3. CMake 와 Visual Studio Code 활용**

> CMake란?
- C/C++에서 사용되는 빌드 시스템
- makefile을 자동으로 생성해주는 툴이라고 보면 된다. 즉 내부적으로 make를 이용하는데, 이 makefile을 직접 관리하는 대신 CMake를 통해서 관리하는 개념이다.
> 
1. CMake 설정 파일 생성
    1. `CMakeLists.txt` 파일 생성 후 아래의 내용 추가
        
        ```cpp
        cmake_minimum_required(VERSION 3.10)
        
        project(cppmysql)
        
        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED True)
        
        # MySQL Connector C++ 라이브러리 경로 설정
        include_directories(/usr/local/mysql-connector-c++-8.3.0/include)
        link_directories(/usr/local/mysql-connector-c++-8.3.0/lib64)
        
        add_executable(cppmysql main.cpp)
        
        target_link_libraries(cppmysql mysqlcppconn)
        ```
        
2. main.cpp 파일 생성
3. CMake 를 활용한 빌드
    
    ```cpp
    cmake .
    make
    ```
    
    *만약, `zhs:command not found cmake` 에러가 나온다면?*
    
    ```cpp
    brew install cmake
    ```
    
4. 프로그램 실행
    
    ```cpp
    ./cppmysql
    ```