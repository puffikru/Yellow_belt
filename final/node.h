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



class Node {
public:
    Node(){}
    virtual bool Evaluate(const Date& date, const string& s) const;
};

class EmptyNode : public Node {
public:
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
    EventComparisonNode(const Comparison& cmp, const string& value);
    bool Evaluate(const Date& date, const string& s) const override;
private:
    const Comparison cmp_;
    const string value_;
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
