/*
问题：述有一大批数据，百万级别的。数据项内容是：用户ID、科目ABC各自的成绩。其中用户ID为0~1000万之间，且是连续的，
可以唯一标识一条记录。科目ABC成绩均在0~100之间。有两块磁盘，空间大小均为512M，内存空间64M。

 1). 为实现快速查询某用户ID对应的各科成绩，问磁盘文件及内存该如何组织；
 2). 改变题目条件，ID为0~10亿之间，且不连续。问磁盘文件及内存该如何组织；
 3). 在问题2的基础上，增加一个需求。在查询各科成绩的同时，获取该用户的排名，问磁盘文件及内存该如何组织。 （实际系统）


分析： 开放问题
1) ID连续，可以用数组存
	如果不从0开始，可以减一个偏移量, 相当于存3000000个int (3M)（因为虽然id在0-1000万，但只有百万数据），
	需要空间大概12M, 内存够用
2） ID不连续，且id范围为0-10亿，需要map或者hash, 并且需要对ID取余做映射放入hash表。空间复杂度大概12M（id本身所需空间）  + hash的键的空间，
    按内存要求，至少可以有12000000个(4倍)key（48M），这样一共耗费60M。相当于将0-10亿id映射到0-12000000个int之间。
3） 需要对100万的数据作排序
	取决于hash表的大小，如果内存不够，需要作外部归并排序
		内存排小块，写入磁盘文件
		文件不断作归并排序
		得到rank值，还可以存入内存
优化思路：
	各科成绩0-100，可以考虑压缩，不一定要存一个int (32bit，其实可以存2^32 约10亿的数据)，用char就可以。
    排序策略不一定用快排，可以计数排序（总分是有范围的：0-300）

*/