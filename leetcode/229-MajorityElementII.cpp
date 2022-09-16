class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x(-1), z(-1), cx(0), cz(0);
        for (int i: nums){
            if (i == x){
                cx++;
            } else if (i == z){
                cz++;
            } else if (!cx){
                x = i;
                cx++;
            } else if (!cz){
                z = i;
                cz++;
            } else {
                cx--;
                cz--;
            }
        }
        cx = cz = 0;
        for (int i: nums){
            if (i == x){
                cx++;
            } else if (i == z){
                cz++;
            }
        }
        vector<int> res;
        if (cx > nums.size() / 3){
            res.push_back(x);
        }
        if (cz > nums.size() / 3){
            res.push_back(z);
        }
        return res;
    }
};