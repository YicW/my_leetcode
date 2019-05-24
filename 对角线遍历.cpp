class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int row_cnt=matrix.size();
        int col_cnt=matrix[0].size();

        auto row_index = 0;
        auto col_index = 0;
        result.push_back(matrix[row_index][col_index]);
        if(row_cnt==1&&col_cnt==1)
            return result;
        bool isup=false;
        bool isstart=true;
        while(1)
        {
            if(isup)
            {
                if(row_index==0)
                {
                    if(col_index==(col_cnt-1))
                    {
                        row_index+=1;
                        result.push_back(matrix[row_index][col_index]);
                        if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                            return result;
                        isup=false;
                        continue;
                    }
                    col_index+=1;
                    result.push_back(matrix[row_index][col_index]);
                    if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                        return result;
                    isup=false;
                    continue;
                }
                else if(col_index==(col_cnt-1))
                {
                    row_index+=1;
                    result.push_back(matrix[row_index][col_index]);
                    if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                        return result;
                    isup=false;
                    continue;
                }
                else
                {
                    row_index-=1;
                    col_index+=1;
                    result.push_back(matrix[row_index][col_index]);
                }
                
                
            }
            else
            {
                if (isstart)
				{
					if (col_cnt > 1)
					{
						col_index += 1;
						result.push_back(matrix[row_index][col_index]);
                        if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                            return result;
					}
					isstart = false;
				}
                if(col_index==0)
                {
                    if(row_index==(row_cnt-1))
                    {
                        col_index+=1;
                        result.push_back(matrix[row_index][col_index]);
                        if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                            return result;
                        isup=true;
                        continue;
                    }
                    row_index+=1;
                    result.push_back(matrix[row_index][col_index]);
                    if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                        return result;
                    isup=true;
                    continue;
                }
                else if(row_index==(row_cnt-1))
                {
                    col_index+=1;
                    result.push_back(matrix[row_index][col_index]);
                    if(((row_index+1)==row_cnt)&&((col_index+1)==col_cnt))
                        return result;
                    isup=true;
                    continue;
                }
                else
                {
                    row_index+=1;
                    col_index-=1;
                    result.push_back(matrix[row_index][col_index]);
                }
            }
        }
    }
};
