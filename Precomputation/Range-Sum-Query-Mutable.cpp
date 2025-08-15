//Use Fenwick tree!
//Create additional data structures if required
//In a private class
//Copy in the class that instantiates

class NumArray {
private:
     vector<int> _bit;
     vector<int> _nums;
     int n;
public:

    NumArray(vector<int>& nums) 
    {
        _nums = nums;
        n = nums.size();
        _bit.resize(n+1, 0);
        for(int i = 0;i<n;i++)
            add(i, _nums[i]);
    }

    void add(int i, int val)
    {
        i++;
        while(i<=n)
        {
            _bit[i] += val;
            i += (i&-i);
        }
    }

    
    
    void update(int index, int val) {
        int diff = val - _nums[index];

      //Update orginal nums, important!
        _nums[index] = val;
        add(index, diff);
    }
    
    int query(int idx)
    {
        idx++;
        int sum = 0;
        while(idx>0)
        {
            sum += _bit[idx];
            idx -= (idx&-idx);
        }
        return sum;
    }
    
    
    int sumRange(int left, int right) {
        if(left == 0)
            return query(right);
        else
            return query(right) - query(left -1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
