//
//  main.cpp
//  05-mysql
//
//  Created by 김규리 on 6/14/24.
//

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
