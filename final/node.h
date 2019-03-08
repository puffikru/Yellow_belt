#pragma once

#include "date.h"

#ifndef YELLOW_NODE_H
#define YELLOW_NODE_H

enum class LogicalOperation {
    And,
    Or
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

//Compile error: Error while compiling unit-tests for contents of file date.h.
// Details: Compile error: b"In file included from /tmp/submissionwiaw7m21/node.cpp:1:\n/tmp/submissionwiaw7m21/node.h:58:60: fatal error: no template named 'shared_ptr'\n    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp);\n                                                           ^\n1 error generated.\nIn file included from /tmp/submissionwiaw7m21/main.cpp:11:\nIn file included from /tmp/submissionwiaw7m21/database.h:4:\n/tmp/submissionwiaw7m21/node.h:58:60: fatal error: no template named 'shared_ptr'\n    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp);\n                                                           ^\n1 error generated.\nIn file included from /tmp/submissionwiaw7m21/condition_parser.cpp:1:\nIn file included from /tmp/submissionwiaw7m21/condition_parser.h:3:\n/tmp/submissionwiaw7m21/node.h:58:60: fatal error: no template named 'shared_ptr'\n    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp);\n                                                           ^\n1 error generated.\nIn file included from /tmp/submissionwiaw7m21/database.cpp:1:\nIn file included from /tmp/submissionwiaw7m21/database.h:4:\n/tmp/submissionwiaw7m21/node.h:58:60: fatal error: no template named 'shared_ptr'\n    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp);\n
//
// ^\n1 error generated.\n"

/*template <typename T>
bool Compare(Comparison cmp, const T& lhs, const T& rhs);*/

template <typename T>
bool Compare(Comparison cmp, const T& lhs, const T& rhs) {
    switch (cmp) {
        case Comparison::Less: return lhs < rhs;
        case Comparison::LessOrEqual: return lhs <= rhs;
        case Comparison::Greater: return lhs > rhs;
        case Comparison::GreaterOrEqual: return lhs >= rhs;
        case Comparison::Equal: return lhs == rhs;
        case Comparison::NotEqual: return lhs != rhs;
        default: throw logic_error("Wrong comparison type");
    }
}


class Node {
public:
    virtual bool Evaluate(const Date& date, const string& s) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode() = default;
    bool Evaluate(const Date& date, const string& s) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& date);

    bool Evaluate(const Date& date, const string& s) const override;
private:
    const Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& event);
    bool Evaluate(const Date& date, const string& s) const override;
private:
    const Comparison cmp_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp);
    bool Evaluate(const Date& date, const string& s) const override;
private:
    const LogicalOperation op_;
    const shared_ptr<Node> sp_;
    const shared_ptr<Node> exp_;
};

#endif //YELLOW_NODE_H
