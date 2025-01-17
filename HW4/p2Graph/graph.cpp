#include "graph.h"
#include "operation+-.h"

Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    // wait to fill, 使用nodes_.insert()新建一个占位符
    Node* value = new PlaceholderNode(node_name);
    nodes_.insert(node_name, value);
}

void Graph::InsertConstant(const string &node_name, float value) {
    // wait to fill, 使用nodes_.insert()新建一个常量
    Node* nodehere = new ConstantNode(node_name, value);
    nodes_.insert(node_name, nodehere);
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    // wait to fill, 根据operation_type的名字调用相应的运算符节点构造函数
    if (operation_type == "+")
    {
        nodes_.insert(node_name,new Operation_plus(node_name,nodes_[input1],nodes_[input2]));
    }
    else
    {
        nodes_.insert(node_name,new Operation_minus(node_name,nodes_[input1],nodes_[input2]));
    }
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {

    // wait to fill, 调用相应的placeholder的set_val函数
    for(int i = 0; i < argument_num; i++)
    {
        dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]])->set_val(argument_value_list_[i]);
    }
    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;   
}

Graph::~Graph() {
    
}


