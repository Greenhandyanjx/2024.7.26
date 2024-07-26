#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isValid(vector<string>& chessBoard, int n, int row, int col) {
        if (chessBoard[row].find('Q') != chessBoard[row].rfind('Q'))return false;
        int num = 0;
        for (int i = 0; i < row; i++) {
            if (chessBoard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>>res;
    vector<string>path;
    void backtracking(vector<string>& chessBoard, int n, int row) {
        if (row == n) {
            res.push_back(chessBoard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(chessBoard, n, row, i)) {
                chessBoard[row][i] = 'Q';
                backtracking(chessBoard, n, row + 1);
                chessBoard[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        vector<string>chessBoard(n, temp);
        backtracking(chessBoard, n, 0);
        return res;
    }
};
int main() {
    vector<vector<string>>result=solveNQueens(4);
    return 0;
}
//class Solution {
//public:
//    vector<int>path;
//    vector<vector<int>>res;
//    void backtracking(vector<int>& nums, vector<bool>& used) {
//        if (path.size() == nums.size()) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)continue;
//            if (used[i] == true)continue;
//            used[i] = true;
//            path.push_back(nums[i]);
//            backtracking(nums, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        res.clear();
//        path.clear();
//        sort(nums.begin(), nums.end());
//        vector<bool>used(nums.size(), false);
//        backtracking(nums, used);
//        return res;
//    }
//};
//class Solution {
//public:
//    vector<int>path;
//    vector<vector<int>>res;
//    void backtracking(vector<int>& nums, vector<bool>& used) {
//        if (path.size() == nums.size()) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (used[i] == true)continue;
//            used[i] = true;
//            path.push_back(nums[i]);
//            backtracking(nums, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> permute(vector<int>& nums) {
//        if (nums.size() == 0)return res;
//        vector<bool>used(nums.size(), false);
//        backtracking(nums, used);
//        return res;
//    }
//};
//class Solution {
//public:
//    vector<int>path;
//    vector<vector<int>>res;
//    void backtracking(vector<int>& nums, int startindex) {
//        if (path.size() >= 2)res.push_back(path);
//        unordered_set<int>uset;
//        for (int i = startindex; i < nums.size(); i++) {
//            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())continue;
//            uset.insert(nums[i]);
//            path.push_back(nums[i]);
//            backtracking(nums, i + 1);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        if (nums.size() == 0)return res;
//        backtracking(nums, 0);
//        return res;
//    }
//};