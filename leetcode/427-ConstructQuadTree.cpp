/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        ans[0] = new Node(false, true, NULL, NULL, NULL, NULL);
        ans[1] = new Node(true, true, NULL, NULL, NULL, NULL);
        return construct(0, 0, grid, grid.size());
    }

    Node* construct(int row, int col, vector<vector<int>>& grid, int s){
      if (s == 1){
        return ans[grid[row][col]];
      }
      s /= 2;
      Node* tl = construct(row, col, grid, s);
      Node* tr = construct(row, col + s, grid, s);
      Node* bl = construct(row + s, col, grid, s);
      Node* br = construct(row + s, col + s, grid, s);
      if (tl == tr && tl == bl && tl == br){
        return ans[grid[row][col]];
      }
      return new Node(false, false, tl, tr, bl, br);
    }

private:
  array<Node*, 2> ans;
};