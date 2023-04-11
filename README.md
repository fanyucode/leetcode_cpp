# 代码随想录

## 数组

### 数组理论

- 数组下表都是从0开始

- 数组的空间地址是连续的

要注意vector 和 array的区别，vector的底层实现是array，严格来讲vector是容器，不是数组。

```cpp
void test_arr() {
    int array[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
    };
    cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl;
    cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl;
}

int main() {
    test_arr();
}
```

测试案例

```text
0x7ffee4065820 0x7ffee4065824 0x7ffee4065828
0x7ffee406582c 0x7ffee4065830 0x7ffee4065834
```

### 二分查找

[704. 二分查找 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-search/)

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){//定义边界条件，当定义r=size-1，就为存在nums[r]
        int mid =l+(r-l)/2;
            if(target>nums[mid]){
                l=mid+1;
            }
            else if(target<nums[mid]){
                r=mid-1;
            }
            else {
                return mid;
            }
        }
            return -1;
      }      
};
```

- 写二分法，区间的定义一般为两种，左闭右闭即[left, right]，或者左闭右开即[left, right)。

  - 第一种写法，我们定义 target 是在一个在左闭右闭的区间里，**也就是[left, right] （这个很重要非常重要）**。

    区间的定义这就决定了二分法的代码应该如何写，**因为定义target在[left, right]区间，所以有如下两点：**

    - while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=

    - if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1

      <img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20210311153055723.jpg" alt="704.二分查找" style="zoom:50%;" />

  - 第二种写法，如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) ，那么二分法的边界处理方式则截然不同。

    有如下两点：

    - while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的
    
    - f (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，所以right更新为middle，即：下一个查询区间不会去比较nums[middle]
    
      <img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20210311153123632.jpg" alt="704.二分查找1" style="zoom:50%;" />

- 总结

  ​         其实主要就是对区间的定义没有理解清楚，在循环中没有始终坚持根据查找区间的定义来做边界处理。

  区间的定义就是不变量，那么在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。

  ### 移除元素

  [27. 移除元素 - 力扣（Leetcode）](https://leetcode.cn/problems/remove-element/)

  ```c++
  class Solution {
  public:
      int removeElement(vector<int>& nums, int val) {
      //通过双指针，当遇到val值时，第一个指针，不动，第二个指针移动，不能使用ptr2++，当到达最后一个元素时，nums【ptr+1】没有这个数
          int ptr1=0;
          for(int ptr2=0;ptr2<nums.size();ptr2++){
               if(val!=nums[ptr2]){
                   nums[ptr1++]=nums[ptr2];
               }
          }
          return ptr1;
      }
  };
  ```

  **双指针法（快慢指针法）在数组和链表的操作中是非常常见的，很多考察数组、链表、字符串等操作的面试题，都使用双指针法。**
  
  ![27.移除元素-双指针法](https://code-thinking.cdn.bcebos.com/gifs/27.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0-%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95.gif)

### 有序数组的平方

[977. 有序数组的平方 - 力扣（Leetcode）](https://leetcode.cn/problems/squares-of-a-sorted-array/)

```  c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int ptr1=0,ptr2=nums.size()-1;
        int k=nums.size()-1;
        while(ptr1<=ptr2){
            int ptr1_val=nums[ptr1]*nums[ptr1],ptr2_val=nums[ptr2]*nums[ptr2];
            if(ptr1_val>=ptr2_val){
                ans[k--]=ptr1_val;
                ptr1++;
            }
            else{
                ans[k--]=ptr2_val;
                ptr2--;
            }
        }
        return ans;
    }
};
```

定义边界条件，首尾肯定是平方最大的数。当大数存入结果数组开始进行，指针往里面走一位。当两指针相遇时，退出。

![img](https://code-thinking.cdn.bcebos.com/gifs/977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.gif)

### 长度最小的子数组

[209. 长度最小的子数组 - 力扣（Leetcode）](https://leetcode.cn/problems/minimum-size-subarray-sum/)

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT32_MAX;//双指针操作，一次for循环，大循环使用终止ptr2
        int ptr1=0;
        int sum=0;
        int subLength =0;
        for(int ptr2=0;ptr2<nums.size();ptr2++){
            sum+=nums[ptr2];
            while(sum>=target){//当出现第一个目标值，开始移动ptr1减小区间
                
                subLength=ptr2-ptr1+1;
                ans=(ans>subLength?subLength:ans);//当出现第一个大于target的区间
                sum-=nums[ptr1++];
            }   
        }
        return ans==INT32_MAX?0:ans;
    }
};
```

#### 滑动窗口

**就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果**。

只用一个for循环，那么这个循环的索引，一定是表示 滑动窗口的终止位置。

- 窗口内是什么？

- 如何移动窗口的起始位置？

- 如何移动窗口的结束位置？

  窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

  窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

  窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。
  
  ![209.长度最小的子数组](https://code-thinking.cdn.bcebos.com/gifs/209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.gif)

### 螺旋矩阵II

[59. 螺旋矩阵 II - 力扣（Leetcode）](https://leetcode.cn/problems/spiral-matrix-ii/)

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));//定义一个二维数组
        int loop=n/2;//确定圈数
        int startx=0,starty=0;//定义每一圈的起始位置
        int mid=n/2;//确定矩阵中间的位置
        int offset=1;//用来控制矩阵中每一条边的遍历长度，每次右边界收缩一位
        int count=1;//用来给矩阵的每一个空格赋值
        int i,j;
        while(loop--){
            //下面四个for就是模拟转了一圈
            //填充上行从左到右(右闭左开)
            for(j=starty;j<n-offset;j++){
            ans[startx][j]=count++;
            }
            //模拟填充右列从上到下（左闭右开）
            for(i=startx;i<n-offset;i++){
                ans[i][j]=count++;
            }
            //模拟填充下行从右到左(左闭右开)
            for(;j>starty;j--){
                ans[i][j]=count++;
            }
            //模拟左从下到上
            for(;i>startx;i--){
                ans[i][j]=count++;
            }
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是                 (1, 1)
            startx++,starty++;
            // offset 控制每一圈里每一条边遍历的长度
            offset++;
        }
        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if(n%2){
            ans[mid][mid]=count;
        }
        return ans;
    }
};
```

### 总结

#### 二分法

在这道题目中我们讲到了**循环不变量原则**，只有在循环中坚持对区间的定义，才能清楚的把握循环中的各种细节。

#### 双指针法

双指针法（快慢指针法）：**通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。**

#### 滑动窗口

本题中，主要要理解滑动窗口如何移动 窗口起始位置，达到动态更新窗口大小的，从而得出长度最小的符合条件的长度。

**滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)的暴力解法降为O(n)。**

## 链表

### 基础理论

#### 链表的结构体

```c++
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
```

通过自己定义构造函数初始化节点：

```c++
ListNode* head = new ListNode(5);
```

使用默认构造函数初始化节点：

```c++
ListNode* head = new ListNode();
head->val = 5;
```

所以如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值！

![链表-链表与数据性能对比](https://code-thinking-1253855093.file.myqcloud.com/pics/20200806195200276.png)

### 移除链表的元素

[203. 移除链表元素 - 力扣（Leetcode）](https://leetcode.cn/problems/remove-linked-list-elements/)

```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead=new ListNode(0);// 设置一个虚拟头结点
        dummyHead->next=head;// 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur=dummyHead;
        while(cur->next!=NULL){
            if(cur->next->val==val){
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else cur=cur->next;
        }
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};
```

- **设置一个虚拟头结点在进行删除操作。**

  ![27.移除元素-双指针法](https://code-thinking.cdn.bcebos.com/gifs/27.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0-%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95.gif)

### 设计链表

[707. 设计链表 - 力扣（Leetcode）](https://leetcode.cn/problems/design-linked-list/)

```c++
class MyLinkedList {
public:
    //定义节点的结构体
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        dummyHead=new  LinkedNode(0);//定义一个虚拟头结点，不是真正的链表
        _size=0;
    }
    int get(int index) {
        if(index>(_size-1)||index<0){
            return -1;
        }
        LinkedNode* cur=dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }
    void addAtHead(int val) {
        LinkedNode* addHead=new LinkedNode(val);
        addHead->next=dummyHead->next;
        dummyHead->next=addHead;
        _size++;
    }
    void addAtTail(int val) {
        LinkedNode* addHead=new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=addHead;
        _size++;
    }
    void addAtIndex(int index, int val) {
         if(index>_size) return;
        if(index<0) index=0;
        LinkedNode* addIndex=new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        addIndex->next=cur->next;
        cur->next=addIndex;
        _size++;
    }
    void deleteAtIndex(int index) {
        if(index<0||index>=_size){
            return;
        }
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        LinkedNode* temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        _size--;
    }
private:
    LinkedNode* dummyHead;
    int _size;
};
```

### 反转链表

[206. 反转链表 - 力扣（Leetcode）](https://leetcode.cn/problems/reverse-linked-list/)

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};
```

首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。

然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。

为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。

接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。

最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。

![img](https://code-thinking.cdn.bcebos.com/gifs/206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.gif)

### 两两交换链表中的节点

[24. 两两交换链表中的节点 - 力扣（Leetcode）](https://leetcode.cn/problems/swap-nodes-in-pairs/)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* temp=cur->next;
            ListNode* temp1=cur->next->next->next;
            cur->next=cur->next->next;
            cur->next->next=temp;
            cur->next->next->next=temp1;
            cur=cur->next->next;
        }
        return dummyHead->next;
    }
};
```

初始时，cur指向虚拟头结点，然后进行如下三步：

![24.两两交换链表中的节点1](https://code-thinking.cdn.bcebos.com/pics/24.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B91.png)

操作之后，链表如下：

![24.两两交换链表中的节点2](https://code-thinking.cdn.bcebos.com/pics/24.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B92.png)

看这个可能就更直观一些了：

![24.两两交换链表中的节点3](https://code-thinking.cdn.bcebos.com/pics/24.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B93.png)

### 删除链表的倒数第N个节点

[19. 删除链表的倒数第 N 个结点 - 力扣（Leetcode）](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode *Head=new ListNode(0);
        Head->next=head;//先创建第一个节点，next连接链表的头节点，这样当删除第一个节点的时候，就会得到了Head->next的节点，即得到第二个节点，否则得不到下一个节点
        ListNode* L=head;
        ListNode* R=head;
        for(int i=0;i<n;i++)  L=L->next;//定义两节点；将L的节点向后移动n位；当L到达末尾指针，R刚好到需要删除的第n个节点
        ListNode* pre=Head;
        while(L)
        {
            L=L->next;
            pre=R;
            R=R->next;
        }
        pre->next=R->next;
        return Head->next;

    }
};
```

### 链表相交

[160. 相交链表 - 力扣（Leetcode）](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA,* curB=headB;
        int m=0,n=0;
        while(curA){
            curA=curA->next;
            m++;
        }
        while(curB){
            curB=curB->next;
            n++;
        }
        curA=headA;
        curB=headB;
        if(m<n){
            swap(m,n);
            swap(curA,curB);
        }
        int gap=m-n;
        while(gap--){
            curA=curA->next;
        }
        while(curA!=NULL){
            if(curA==curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return NULL;
    }
};
```

### 环形链表

[142. 环形链表 II - 力扣（Leetcode）](https://leetcode.cn/problems/linked-list-cycle-ii/)

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                ListNode* index1=slow;
                ListNode* index2=head;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
```

可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢

首先第一点：**fast指针一定先进入环中，如果fast指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。**

fast和slow各自再走一步， fast和slow就相遇了

这是因为fast是走两步，slow是走一步，**其实相对于slow来说，fast是一个节点一个节点的靠近slow的**，所以fast一定可以和slow重合。

**此时已经可以判断链表是否有环了，那么接下来要找这个环的入口了。**

**从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点**。

## 哈希表

### 哈希表理论基础

#### 哈希函数

哈希函数，把学生的姓名直接映射为哈希表上的索引，然后就可以通过查询索引下标快速知道这位同学是否在这所学校里了。

![哈希表2](https://code-thinking-1253855093.file.myqcloud.com/pics/2021010423484818.png)

#### 哈希碰撞

小李和小王都映射到了索引下标 1 的位置，**这一现象叫做哈希碰撞**。

![哈希表3](https://code-thinking-1253855093.file.myqcloud.com/pics/2021010423494884.png)

#### 拉链法

刚刚小李和小王在索引1的位置发生了冲突，发生冲突的元素都被存储在链表中。 这样我们就可以通过索引找到小李和小王了

![哈希表4](https://code-thinking-1253855093.file.myqcloud.com/pics/20210104235015226.png)

#### 线性探测

使用线性探测法，一定要保证tableSize大于dataSize。 我们需要依靠哈希表中的空位来解决碰撞问题。

例如冲突的位置，放了小李，那么就向下找一个空位放置小王的信息。所以要求tableSize一定要大于dataSize ，要不然哈希表上就没有空置的位置来存放 冲突的数据了。

![哈希表5](https://code-thinking-1253855093.file.myqcloud.com/pics/20210104235109950.png)

#### 三种哈希结构

- 数组
- set 集合
- map 映射

### 有效的字母异位词

[242. 有效的字母异位词 - 力扣（Leetcode）](https://leetcode.cn/problems/valid-anagram/)

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26]={0};//将26个字母存入vector数组并记录
        for(int i=0;i<s.size();i++){
            record[s[i]-'a']++;//s[i]-'a'相对数值
        }
        for(int j=0;j<t.size();j++){
            record[t[j]-'a']--;
        }
        for(int k=0;k<26;k++){
            if(record[k]!=0)
            return false;
        }
        return true;
    }
};
```

需要把字符映射到数组也就是哈希表的索引下标上，**因为字符a到字符z的ASCII是26个连续的数值，所以字符a映射为下标0，相应的字符z映射为下标25。**

再遍历 字符串s的时候，**只需要将 s[i] - ‘a’ 所在的元素做+1 操作即可，并不需要记住字符a的ASCII，只要求出一个相对数值就可以了。** 这样就将字符串s中字符出现的次数，统计出来了。

那看一下如何检查字符串t中是否出现了这些字符，同样在遍历字符串t的时候，对t中出现的字符映射哈希表索引上的数值再做-1的操作。

那么最后检查一下，**record数组如果有的元素不为零0，说明字符串s和t一定是谁多了字符或者谁少了字符，return false。**

最后如果record数组所有元素都为零0，说明字符串s和t是字母异位词，return true。

![242.有效的字母异位词](https://code-thinking.cdn.bcebos.com/gifs/242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.gif)

### 两个数组的交集

[349. 两个数组的交集 - 力扣（Leetcode）](https://leetcode.cn/problems/intersection-of-two-arrays/)

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_set;
        int res[1005]={0};
        for(int num:nums1){
            res[num]=1;
        }
        for(int num:nums2){
            if(res[num]==1){
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(),res_set.end());
    }
};
```

**使用数组来做哈希的题目，是因为题目都限制了数值的大小。**

而这道题目没有限制数值的大小，就无法使用数组来做哈希表了。

**而且如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。**

**set容器浪费时间，数组访问快**

![set哈希法](https://code-thinking-1253855093.file.myqcloud.com/pics/20220707173513.png)

### 快乐数

[202. 快乐数 - 力扣（Leetcode）](https://leetcode.cn/problems/happy-number/)

```c++
class Solution {
public:
    int getSum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }//通过每次叠加个位数上的和，得到新的sum值
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum=getSum(n);
            if(sum==1){
                return true;
            }
            if(set.find(sum)!=set.end()){
                return false;
            }else
            set.insert(sum);
            n=sum;
        }
    }
};
```

### 两数之和

[1. 两数之和 - 力扣（Leetcode）](https://leetcode.cn/problems/two-sum/)

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            auto iter=map.find(target-nums[i]);
            if(iter!=map.end()){
                return {iter->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};
```

首先我在强调一下 **什么时候使用哈希法**，当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。

再来看一下使用数组和set来做哈希法的局限。

- 数组的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
- set是一个集合，里面放的元素只能是一个key，而两数之和这道题目，不仅要判断y是否存在而且还要记录y的下标位置，因为要返回x 和 y的下标。所以set 也不能用。

| 映射               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::map           | 红黑树   | key有序  | key不可重复      | key不可修改  | O(log n) | O(log n) |
| std::multimap      | 红黑树   | key有序  | key可重复        | key不可修改  | O(log n) | O(log n) |
| std::unordered_map | 哈希表   | key无序  | key不可重复      | key不可修改  | O(1)     | O(1)     |

![过程一](https://code-thinking-1253855093.file.myqcloud.com/pics/20220711202638.png)

![过程二](https://code-thinking-1253855093.file.myqcloud.com/pics/20230220223536.png)

### 四数相加II

[454. 四数相加 II - 力扣（Leetcode）](https://leetcode.cn/problems/4sum-ii/)

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;//key:a+b的数值，val：a+b的次数
        int ans=0;
        //遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                auto iter=map.find(nums1[i]+nums2[j]);
                if(iter!=map.end()){
                    iter->second++;
                }
                map.insert(pair<int,int>{nums1[i]+nums2[j],1});
            }
        }
        for(int k=0;k<nums3.size();k++){
            for(int l=0;l<nums4.size();l++){
                auto iter=map.find(-(nums3[k]+nums4[l]));
                if(iter!=map.end()){
                    ans+=(iter->second);
                }
            }
        }
        return ans;
    }
};
```

### 赎金信

[383. 赎金信 - 力扣（Leetcode）](https://leetcode.cn/problems/ransom-note/)

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(int i=0;i<magazine.size();i++){
            auto iter=map.find(magazine[i]);
            if(iter!=map.end()){
                iter->second++;
            }
            map.insert(pair<char,int>{magazine[i],1});
        }
        for(int j=0;j<ransomNote.size();j++){
            auto iter=map.find(ransomNote[j]);
            if(iter!=map.end()&&(iter->second)>0){
                (iter->second)--;
            }
            else
            return false;
        }
        return true;
    }
};
```

### 三数之和

[15. 三数之和 - 力扣（Leetcode）](https://leetcode.cn/problems/3sum/)

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return ans;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }
                else{
                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
```

**动态思路**：

![15.三数之和](https://code-thinking.cdn.bcebos.com/gifs/15.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.gif)

#### a去重操作

```c++
if (i > 0 && nums[i] == nums[i - 1]) {
    continue;
}
```

这么写就是当前使用 nums[i]，我们判断前一位是不是一样的元素，在看 {-1, -1 ,2} 这组数据，当遍历到 第一个 -1 的时候，只要前一位没有-1，那么 {-1, -1 ,2} 这组数据一样可以收录到 结果集里。

#### b与c去重操作

```c++
while (right > left) {
    if (nums[i] + nums[left] + nums[right] > 0) {
        right--;
        // 去重 right
        while (left < right && nums[right] == nums[right + 1]) right--;
    } else if (nums[i] + nums[left] + nums[right] < 0) {
        left++;
        // 去重 left
        while (left < right && nums[left] == nums[left - 1]) left++;
    } else {
    }
}
```

### 四数之和

[18. 四数之和 - 力扣（Leetcode）](https://leetcode.cn/problems/4sum/)

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target&&target>=0){
                break;
            }
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]+nums[i]>target&&nums[i]+nums[j]>=0){
                    break;
                }
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }
                    else{
                        ans.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        right--;
                        left++;
                    }
                }
                
            }
        }
        return ans;
    }
};
```

**难点在于剪枝操作**

## 字符串

### 反转字符串

[344. 反转字符串 - 力扣（Leetcode）](https://leetcode.cn/problems/reverse-string/)

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0,right=s.size()-1;
        char temp;
        while(right>=left){
            temp=s[right];
            s[right]=s[left];
            s[left]=temp;
            right--;
            left++;
        }
        return;
    }
};
```

### 反转字符串II

[541. 反转字符串 II - 力扣（Leetcode）](https://leetcode.cn/problems/reverse-string-ii/solutions/)

```c++
class Solution {
public:
    void reverse(string&s,int l,int r){
        for(int i=l,j=r;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=(k*2)){
            if(i+k<s.size()){
                reverse(s,i,i+k-1);
            }
            else
            reverse(s,i,s.size()-1);
        }
        return s;
    }  
};
```

### 替换空格

[剑指 Offer 05. 替换空格 - 力扣（Leetcode）](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int count=0;
        int sLenth=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') count+=2;
        }
        s.resize(s.size()+count);
        for(int i=sLenth-1,j=s.size()-1;j>i;i--,j--){
            if(s[i]!=' '){
                s[j]=s[i];
            }
            else{
                s[j]='0';
                s[j-1]='2';
                s[j-2]='%';
                j-=2;
            }
            
        }
        return s;
    }
};
```

**其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**

### 翻转字符串里的单词

[151. 反转字符串中的单词 - 力扣（Leetcode）](https://leetcode.cn/problems/reverse-words-in-a-string/)

```c++
class Solution {
public:
    void removeExtraSpaces(string& s){
        int slow=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                if(slow!=0){
                    s[slow++]=' ';
                }
                while(i<s.size()&&s[i]!=' '){
                    s[slow++]=s[i++];
                }
            }
        }
        s.resize(slow);
    }
    void reverse(int left,int right,string& s){
        for(int i=left,j=right;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(0,s.size()-1,s);
        int start=0;
        for(int i=0;i<=s.size();++i){
            if(i==s.size()||s[i]==' '){
                reverse(start,i-1,s);
                start=i+1;
            }
        }
        return s;
    }
};
```

### 左旋转字符串

[剑指 Offer 58 - II. 左旋转字符串 - 力扣（Leetcode）](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

```c++
class Solution {
public:
    void reverse(int l,int r,string& s){
        for(int i=l,j=r;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseLeftWords(string s, int n) {
        reverse(0,n-1,s);
        reverse(n,s.size()-1,s);
        reverse(0,s.size()-1,s);
        return s;
    }
};
```

![img](https://code-thinking.cdn.bcebos.com/pics/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.png)

### 实现strStr()

[28. 找出字符串中第一个匹配项的下标 - 力扣（Leetcode）](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

```c++
class Solution {
public:
    void getNext(const string& s,int* next){
        next[0]=0;
        int j=0;
        for(int i=1;i<s.size();i++){
            while(j>0&&s[i]!=s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }    
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        int next[needle.size()];
        getNext(needle,next);
        int j=0;
        for(int i=0;i<haystack.size();i++){
            while(j>0&&haystack[i]!=needle[j]){
                j=next[j-1];
            }
            if(needle[j]==haystack[i]){
                j++;
            }
            if(j==needle.size()){
            return (i-needle.size()+1);
            }    
        }
        return -1;
    }
};
```

#### kmp算法

##### 前缀表

**前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。**

![KMP精讲8](https://code-thinking.cdn.bcebos.com/pics/KMP%E7%B2%BE%E8%AE%B28.png)

##### 使用NEXT数组匹配

![KMP精讲4](https://code-thinking.cdn.bcebos.com/gifs/KMP%E7%B2%BE%E8%AE%B24.gif)

### 重复的子字符串

[459. 重复的子字符串 - 力扣（Leetcode）](https://leetcode.cn/problems/repeated-substring-pattern/)

```c++
class Solution {
public:
    void getNext(const string& s,int* next){
        next[0]=0;
        int j=0;
        for(int i=1;i<s.size();i++){
            while(j>0&&s[i]!=s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]) j++;
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0){
            return false;
        }
        int next[s.size()];
        getNext(s,next);
        int len=s.size();
        if(next[len-1]!=0&&len%(len-(next[len-1]))==0){
            return true;
        }
        return false;
    }
};
```

### 总结

字符串是若干字符组成的有限序列，也可以理解为是一个字符数组，但是很多语言对字符串做了特殊的规定，接下来我来说一说C/C++中的字符串。

```c++
string a = "asd";
for (int i = 0; i < a.size(); i++) {
}
```

那么vector< char > 和 string 又有什么区别呢？

其实在基本操作上没有区别，但是 string提供更多的字符串处理的相关接口，例如string 重载了+，而vector却没有。

## 栈与队列 

### 栈与队列的基本理论

<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20210104235459376.png" alt="栈与队列理论3" style="zoom:80%;" />

我们也可以指定vector为栈的底层实现，初始化语句如下：

```c++
std::stack<int, std::vector<int> > third;  // 使用vector为底层容器的栈
```

也可以指定list 为起底层实现，初始化queue的语句如下：

```c++
std::queue<int, std::list<int>> third; // 定义以list为底层容器的队列
```

### 栈 实现队列

[232. 用栈实现队列 - 力扣（Leetcode）](https://leetcode.cn/problems/implement-queue-using-stacks/)

```
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int result=outStack.top();
        outStack.pop();
        return result;
    }
    
    int peek() {
        int res=this->pop();
        outStack.push(res);
        return res;
    }
    bool empty() {
        return inStack.empty()&&outStack.empty();
    }
    private:
    stack<int> inStack;
    stack<int> outStack;
};
```

### 队列实现栈

[225. 用队列实现栈 - 力扣（Leetcode）](https://leetcode.cn/problems/implement-stack-using-queues/)

```c++
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
//使用辅助队列que2；将que1存的值复制到que2到只剩最后一个元素，存储que1的front
//然后将front删除，再将que2的值传给que1，再将que2中的元素全部删除，返回存储值    
    int pop() {
        int size=que1.size();
        size--;
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        int result=que1.front();
        que1.pop();
        que1=que2;
        while(!que2.empty()){
            que2.pop();
        }
        return result;
    }
    
    int top() {
        int ans=this->pop();
        que1.push(ans);
        return ans;
    }
    
    bool empty() {
        return que1.empty();
    }
private: 
    queue<int> que1;
    queue<int> que2;
};
```

### 有效的括号

[20. 有效的括号 - 力扣（Leetcode）](https://leetcode.cn/problems/valid-parentheses/)

```c++
class Solution {
public:
    bool isValid(string s) {
        int count=s.size();
        if(count%2!=0){
            return false;
        }
        map<char,char> m={
            {')','('},
            {']','['},
            {'}','{'},
        };
        stack<char> st;
        for(char ch:s){
            if(m.count(ch)){
               if(st.empty()||m[ch]!=st.top()){
                   return false;
               }
               st.pop();
               }
            else{
                st.push(ch);
                }
        }
        return st.empty();
    }
};
```

<img src="https://code-thinking.cdn.bcebos.com/gifs/20.%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7.gif" alt="20.有效括号" style="zoom:67%;" />

**三种return false的情况**

### 删除字符串中所有相邻重复项 

[1047. 删除字符串中的所有相邻重复项 - 力扣（Leetcode）](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(char ch:s){
            if(res.back()!=ch||res.empty()){
                res.push_back(ch);
            }
            else{
                res.pop_back();
            }
        }
        return res;
    }
};
```

**过程**

<img src="https://code-thinking.cdn.bcebos.com/gifs/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.gif" alt="1047.删除字符串中的所有相邻重复项" style="zoom:50%;" />



### 逆波兰表达式求值

[150. 逆波兰表达式求值 - 力扣（Leetcode）](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
            long long nums1=st.top();st.pop();
            long long nums2=st.top();st.pop();
            if(tokens[i]=="+") st.push(nums1+nums2);
            if(tokens[i]=="-") st.push(nums2-nums1);
            if(tokens[i]=="*") st.push(nums1*nums2);
            if(tokens[i]=="/") st.push(nums2/nums1);
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
        int ans=st.top();
        st.pop();
        return ans;
    }
};
```

**解题**

<img src="https://code-thinking.cdn.bcebos.com/gifs/150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.gif" alt="150.逆波兰表达式求值" style="zoom:50%;" />

### 滑动窗口最大值

[239. 滑动窗口最大值 - 力扣（Leetcode）](https://leetcode.cn/problems/sliding-window-maximum/)

```c++
class Solution {
private:
    class myQue{
    public:
        deque<int> que;
        void pop(int value){//删除操作：将存储的value值给删除
            if(!que.empty()&&value==que.front()){//判断队列是否为空，且当value等于front时就存满就要删除
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty()&&value>que.back()){//当value大于front时即value为最大值；只需要将que清空；                                               //存入value就可以
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQue que;
        vector<int> res;
        for(int i=0;i<k;i++){//将前k个值存入que中
            que.push(nums[i]);
        }
        res.push_back(que.front());//将第一次存入k的比较得到max；存入res
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);//如果第一个数是最大值；当为max值，存满要将从que删除
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }

};
```

### 前 k个高频元素

[347. 前 K 个高频元素 - 力扣（Leetcode）](https://leetcode.cn/problems/top-k-frequent-elements/)

```
class Solution {
public:
    class mcomparison{
        public:
        bool operator()(const pair<int,int>&lhs,const pair<int,int>&rhs){
            return lhs.second>rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;//存取中map中将每个元素出现的值赋给val
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        //对频率开始排序
        //定义一个小顶堆，大小值为k
        priority_queue<pair<int,int>,vector<pair<int,int>>,mcomparison> pri_que;
        for(unordered_map<int,int>::iteratorit=map.begin();it!=map.end();it++){
            pri_que.push(*it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
```

### 总结

1. C++中stack，queue 是容器么？
2. 我们使用的stack，queue是属于那个版本的STL？
3. 我们使用的STL中stack，queue是如何实现的？
4. stack，queue 提供迭代器来遍历空间么？

- 陷阱1：栈是容器适配器，底层容器使用不同的容器，导致栈内数据在内存中是不是连续分布。
- 陷阱2：缺省情况下，默认底层容器是deque，那么deque的在内存中的数据分布是什么样的呢？ 答案是：不连续的，下文也会提到deque。

## 二叉树

### 二叉树理论基础

#### 二叉树的种类

- **满二叉树**

	满二叉树：如果一棵二叉树只有度为0的结点和度为2的结点，并且度为0的结点在同一层上，则这棵二叉树为满二叉树。

	<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20200806185805576.png" alt="img" style="zoom:25%;" />



- **完全二叉树**

	完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^(h-1) 个节点。

	<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20200920221638903.png" alt="img" style="zoom:25%;" />

- **二叉搜素树**

	前面介绍的树，都没有数值的，而二叉搜索树是有数值的了，**二叉搜索树是一个有序树**。

	- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；

	- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；

	- 它的左、右子树也分别为二叉排序树

		<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20200806190304693.png" alt="img" style="zoom:25%;" />

- **平衡二叉搜索树**

	平衡二叉搜索树：又被称为AVL（Adelson-Velsky and Landis）树，且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

	<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20200806190511967.png" alt="img" style="zoom:25%;" />

	**C++中map、set、multimap，multiset的底层实现都是平衡二叉搜索树**，所以map、set的增删操作时间时间复杂度是logn，注意我这里没有说unordered_map、unordered_set，unordered_map、unordered_set底层实现是哈希表。

#### 遍历方式

- 深度优先遍历
	- 前序遍历（递归法，迭代法）
	- 中序遍历（递归法，迭代法）
	- 后序遍历（递归法，迭代法）
- 广度优先遍历
	- 层次遍历（迭代法）

#### 二叉树的定义

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

### 二叉树的递归遍历

**每次写递归，都按照这三要素来写，可以保证大家写出正确的递归算法！**

1. **确定递归函数的参数和返回值：** 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2. **确定终止条件：** 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
3. **确定单层递归的逻辑：** 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。

#### 前序遍历

```c++
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
```

#### 后序遍历

```c++
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
    vec.push_back(cur->val);    // 中
}
```

#### 中序遍历

```c++
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    traversal(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中
    traversal(cur->right, vec); // 右
}
```

### 二叉树的迭代遍历

#### 前序遍历

[144. 二叉树的前序遍历 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

<img src="https://code-thinking.cdn.bcebos.com/gifs/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86%EF%BC%88%E8%BF%AD%E4%BB%A3%E6%B3%95%EF%BC%89.gif" alt="二叉树前序遍历（迭代法）" style="zoom:25%;" />

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root==NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }
};
```

#### 中序遍历

[94. 二叉树的中序遍历 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

<img src="https://code-thinking.cdn.bcebos.com/gifs/%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%EF%BC%88%E8%BF%AD%E4%BB%A3%E6%B3%95%EF%BC%89.gif" alt="二叉树中序遍历（迭代法）" style="zoom:25%;" />

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur!=NULL||!st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                cur=st.top();
                st.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }
};
```

#### 后序遍历

[145. 二叉树的后序遍历 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

<img src="https://code-thinking-1253855093.file.myqcloud.com/pics/20200808200338924.png" alt="前序到后序" style="zoom:25%;" />

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root==NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```

### 二叉树的统一迭代法

#### 中序遍历

<img src="https://code-thinking.cdn.bcebos.com/gifs/%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E8%BF%AD%E4%BB%A3%EF%BC%88%E7%BB%9F%E4%B8%80%E5%86%99%E6%B3%95%EF%BC%89.gif" alt="中序遍历迭代（统一写法）" style="zoom:50%;" />

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur!=NULL||!st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                cur=st.top();
                st.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }
};
```

####  前序遍历

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root==NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }
};
```

#### 后序遍历

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root==NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```

### 二叉树的层序遍历

[102. 二叉树的层序遍历 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

<img src="https://code-thinking.cdn.bcebos.com/gifs/102%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.gif" alt="102二叉树的层序遍历" style="zoom:33%;" />

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> vec;
            while(size--){
                TreeNode* node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left!=NULL) que.push(node->left);
                if(node->right!=NULL) que.push(node->right);
            }
            res.push_back(vec);
        }
            
        return res;
    }
};
```

### 翻转二叉树

[226. 翻转二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/invert-binary-tree/submissions/)

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

### 对称二叉树

[101. 对称二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/symmetric-tree/)

```c++
class Solution {
public:
    bool compare(TreeNode*left,TreeNode* right){
        if(right==NULL&&left!=NULL) return false;//首先排除空节点的情况 
        else if(right!=NULL&&left==NULL) return false;
        else if(left==NULL&&right==NULL) return true;
        else if(right->val!=left->val) return false;//排除了空节点 ，在排除数值不同的情况 
        //此时就是，左右节点都不为空，且数值相同的情况
        //此时才做递归，做下一层的判断
        bool comp1=compare(left->left,right->right);
        bool comp2=compare(left->right,right->left);
        bool ans=comp1&&comp2;
        return ans;
    };
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=compare(root->left,root->right);
        return ans;
    }
};
```

### 二叉树最大的深度

[104. 二叉树的最大深度 - 力扣（Leetcode）](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

```c++
class Solution {
public:
    int getDepth(TreeNode* node){
        if(node==NULL) return 0;
        int leftDepth=getDepth(node->left);
        int rightDepth=getDepth(node->right);
        int depth=1+max(leftDepth,rightDepth);
        return depth;
    };
    int maxDepth(TreeNode* root) {
        int res=0;
        if(root==NULL) return res;
        res=getDepth(root);
        return res;
    }
};
```

本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。

- 二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
- 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数后者节点数（取决于高度从0开始还是从1开始）

### 二叉树的最小深度

[111. 二叉树的最小深度 - 力扣（Leetcode）](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

```c++
class Solution {
public:
    int getDepth(TreeNode* node){
        if(node==0) return 0;
        int leftHight=getDepth(node->left);
        int rightHight=getDepth(node->right);
        if(node->left==NULL&&node->right!=NULL){
            return 1+rightHight;
        }
        if(node->left!=NULL&&node->right==NULL){
            return 1+leftHight;
        }
        int res=1+min(leftHight,rightHight);
        return res;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
```

### 完全二叉树的节点个数

[222. 完全二叉树的节点个数 - 力扣（Leetcode）](https://leetcode.cn/problems/count-complete-tree-nodes/)

```c++
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int countLeft=countNodes(root->left);
        int countRight=countNodes(root->right);
        // if(root->left==NULL&&root->right!=NULL){
        //     countRight++;
        // }
        // if(root->left!=NULL&&root->right==NULL){
        //     countLeft++;
        // }
        // if(root->left!=NULL&&root->right!=NULL){
        //     countLeft++;
        //     countRight++;
        // }
        // if(root->left==NULL&&root->right==NULL){

        // }
        return countLeft+countRight+1;
            
    }
};
```

### 平衡二叉树

[110. 平衡二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/balanced-binary-tree/)

```c++
class Solution {
public:
    // 只需要判断左右节点的差值大于1；
    // 递归遍历只需出现差值大于1就返回-1
    int getDepth(TreeNode* node){  //确定返回值和传入值
        if(node==NULL) return 0;  // 确定终止条件
        int leftHight=getDepth(node->left);
        if(leftHight==-1) return -1;
        int rightHight=getDepth(node->right);
        if(rightHight==-1) return -1;
        int res;
        if(abs(leftHight-rightHight)>1){
            res=-1;
        }else{
            res=1+max(leftHight,rightHight);
        }
        return res;
    }
    bool isBalanced(TreeNode* root) {
        if(getDepth(root)==-1) return false;
        else return true;
    }
};
```

### 二叉树的所有路径

[257. 二叉树的所有路径 - 力扣（Leetcode）](https://leetcode.cn/problems/binary-tree-paths/)

```c++
class Solution {
private:
    void traversal(TreeNode* node,vector<int>& path,vector<string>& res){
        path.push_back(node->val);//最后一个节点也要加入path中
        if(node->left==NULL&&node->right==NULL){//当node的左右子节点都为空时，遍历到叶子节点
            string sPath;
            for(int i=0;i<path.size()-1;i++){   //当sPath到达到最后一个，不能有箭头；
                sPath+=to_string(path[i]);
                sPath+="->";
            }
            sPath+=to_string(path[path.size()-1]);
            res.push_back(sPath);
            return;
        }
        if(node->left){//左节点遍历
            traversal(node->left,path,res);
            path.pop_back();//回溯
        }
        if(node->right){//右节点遍历
            traversal(node->right,path,res);
            path.pop_back();//回溯
        }
    };    
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if(root==NULL) return res;
        traversal(root,path,res);
        return res;
    }
};
```

### 左叶子之和

[404. 左叶子之和 - 力扣（Leetcode）](https://leetcode.cn/problems/sum-of-left-leaves/submissions/)

```c++
class Solution {
public:
        //只能通过前一个节点来遍历他的left节点的值并存储。
    int sumOfLeftLeaves(TreeNode* root) {
        //终止条件：到达空节点，到达了叶子节点。
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 0;
        //后序遍历
        int leftNum=sumOfLeftLeaves(root->left);//左
        if(root->left!=NULL&&root->left->left==NULL&&root->left->right==NULL) leftNum=root->left->val;
        int rightNum=sumOfLeftLeaves(root->right);
        //只需要右边的结果，返回左边的值就可以
        int sum = leftNum+rightNum;//中
        return sum;
    }
};
```



### 找树左下角的值

[513. 找树左下角的值 - 力扣（Leetcode）](https://leetcode.cn/problems/find-bottom-left-tree-value/submissions/)

```c++
class Solution {
public:
        int maxDepth= INT_MIN;
        int res;
        //确定返回值和参数。需要节点和深度
        void traversal(TreeNode* node,int depth){
            //确定终止条件，
            if(node->left==NULL&&node->right==NULL){
               if(depth>maxDepth){//当depth必须要大于maxDepth，此时才是第一个访问这个
                   //二叉树的第一个节点并记录res值.只处理最左值
                   maxDepth=depth;
                   res=node->val;
               }
               return;
            }
            //左,判断左子树是不是空
            if(node->left) {
                depth++;//不是空，深度+1
                traversal(node->left,depth);
                depth--;//回溯：当深度返回上一级的时候，需要减一
                //以上三行代码简化：traversal(node->left,depth+1);
                //当使用depth+1；depth的值并没有发生改变；当返回上一级的时候。有个隐藏回退的过程
            }
            if(node->right){
                depth++;
                traversal(node->right,depth);
                depth--;
            }
            return;
        }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return res;
    }
};
```

### 路径总和

[112. 路径总和 - 力扣（Leetcode）](https://leetcode.cn/problems/path-sum/)

```c++
class Solution {
public:
    bool traversal(TreeNode* node,int count){
        //终止条件：到达叶子节点，判断count的值
        if(node->left==NULL&&node->right==NULL&&count==0){
            return true;
        }
        if(node->left==NULL&&node->right==NULL&&count!=0){
            return false;
        }
        if(node->left){
            count-=node->left->val;//减去node->left的val
            if(traversal(node->left,count)) return true;//将结果传到上一级
            count+=node->left->val;//回溯
        }
        if(node->right){
            count-=node->right->val;
            if(traversal(node->right,count)) return true;
            count+=node->right->val;//回溯
        }
        return false;//如果都没有返回false
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return traversal(root,targetSum-root->val);//减去root->val;
    }
};
```

### 从中序和后序遍历序列构造二叉树

[106. 从中序与后序遍历序列构造二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

```c++
class Solution {
public:
    TreeNode* traversal(vector<int>&inorder,vector<int>& postorder){
        //终止条件：两种情况；如果空节点，或者到达叶子节点
        if(postorder.size()==0) return NULL;
        int rootValue = postorder[postorder.size()-1];
        //到达叶子节点返回值
        TreeNode* root = new TreeNode(rootValue);
        if(postorder.size()==1) return root;
        //设定index值；寻找二叉树的切割点
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==rootValue) break;
        }
        //开始切割inorder数组
        //inorder的left的作为根的左边，重新作为一个数组；左闭右开区间
        vector<int>leftInorder(inorder.begin(),inorder.begin()+index);
        //inorder的right作为root的right，重新作为一个数组；左闭右开区间
        vector<int>rightInorder(inorder.begin()+index+1,inorder.end());
        //切割postorder数组
            //因为每次分割一个数组把index值已经存储到root值，所以分割完把index去除
        postorder.resize(postorder.size()-1);
        //postorder的左右区间的数量一定是和的inorder切割的左右区间是一样大的，左闭右开区间
        vector<int>leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int>rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());
        //左右递归
        root->left=traversal(leftInorder,leftPostorder);
        root->right=traversal(rightInorder,rightPostorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.size()==0||postorder.size()==0) return NULL;
            return traversal(inorder,postorder);
    }
};
```

### 最大二叉树

[654. 最大二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/maximum-binary-tree/)

```c++
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //确定终止条件
        TreeNode* node=new TreeNode(0);
        if(nums.size()==1){
            node->val=nums[0];
            return node;
        }
        int maxValue=0;
        int maxValueIndex=0;
        for(int i=0;i<nums.size();i++){
            if(maxValue<nums[i]){
                maxValue=nums[i];
                maxValueIndex=i;
            }
        }
        node->val=maxValue;
        if(maxValueIndex>0){
            vector<int> newVec(nums.begin(),nums.begin()+maxValueIndex);
            node->left=constructMaximumBinaryTree(newVec);

        }
        if(maxValueIndex<nums.size()-1){
            vector<int> newVec(nums.begin()+maxValueIndex+1,nums.end());
            node->right=constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};
```

### 合并二叉树

[617. 合并二叉树 - 力扣（Leetcode）](https://leetcode.cn/problems/merge-two-binary-trees/)

```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //重构一般使用前序遍历
        //终止条件
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        //中
        root1->val+=root2->val;
        //左
        root1->left=mergeTrees(root1->left,root2->left);
        //右
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};
```

### 二叉搜索树中的搜索

[700. 二叉搜索树中的搜索 - 力扣（Leetcode）](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //终止条件；root为空，搜索到val值
        if(root==NULL||root->val==val) return root;
        TreeNode* res=NULL;
        if(root->val>val) res=searchBST(root->left,val);
        if(root->val<val) res=searchBST(root->right,val);
        return res;
    }
};
```

### 验证二叉搜索树

[98. 验证二叉搜索树 - 力扣（Leetcode）](https://leetcode.cn/problems/validate-binary-search-tree/)

```c++
class Solution {
public:
    TreeNode* pre=NULL;
    bool isValidBST(TreeNode* root) {
        //终止条件：root为NULL
        if(root==NULL) return true;
        //左
        bool left=isValidBST(root->left);
        //中，比较前一个值和后一个值
        if(pre!=NULL&&pre->val>=root->val)
        return false;
        pre=root;
        bool right=isValidBST(root->right);
        return left&&right;
    }
};
```

### 二叉搜索树的最小绝对差

[530. 二叉搜索树的最小绝对差 - 力扣（Leetcode）](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

````c++
class Solution {
public:
    int res=INT_MAX;
    TreeNode* pre=NULL;
    void traversal(TreeNode* cur){
        //终止条件
        if(cur==NULL) return;
        traversal(cur->left);//左
        // 中
        if(pre!=NULL){
            res=min(res,cur->val-pre->val);
        }
        pre=cur;//pre记录前一个值，中序遍历的先访问左边；第一次遍历直接到最左节点；pre==NULL，
        // 不执行if语句，记录pre等于cur；cur回退。比较cur和pre的值
        traversal(cur->right);//右
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
````

### 二叉搜索树中的众数

[501. 二叉搜索树中的众数 - 力扣（Leetcode）](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)

```c++
class Solution {
public:
//定义全局变量:双指针法，当pre=cur时，记录count。
// 当在二叉搜索树中一般使用中序遍历
    TreeNode* pre=NULL;int count=0,maxCount=0;vector<int> res;
    void traversal(TreeNode* cur){
        //终止条件
        if(cur==NULL) return;
        //左
        traversal(cur->left);
        //中
        if(pre==NULL) count=1;//当cur到达叶子节点时；第一次计数，将count=1
        else if(pre->val==cur->val) count++;//当pre的值和cur的值相等时；需要将count++
        else count=1;//当值不相等时，就是到了一个新的数；只需要将count=1；重新开始计数
        pre=cur;//pre记录前一个节点
        if(count==maxCount){
            res.push_back(cur->val);//当count的值和maxCount值相等；将当前值传入res数组
        }
        if(count>maxCount){
            res.clear();//当存入的count大于maxCount，将结果数组清空；并将新的结果传入。
            res.push_back(cur->val);
            maxCount=count;//更新maxCount值
        }
        //右
        traversal(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};
```

### 二叉树的最近公共祖先

[236. 二叉树的最近公共祖先 - 力扣（Leetcode）](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

```c++
class Solution {
public:
    //一层层将结果传入上一级。只需要比较左右子树的结果。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //后序遍历
        //终止条件
        if(root==p||root==q||root==NULL) return root;
        //左
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        //右
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //中
        if(right!=NULL&&left!=NULL) return root;//同时寻找到两个值直接返回它的上一级root，就是它的公共祖先
        if(left!=NULL&&right==NULL) return left;//当右边的全都是NULL；左边寻找到值只需传到上一层这个值
        if(left==NULL&&right!=NULL) return right;//上面相同的结果
        else{
            return NULL;
        }
    }
};
```

### 二叉树的最近公共祖先

[236. 二叉树的最近公共祖先 - 力扣（Leetcode）](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

```c++
class Solution {
public:
    //一层层将结果传入上一级。只需要比较左右子树的结果。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //后序遍历
        //终止条件
        if(root==p||root==q||root==NULL) return root;
        //左
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        //右
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //中
        if(right!=NULL&&left!=NULL) return root;//同时寻找到两个值直接返回它的上一级root，就是它的公共祖先
        if(left!=NULL&&right==NULL) return left;//当右边的全都是NULL；左边寻找到值只需传到上一层这个值
        if(left==NULL&&right!=NULL) return right;//上面相同的结果
        else{
            return NULL;
        }
    }
};
```

### 二叉搜索树的最近公共祖先

[LeetCode链接](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

```c++
// 当cur的值大于p和q的值，向左遍历；当cur的值小于p和q的值，向右遍历；当值介于pq之间一定是最近祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;//终止条件
        if(root->val>p->val&&root->val>q->val){
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            if(left!=NULL) return left;
        }
        if(root->val<p->val&&root->val<q->val){
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(right!=NULL) return right;
        }
        return root;
    }
```

### 二叉搜索树中的插入操作

[题目链接](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)

```c++
//直接在叶子节点操作就合法
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* node=new TreeNode(val);
            return node;
        }//终止条件:当遍历到空节点时，直接将空节点new的新的节点并返回给上一层
        if(val<root->val){
            root->left=insertIntoBST(root->left,val);
        }
        if(val>root->val){
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
```

### 删除二叉搜索树中的节点

[题目链接](https://leetcode.cn/problems/delete-node-in-a-bst/)

```c++
 TreeNode* deleteNode(TreeNode* root, int key) {
        //终止条件：当节点是NULL或root->val==key
        if(root==NULL) return NULL;
        if(root->val==key){
            //四种情况：左右为空，左空右不空，左不空右空，左右都不空
            if(root->left==NULL&&root->right==NULL){
                return NULL;//将null返回给root
            }
            if(root->left!=NULL&&root->right==NULL){
                return root->left;//将root->left返回给root，就是将root删除
            }
            if(root->left==NULL&&root->right!=NULL){
                return root->right;//同理将root->right返回给root
            }
            else{
                //当左右都不是空时，就是将它的任一子节点替代它
                //当右节点替代时，就是将原来的左子树，接到后来的最左节点
                TreeNode* cur=root->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                TreeNode* tmp=root;//将root节点存入，便于后续删除
                cur->left=root->left;
                root=root->right;
                delete tmp;
                return root;
            }
        }
        if(key<root->val) root->left=deleteNode(root->left,key);
        if(key>root->val) root->right=deleteNode(root->right,key);
        return root;
    }
```

### 修剪二叉搜索树

[题目链接](https://leetcode.cn/problems/trim-a-binary-search-tree/)

```c++
TreeNode* trimBST(TreeNode* root, int low, int high) {
        //终止条件
        if(root==NULL) return NULL;
        if(root->val<low){
            TreeNode* right=trimBST(root->right,low,high);
            //root的val小于low，但他的右边可能大于low，贼需要递归处理,删除完了。return 结果
            return right;
        }
        if(root->val>high){
            TreeNode* left=trimBST(root->left,low,high);
            return left;//
        }
        root->left=trimBST(root->left,low,high);//左
        root->right=trimBST(root->right,low,high);//右
        return root;
    }
```

### 将有序数组转换为二叉搜索树

[题目链接](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

```c++
 TreeNode* traversal(vector<int>&nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid=(left+right)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=traversal(nums,left,mid-1);
        root->right=traversal(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums,0,nums.size()-1);
    }
```

### 把二叉搜索树转换为累加树

[题目链接](https://leetcode.cn/problems/convert-bst-to-greater-tree/)

```c++
//二叉搜索树的左中右是升序遍历，右中左是降序遍历
    int pre=0;//使用pre初始加上第一个访问的叶子结点
    void traversal(TreeNode* cur){
        if(cur==NULL) return;
        traversal(cur->right);
        cur->val+=pre;//将累加值加上现在val，并赋给val
        pre=cur->val;//使用pre记录前一个值
        traversal(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
       pre=0;
       traversal(root);
       return root;
    }
```

## 回溯

### 组合

[题目链接](https://leetcode.cn/problems/combinations/)

```c++
//回溯三部曲：1.递归函数参数和返回值
// 确定终止条件
// 单层递归的逻辑
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int n,int k,int startIndex){
        //终止条件
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        //单层递归的逻辑,i不能等于n，最后一个节点没有值与其匹配
        for(int i=startIndex;i<=n-(k-path.size())+1;i++){
            path.push_back(i);//处理节点，将值传入path中
            backtracking(n,k,i+1);//递归
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }
```

### 组合总和III

[题目链接](https://leetcode.cn/problems/combination-sum-iii/)

```c++
//定义全局路径，结果
//确定返回值，函数参数
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int k,int n,int sum,int startIndex){
        //终止条件：当path.size大小和k相等并且sum等于目标值
        if(sum>n){
            return;//剪枝，当sum大于我们求的k时，就能直接return，可以在处理阶段就直接剪枝
        }
        if(path.size()==k&&sum==n){
            res.push_back(path);
            return;
        }
        for(int i=startIndex;i<=9;i++){
            sum+=i;//累加求得sum值
            path.push_back(i);//将此时的值放入结果数组
            backtracking(k,n,sum,i+1);//递归
            sum-=i;//回溯
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,0,1);
        return res;
    }
```

### 电话号码的字母组合

[题目链接](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

```c++
private:
const string letterMap[10]{
    "",//0
    "",//1
    "abc",//2
    "def",//3
    "ghi",//4
    "jkl",//5
    "mno",//6
    "pqrs",//7
    "tuv",//8
    "wxyz",//9
};
public:
    string path;//存入一条路径
    vector<string> res;//存入结果
    void backtracking(string& digits,int index){
        //终止条件:将digits里的数遍历完
        if(index==digits.size()){
            res.push_back(path);
            return;//将一层的path，存入res中
        }
        int digit=digits[index]-'0';//将digits里string数字减去0，得到int数值
        string letter=letterMap[digit];//将定义一个string数组来接收所按数字的所有字母
        for(int i=0;i<letter.size();i++){
            path.push_back(letter[i]);
            backtracking(digits,index+1);//递归
            path.pop_back();//回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return res;
        }
        backtracking(digits,0);
        return res;
    }
```

### 组合总和

[题目链接](https://leetcode.cn/problems/combination-sum/)

```c++
vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex){
        //终止条件
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);//递归
            sum-=candidates[i];//回溯
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return res;
    }
```

### 组合总和II

[题目链接](https://leetcode.cn/problems/combination-sum-ii/)

```c++
 vector<vector<int>> res;
    vector<int> path;
    void combinationSum2_backtracking(vector<int>& nums, int sum, int targetSum, int startIndex, vector<bool>& used) {
        //终止条件
        if (sum == targetSum) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex;i < nums.size()&&sum+nums[i]<=targetSum;i++) {
            //去重的逻辑：对数组进行排序；当左右元素相同时；收集的结果一定是相同的，
            //防止有溢出，当前一个也是用过的元素；你的下一个元素虽然可能相同；但也是需要的，不能直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += nums[i];
            used[i] = true;
            path.push_back(nums[i]);
            combinationSum2_backtracking(nums, sum, targetSum, i + 1, used);//递归
            path.pop_back();//回溯
            sum -= nums[i];
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        combinationSum2_backtracking(candidates, 0, target, 0, used);
        return res;
    }
```

### 分割回文串

[题目链接](https://leetcode.cn/problems/palindrome-partitioning/)

```c++
vector<vector<string>> res;
    vector<string> path;
     bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end;i < j;i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void partition_backtracking(string& s,int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }//终止条件
        for (int i = startIndex;i < s.size();i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);//从startIndex开始；后面截取的str数量
                path.push_back(str);
            }else{
                continue;
            }//不是回文直接跳过
            partition_backtracking(s, i + 1);//递归，寻找i+1为起始位置的子串
            path.pop_back();//回溯
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        partition_backtracking(s, 0);
        return res;
    }
```

### 复原IP地址

[题目链接](https://leetcode.cn/problems/restore-ip-addresses/)

```c++
vector<string> res;
    bool isVaild(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (start != end && s[start] == '0') {//首字母为0；不合法
            return false;
        }
        int num = 0;
        for (int i = start;i <= end;i++) {
            if (s[i] > '9' || s[i] < '0') {//ascII码值大于9或者小于0；不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');//num大于255,不合法
            if (num > 255) {
                return false;
            }
        }
        return true;  
    }
    void restoreIpAddress_backtracking(string& s, int startIndex,int pointSum) {
        //确定终止条件
        if (pointSum == 3) {
            if (isVaild(s, startIndex, s.size() - 1)) {
                res.push_back(s);
                cout << s;
                cout << endl;
            }
            return;
        }
        //单层搜索逻辑
        for (int i = startIndex;i < s.size();i++) {
            if (isVaild(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointSum++;
                restoreIpAddress_backtracking(s, i + 2, pointSum);
                pointSum--;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
           
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        restoreIpAddress_backtracking(s, 0, 0);
        return res;
    }
```

### 子集

[题目链接](https://leetcode.cn/problems/subsets/)

```c++
vector<vector<int>> res;
    vector<int> path;
    void subsets_backtracking(vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex;i < nums.size();i++) {
            path.push_back(nums[i]);
            cout << nums[i] << " ";
            subsets_backtracking(nums, i + 1);
            cout << endl;
            path.pop_back();
        }
    }
    // 子集问题，每次递归开始就要收取结果；并不是到叶子节点去得到结果
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        subsets_backtracking(nums, 0);
        return res;
    }
```

### 子集II

[题目链接](https://leetcode.cn/problems/subsets-ii/)

```c++
vector<int>path;
    vector<vector<int>>res;
    void subsetWithDup_backtracking(vector<int>& nums, int startIndex,vector<bool> used) {
        res.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex;i < nums.size();i++) {
            //排序去重 ；保证不出现负数；i>0
            //前一个数字和本轮数字相同；并且没有用过直接跳过  
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            subsetWithDup_backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        vector < bool>used(nums.size(), false);
        sort(nums.begin(), nums.end());
        subsetWithDup_backtracking(nums, 0, used);
        return res;
    }
```

### 递增子序列

[题目链接](https://leetcode.cn/problems/non-decreasing-subsequences/)

```c++
 vector<int>path;
    vector<vector<int>>res;
    void backtracking_findSubsequences(vector<int>& nums, int startIndex) {
        //终止条件
        if (path.size() > 1) {
            res.push_back(path);
        }
        unordered_set<int>  uset;//将得到的数存入
        for (int i = startIndex;i < nums.size();i++) {
            if ((!path.empty() && path.back() > nums[i]) || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);//插入nums[i]
            path.push_back(nums[i]);
            backtracking_findSubsequences(nums, i + 1);
            //单层的unordered_set;此处的set容器不需要存入
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking_findSubsequences(nums, 0);
        return res;
    }
```

### 全排列

[题目链接](https://leetcode.cn/problems/permutations/)

```c++
 vector<int>path;
    vector<vector<int>> res;
    //全排列不需要考虑子集；顺序不同也要收集；所以不需要startIndex来控制顺序
    void backtracking_premute(vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
        }//终止条件
        //只需要用used数组；记录这个数是否用过就可以
        for (int i = 0;i < nums.size();i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking_premute(nums, used);//递归
            used[i] = false;//回溯
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        backtracking_premute(nums, used);
        return  res;
    }
```

### 全排列II

[题目链接](https://leetcode.cn/problems/permutations-ii/)

```c++
vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size()==used.size()){
            res.push_back(path);
            return;
        }//终止条件；当path将所有数都收集时直接得到所有的路径结果
        for(int i=0;i<nums.size();i++){
            //去重操作
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            //保证你用的重复数字是否被用过需要判断used[i]的值
            if(used[i]==false){
                path.push_back(nums[i]);
                used[i]=true;
                backtracking(nums,used);//递归
                path.pop_back();
                used[i]=false;//回溯
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(),nums.end());//对数组进行排序；为后续去重
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return res;
    }
```

### N皇后

[51.N皇后](https://leetcode.cn/problems/n-queens/)

```c++
//51 N皇后
    vector<vector<string>> res;
    //每次检查只需要检查上边层数的有没有Q就可以
    //因为每次深搜都是从下一行开始进行搜索
    bool isValid(vector<string>& chessboard, int row, int col,int n) {
        //每次插值都是从row+1开始；不需要检查行
        for (int i = 0;i < row;i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        //检查左上对角线有没Q
        for (int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        //检查右上角对角线有没有Q
        for (int i = row - 1, j = col + 1;i >= 0 && j < n;i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtracking_solveNQueens(vector<string>& chesssboard, int row, int n) {
        //终止条件：当row到了最后的结果 
        if (row == n) {
            res.push_back(chesssboard);
            return;
        }
        for (int col = 0;col < n;col++) {
            if (isValid(chesssboard,row,col,n)) {
                chesssboard[row][col] = 'Q';
                backtracking_solveNQueens(chesssboard, row + 1, n);
                chesssboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //定义一个n x n的'.'的棋盘
        res.clear();
        vector<string> chessboard(n,string(n, '.'));
        backtracking_solveNQueens(chessboard, 0, n);
        return  res;
    }
```

### 解数独

[题目链接](https://leetcode.cn/problems/sudoku-solver/)

```c++
//解决二维数组；使用二维回溯
    bool isValid(int  i, int j,const vector<vector<char>>& board,char k) {
        for (int row = 0;row < 9;row++) {//列判重
            if (board[row][j]==k) {
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
```

## 贪心

### 分发饼干

[题目链接 ](https://leetcode.cn/problems/assign-cookies/)

```c++
//使用最小的饼干给最小的胃口的小孩的局部最优解
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;//小孩的位置
        for (int i = 0;i < s.size();i++) {//遍历饼干的位置
            //如果index大于小孩的数量就退出index处理，并且饼干大于等于胃口
            if (index<g.size()&&g[index] <=s[i]) {
                index++;
            }
        }
        return index;
    }
```

### 摆动序列

[题目链接](https://leetcode.cn/problems/wiggle-subsequence/)

```c++
int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int preDiff = 0;//前一对差值
        int curDiff = 0;//当前差值 
        int res = 1;//默认前面有一个差值
        for (int i = 0;i < nums.size()-1;i++) {
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
```

###  最大子序和

[题目链接](https://leetcode.cn/problems/maximum-subarray/)

```c++
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
```

###  买股票的最佳时机II

[题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

```c++
int maxProfit(vector<int>& prices) {
        //多次购买股票可以通；一直累加正数得到最大利润
        int res = 0;
        for (int i = 1;i < prices.size();i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
```

### 跳跃游戏 

[题目 链接](https://leetcode.cn/problems/jump-game/)

```c++
bool canJump(vector<int>& nums) {
        //遍历数组只需要判断当前cover能不能到达末位
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0;i <=cover;i++) {//当前遍历到最大cover值；也就是能到达最大位置
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) {//当cover大于nums.size()-1;返回true
                return true;
            }
        }
        return false;
    }
```

### 跳跃游戏II

[题目链接](https://leetcode.cn/problems/jump-game-ii/)

```c++
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
```

### k次取反后最大化的数组和

[题目链接](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

```c++
static bool  myCompare(int a, int b) {
         return abs(a) > abs(b);
     }//将数组按绝对值从大到小进行排序
     int largestSumAfterKNegations(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end(),myCompare);
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
```

### 加油站

[题目链接](https://leetcode.cn/problems/gas-station/)

```c++
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
```

### 分发糖果

[题目链接](https://leetcode.cn/problems/candy/)

```c++
int candy(vector<int>& ratings) {
         //分别从两边开始遍历；判断存储的candy
         vector<int>  candies(ratings.size(), 1);//定义数组；因为每个小孩至少获得一个
         //从左向右遍历；如果左边小于右边；则需要右边增加一个
         for (int i = 1;i < ratings.size();i++) {
             if (ratings[i] > ratings[i - 1]) {
                 candies[i] = candies[i-1] + 1;
             }
         }
         //从右向左进行遍历；比较两边值；如果大于左边则比较当前值+1；和他的此时的最大值
         for (int j = ratings.size() - 2;j >= 0;j--) {
             if (ratings[j] > ratings[j + 1]) {
                 candies[j] = max(candies[j], candies[j + 1] + 1);//防止出现没有顾及前一种情况；要取最大值
             }
         }
         int res = 0;
         for (int cand: candies) res += cand;
         return res;
     }
```

### 柠檬水找零

[题目链接](https://leetcode.cn/problems/lemonade-change/)

```c++
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
```

### 根据身高重建队列

[题目链接](https://leetcode.cn/problems/queue-reconstruction-by-height/)

```c++
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
         return  vector<vector<int>>(que.begin(),que.end());
     }
```

### 用最少数量的 箭引爆气球

[题目链接](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

```c++
static bool comp1(const vector<int>&a,const vector<int>& b) {
         return a[0] < b[0];
     }
     int findMinArrowShots(vector<vector<int>>& points) {
         if (points.size() == 0) return 0;
         sort(points.begin(), points.end(), comp1);//将数组按第一个数排列
         int res = 1;//size大于0；至少需要一支箭
         for (int i = 1;i < points.size();i++) {
             if (points[i-1][1] < points[i][0]) {//当前一个气球的右边界小于后一个气球左边界
                 res++;//弓箭需要增加
             }
             else {//当重叠的时候；只需要将前一个气球和当前的比较右边界；谁短取哪个右边界；重新给这个区间定义
                 points[i][1] = min(points[i-1][1], points[i][1]);
             }
         }
         return res;
     }
```

### 无重叠区间

[题目链接](https://leetcode.cn/problems/non-overlapping-intervals/)

```c++
static bool comp1(const vector<int>&a,const vector<int>& b) {
         return a[0] < b[0];
     }
     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         // 对数组左边界进行排序
         if (intervals.size() == 0) return 0;
         sort(intervals.begin(), intervals.end(),comp1);
         int count = 0;
         for (int i = 1;i < intervals.size();i++) {
             if (intervals[i][0] < intervals[i - 1][1]) {//当区间重叠
                 intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);//更新最小右边界和下一个是否重叠；来进行比较
                 count++;//需要移除的区间加一
             }
         }
         return count;
     }
```

### 划分字母区间

[题目链接](https://leetcode.cn/problems/partition-labels/)

```c++
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
                 res.push_back(right - left+1);//收集结果集
                 left = i + 1;//left更新成下一个
             }
         }
         return res;
     }
```

### 合并区间

[题目链接](https://leetcode.cn/problems/merge-intervals/)

```c++
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
     }c
```

### 单调递增的数字 

[题目链接](https://leetcode.cn/problems/monotone-increasing-digits/)

```c++
int monotoneIncreasingDigits(int n) {
         string str = to_string(n);//将int数转换成string类型
         int flag = str.size();//定义一个数组记录最后需要变成9的序列
         for (int i = str.size()-1;i > 0;i--) {//从后向前遍历；向后遍历不会对前面值得修改影响后面的结果
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
```



# ACM模式测试案例输入

## 数组

```c++

```

