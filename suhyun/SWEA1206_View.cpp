#include<iostream>
#include<vector>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int houseViewCount = 0;
        int numOfBuilding;
        vector<int> buildingArr;
        int tmp;
         
        cin >> numOfBuilding;
        for(int i=0; i<numOfBuilding;i++){
            cin >> tmp;
            buildingArr.push_back(tmp);
        }
         
        for(int i=2; i<numOfBuilding-2;i++){
            int height = buildingArr[i];
            if(buildingArr[i-1]< height && buildingArr[i+1]< height && buildingArr[i-2]< height && buildingArr[i+2]< height){
                 
                int maxHeight = 0; 
                for(int j=i-2; j<i+3;j++){
                    if(j !=i && maxHeight <buildingArr[j] ){
                        maxHeight = buildingArr[j];
                    }
                }
                houseViewCount+= height-maxHeight;
            }
        }
         
        cout << "#" << test_case<< " " << houseViewCount << endl;
 
    }
    return 0;
}