//Fin interseciton
//Max start, Min end
//Earlier end times

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> inter;
        int n = firstList.size(), m = secondList.size();

        //4 condtions
        //first overlaps with second
        //second overlaps with first
        //first is smaller
        //second is smaller

        int i = 0, j = 0;
        int s = 0, e = 0;

        while(i<n && j<m)
        {
            s = max(firstList[i][0], secondList[j][0]);
            e = min(firstList[i][1], secondList[j][1]);

            if(s<=e)
                inter.push_back({s, e});
            if(firstList[i][1] < secondList[j][1])
                i++;
            else if(secondList[j][1] < firstList[i][1])
                j++;
            else
            {
                i++;
                j++;
            }    
        }
        return inter;
    }
};
