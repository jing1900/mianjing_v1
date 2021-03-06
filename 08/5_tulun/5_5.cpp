/*
问题：	给定矩形棋盘，再给你若干个位置(x,y)，你可以从任何给定的位置出发，只能在给定位置之间移动。
每次移动只能是沿着水平和竖直方向走，并且这次走的方向和上次不同（交错方向），每个位置只能经过一次，是否可行？ （直角遍历棋盘）

分析：我们把所有节点的x放在一起X，所有y放在一起Y。每走一步，要么从X跳到Y，要么从Y跳到X。（水平跳，变y，垂直跳，变x

这样就变成一个欧拉路的问题，即一笔画问题，参考ppt里面的图。每个节点能经过n次，但每条边只能走一遍

思考题： 一个密码锁，密码是4位数字，操作是
（1） 扔掉高位数字
（2） 把低位数字移动到高位
（3） 添加任意低位数字
即abcd变为bcd(前挪)e(新加）,问从任意数字开始，是否可以经过0000-9999仅一次？
提示：
    节点：任何3位数字从"000"到"999"
    边：  后两位等于前两位 a bc->bc d 相当于一条边 代表abcd的组合



*/