#include <iostream>
#include "sqlselectquerybuilder.h"


int main()
{

    {
        SqlSelectQueryBuilder qb;
        qb.AddFrom("students")
               .AddColumn("name")
               .AddColumn("phone")
               .AddWhere("id", "42")
               .AddWhere("name", "John")
                ;

        std::cout << "SELECT name, phone FROM students WHERE id=42 AND name=John;" << std::endl;
        std::cout << qb.BuildQuery() << std::endl;
    }

    return 0;
}
