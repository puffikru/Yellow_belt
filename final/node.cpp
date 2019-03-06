//
// Created by Igor Bulakh on 2019-03-06.
//

#include "node.h"


bool EmptyNode::Evaluate(const Date& date, const string& s) const {

}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& s) const {

}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& value) : cmp_(cmp), value_(value) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& s) const {

}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp)
    : op_(op), sp_(sp), exp_(exp) {}
bool LogicalOperationNode::Evaluate(const Date& date, const string& s) const {

}