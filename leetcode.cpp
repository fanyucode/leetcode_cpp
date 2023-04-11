#include<iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<list>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    //-------------------------------------------------------------------------------------------------------
    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0;i < nums.size();i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return { iter->second,i };
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }

    //----------------------------------------------------------------------------------------------------------------------------------------------


    //组合总和2
    //void combinationSum2_backtracking(vector<int>& nums, int sum, int targetSum, int startIndex, vector<bool>& used) {
    //    //终止条件
    //    if (sum == targetSum) {
    //        res.push_back(path);
    //        return;
    //    }
    //    //第一层的sum>targetSum的情况直接在for循环中直接解决 
    //    for (int i = startIndex;i < nums.size()&&sum+nums[i]<=targetSum;i++) {
    //        //去重的逻辑：对数组进行排序；当左右元素相同时；收集的结果一定是相同的，
    //        //防止有溢出，当前一个也是用过的元素；你的下一个元素虽然可能相同；但也是需要的，不能直接跳过
    //        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    //            continue;
    //        }
    //        sum += nums[i];
    //        used[i] = true;
    //        //path.push_back(nums[i]);
    //        combinationSum2_backtracking(nums, sum, targetSum, i + 1, used);//递归
    //        path.pop_back();//回溯
    //        sum -= nums[i];
    //        used[i] = false;
    //    }
    //}
    //vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    //    path.clear();
    //    res.clear();
    //    vector<bool> used(nums.size(), false);
    //    sort(nums.begin(), nums.end());
    //    combinationSum2_backtracking(nums, 0, target, 0, used);
    //    //return res;
    //}//组合总和2

    //----------------------------------------------------------------------------------------------------------------------

    ////分割回文串
    //bool isPalindrome(const string& s, int start, int end) {//判断是否是回文串
    //    for (int i = start, j = end;i < j;i++, j--) {
    //        if (s[i] != s[j]) {
    //            return false;
    //        }
    //    }
    //    return true;
    //}
    //void patition_backtracking(const string& s, int startIndex) {
    //    if (startIndex >= s.size()) {
    //        res.push_back(path);
    //        cout << endl;//将每个打印收集到最后的结果换行
    //        return;
    //    }//终止条件；当startIndex到达时候表示分割都是回文串；将结果收集
    //    for (int i = startIndex;i < s.size();i++) {
    //        if (isPalindrome(s, startIndex, i)) {//当结果子串是回文串将结果收集
    //            string str = s.substr(startIndex, i - startIndex + 1);
    //            //path.push_back(str);
    //            cout << str << " ";//打印单个回文串
    //        }
    //        else {
    //            continue;//不是则跳过
    //        }
    //        patition_backtracking(s, i + 1);//递归
    //        path.pop_back();//回溯

    //    }
    //}
    //vector<vector<string>> partition(string s) {
    //    res.clear();
    //    path.clear();
    //    patition_backtracking(s, 0);
    //    //return res;
    //}

    //----------------------------------------------------------------------------------------------------

    //93.复原ip地址
    /*vector<string> res;
    string path;*/
    //bool isVaild(const string& s, int start, int end) {
    //    if (start > end) {
    //        return false;
    //    }
    //    if (start != end && s[start] == '0') {//首字母为0；不合法
    //        return false;
    //    }
    //    int num = 0;
    //    for (int i = start;i <= end;i++) {
    //        if (s[i] > '9' || s[i] < '0') {//ascII码值大于9或者小于0；不合法
    //            return false;
    //        }
    //        num = num * 10 + (s[i] - '0');//num大于255,不合法
    //        if (num > 255) {
    //            return false;
    //        }
    //    }
    //    return true;  
    //}
    //void restoreIpAddress_backtracking(string& s, int startIndex,int pointSum) {
    //    //确定终止条件
    //    if (pointSum == 3) {//插入数量等于三时；需要 return
    //        if (isVaild(s, startIndex, s.size() - 1)) {
    //            res.push_back(s);
    //            cout << s;
    //            cout << endl;
    //        }
    //        return;
    //    }
    //    //单层搜索逻辑
    //    for (int i = startIndex;i < s.size();i++) {
    //        if (isVaild(s, startIndex, i)) {
    //            s.insert(s.begin() + i + 1, '.');
    //            pointSum++;
    //            restoreIpAddress_backtracking(s, i + 2, pointSum);//当插入的一个点；他的i需要加2来进行下一层的递归操作
    //            pointSum--;//回溯
    //            s.erase(s.begin() + i + 1);
    //        }
    //        else break;
    //    }
    //       
    //}
    //vector<string> restoreIpAddress(string& s) {
    //    res.clear();
    //    restoreIpAddress_backtracking(s, 0, 0);
    //    return res;
    //}

//------------------------------------------------------------------------------------------------------------------------------
    //78子集
   /* vector<vector<int>> res;*/
    //vector<int> path;
    //void subsets_backtracking(vector<int>& nums, int startIndex) {
    //    res.push_back(path);//得到结果集
    //    if (startIndex >= nums.size()) {
    //        return;
    //    }
    //    for (int i = startIndex;i < nums.size();i++) {
    //        path.push_back(nums[i]);
    //        subsets_backtracking(nums, i + 1);
    //        path.pop_back();
    //    }
    //}
    //// 子集问题，每次递归开始就要收取结果；并不是到叶子节点去得到结果
    //vector<vector<int>> subsets(vector<int>& nums) {
    //    path.clear();
    //    res.clear();
    //    subsets_backtracking(nums, 0);
    //    return res;
    //}
//-------------------------------------------------------------------------------------------------------------------

    //90、子集II
    //vector<int>path;
    //vector<vector<int>>res;
    //void subsetWithDup_backtracking(vector<int>& nums, int startIndex,vector<bool> used) {
    //    res.push_back(path);
    //    if (startIndex >= nums.size()) {
    //        return;
    //    }
    //    for (int i = startIndex;i < nums.size();i++) {
    //        //排序去重 ；保证不出现负数；i>0
    //        //前一个数字和本轮数字相同；并且没有用过直接跳过  
    //        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    //            continue;
    //        }
    //        path.push_back(nums[i]);
    //        used[i] = true;
    //        subsetWithDup_backtracking(nums, i + 1, used);
    //        path.pop_back();
    //        used[i] = false;
    //    }
    //}
    //vector<vector<int>> subsetWithDup(vector<int>& nums) {
    //    res.clear();
    //    path.clear();
    //    vector < bool>used(nums.size(), false);
    //    sort(nums.begin(), nums.end());
    //    subsetWithDup_backtracking(nums, 0, used);
    //    return res;
    //}
//----------------------------------------------------------------------------------------------------------------
   //491递增子序列
    //vector<int>path;
    //vector<vector<int>>res;
    //void backtracking_findSubsequences(vector<int>& nums, int startIndex) {
    //    //终止条件
    //    if (path.size() > 1) {
    //        res.push_back(path);
    //    }
    //    unordered_set<int>  uset;//将得到的数存入
    //    for (int i = startIndex;i < nums.size();i++) {
    //        if ((!path.empty() && path.back() > nums[i]) || uset.find(nums[i]) != uset.end()) {
    //            continue;
    //        }
    //        uset.insert(nums[i]);//插入nums[i]
    //        path.push_back(nums[i]);
    //        backtracking_findSubsequences(nums, i + 1);
    //        //单层的unordered_set;此处的set容器不需要存入
    //        path.pop_back();
    //    }
    //}
    //vector<vector<int>> findSubsequences(vector<int>& nums) {
    //    res.clear();
    //    path.clear();
    //    backtracking_findSubsequences(nums, 0);
    //    return res;
    //}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //46.全排列
    //vector<int>path;
    //vector<vector<int>> res;
    ////全排列不需要考虑子集；顺序不同也要收集；所以不需要startIndex来控制顺序
    //void backtracking_premute(vector<int>& nums, vector<bool> used) {
    //    if (path.size() == nums.size()) {
    //        res.push_back(path);
    //    }//终止条件
    //    //只需要用used数组；记录这个数是否用过就可以
    //    for (int i = 0;i < nums.size();i++) {
    //        if (used[i]) {
    //            continue;
    //        }
    //        used[i] = true;
    //        path.push_back(nums[i]);
    //        backtracking_premute(nums, used);//递归
    //        used[i] = false;//回溯
    //        path.pop_back();//回溯
    //    }
    //}
    //vector<vector<int>> permute(vector<int>& nums) {
    //    path.clear();
    //    res.clear();
    //    vector<bool> used(nums.size(), false);
    //    backtracking_premute(nums, used);
    //    return  res;
    //}

//-----------------------------------------------------------------------------------------------------------------
    //47.全排列2
    //vector<int> path;
    //vector<vector<int>> res;
    //void backtracking_permuteUnique(vector<int>& nums, vector <bool> used) {
    //    //终止条件
    //    if (path.size() == nums.size()) {
    //        res.push_back(path);
    //        return;
    //    }
    //    for (int i = 0;i < nums.size();i++) {
    //        //去重逻辑；有重复数组，当前一个数和后一个数相同时第一个排序逻辑已经用完；只需要判断前一个数是否用过
    //        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    //            continue;
    //        }
    //        //使用used数组来解决是否是同一个数；同一个数直接跳过不能重复操作
    //        if (used[i] == false) {
    //            used[i] = true;
    //            path.push_back(nums[i]);
    //            backtracking_permuteUnique(nums,used);
    //            path.pop_back();
    //            used[i] = false;
    //        }
    //    }
    //}
    //vector<vector<int>> permuteUnique(vector<int>& nums) {
    //    path.clear();
    //    res.clear();
    //    sort(nums.begin(), nums.end());
    //    vector<bool>used(nums.size(), false);
    //    backtracking_permuteUnique(nums, used);
    //    return res;
    //}

//-------------------------------------------------------------------------------------------------------------------

    ////51 N皇后
    //vector<vector<string>> res;
    ////每次检查只需要检查上边层数的有没有Q就可以
    ////因为每次深搜都是从下一行开始进行搜索
    //bool isValid(vector<string>& chessboard, int row, int col,int n) {
    //    //每次插值都是从row+1开始；不需要检查行
    //    for (int i = 0;i < row;i++) {
    //        if (chessboard[i][col] == 'Q') {
    //            return false;
    //        }
    //    }
    //    //检查左上对角线有没Q
    //    for (int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--, j--) {
    //        if (chessboard[i][j] == 'Q') {
    //            return false;
    //        }
    //    }
    //    //检查右上角对角线有没有Q
    //    for (int i = row - 1, j = col + 1;i >= 0 && j < n;i--, j++) {
    //        if (chessboard[i][j] == 'Q') {
    //            return false;
    //        }
    //    }
    //    return true;
    //}
    //void backtracking_solveNQueens(vector<string>& chesssboard, int row, int n) {
    //    //终止条件：当row到了最后的结果 
    //    if (row == n) {
    //        res.push_back(chesssboard);
    //        return;
    //    }
    //    for (int col = 0;col < n;col++) {
    //        if (isValid(chesssboard,row,col,n)) {
    //            chesssboard[row][col] = 'Q';
    //            backtracking_solveNQueens(chesssboard, row + 1, n);
    //            chesssboard[row][col] = '.';
    //        }
    //    }
    //}
    //vector<vector<string>> solveNQueens(int n) {
    //    //定义一个n x n的'.'的棋盘
    //    res.clear();
    //    vector<string> chessboard(n,string(n, '.'));
    //    backtracking_solveNQueens(chessboard, 0, n);
    //    return  res;
    //}

//------------------------------------------------------------------------------------------------------------------------------
//37.解数独
    //解决二维数组；使用二维回溯
    bool isValid(int  i, int j, const vector<vector<char>>& board, char k) {
        for (int row = 0;row < 9;row++) {//列判重
            if (board[row][j] == k) {
                return false;
            }
        }
        for (int col = 0;col < 9;col++) {//行判重
            if (board[i][col] == k) {
                return false;
            }
        }
        //定义该数的区域起始的行列 
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;
        //定义三乘三的区域；暴力遍历该区域
        for (int i = startRow;i < startRow + 3;i++) {
            for (int j = startCol;j < startCol + 3;j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }
        return true;
    }
    bool bracktracking_solveSudoku(vector<vector<char>>& board) {
        //暴力遍历每个位置；挨个插值
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') {//当此数等于说明可以插值；
                    //只需要判断当前位置；某些数插值能不能合法；
                    //
                    for (char k = '1';k <= '9';k++) {
                        if (isValid(i, j, board, k)) {
                            board[i][j] = k;
                            if (bracktracking_solveSudoku(board)) {
                                return true;//当搜到了合适的值返回TRUE；一层往上递归
                            }
                        }
                    }
                    return false;//当九个数都不可以的时候；返回false
                }
            }
        }
        return true;//两层循环结束直接返回true
    }
    void solveSudoku(vector<vector<char>>& board) {
        bracktracking_solveSudoku(board);
    }
    //-----------------------------------------------------------------------------------------------------------------------------   

   //贪心算法
       //分发饼干
       //使用最小的饼干给最小的胃口的小孩的局部最优解
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;//小孩的位置
        for (int i = 0;i < s.size();i++) {//遍历饼干的位置
            //如果index大于小孩的数量就退出index处理，并且饼干大于等于胃口
            if (index < g.size() && g[index] <= s[i]) {
                index++;
            }
        }
        return index;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
        //376.摆动序列
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int preDiff = 0;//前一对差值
        int curDiff = 0;//当前差值 
        int res = 1;//默认前面有一个差值
        for (int i = 0;i < nums.size() - 1;i++) {
            curDiff = nums[i + 1] - nums[i];//用之后的一个数减去当前的数就是当前差值
            //当出现平坡preDiff随机，curDiff一定为0；
            //使用这个可以去掉平坡情况 ；直到出现摆动
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                res++;
                preDiff = curDiff;//当出现单调平坡的情况；只需要将进行摆动的时候进行记录更新
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------
        //最大子序和
    int maxSubArray(vector<int>& nums) {
        //如果出现连续和是负数抛弃
        //从新的开始记录；当为正数；用res记录；
        //防止当前res是最大；但当前的正数可能对后面有影响
        int sum = 0;
        int res = INT_MIN;
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            res = max(sum, res);
            if (sum < 0) sum = 0;
        }
        return res;
    }
    //-----------------------------------------------------------------------------------------------------
        //买卖股票的最佳时机II
    int maxProfit(vector<int>& prices) {
        //多次购买股票可以通；一直累加正数得到最大利润
        int res = 0;
        for (int i = 1;i < prices.size();i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------
        //跳跃游戏
    bool canJump(vector<int>& nums) {
        //遍历数组只需要判断当前cover能不能到达末位
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0;i <= cover;i++) {//当前遍历到最大cover值；也就是能到达最大位置
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) {//当cover大于nums.size()-1;返回true
                return true;
            }
        }
        return false;
    }
    //-----------------------------------------------------------------------------------------------------
         //跳跃游戏II
    int jump(vector<int>& nums) {
        int next = 0;
        int cur = 0;
        int res = 0;
        for (int i = 0;i < nums.size();i++) {
            next = max(i + nums[i], next);//当前覆盖的最大值
            if (i == cur) {//如果到了当前最大覆盖范围
                if (cur < nums.size() - 1) {//如果当前覆盖范围小于末位增加跳跃次数
                    //当前的cur更新成下一次跳跃的起始位置。
                    res++;
                    cur = next;
                    if (next >= nums.size() - 1) break;//如果下一次的跳跃位置；大于末位
                }
                else break;
            }
        }
        return res;
    }
    //-------------------------------------------------------------------------------------------------
         //k次取反后最大的数组和
    static bool  myCompare(int a, int b) {
        return abs(a) > abs(b);
    }//将数组按绝对值从大到小进行排序
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), myCompare);
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] < 0 && k>0) {//如果遍历数组出现nums的值小于0；且k还没用完翻转
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;//如果k没用完；取最小的翻转后的数进行反转
        //当剩余k是奇数只需要取最小的正数值进行反转；就是使用绝对排序后从大到小最后一个数；
        //当剩余k为偶数；不管怎么反转任一数都是正数原来值所以不需要进行操作
        int res = 0;
        for (int num : nums) res += num;
        return res;
    }
    //------------------------------------------------------------------------------------------------------
         //加油站
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //贪心的思路：通过累加gas-cost；当出现补给小于消耗；就从下一个节点开始
        //当所有的总和还是小于0；是不肯能跑完直接返回-1
        int curSum = 0;//定义当前区间损耗
        int totalSum = 0;//所有的损失和供给
        int start = 0;//定义计算curSum的起始位置
        for (int i = 0;i < gas.size();i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {//当局部出现损耗小于0；重新定义局部区间
                curSum = 0;//清空curSum
                start = i + 1;//记录起始位置
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
    //--------------------------------------------------------------------------------------------------
         //分发糖果
    int candy(vector<int>& ratings) {
        //分别从两边开始遍历；判断存储的candy
        vector<int>  candies(ratings.size(), 1);//定义数组；因为每个小孩至少获得一个
        //从左向右遍历；如果左边小于右边；则需要右边增加一个
        for (int i = 1;i < ratings.size();i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        //从右向左进行遍历；比较两边值；如果大于左边则比较当前值+1；和他的此时的最大值
        for (int j = ratings.size() - 2;j >= 0;j--) {
            if (ratings[j] > ratings[j + 1]) {
                candies[j] = max(candies[j], candies[j + 1] + 1);//防止出现没有顾及前一种情况；要取最大值
            }
        }
        int res = 0;
        for (int cand : candies) res += cand;
        return res;
    }
    //--------------------------------------------------------------------------------------------------
         //柠檬水找零
    bool lemonadeChange(vector<int>& bills) {
        //贪心策略：对于二十找零的情况有两种
        //优先使用十加五的情况；其次三个五的情况
        int five = 0;int ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                else {
                    five--;
                    ten++;
                }
            }
            if (bill == 20) {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
    //-----------------------------------------------------------------------------------------------------------------
         //根据身高重建队列
    static bool comp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }//将数组按身高从大到小排列；当身高相同时按位置从小到大排列
    //可以使用list数据进行插入操作；比数组操作要快很多
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        list<vector<int>> que;//定义结果数组
        for (int i = 0;i < people.size();i++) {//遍历数组
            int pos = people[i][1];
            list<vector<int>>::iterator it = que.begin();
            while (pos--) {
                it++;
            }
            que.insert(it, people[i]);
        }
        return  vector<vector<int>>(que.begin(), que.end());
    }
    //-------------------------------------------------------------------------------------------------------------+--
         //用最少数量的箭引爆气球
    static bool comp1(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), comp1);//将数组按第一个数排列
        int res = 1;//size大于0；至少需要一支箭
        for (int i = 1;i < points.size();i++) {
            if (points[i - 1][1] < points[i][0]) {//当前一个气球的右边界小于后一个气球左边界
                res++;//弓箭需要增加
            }
            else {//当重叠的时候；只需要将前一个气球和当前的比较右边界；谁短取哪个右边界；重新给这个区间定义
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
    //----------------------------------------------------------------------------------------------------------------------
         //无重叠区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 对数组左边界进行排序
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), comp1);
        int count = 0;
        for (int i = 1;i < intervals.size();i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {//当区间重叠
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);//更新最小右边界和下一个是否重叠；来进行比较
                count++;//需要移除的区间加一
            }
        }
        return count;
    }


    //---------------------------------------------------------------------------------------------------------------------------
         //划分字母区间
    vector<int> partitionLabels(string s) {
        //使用hash数组；记录最远的位置
        int hash[27] = { 0 };
        for (int i = 0;i < s.size();i++) {
            hash[s[i] - 'a'] = i;
        }//遍历数组将数值传入
        vector<int> res;//定义结果集
        int left = 0, right = 0;//定义左右区间
        for (int i = 0;i < s.size();i++) {
            right = max(right, hash[s[i] - 'a']);//将右边界选取最远的
            if (i == right) {//如果到达了最远的值
                res.push_back(right - left + 1);//收集结果集
                left = i + 1;//left更新成下一个
            }
        }
        return res;
    }
    //------------------------------------------------------------------------------------------------------------------------
        //合并区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), comp1);//按左边界进行排序
        res.push_back(intervals[0]);//先将第一个存入修改这个结果集就可以
        for (int i = 1;i < intervals.size();i++) {
            if (res.back()[1] >= intervals[i][0]) {//重叠区间
                res.back()[1] = max(res.back()[1], intervals[i][1]);
                //将最后收集结果的右边界修改就可以；左边界按从小到大排序；一定是最小的
            }
            else {// 没有重叠区间
                res.push_back(intervals[i]);//收集结果
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------------------------------
         //单调自增的数字
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);//将int数转换成string类型
        int flag = str.size();//定义一个数组记录最后需要变成9的序列
        for (int i = str.size() - 1;i > 0;i--) {//从后向前遍历；向后遍历不会对前面值得修改影响后面的结果
            if (str[i - 1] > str[i]) {//当前一个数大于后一个数时；就不是递增序列
                str[i - 1]--;//前数减一
                flag = i;//定义flag后面都需要变成9
            }
        }
        for (;flag < str.size();flag++) {
            str[flag] = '9';
        }
        //使用库函数stdlib.h里面的stoi函数;将string转换成int
        int  res = stoi(str);
        return res;

    }
    //----------------------------------------------------------------------------------------------------------------------
    //监控二叉树
    int res_Camera;
    int traversal(TreeNode* cur) {
     //后序遍历；
        if (cur == NULL) return 2;//终止条件
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (left == 2 && right == 2) {
            return 0;
        }//当左右子节点都是2；父亲节点不用设置摄像
        if (right == 0 || left == 0) {
            res_Camera++;
            return 1;
        }//当左右子节点没有被覆盖；则父节点必须设置摄像
        if (left == 1 || right == 1) {
            return 2;
        }//当左右子节点出现摄像；则父节点一定被覆盖
        return -1;
    };
    int minCameraCover(TreeNode* root) {
        res_Camera = 0;
        //当根节点上部没有父节点；且没有被覆盖贼需要增加一个camera
        if (traversal(root) == 0) {
            res_Camera++;
        }
        return  res_Camera;
    }
    //---------------------------------------------------------
    
    //动态规划
    /*  确定dp数组（dp table）以及下标的含义
        确定递推公式
        dp数组如何初始化
        确定遍历顺序
        举例推导dp数组*/
    //----------------------------------------------------------


    //斐波那契数
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        //定义dp数组
        vector<int>dp(n+1);
        //确定递推公式
        dp[0] = 0;dp[1] = 1;//初始化
        cout << 0 << " " << 1 << " ";
        for (int i = 2;i <= n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i] << " ";
        }
        return dp[n];
    }
    //----------------------------------------------------------------

    //爬楼梯
    int climbStairs(int n) {
        if(n<=1){
            return n;
        }
           //定义dp数组
        vector<int> dp(n + 1);
       //dp数组的初始化
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            //确定dp逻辑
            dp[i] = dp[i - 1] + dp[i - 2];
            // //打印dp数组
            // cout << dp[i] << " ";
            
        }
        return dp[n];
    }
    //--------------------------------------------------------------
    //使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost) {
            //定义dp数组
            vector<int> dp(cost.size() + 1);
            //初始化dp数组
            dp[0] = 0, dp[1] = 0;
            //遍历顺序 
            for (int i = 2; i <= cost.size(); i++) {
                //dp逻辑：选择最小的花费进行跳跃
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
                cout << dp[i] << " ";
            }
            return dp[cost.size()];
    }
    //-------------------------------------------------------------------
    //不同路径
    int uniquePaths(int m, int n) {
        //定义dp数组；本题是二维矩阵
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化:将第一行和第一列的数组置为0
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        //填充dp数组
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //当前状态只能是他的上面和左面传递
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1]; 
    }  
    //------------------------------------------------------------------------
    //不同路径II 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //定义dp数组；本题是二维矩阵
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //当数组开始和结尾有障碍一定不会有路线直接返回0
        if (obstacleGrid[0][0] == 1 && obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化:将第一行和第一列的数组置为1,有障碍置为0
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //当这个地方是障碍直接跳过
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                //当前状态只能是他的上面和左面传递
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    //-------------------------------------------------------------------
    //整数拆分
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(max(j*(i-j),j*dp[i-j]),dp[i]);
            }
        }
        return dp[n];
    }

};

int main() {
    int test = 10;
    Solution solution;
    int res = solution.integerBreak(test);
    cout << res << endl;
    system("pause");
    return 0;
};