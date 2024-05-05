#include <iostream>
#include "sqlselectquerybuilder.h"
#include <map>
#include <vector>

int main()
{

    {
        SqlSelectQueryBuilder qb;
        qb.AddFrom("students")
               .AddColumns(std::vector<std::string>{"name", "phone"})
               .AddWhere(std::map<std::string, std::string>{{"id", "42"}, {"name", "John"}});

        std::cout << "SELECT name, phone FROM students WHERE id=42 AND name=John;" << std::endl;
        std::cout << qb.BuildQuery() << std::endl;
    }

    return 0;
}
