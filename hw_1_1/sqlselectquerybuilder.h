#ifndef SQLSELECTQUERYBUILDER_H
#define SQLSELECTQUERYBUILDER_H

#include <string>
#include <vector>
#include <map>
#include <sstream>

class SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder();

    SqlSelectQueryBuilder& AddFrom(const std::string& table_name);

    SqlSelectQueryBuilder& AddColumn(const std::string& column_name);

    SqlSelectQueryBuilder& AddWhere(const std::string& column_name, const std::string& value);

    std::string BuildQuery();


private:

    std::string table_name;

    std::vector<std::string> columns;

    std::map<std::string, std::string> where_clauses;

};

#endif // SQLSELECTQUERYBUILDER_H
