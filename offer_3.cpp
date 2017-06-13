class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if(array.empty())
			return false;

		int row = array.size();
		for(int i=0; i<row; i++){
			if(array[i].empty())
				continue;
			else if(target >= array[i][0]){
				if(target <= array[i][array[i].size()-1])
					for (int j=array[i].size()-1; j>=0; j--){
						if(target == array[i][j])
							return true;
						else if(target > array[i][j])
							break;
					}
				else
					continue;
			}
			else
				return false;                
		}

		return false;
	}
};