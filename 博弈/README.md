# 博弈知识总结

今天开始总结博弈这块的知识点，博弈论真的是一门非常神奇的学科。博弈是信息学和数学试题中常会出现的一种类型，算法灵活多变是其最大特点，而其中有一类试题更是完全无法用常见的博弈树来进行解答。 **寻找必败态**即为针对此类试题给出一种解题思路。

常见的几种博弈：

## 巴什博弈（Bash Game）
> 问题模型：只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个。最后取光者得胜。
>

显然，如果n=m+1，那么由于一次最多只能取m个，所以，无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜。因此我们发现了如何取胜的法则：
$$
如果n=(m+1)r+s，（r为任意自然数，s≤m)
$$
那么先取者要拿走s个物品，如果后取者拿走k（≤m)个，那么先取者再拿走m+1-k个，结果剩下(m+1)(r-1)个，以后保持这样的取法，那么先取者肯定获胜。

总之，要保持给对手留下(m+1)的倍数，那么最后就能获胜。


$$
取石子（一)\\
时间限制：3000 ms   |   内存限制：65535 KB \\
难度：2\\ 
$$
描述
​	一天，TT在寝室闲着无聊，和同寝的人玩起了取石子游戏，而由于条件有限，他/她们是用旺仔小馒头当作石子。游戏的规则是这样的。设有一堆石子，数量为N（1<=N<=1000000），两个人轮番取出其中的若干个，每次最多取M（1<=M<=1000000），最先把石子取完者胜利。我们知道，TT和他/她的室友都十分的聪明，那么如果是TT先取，他/她会取得游戏的胜利么？ 

输入 
​	第一行是一个正整数n表示有n组测试数据 
​	输入有不到1000组数据，每组数据一行，有两个数N和M,之间用空格分隔。 

输出 
​	对于每组数据，输出一行。如果先取的TT可以赢得游戏，则输出“Win”，否则输出“Lose”（引号不用输出） 

样例输入 

```
2
1000 1
1 100 
```

样例输出 

```
Lose

Win
```

```c++
/*
 * 巴什博弈
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
	int N, num, limit;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d",&num, &limit);
		if(num%(limit+1)!=0)
			printf("Win\n");
		else
			printf("Lose\n");
	}
	return 0;
}
```



巴什博弈变形： 


$$
取石子（七） \\
时间限制：1000 ms  |  内存限制：65535 KB \\
难度：1
$$
描述 
​	Yougth和Hrdv玩一个游戏，拿出n个石子摆成一圈，Yougth和Hrdv分别从其中取石子，谁先取完者胜，每次可以从中取一个或者相邻两个，Hrdv先取，输出胜利着的名字。 

输入 
​	输入包括多组测试数据。 
​	每组测试数据一个n，数据保证int范围内。 

输出 
​	输出胜利者的名字。 

样例输入 

```
2
3 
```

样例输出 

```
Hrdv
Yougth
```

```c++
//解题思路：假设石子数等于5，如果先者先取一个，那么后者拿走两个，将剩下的两个石子分成两堆，后者赢。如果先者先取二个，那么后者取一个使剩下的两个石子分成两堆，后者赢。假设石子数等于6，如果先者先取一个，那么后者拿走一个，将剩下的石子分成两段，每段两个，如果先者再拿两个，那么后者赢，如果先者再拿一个，那么后者再取另一堆中的一个，这样剩下的两个石子被分成两堆， 后者赢。         如果先者先取两个，那么后者也取两个使剩下的两个石子分成两堆，后者赢。所以当先者取走后，后者取走一个或者两个，将剩下的石子分成对称的两段，以此类推，那么如果石子数大于2后者一定赢。

#include <iostream>
#include <string>
using namespace std;

int main (void)  
{  
	int n;  
	while (scanf("%d", &n) != EOF)  
	{  
		if(n > 2)  
			printf("Yougth\n");  
		else  
			printf("Hrdv\n");  
	}  
	return 0;  
}  
```



## 威佐夫博弈（Wythoff Game）

> 问题模型：有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

我们用（ak，bk）（ak ≤ bk ,k=0，1，2，...,n)表示两堆物品的数量并称其为局势，如果甲面对（0，0），那么甲已经输了，这种局势我们称为奇异局势。前几个奇异局势是：（0，0）、（1，2）、（3，5）、（4，7）、（6，10）、（8，13）、（9，15）、（11，18）、（12，20）。 可以看出,a0=b0=0,ak是未在前面出现过的最小自然数,而 bk= ak + k，奇异局势有如下三条性质： 

- 任何自然数都包含在一个且仅有一个奇异局势中。 
- 任意操作都可将奇异局势变为非奇异局势。 
- 采用适当的方法，可以将非奇异局势变为奇异局势。

从如上性质可知，两个人如果都采用正确操作，那么面对非奇异局势，先拿者必胜；反之，则后拿者取胜。 
 那么任给一个局势（a，b），怎样判断它是不是奇异局势呢？我们有如下公式： 
$$
a_k =[\frac {k(1+√5)}2]，b_k= a_k + k（k=0，1，2，...,n 方括号表示取整函数)
$$

$$
取石子 (四） \\
时间限制：1000 ms  |  内存限制：65535 KB \\
难度：4
$$
描述 
​	有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。 

输入 
​	输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于1,000,000,000。 

输出 
​	输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。 

样例输入 

```
2 1
8 4
4 7
```

样例输出 

```
0
1
0
```

```c++
#include <iostream>
#include <string>
using namespace std;

int main(){
	int m,n;
	while(cin>>m>>n){
		if(m>n)
			swap(m,n);
		int k = n-m;
		int data = floor(k*(1.0+sqrt(5.0))/2.0);
		if(data==m)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
```


$$
Wythoff Game \\
时间限制：1000 ms  |  内存限制：65535 KB \\
难度：1
$$

描述 
​	最近ZKC同学在学博弈，学到了一个伟大的博弈问题--威佐夫博弈。 
​	相信大家都学过了吧？没学过？没问题。我将要为你讲述一下这个伟大的博弈问题。 有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。 游戏规定，每次有两种不同的取法： 
一是可以在任意的一堆中取走任意多的石子； 二是可以在两堆中同时取走相同数量的石子。 最后把石子全部取完者为胜者。 
​	我们今天要做的是求前n个必败态。 
​	什么是必败态？比如我们把（a，b）称为一种状态，a，b分别为两堆石子中所剩的数目。如果a=0，b=0，我们说该种状态为必败态，因为我不能再进行游戏，即使是可以进行，那也是必败的，你知道，游戏的我们都是非常聪明的。（0,0）（1,2）（3,5）...都是必败态，我们今天要做的就是求前n个必败态。不会？好吧！ 
​	我再告诉你：假设第n个必败态为（a，b）a为前n-1个必败态中没有出现的最小自然数，b=a+n。这下大家应该明白了吧。好吧，我们的任务就的要前n个必败态。规定第0个必败态为（0,0）。 

输入 
​	多组数据。 
​	输入为一个数n（0<=n<=100000）。 

输出 
​	按照要求求出前n个必败态。输出格式看下面样例。 
样例输入 

```
3
1 
```

样例输出 

```
(0,0)(1,2)(3,5)(4,7)
(0,0)(1,2) 
```

```c++
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct node{
	int a,b;
}N;

N res[100001];

int main(){
	int n;
	res[0].a = 0;
	res[0].b = 0;
	for(int i=1; i<100001; i++){
		res[i].a = (1+sqrt(5))*i/2;
		res[i].b = res[i].a+i;
	}
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i<=n; i++){
			printf("(%d,%d)", res[i].a, res[i].b);
		}
		printf("\n");
	}
	return 0;
}
```



## 尼姆博弈（Nimm Game）

> 问题模型：有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

用（a，b，c）表示某种局势，显证（0，0，0）是第一种奇异局势，无论谁面对奇异局势，都必然失败。第二种奇异局势是（0，n，n），只要与对手拿走一样多的物品，最后都将导致（0，0，0）。搞定这个问题需要把必败态的规律找出：(a,b,c)是必败态等价于a^b^c=0(^表示异或运算）。



$$
取石子（二） \\
时间限制：3000 ms  |  内存限制：65535 KB \\
难度：5
$$
描述 
​	小王喜欢与同事玩一些小游戏，今天他们选择了玩取石子。 游戏规则如下：共有N堆石子，已知每堆中石子的数量，并且规定好每堆石子最多可以取的石子数（最少取1颗）。 

​	两个人轮流取子，每次只能选择N堆石子中的一堆，取一定数量的石子(最少取一个），并且取的石子数量不能多于该堆石子规定好的最多取子数，等哪个人无法取子时就表示此人输掉了游戏。 

​	假设每次都是小王先取石子，并且游戏双方都绝对聪明，现在给你石子的堆数、每堆石子的数量和每堆石子规定的单次取子上限，请判断出小王能否获胜。 

输入 
​	第一行是一个整数T表示测试数据的组数(T<100) 
​	每组测试数据的第一行是一个整数N(1<N<100),表示共有N堆石子，随后的N行每行表示一堆石子，这N行中每行有两个数整数m,n表示该堆石子共有m个石子，该堆石子每次最多取n个。(0<=m,n<=2^31) 

输出 
​	对于每组测试数据，输出Win表示小王可以获胜，输出Lose表示小王必然会败。 

样例输入 

```
2
1 
1000 1
2
1 1
1 1 
```

样例输出 

```
Lose
Lose 
```

 提示 
​	注意下面一组测试数据 

```
2 
1 1
2 2 
```

​	正确的结果应该是`Win` 
​	因为小王会先从第二堆石子中取一个石子，使状态变为

```
 1 1
 1 2 
```

​	这种状态下，无论对方怎么取，小王都能获胜。

```c++
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int m,n,g,sum=0;
		cin>>g;
		while(g--){
			cin>>m>>n;
			sum ^= m%(n+1);
		}
		cout<<(sum? "Win":"Lose")<<endl;
	}
	system("pause");
	return 0;
}
```



$$
取石子（三）\\
时间限制：1000 ms  |  内存限制：1000 KB\\
难度：6
$$

描述
​	小王喜欢与同事玩一些小游戏，今天他们选择了玩取石子。游戏规则如下：共有N堆石子，已知每堆中石子的数量，两个人轮流取子，每次只能选择N堆石子中的一堆，取一定数量的石子（最少取一个），取过子之后，还可以将该堆石子中剩下的任意多个石子中随意选取几个放到其它的任意一堆或几堆上。等哪个人无法取子时就表示此人输掉了游戏。注意，一堆石子没有子之后，就不能再往此处放石子了。
​	假设每次都是小王先取石子，并且游戏双方都绝对聪明，现在给你石子的堆数、每堆石子的数量，请判断出小王能否获胜。
​	例如：如果最开始有4堆石子，石子个数分别为3 1 4 2，而小王想决定要先拿走第三堆石子中的两个石子（石子堆状态变为3 1 2 2），然后他可以使石子堆达到的状态有以下几种：
​	3 1 2 2（不再移动石子）
​	4 1 1 2（移动到第一堆一个）
​	3 2 1 2（移动到第二堆一个）
​	3 1 1 3（移动到第四堆一个）
​	5 1 0 2（全部移动到第一堆）
​	3 3 0 2（全部移动到第二堆）
​	3 1 0 4（全部移动到最后）



输入
​	可能有多组测试数据(测试数据组数不超过1000)
​	每组测试数据的第一行是一个整数，表示N(1<=N<=10)
​	第二行是N个整数分别表示该堆石子中石子的数量。（每堆石子数目不超过100）
​	当输入的N为0时，表示输入结束

输出
​	对于每组测试数据，输出Win表示小王可以获胜，输出Lose表示小王必然会败。

样例输入
```
3
2 1 3
2
1 1
0
```

样例输出
```
Win
Lose
```

```c++
#include <stdio.h>
#include <string.h>

int arr[1001];

int main(){
	int n, ans, a;
	while(scanf("%d", &n), n){
		while(n--){
			scanf("%d", &a);
			++arr[a];
		}
		ans = 0;
		for(int i = 0; i < 1001; ++i)
			if(arr[i] & 1){
				ans = 1;
				break;
			}
		printf(ans ? "Win\n" : "Lose\n");
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}
```

