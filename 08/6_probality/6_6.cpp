/*
问题：用数组a[0..n -1]随机产生一个全排列

分析：方法
    for(int i =0;i<n;i++)
        a[i]=i;//赋下初值
    for(int i = 0;i<n;i++)//将a[i]和a[i,n-1]范围内的随机位置交换
        swap(a[i],a[rand()%(n-i)+i]);
*/