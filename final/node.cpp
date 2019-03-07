//
// Created by Igor Bulakh on 2019-03-06.
//

#include "node.h"

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


bool EmptyNode::Evaluate(const Date& date, const string& s) const {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& s) const {
    return Compare(cmp_, date, date_);
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& value) : cmp_(cmp), value_(value) {}

//TODO: EventComparisonNode
bool EventComparisonNode::Evaluate(const Date& date, const string& s) const {

}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& sp, const shared_ptr<Node>& exp)
    : op_(op), sp_(sp), exp_(exp) {}

//TODO: LogicalOperationNode
bool LogicalOperationNode::Evaluate(const Date& date, const string& s) const {

}