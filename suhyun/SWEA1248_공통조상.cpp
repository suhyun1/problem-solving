#include<iostream>
#include<vector>
using namespace std;

int getDepth(vector<int>& parent, int node){
    int depth = 1;
    while(node !=1){
        node = parent[node];
        depth++;
    }
    return depth;
}
int findCommonAncestor(vector<int>& parent, int n1, int n2){
    int n1_d = getDepth(parent, n1);
    int n2_d = getDepth(parent, n2);
    
    if(n1_d > n2_d){
        while(n1_d != n2_d){
            n1 = parent[n1];
            n1_d --;
        }
    }else if(n1_d < n2_d){
        while(n1_d != n2_d){
            n2 = parent[n2];
            n2_d --;
        }
    }
    while(n1!=n2){
        n1 = parent[n1];
        n2 = parent[n2];
    }
    return n1;
}
int getTreeSize(vector<vector<int> >&child, int node ){
    int cnt = 1;
    if(child[node].size() == 0)
        return 1;
    for(int i=0;i<child[node].size();i++){
        cnt += getTreeSize(child, child[node][i]);
    }
    return cnt;
    
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int V, E, n1, n2;
        cin >> V >> E >> n1>>n2;
        vector<int> parent(V+1);
        vector<vector<int> > child(V+1);
        int top, bottom;
        for(int i=0; i<E;i++){
            cin >> top >> bottom;
            parent[bottom] = top;
            child[top].push_back(bottom);
        }
        
        int ancestor = findCommonAncestor(parent, n1,n2);
        int size = getTreeSize(child, ancestor) ;
        cout << "#" << test_case <<" "<< ancestor <<" "<< size<< endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}