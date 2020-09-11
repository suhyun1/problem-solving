#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//풀이 순서
//y높이 순 정렬
//각 node의 children 지정
//전위순회, 후위순회

struct Node {
    int index;
    int x,y;
    Node* leftChild = NULL;
    Node* rightChild = NULL;
};

bool cmp(const Node& a, const Node& b){
    return a.y > b.y;
}

void insert(Node* parent, Node* child){
    if(child -> x < parent -> x){
        if(parent -> leftChild == NULL)
            parent -> leftChild = child;
        else
            insert(parent -> leftChild, child);
    }else{
        if(parent -> rightChild == NULL)
            parent -> rightChild = child;
        else
            insert(parent -> rightChild, child);
    }
}

void preorder(Node* node,  vector<int>& result){
    if(node == NULL) return;
    result.push_back(node -> index);
    preorder(node -> leftChild, result);
    preorder(node -> rightChild, result);
}
void postorder(Node* node,  vector<int>& result){
    if(node == NULL) return;
    postorder(node -> leftChild, result);
    postorder(node -> rightChild, result);
    result.push_back(node -> index);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes(nodeinfo.size());
    for(int i=0; i<nodeinfo.size();i++){
        nodes[i].index = i + 1;
        nodes[i].x = nodeinfo[i][0];
        nodes[i].y = nodeinfo[i][1];
    }
    sort(nodes.begin(), nodes.end(), cmp);

    Node* root = &nodes[0];
    for(int i=1; i<nodes.size();i++){
        insert(root, &nodes[i]);
    }
    vector<int> pre_result, post_result;
    preorder(root, pre_result);
    postorder(root, post_result);

    answer.push_back(pre_result);
    answer.push_back(post_result);
    return answer;
}