/*
问题： 有两个包，甲包有8个红球和2个蓝球，乙包有2个红球和8个蓝球，先抛硬币决定从甲包还是乙包取球。
确定后，一共取了11次球（都是从甲or乙），每次取一个球并且放回，11次的结果是7次红球，4次蓝球，问选中甲包取球的概率？ (概率）

分析：明显，这是一个后验概率问题，
如果从甲取球，取7红4蓝的概率为c(11,4)*(8/10)^7*(2/10)^4
如果从乙，那么概率为c(11,4)*(2/10)^7*（8/10）^7

然后甲的处以（甲+乙）



*/