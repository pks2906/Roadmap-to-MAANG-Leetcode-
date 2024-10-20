bool possible(vector<int> &arr, int day, int r, int b){
	int cnt = 0;
	int noOfB = 0;

	for(int i = 0; i<arr.size(); i++){
		if(arr[i] <= day){
			cnt++;
		}
		else{
			noOfB += (cnt/b);
			cnt = 0;
		}
	}

	noOfB += (cnt/b);
	return noOfB >= r;
}


class Solution {
public:
    int minDays(vector<int>& bloomDay, int k, int m) {
    long long val = k * 1LL * m * 1LL;
	if(val > bloomDay.size()) return -1;
	int mini = INT_MAX, maxi = INT_MIN;
	for(int i = 0; i<bloomDay.size(); i++){
		mini = min(mini, bloomDay[i]);
		maxi = max(maxi, bloomDay[i]);
	}

	int low = mini, high = maxi;
	while(low <= high){
		int mid = (low + high) / 2;
		if(possible(bloomDay, mid, k, m)){
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return low;
        
    }
};