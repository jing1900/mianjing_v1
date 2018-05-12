/*
	树 5_2.cpp
	问题1 树的高度（最大深度）leetcode104
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

	问题2 二叉树对称判断
	leetcode101
https://leetcode.com/problems/symmetric-tree/description/

	问题3 二叉树平衡判断
	a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.），leetcode110
https://leetcode.com/problems/balanced-binary-tree/description/

	问题4 二叉树的最小深度
	（从根到叶子最小经过的节点数）(Leetcode  111) 注意空子树
https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

	问题5 指定和的路径
	(Leetcode 124) 二叉树每个节点有一个整数，返回和最大的路径。
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

分析：这个最大路径有三种可能：
    左子树延伸下去的最大路径，右子树延伸下去的最大路径，和通过根节点的路径

	问题6 二叉树双向链表转换 5-3.cpp

	问题7 前中后序遍历 5-1.cpp

	问题8 给定一个树（无向无环图），求距离最远的两个点(定是叶子节点）（树的直径）
	○ 简单、巧妙地贪心
		• 以任意一点为根，找到距离它最远的节点x（dfs一次）
		• 以x为根找到距离x最远的点y（再dfs一次）
		• (x,y)就是一条直径
	○ 如何找最远的点？ dfs求深度


*/