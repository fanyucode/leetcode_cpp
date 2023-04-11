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


    //����ܺ�2
    //void combinationSum2_backtracking(vector<int>& nums, int sum, int targetSum, int startIndex, vector<bool>& used) {
    //    //��ֹ����
    //    if (sum == targetSum) {
    //        res.push_back(path);
    //        return;
    //    }
    //    //��һ���sum>targetSum�����ֱ����forѭ����ֱ�ӽ�� 
    //    for (int i = startIndex;i < nums.size()&&sum+nums[i]<=targetSum;i++) {
    //        //ȥ�ص��߼���������������򣻵�����Ԫ����ͬʱ���ռ��Ľ��һ������ͬ�ģ�
    //        //��ֹ���������ǰһ��Ҳ���ù���Ԫ�أ������һ��Ԫ����Ȼ������ͬ����Ҳ����Ҫ�ģ�����ֱ������
    //        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    //            continue;
    //        }
    //        sum += nums[i];
    //        used[i] = true;
    //        //path.push_back(nums[i]);
    //        combinationSum2_backtracking(nums, sum, targetSum, i + 1, used);//�ݹ�
    //        path.pop_back();//����
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
    //}//����ܺ�2

    //----------------------------------------------------------------------------------------------------------------------

    ////�ָ���Ĵ�
    //bool isPalindrome(const string& s, int start, int end) {//�ж��Ƿ��ǻ��Ĵ�
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
    //        cout << endl;//��ÿ����ӡ�ռ������Ľ������
    //        return;
    //    }//��ֹ��������startIndex����ʱ���ʾ�ָ�ǻ��Ĵ���������ռ�
    //    for (int i = startIndex;i < s.size();i++) {
    //        if (isPalindrome(s, startIndex, i)) {//������Ӵ��ǻ��Ĵ�������ռ�
    //            string str = s.substr(startIndex, i - startIndex + 1);
    //            //path.push_back(str);
    //            cout << str << " ";//��ӡ�������Ĵ�
    //        }
    //        else {
    //            continue;//����������
    //        }
    //        patition_backtracking(s, i + 1);//�ݹ�
    //        path.pop_back();//����

    //    }
    //}
    //vector<vector<string>> partition(string s) {
    //    res.clear();
    //    path.clear();
    //    patition_backtracking(s, 0);
    //    //return res;
    //}

    //----------------------------------------------------------------------------------------------------

    //93.��ԭip��ַ
    /*vector<string> res;
    string path;*/
    //bool isVaild(const string& s, int start, int end) {
    //    if (start > end) {
    //        return false;
    //    }
    //    if (start != end && s[start] == '0') {//����ĸΪ0�����Ϸ�
    //        return false;
    //    }
    //    int num = 0;
    //    for (int i = start;i <= end;i++) {
    //        if (s[i] > '9' || s[i] < '0') {//ascII��ֵ����9����С��0�����Ϸ�
    //            return false;
    //        }
    //        num = num * 10 + (s[i] - '0');//num����255,���Ϸ�
    //        if (num > 255) {
    //            return false;
    //        }
    //    }
    //    return true;  
    //}
    //void restoreIpAddress_backtracking(string& s, int startIndex,int pointSum) {
    //    //ȷ����ֹ����
    //    if (pointSum == 3) {//��������������ʱ����Ҫ return
    //        if (isVaild(s, startIndex, s.size() - 1)) {
    //            res.push_back(s);
    //            cout << s;
    //            cout << endl;
    //        }
    //        return;
    //    }
    //    //���������߼�
    //    for (int i = startIndex;i < s.size();i++) {
    //        if (isVaild(s, startIndex, i)) {
    //            s.insert(s.begin() + i + 1, '.');
    //            pointSum++;
    //            restoreIpAddress_backtracking(s, i + 2, pointSum);//�������һ���㣻����i��Ҫ��2��������һ��ĵݹ����
    //            pointSum--;//����
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
    //78�Ӽ�
   /* vector<vector<int>> res;*/
    //vector<int> path;
    //void subsets_backtracking(vector<int>& nums, int startIndex) {
    //    res.push_back(path);//�õ������
    //    if (startIndex >= nums.size()) {
    //        return;
    //    }
    //    for (int i = startIndex;i < nums.size();i++) {
    //        path.push_back(nums[i]);
    //        subsets_backtracking(nums, i + 1);
    //        path.pop_back();
    //    }
    //}
    //// �Ӽ����⣬ÿ�εݹ鿪ʼ��Ҫ��ȡ����������ǵ�Ҷ�ӽڵ�ȥ�õ����
    //vector<vector<int>> subsets(vector<int>& nums) {
    //    path.clear();
    //    res.clear();
    //    subsets_backtracking(nums, 0);
    //    return res;
    //}
//-------------------------------------------------------------------------------------------------------------------

    //90���Ӽ�II
    //vector<int>path;
    //vector<vector<int>>res;
    //void subsetWithDup_backtracking(vector<int>& nums, int startIndex,vector<bool> used) {
    //    res.push_back(path);
    //    if (startIndex >= nums.size()) {
    //        return;
    //    }
    //    for (int i = startIndex;i < nums.size();i++) {
    //        //����ȥ�� ����֤�����ָ�����i>0
    //        //ǰһ�����ֺͱ���������ͬ������û���ù�ֱ������  
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
   //491����������
    //vector<int>path;
    //vector<vector<int>>res;
    //void backtracking_findSubsequences(vector<int>& nums, int startIndex) {
    //    //��ֹ����
    //    if (path.size() > 1) {
    //        res.push_back(path);
    //    }
    //    unordered_set<int>  uset;//���õ���������
    //    for (int i = startIndex;i < nums.size();i++) {
    //        if ((!path.empty() && path.back() > nums[i]) || uset.find(nums[i]) != uset.end()) {
    //            continue;
    //        }
    //        uset.insert(nums[i]);//����nums[i]
    //        path.push_back(nums[i]);
    //        backtracking_findSubsequences(nums, i + 1);
    //        //�����unordered_set;�˴���set��������Ҫ����
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

    //46.ȫ����
    //vector<int>path;
    //vector<vector<int>> res;
    ////ȫ���в���Ҫ�����Ӽ���˳��ͬҲҪ�ռ������Բ���ҪstartIndex������˳��
    //void backtracking_premute(vector<int>& nums, vector<bool> used) {
    //    if (path.size() == nums.size()) {
    //        res.push_back(path);
    //    }//��ֹ����
    //    //ֻ��Ҫ��used���飻��¼������Ƿ��ù��Ϳ���
    //    for (int i = 0;i < nums.size();i++) {
    //        if (used[i]) {
    //            continue;
    //        }
    //        used[i] = true;
    //        path.push_back(nums[i]);
    //        backtracking_premute(nums, used);//�ݹ�
    //        used[i] = false;//����
    //        path.pop_back();//����
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
    //47.ȫ����2
    //vector<int> path;
    //vector<vector<int>> res;
    //void backtracking_permuteUnique(vector<int>& nums, vector <bool> used) {
    //    //��ֹ����
    //    if (path.size() == nums.size()) {
    //        res.push_back(path);
    //        return;
    //    }
    //    for (int i = 0;i < nums.size();i++) {
    //        //ȥ���߼������ظ����飬��ǰһ�����ͺ�һ������ͬʱ��һ�������߼��Ѿ����ꣻֻ��Ҫ�ж�ǰһ�����Ƿ��ù�
    //        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    //            continue;
    //        }
    //        //ʹ��used����������Ƿ���ͬһ������ͬһ����ֱ�����������ظ�����
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

    ////51 N�ʺ�
    //vector<vector<string>> res;
    ////ÿ�μ��ֻ��Ҫ����ϱ߲�������û��Q�Ϳ���
    ////��Ϊÿ�����Ѷ��Ǵ���һ�п�ʼ��������
    //bool isValid(vector<string>& chessboard, int row, int col,int n) {
    //    //ÿ�β�ֵ���Ǵ�row+1��ʼ������Ҫ�����
    //    for (int i = 0;i < row;i++) {
    //        if (chessboard[i][col] == 'Q') {
    //            return false;
    //        }
    //    }
    //    //������϶Խ�����ûQ
    //    for (int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--, j--) {
    //        if (chessboard[i][j] == 'Q') {
    //            return false;
    //        }
    //    }
    //    //������ϽǶԽ�����û��Q
    //    for (int i = row - 1, j = col + 1;i >= 0 && j < n;i--, j++) {
    //        if (chessboard[i][j] == 'Q') {
    //            return false;
    //        }
    //    }
    //    return true;
    //}
    //void backtracking_solveNQueens(vector<string>& chesssboard, int row, int n) {
    //    //��ֹ��������row�������Ľ�� 
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
    //    //����һ��n x n��'.'������
    //    res.clear();
    //    vector<string> chessboard(n,string(n, '.'));
    //    backtracking_solveNQueens(chessboard, 0, n);
    //    return  res;
    //}

//------------------------------------------------------------------------------------------------------------------------------
//37.������
    //�����ά���飻ʹ�ö�ά����
    bool isValid(int  i, int j, const vector<vector<char>>& board, char k) {
        for (int row = 0;row < 9;row++) {//������
            if (board[row][j] == k) {
                return false;
            }
        }
        for (int col = 0;col < 9;col++) {//������
            if (board[i][col] == k) {
                return false;
            }
        }
        //���������������ʼ������ 
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;
        //���������������򣻱�������������
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
        //��������ÿ��λ�ã�������ֵ
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') {//����������˵�����Բ�ֵ��
                    //ֻ��Ҫ�жϵ�ǰλ�ã�ĳЩ����ֵ�ܲ��ܺϷ���
                    //
                    for (char k = '1';k <= '9';k++) {
                        if (isValid(i, j, board, k)) {
                            board[i][j] = k;
                            if (bracktracking_solveSudoku(board)) {
                                return true;//���ѵ��˺��ʵ�ֵ����TRUE��һ�����ϵݹ�
                            }
                        }
                    }
                    return false;//���Ÿ����������Ե�ʱ�򣻷���false
                }
            }
        }
        return true;//����ѭ������ֱ�ӷ���true
    }
    void solveSudoku(vector<vector<char>>& board) {
        bracktracking_solveSudoku(board);
    }
    //-----------------------------------------------------------------------------------------------------------------------------   

   //̰���㷨
       //�ַ�����
       //ʹ����С�ı��ɸ���С��θ�ڵ�С���ľֲ����Ž�
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;//С����λ��
        for (int i = 0;i < s.size();i++) {//�������ɵ�λ��
            //���index����С�����������˳�index�������ұ��ɴ��ڵ���θ��
            if (index < g.size() && g[index] <= s[i]) {
                index++;
            }
        }
        return index;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
        //376.�ڶ�����
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int preDiff = 0;//ǰһ�Բ�ֵ
        int curDiff = 0;//��ǰ��ֵ 
        int res = 1;//Ĭ��ǰ����һ����ֵ
        for (int i = 0;i < nums.size() - 1;i++) {
            curDiff = nums[i + 1] - nums[i];//��֮���һ������ȥ��ǰ�������ǵ�ǰ��ֵ
            //������ƽ��preDiff�����curDiffһ��Ϊ0��
            //ʹ���������ȥ��ƽ����� ��ֱ�����ְڶ�
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                res++;
                preDiff = curDiff;//�����ֵ���ƽ�µ������ֻ��Ҫ�����аڶ���ʱ����м�¼����
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------
        //��������
    int maxSubArray(vector<int>& nums) {
        //��������������Ǹ�������
        //���µĿ�ʼ��¼����Ϊ��������res��¼��
        //��ֹ��ǰres����󣻵���ǰ���������ܶԺ�����Ӱ��
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
        //������Ʊ�����ʱ��II
    int maxProfit(vector<int>& prices) {
        //��ι����Ʊ����ͨ��һֱ�ۼ������õ��������
        int res = 0;
        for (int i = 1;i < prices.size();i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------
        //��Ծ��Ϸ
    bool canJump(vector<int>& nums) {
        //��������ֻ��Ҫ�жϵ�ǰcover�ܲ��ܵ���ĩλ
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0;i <= cover;i++) {//��ǰ���������coverֵ��Ҳ�����ܵ������λ��
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) {//��cover����nums.size()-1;����true
                return true;
            }
        }
        return false;
    }
    //-----------------------------------------------------------------------------------------------------
         //��Ծ��ϷII
    int jump(vector<int>& nums) {
        int next = 0;
        int cur = 0;
        int res = 0;
        for (int i = 0;i < nums.size();i++) {
            next = max(i + nums[i], next);//��ǰ���ǵ����ֵ
            if (i == cur) {//������˵�ǰ��󸲸Ƿ�Χ
                if (cur < nums.size() - 1) {//�����ǰ���Ƿ�ΧС��ĩλ������Ծ����
                    //��ǰ��cur���³���һ����Ծ����ʼλ�á�
                    res++;
                    cur = next;
                    if (next >= nums.size() - 1) break;//�����һ�ε���Ծλ�ã�����ĩλ
                }
                else break;
            }
        }
        return res;
    }
    //-------------------------------------------------------------------------------------------------
         //k��ȡ�������������
    static bool  myCompare(int a, int b) {
        return abs(a) > abs(b);
    }//�����鰴����ֵ�Ӵ�С��������
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), myCompare);
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] < 0 && k>0) {//��������������nums��ֵС��0����k��û���귭ת
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;//���kû���ꣻȡ��С�ķ�ת��������з�ת
        //��ʣ��k������ֻ��Ҫȡ��С������ֵ���з�ת������ʹ�þ��������Ӵ�С���һ������
        //��ʣ��kΪż����������ô��ת��һ����������ԭ��ֵ���Բ���Ҫ���в���
        int res = 0;
        for (int num : nums) res += num;
        return res;
    }
    //------------------------------------------------------------------------------------------------------
         //����վ
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //̰�ĵ�˼·��ͨ���ۼ�gas-cost�������ֲ���С�����ģ��ʹ���һ���ڵ㿪ʼ
        //�����е��ܺͻ���С��0���ǲ���������ֱ�ӷ���-1
        int curSum = 0;//���嵱ǰ�������
        int totalSum = 0;//���е���ʧ�͹���
        int start = 0;//�������curSum����ʼλ��
        for (int i = 0;i < gas.size();i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {//���ֲ��������С��0�����¶���ֲ�����
                curSum = 0;//���curSum
                start = i + 1;//��¼��ʼλ��
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
    //--------------------------------------------------------------------------------------------------
         //�ַ��ǹ�
    int candy(vector<int>& ratings) {
        //�ֱ�����߿�ʼ�������жϴ洢��candy
        vector<int>  candies(ratings.size(), 1);//�������飻��Ϊÿ��С�����ٻ��һ��
        //�������ұ�����������С���ұߣ�����Ҫ�ұ�����һ��
        for (int i = 1;i < ratings.size();i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        //����������б������Ƚ�����ֵ��������������Ƚϵ�ǰֵ+1�������Ĵ�ʱ�����ֵ
        for (int j = ratings.size() - 2;j >= 0;j--) {
            if (ratings[j] > ratings[j + 1]) {
                candies[j] = max(candies[j], candies[j + 1] + 1);//��ֹ����û�й˼�ǰһ�������Ҫȡ���ֵ
            }
        }
        int res = 0;
        for (int cand : candies) res += cand;
        return res;
    }
    //--------------------------------------------------------------------------------------------------
         //����ˮ����
    bool lemonadeChange(vector<int>& bills) {
        //̰�Ĳ��ԣ����ڶ�ʮ��������������
        //����ʹ��ʮ�����������������������
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
         //��������ؽ�����
    static bool comp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }//�����鰴��ߴӴ�С���У��������ͬʱ��λ�ô�С��������
    //����ʹ��list���ݽ��в�����������������Ҫ��ܶ�
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        list<vector<int>> que;//����������
        for (int i = 0;i < people.size();i++) {//��������
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
         //�����������ļ���������
    static bool comp1(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), comp1);//�����鰴��һ��������
        int res = 1;//size����0��������Ҫһ֧��
        for (int i = 1;i < points.size();i++) {
            if (points[i - 1][1] < points[i][0]) {//��ǰһ��������ұ߽�С�ں�һ��������߽�
                res++;//������Ҫ����
            }
            else {//���ص���ʱ��ֻ��Ҫ��ǰһ������͵�ǰ�ıȽ��ұ߽磻˭��ȡ�ĸ��ұ߽磻���¸�������䶨��
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
    //----------------------------------------------------------------------------------------------------------------------
         //���ص�����
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // ��������߽��������
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), comp1);
        int count = 0;
        for (int i = 1;i < intervals.size();i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {//�������ص�
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);//������С�ұ߽����һ���Ƿ��ص��������бȽ�
                count++;//��Ҫ�Ƴ��������һ
            }
        }
        return count;
    }


    //---------------------------------------------------------------------------------------------------------------------------
         //������ĸ����
    vector<int> partitionLabels(string s) {
        //ʹ��hash���飻��¼��Զ��λ��
        int hash[27] = { 0 };
        for (int i = 0;i < s.size();i++) {
            hash[s[i] - 'a'] = i;
        }//�������齫��ֵ����
        vector<int> res;//��������
        int left = 0, right = 0;//������������
        for (int i = 0;i < s.size();i++) {
            right = max(right, hash[s[i] - 'a']);//���ұ߽�ѡȡ��Զ��
            if (i == right) {//�����������Զ��ֵ
                res.push_back(right - left + 1);//�ռ������
                left = i + 1;//left���³���һ��
            }
        }
        return res;
    }
    //------------------------------------------------------------------------------------------------------------------------
        //�ϲ�����
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), comp1);//����߽��������
        res.push_back(intervals[0]);//�Ƚ���һ�������޸����������Ϳ���
        for (int i = 1;i < intervals.size();i++) {
            if (res.back()[1] >= intervals[i][0]) {//�ص�����
                res.back()[1] = max(res.back()[1], intervals[i][1]);
                //������ռ�������ұ߽��޸ľͿ��ԣ���߽簴��С��������һ������С��
            }
            else {// û���ص�����
                res.push_back(intervals[i]);//�ռ����
            }
        }
        return res;
    }
    //--------------------------------------------------------------------------------------------------------------------------
         //��������������
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);//��int��ת����string����
        int flag = str.size();//����һ�������¼�����Ҫ���9������
        for (int i = str.size() - 1;i > 0;i--) {//�Ӻ���ǰ�����������������ǰ��ֵ���޸�Ӱ�����Ľ��
            if (str[i - 1] > str[i]) {//��ǰһ�������ں�һ����ʱ���Ͳ��ǵ�������
                str[i - 1]--;//ǰ����һ
                flag = i;//����flag���涼��Ҫ���9
            }
        }
        for (;flag < str.size();flag++) {
            str[flag] = '9';
        }
        //ʹ�ÿ⺯��stdlib.h�����stoi����;��stringת����int
        int  res = stoi(str);
        return res;

    }
    //----------------------------------------------------------------------------------------------------------------------
    //��ض�����
    int res_Camera;
    int traversal(TreeNode* cur) {
     //���������
        if (cur == NULL) return 2;//��ֹ����
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (left == 2 && right == 2) {
            return 0;
        }//�������ӽڵ㶼��2�����׽ڵ㲻����������
        if (right == 0 || left == 0) {
            res_Camera++;
            return 1;
        }//�������ӽڵ�û�б����ǣ��򸸽ڵ������������
        if (left == 1 || right == 1) {
            return 2;
        }//�������ӽڵ���������򸸽ڵ�һ��������
        return -1;
    };
    int minCameraCover(TreeNode* root) {
        res_Camera = 0;
        //�����ڵ��ϲ�û�и��ڵ㣻��û�б���������Ҫ����һ��camera
        if (traversal(root) == 0) {
            res_Camera++;
        }
        return  res_Camera;
    }
    //---------------------------------------------------------
    
    //��̬�滮
    /*  ȷ��dp���飨dp table���Լ��±�ĺ���
        ȷ�����ƹ�ʽ
        dp������γ�ʼ��
        ȷ������˳��
        �����Ƶ�dp����*/
    //----------------------------------------------------------


    //쳲�������
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        //����dp����
        vector<int>dp(n+1);
        //ȷ�����ƹ�ʽ
        dp[0] = 0;dp[1] = 1;//��ʼ��
        cout << 0 << " " << 1 << " ";
        for (int i = 2;i <= n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i] << " ";
        }
        return dp[n];
    }
    //----------------------------------------------------------------

    //��¥��
    int climbStairs(int n) {
        if(n<=1){
            return n;
        }
           //����dp����
        vector<int> dp(n + 1);
       //dp����ĳ�ʼ��
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            //ȷ��dp�߼�
            dp[i] = dp[i - 1] + dp[i - 2];
            // //��ӡdp����
            // cout << dp[i] << " ";
            
        }
        return dp[n];
    }
    //--------------------------------------------------------------
    //ʹ����С������¥��
    int minCostClimbingStairs(vector<int>& cost) {
            //����dp����
            vector<int> dp(cost.size() + 1);
            //��ʼ��dp����
            dp[0] = 0, dp[1] = 0;
            //����˳�� 
            for (int i = 2; i <= cost.size(); i++) {
                //dp�߼���ѡ����С�Ļ��ѽ�����Ծ
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
                cout << dp[i] << " ";
            }
            return dp[cost.size()];
    }
    //-------------------------------------------------------------------
    //��ͬ·��
    int uniquePaths(int m, int n) {
        //����dp���飻�����Ƕ�ά����
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //��ʼ��:����һ�к͵�һ�е�������Ϊ0
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        //���dp����
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //��ǰ״ֻ̬����������������洫��
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1]; 
    }  
    //------------------------------------------------------------------------
    //��ͬ·��II 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //����dp���飻�����Ƕ�ά����
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //�����鿪ʼ�ͽ�β���ϰ�һ��������·��ֱ�ӷ���0
        if (obstacleGrid[0][0] == 1 && obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //��ʼ��:����һ�к͵�һ�е�������Ϊ1,���ϰ���Ϊ0
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //������ط����ϰ�ֱ������
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                //��ǰ״ֻ̬����������������洫��
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    //-------------------------------------------------------------------
    //�������
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