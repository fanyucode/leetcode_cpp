#include<iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<list>
#include<stdlib.h>
#include<stack>
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
        vector<int>dp(n+1);//定义dp数组
        dp[2]=1;//初始化dp数组，dp[2]等于1
        for(int i=3;i<=n;i++){
            //比较dp[i]是因为；在第二次for循环当中不断地查找最大dp[i]
            for(int j=1;j<=i/2;j++){
                dp[i]=max(max(j*(i-j),j*dp[i-j]),dp[i]);
                //j*(i-j)两个数比较；j*dp[i-j]是比较多个数的集合；
            }
        }
        return dp[n];
    }
    //------------------------------------------------------------
    //不同的二叉搜索树
    /*将二叉树分为左右子树，左右子树相乘，再将一个搜索树分成多少种情况累加，
    得到最后的dp数组*/
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0]=1,dp[1]=1;//初始化dp
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){//定义一棵子树的情况，i-j就是另一个子树的情况
                dp[i]+=dp[j-1]*dp[i-j];//j-1是因为要去除头结点
            }
        }
        return dp[n];
    }
    //----------------------------------------------------------------
    //背包问题，二维数组
    void test_2_wei_bag_problem1(){
        vector<int>weight={1,3,4};
        vector<int>value={15,20,30};
        int bagWeight=4;
        //定义dp数组
        vector<vector<int>>dp(weight.size(),vector<int>(bagWeight+1,0));
        //初始化
        for(int i=weight[0];i<=bagWeight;i++){
            dp[0][i]=value[0];
        }//将装上物品0的背包重量，开始设置为value[0];设置为初始值
        for(int i=1;i<weight.size();i++){//遍历物品 
            for(int j=0;j<=bagWeight;j++){//遍历背包容量
                if(j<weight[i]) dp[i][j]=dp[i-1][j];/*
                当j没有想拿的物品种，当前物品就是没拿当前物品的东西的最大价值*/
                else dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i]]+value[i]);
                //当拿到了物品，上个物品减去当前重量加上val的值，和之前最大的dp[i][j]的最大值
            }
        }
        cout<<dp[weight.size()-1][bagWeight]<<endl;
    }
    //背包问题的滚动数组
    void test_1_wei_bag_problem() {
        vector<int>weight={1,3,4};
        vector<int>value={15,20,30};
        int bagWeight=4;
        vector<int> dp(bagWeight,0);
        for(int i=0;i<weight.size();i++){
            for(int j=bagWeight;j>=weight[i];j--){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
    }
    //------------------------------------------------------------------
    //分割等和子集
    bool  canPartition(vector<int>&  nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }//将数组sum累加
        if(sum%2==1){
            return  false;
        }//当数组的和是奇数；不可能存在两个子集相等
        int target=(sum/2);//将一个数组的一半设置成背包容量
        vector<int>dp(10001,0);//定义dp数组
        dp[0]=0;//初始化，当dp没有装物品一定是0
        for(int i=0;i<nums.size();i++){//遍历放入背包的数量
            for(int j=target;j>=nums[i];j--){//倒序遍历背包的容量
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);//数组的容量也是背包的价值
            }
        }
        if(dp[target]==target) return true;//当出现相加等于原数组的一半时，就返回true
        //出现一组是一半，另一半的量也必是target
        return false;
    }
    //----------------------------------------------------------------------------
    //最后一块石头的重量II
    //就是求两个最相近的子集的最小的差值
    int  lastStoneWightII(vector<int>& stones){
        int sum=0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
        }//重量求和
        int target=(sum/2);
        vector<int>dp(1501,0);
        dp[0]=0;//初始化dp数组
        for(int i=0;i<stones.size();i++){//对数量遍历
            for(int j=target;j>=stones[i];j--){//对容量遍历
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return abs(sum-(dp[target]*2));//返回相差最小的target
    }
    //------------------------------------------------------------
    //目标和
    int findTargetSumWays(vector<int>& nums,int target){
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];//总和
        if((sum+target)%2==1) return 0;//如果除二有余数；必定没有结果
        if(abs(target)>sum) return 0;//如果target大于数组所有的和；也不可能存在 
        int bagSize=(sum+target)/2;//将书包的容量定义成正数的集合；正数加上负数的集合等于target
        vector<int>dp(bagSize+1,0);//将数组其他数初始化为零
        dp[0]=1;//dp[0]等于1
        for(int i=0;i<nums.size();i++){
            for(int j=bagSize;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];//dp[j]=dp[j-1]+dp[j-2]+...+dp[0]递推逻辑
            }
        }
        return dp[bagSize];
    }
    //---------------------------------------------------------------------------
    //零和一
    int findMaxForm(vector<string>& strs,int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //val的值就是子序列的最大容量
        //背包的容量就是0和1的值
        for(string  str:strs){//遍历物体的个数
            int x=0,y=0;//初始化遍历的字符串的初始化
            for(char a:str){
                if(a=='0')
                    x++;
                else y++;
                //计算每次字符串中0和1的大小,作为背包的容量
            }
            for(int i=m;i>=x;i--){
                for(int j=n;j>=y;j--){
                    dp[i][j]=max(dp[i-x][j-y]+1,dp[i][j]);
                }
            }//两次for循环都是对背包总体重量的一个遍历
        }
        return dp[m][n];
    }
    //--------------------------------------------------------------------------------
    //完全背包
    //先遍历物品，后遍历容量是组合数
    void test_CompletePack1() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagWeight = 4;
        vector<int> dp(bagWeight + 1, 0);
        for(int i = 0; i < weight.size(); i++) { // 遍历物品
            for(int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                cout<<dp[j]<<" ";
            }
            cout<<endl;

        }
        cout << dp[bagWeight] << endl;
    };
    //先遍历背包；在遍历物品，是排列数
    void test_CompletePack2() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagWeight = 4;

        vector<int> dp(bagWeight + 1, 0);

        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            for(int i = 0; i < weight.size(); i++) { // 遍历物品
                if (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                cout<<dp[j]<<" ";
            }
            cout<<endl;
        }
        cout << dp[bagWeight] << endl;
    };
    //-------------------------------------------------------------
    //零钱兑换II
    int change(int amount,vector<int>& coins){
        vector<int>dp(amount+1,0);//初始化dp数组
        dp[0]=1;//dp[0]等于1
        for(int i=0;i<coins.size();i++){//遍历物品
            for(int j=coins[i];j<=amount;j++){//遍历背包的容量
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    };
    //--------------------------------------------------------------
    //组合总和IV
    //求排列问题应先遍历背包容量；在遍历物品
    int combinationSum4(vector<int>&nums,int target){
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int j=0;j<=target;j++){//遍历背包容量
            for(int i=0;i<nums.size();i++)//遍历物品
            if(j-nums[i]&&dp[j]<INT_MAX-dp[j-nums[i]])
             dp[j]+=dp[j-nums[i]];
        }
        return dp[target];
    }
    //-----------------------------------------------------------
    //零钱兑换
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){//遍历物品
            for(int j=coins[i];j<=amount;j++){//遍历背包
                if(dp[j-coins[i]]!=INT_MAX){//如果dp[j-coins[i]]是初始值则跳过 
                    dp[j]=min(dp[j-coins[i]]+1,dp[j]);//取最小的硬币数
                }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
    //-----------------------------------------------------
    //完全平方数
    int numSquares(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i<=n;i++){//遍历平方数，临界值是小于这个容量
            for(int j=i*i;j<=n;j++){//便利背包小于n的容量
                dp[j]=min(dp[j-(i*i)]+1,dp[j]);  
            }
        }
        return dp[n];
    }
    //-------------------------------------------------------------
    //单词拆分
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.size()+1,false);//初始化dp数组，dp数组的其他都将置为false
        dp[0]=true;//将dp[0]置为true，否则后面都是false
        //由于数求排列数
        for(int i=1;i<=s.size();i++){//定义字符串后面的数
            for(int j=0;j<i;j++){//遍历字符串前面的数
                string word =s.substr(j,i-j);
                if(wordSet.find(word)!=wordSet.end()&&dp[j]){
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
    }
    //-----------------------------------------------------------------
    //打家劫舍
    int rob(vector<int>& nums){
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()+1,0);
        dp[0]=nums[0];//dp[0]只能取第一家所以必须要偷
        dp[1]=max(nums[0],nums[1]);//dp[1]需要比较第一家和第二家哪个比较多
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);//不能偷相邻的，则需要比较dp[i-2]加上当前的钱数比较dp[i-1]的大小 
        }
        return  dp[nums.size()-1];
    }
    //---------------------------------------------------------------------
    //打家劫舍II
    //分为两种情况，一个取第一个数，不取末尾数；二是不取第一个数，取末尾数
    //可以将一个环形任务转换成两个线性任务；取两个情况的最大值就是最后答案
    int  robII(vector<int>&nums){
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int>v1,v2;
        v1.assign(nums.begin(),nums.end()-1);
        v2.assign(nums.begin()+1,nums.end());
        return max(rob(v1),rob(v2));
    }
    //---------------------------------------------------------------------
    //打家劫舍III
    /*当前节点定义成两个状态，dp[1]表示偷，dp[0]表示不偷
    比较最后的根节点偷不偷两个大小，使用后序遍历*/
    vector<int> robtree(TreeNode* cur){
        if(cur==NULL) return vector<int>{0,0};//终止条件
        vector<int>leftdp=robtree(cur->left);//左
        vector<int>rightdp=robtree(cur->right);//右
        //当root偷的情况,左右子树肯定不能偷
        int val1=cur->val+leftdp[0]+rightdp[0];
        //当root不偷，左右子树只需要取两棵子树的大小
        int val2=max(leftdp[0],leftdp[1])+max(rightdp[0],rightdp[1]);
        return {val2,val1};
    }
    int robIII(TreeNode* root){
        vector<int>res=robtree(root);
        return max(res[0],res[1]);
    }
    //---------------------------------------------------------------------
    //买卖股票的最佳时机
    int maxProfitDp(vector<int>& prices){
        int len=prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2));
        dp[0][0]=0;//表示第一天不持有股票的状态，第一天不买就为0
        dp[0][1]-=prices[0];//表示第一天购买了股票的状态
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//如果当天没有股票，只有可能前一天也没有，或者前一天有，此时卖了
            dp[i][1]=max(dp[i-1][1],-prices[i]);//前一天有，当时购入，因为不能重复购买，此时一定只能是-prices
        } 
        return dp[len-1][0];
    }
    //--------------------------------------------------------------------------
    //买卖股票的最佳时机II
    int maxProfitIIDp(vector<int>& prices){
        int len=prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2));
        dp[0][0]=0;//表示第一天不持有股票的状态，第一天不买就为0
        dp[0][1]-=prices[0];//表示第一天购买了股票的状态
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//如果当天没有股票，只有可能前一天也没有，或者前一天有，此时卖了
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//可以购买多次，贼需要记录前一天的状态
        } 
        return dp[len-1][0];
    }
    //-------------------------------------------------------------------------------
    //买卖股票的最佳时机III
    int maxProfitIIIDp(vector<int>& prices){
        int len =prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(5));
        //初始化
        dp[0][0]=0;//第一天不操作为0
        dp[0][1]-=prices[0];//第一天购买初始化为减去第一天股票价格
        dp[0][2]=0;//第一天购买又卖出初始化0
        dp[0][3]-=prices[0];//第一天再次购买
        dp[0][4]=0;//再次卖出
        for(int i=1;i<len;i++){
            dp[i][0]=dp[i-1][0];//没有操作就只能是前一天没操作状态得到
            dp[i][1]=max(dp[i-1][1],-prices[i]);//前一天有了或者现在购买
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i]);//前一天卖出或者现在卖出；
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);//保持前一天状态或者现在购入 
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);//保持前一天状态或者现在卖出
        }
        return dp[len-1][4];
    }
    //-------------------------------------------------------------------------------
    //买卖股票的最佳时机IV
    int maxProfitIVDp(vector<int>& prices,int k){
        int len = prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2*k+1,0));
        for(int j=1;j<2*k;j+=2){
            dp[0][j]-=prices[0];
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<2*k-1;j+=2){
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]-prices[i]);
                dp[i][j+2]=max(dp[i-1][j+2],dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[len-1][2*k];
    }
    //---------------------------------------------------------------------------------
    //最佳买卖股票时机含冷冻期
    int maxProfitDpV(vector<int>& prices){
        int len = prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(4,0));
        dp[0][0]-=prices[0];//第一天购买股票
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1]-prices[i],dp[i-1][2]-prices[i]));//购入股票
            dp[i][1]=max(dp[i-1][1],dp[i-1][2]);//持续没有时期 
            dp[i][2]=dp[i-1][3];//冷冻期
            dp[i][3]=dp[i-1][0]+prices[i];//卖出
        }
        return max(dp[len-1][1],max(dp[len-1][2],dp[len-1][3]));
    }
    //--------------------------------------------------------------------------------
    //买卖股票的最佳时机含手续费
    int maxProfitDpVI(vector<int>& prices,int fee){
        int len=prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2));
        dp[0][0]=0;//表示第一天不持有股票的状态，第一天不买就为0
        dp[0][1]-=prices[0];//表示第一天购买了股票的状态
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);//如果当天没有股票，只有可能前一天也没有，或者前一天有,现在卖加上利润减去手续费 
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//可以购买多次，贼需要记录前一天的状态
        } 
        return dp[len-1][0];
    }
    //-----------------------------------------------------------------------------------
    //最长递增子序列
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        vector<int>dp(nums.size()+1,1);//dp数组的含义是以当前值为末尾的最大子序列
        dp[0]=1;
        int res=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
    //-----------------------------------------------------------------------------------
    //最长的连续递增序列
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        vector<int>dp(nums.size()+1,1);//以当前值为末尾的最大连续子序列
        dp[0]=1;
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
            }
            res=max(dp[i],res);
        }
        return res;
    }
    //-------------------------------------------------------------------------------------
    //最长重复子序列
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0) return 0;
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));//dp数组的含义，nums1以i-1为结尾，nums2以j-1为结尾的最大重复子序列
        /*如果使用dp数组的含义定义为i，j为末尾；则当dp数组进行dp初始化；
        需要判断初始化的值，因为有的可能是相同的则需要将dp数组的值初始化为1*/  
        int res=0;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;//因为两个数组要同时进行+1操作，则dp[i][j]的状态只能由dp[i-1][j-1]得到
                }
                res=max(dp[i][j],res);
            }
        }  
        return res;
    };
    //------------------------------------------------------------------------------------------
    //最长公共子序列
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0||text2.size()==0) return 0;
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));//dp数组定义同上
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;//当末尾相等直接前面加一
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//当末尾不相等，dp[i][j]可能的两个状态
                    //去掉第一个数组的末尾比较结果，或者去掉第二数组的末尾比较结果，取最大值
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
    //----------------------------------------------------------------------------------------
    //不相交的线
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0) return 0;
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));//dp数组定义同上
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;//当末尾相等直接前面加一
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//当末尾不相等，dp[i][j]可能的两个状态
                    //去掉第一个数组的末尾比较结果，或者去掉第二数组的末尾比较结果，取最大值
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
    //----------------------------------------------------------------------------------------
    //最大的连续子序列和
    int maxSubArrayDp(vector<int>& nums){
        vector<int>dp(nums.size());//以该结尾的最大子序列和
        dp[0]=nums[0];
        int res=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            if(res<dp[i]) res=dp[i];
        }
        return res;
    }
    //--------------------------------------------------------------------------------------
    //判断子序列
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));//以i-1，j-1为末尾的数
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=dp[i][j-1];//比较是不是子序列，t去掉末尾等于现在状态就可以
                }
            }
        }
        return dp[s.size()][t.size()]==s.size();
    }
    //-------------------------------------------------------------------------------------
    //不同的子序列
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }//当t等于零时；只能将s删完这个方法；所以dp[i][0]=1
        for(int j=1;j<=t.size();j++){
            dp[0][j]=0;
        }//当s等于零时，t不等于0；没有办法删除使其相等
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){//当末尾数相等时；
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//当两边同时减去的末尾也一定是成立，然后s可能减去这个末尾也可能同样成立
                }else{
                    dp[i][j]=dp[i-1][j];//不相等，只能是s只能减去末尾的状态
                }
            }
        }
        return dp[s.size()][t.size()];
    }
    //------------------------------------------------------------
    //两个字符串的删除操作
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<=word1.size();i++){
            dp[i][0]=i;
        };//当word1有i个数字时,word2有0个字母；word1删除i个相同
        for(int j=1;j<=word2.size();j++){
            dp[0][j]=j;
        };//同上
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];//当相等时则直接等于两边直接减一不需要进行操作
                }else{
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                }//当不相等需要删除其中末尾一个数字，则需要进行操作加1
            }
        }
        return dp[word1.size()][word2.size()];
    }
    //----------------------------------------------------------------------------------------
    //编辑距离
    int minDistance1(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<=word1.size();i++){
            dp[i][0]=i;
        };//当word1有i个数字时,word2有0个字母；word1删除i个相同
        for(int j=1;j<=word2.size();j++){
            dp[0][j]=j;
        };//同上
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];//当末尾相等时；他的操作次数直接等于两边末尾忽略的次数
                }else{
                    dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
                    /*当两边不相等时，三个状态得到，各自删除末尾的单词，增加一个单词的等同于另一个删除末尾；
                    替换操作，当末尾替换时，就等于增加一次操作，然后等于末尾相等那种情况*/
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
    //-------------------------------------------------------------------------------------------------
    //回文子串
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        //dp数组的含义，i，j范围是否是回文串
        int res=0;
        //根据递推公式，dp[i][j]只能从左下角往上推，所以遍历顺序是i从小到大，j从i开始增加
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){//判断ij是否相等
                    if((j-i)<=1){//如果i和j的差小于等于1，说明两数是同一个或者相邻
                        dp[i][j]=true;
                        res++;
                    }else{
                        if(dp[i+1][j-1]==true){//两头缩减的子串是回文串，则i,j范围也是子串,dp[i][j]为true
                            dp[i][j]=true;
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------------
    //最长回文子序列
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));//i,j范围内的最长回文子串
        for(int  i=0;i<s.size();i++)  dp[i][i]=1;//将ij相等的位置初始化为1
        for(int i=s.size()-1;i>=0;i--){//只能从左下向右上推
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){//如果ij相等
                    dp[i][j]=dp[i+1][j-1]+2;//两边同时缩减，将长度加二
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);//如果不相等，只能由前面去掉或者后面去掉来得到
                }
            }
        }
        return dp[0][s.size()-1];//返回左边界和右边界的最大子串   
    }
    //--------------------------------------------------------------------------------------------------
    //每日温度
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;//定义栈，栈中存入遍历的数组下标
        vector<int>res(temperatures.size(),0);//将数组初始化成0,当遍历完栈中仍然没有比他的数，就默认初始化的数为0
        st.push(0);//将第一个数加入栈
        for(int  i=1;i<temperatures.size();i++){
            if(temperatures[i]<=temperatures[st.top()]){//如果当前数比栈顶数小，将下标存入栈
                st.push(i);
            }else{
                while(!st.empty()&&temperatures[i]>temperatures[st.top()]){//使用while因为当前数要不断比较栈顶元素，st不为空
                    res[st.top()]=i-st.top();//将结果数组下标位置为栈顶元素到比较数的距离 
                    st.pop();//比较结束将栈顶元素删除
                }
                st.push(i);//while结束需要将这个数加入栈中
            }
        }
        return res;
    }
    //-------------------------------------------------------------------------------------------------------
    //下一个更大的元素
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);//将数组初始化成-1
        if(nums1.size()==0) return res;
        stack<int>  st;//定义栈
        unordered_map<int,int>umap;//使用unordered_map查值更加迅速
        for(int i=0;i<nums1.size();i++){
            umap[nums1[i]]=i;
        }//对数组1进行哈希映射
        st.push(0);//将栈中首位存入
        for(int i=1;i<nums2.size();i++){
            if(nums2[i]<=nums2[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&nums2[i]>nums2[st.top()]){
                    if(umap.count(nums2[st.top()])>0){//当出现栈顶元素时,注意栈中记录的在nums2中的位置
                        int index=umap[nums2[st.top()]];//记录哈希映射的nums1数组位置
                        res[index]= nums2[i];//结果数组按照数组位置进行赋值
                        st.pop();//删除栈中元素
                    }
                }
                st.push(i);//将新的更大值存入栈中
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------
    //下一个更大元素II
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<nums.size()*2;i++){//将数组遍历两次
            //对于数组取环，可以计算他的取模进行定义
            if(nums[i%(nums.size())]<=nums[st.top()]){
                st.push(i%(nums.size()));
            }else{
                while(!st.empty()&&nums[i%(nums.size())]>nums[st.top()]){
                    res[st.top()]=nums[i%(nums.size())];
                    /*当模拟单调递增，会重复出现相同的结果数组；
                    当单调递减时，后面的值都存入栈中，并未进行赋值操作，就如同上面的默认初始化的操作，
                    后面的没有大数并没有进行操作，一直都是初始化的数*/
                    st.pop();
                }
                st.push(i%(nums.size()));
            }
        }
        return res;
    }
    //------------------------------------------------------------------------------------------
    //接雨水
    int trap(vector<int>& height) {
        int sum=0;//定义结果
        stack<int> st;//定义单调栈
        st.push(0);
        for(int i=1;i<height.size();i++){
            if(height[i]<=height[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&height[i]>height[st.top()]){
                    int mid=st.top();
                    st.pop();
                    if(!st.empty()){
                        int h=min(height[i],height[st.top()])-height[mid];//定义高度 
                        int w=i-st.top()-1;//定义宽度
                        sum+=(h*w);//累加容量
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
    //------------------------------------------------------------------------------------------
    //柱状图中最大的矩形
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;//定义结果数组
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        st.push(0);
        /*使用，单调栈求解右边，比当前最小的值*/
        for(int i=1;i<heights.size();i++){
            if(heights[i]>=heights[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&heights[i]<heights[st.top()]){
                    int mid=st.top();
                    st.pop();
                    if(!st.empty()){
                        int left=st.top();
                        int right=i;
                        int w=right-left-1;
                        int h=heights[mid];
                        maxArea=max(maxArea,w*h);
                    }
                }
                st.push(i);
            }
        }
        return maxArea;
    }

};

int main() {
    vector<int> prices={2,4};
    Solution solution;
    int ans=solution.largestRectangleArea(prices);
    cout<<ans<<endl;
    system("pause");
    return 0;
};