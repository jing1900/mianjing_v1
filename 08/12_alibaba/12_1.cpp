/*
问题：有8只球队，采用抽签的方式随机配对，组成4场比赛。假设其中有3只强队，那么出现强强对话（任意两只强队相遇）的概率为多少 （概率）

分析：
 基本事件总数：7×5×3×1,
 没有强强联合的概率数为 从5个弱选三个配对，剩下的两弱一队，可能数为c(5,3)*A(3,3) = 60

 那么强强相遇= 105-60
*/