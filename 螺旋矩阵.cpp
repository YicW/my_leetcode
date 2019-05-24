class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result,index_x,index_y;
        if(matrix.empty())
            return result;
        for(auto i=0;i<matrix.size();i++)
        {
            index_y.push_back(i);
        }
        for(auto i=0;i<matrix[0].size();i++)
        {
            index_x.push_back(i);
        }
        int matrix_case = 1;
        /*bool row = true;当前访问的是不是矩阵的行
        bool isreverse = false;当前访问方向:true：begin->end；false：end->begin
        case    row     reverse
            1   true    false
            2   false   false
            3   true    true
            4   false   true*/
        while(1)
        {
            switch (matrix_case)
            {
                case 1 :
                    {
                        for(auto it = index_x.begin();it!=index_x.end();it++)
                            result.push_back(matrix[index_y[0]][*it]);
                        index_y.erase(index_y.begin());
                        if(index_x.empty()||index_y.empty())
                            return result;
                        matrix_case=2;
                        break;
                    }
                case 2 :
                    {
                        for(auto it = index_y.begin();it!=index_y.end();it++)
                            result.push_back(matrix[*it][*(index_x.rbegin())]);
                        index_x.erase(index_x.end()-1);
                        if(index_x.empty()||index_y.empty())
                            return result;
                        matrix_case=3;
                        break;
                    }
                case 3 :
                    {
                        for(auto it = index_x.rbegin();it!=index_x.rend();it++)
                            result.push_back(matrix[*(index_y.rbegin())][*it]);
                        index_y.erase(index_y.end()-1);
                        if(index_x.empty()||index_y.empty())
                            return result;
                        matrix_case=4;
                        break;
                    }
                case 4 :
                    {
                        for(auto it = index_y.rbegin();it!=index_y.rend();it++)
                            result.push_back(matrix[*it][index_x[0]]);
                        index_x.erase(index_x.begin());
                        if(index_x.empty()||index_y.empty())
                            return result;
                        matrix_case=1;
                        break;
                    }     
            }

            
        }
    }
};
