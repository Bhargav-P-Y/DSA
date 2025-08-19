//You don't need to worry about further maximum values
//Becasue the bottleneck is the minimum between the 
//left and right values

//If a value is smaller, move that
//Becasue that is our bottleneck
//Move it forward hopefully you'll get a larger value

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lmax = height[l], rmax = height[r]; 
        int water = 0;

        while(l<r)
        {
            if(lmax<rmax)
            {
                l+=1;
                lmax = max(lmax, height[l]);
                water += lmax-height[l];
            }
            else
            {
                r-=1;
                rmax = max(rmax, height[r]);
                water += rmax -height[r];
            }
        }
        return water;
        
    }
};
