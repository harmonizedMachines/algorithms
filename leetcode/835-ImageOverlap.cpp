class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0;
        for (int a = 0; a < img1.size(); ++a){
            for (int b = 0; b < img1[0].size(); ++b){
                int tempres1 = 0, tempres2 = 0, tempres3 = 0, tempres4 = 0;
                for (int c = 0; c + a < img1.size(); ++c){
                    for (int d = 0; d + b < img1[0].size(); ++d){
                        if (img1[c+a][d+b] && img2[c][d]){
                            ++tempres1;
                        }
                        if (img2[c+a][d+b] && img1[c][d]){
                            ++tempres2;
                        }
                        if (img1[c][d+b] && img2[c+a][d]){
                            ++tempres3;
                        }
                        if (img2[c][d+b] && img1[c+a][d]){
                            ++tempres4;
                        }
                    }
                }
                res = max(max(res, tempres1), tempres2);
                res = max(max(res, tempres3), tempres4);
            }
        }
        return res;
    }
};