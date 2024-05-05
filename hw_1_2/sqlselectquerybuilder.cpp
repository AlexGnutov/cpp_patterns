#include "sqlselectquerybuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{

}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddFrom(const std::string &table_name) {
    this->table_name = table_name;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumn(const std::string &column_name) {
    this->columns.push_back(column_name);
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumns(std::vector<std::string> columns)
{
    this->columns = columns;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddWhere(const std::string &column_name, const std::string &value) {
    this->where_clauses[column_name] = value;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddWhere(std::map<std::string, std::string> kv)
{
    this->where_clauses = kv;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {

    if (table_name.empty()) {
        return "error: table_name is not set";
    }

    std::stringstream ss;

    ss << "SELECT ";

    if (columns.empty()) {
        ss << "* ";
    } else {
        std::string sep;
        for (auto& c : columns) {
            ss << sep << c;
            sep = ", ";
        }
        ss << " ";
    }

    ss << "FROM " << table_name;

    if (!where_clauses.empty()) {
        ss << " WHERE ";
        std::string sep;
        for (auto& p : where_clauses) {
            ss << sep << p.first << "=" << p.second;
            sep = " AND ";
        }
    }

    ss << ";";
    return ss.str();
}
