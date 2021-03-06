> 因为github的markdown对数学公式mathjax不支持，所以建议到我的博客阅读：[排序算法](https://hushhw.cn/posts/learn/61237.html)

# 排序算法

之前也有总结排序部分，但是总是忘记，这段时间在整理算法笔记，所以借机再整理一份。
主要整理的是八大内部排序，分析代码，时间复杂度等

排序分类见图：（图片来源见图片链接）
![图片来源见链接](http://cuijiahua.com/wp-content/uploads/2018/01/algorithm_9_2.png)

各排序算法基本性能：
![图片来源见链接](http://cuijiahua.com/wp-content/uploads/2018/01/algorithm_9_3.png)



## 1. 冒泡排序

### 1.1 冒泡排序算法思想及代码实现

冒泡排序是一种交换排序，基本算法思想是重复访问要排序的数列，每趟排序过程中通过两两比较相邻元素，按一定顺序交换，直到没有在需要交换即数列排序完成。

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	for(int i=0; i < result.size()-1; ++i){		//外层循环仅标记趟数
		cout<<"第"<<i+1<<"趟排序:"<<endl;
		for(int j=0; j < result.size()-1; j++){	//内层循环进行相邻数据交换
			if(result[j+1] < result[j]){
				swap(result[j+1], result[j]);
			}
			cout<<"排序中:";
			for(int s=0; s<result.size(); s++){
				cout<<result[s]<<" ";
			}
			cout<<endl;
		}

		cout<<"排序结果:";
		for(int s=0; s < result.size(); s++){
			cout<<result[s]<<" ";
		}
		cout<<endl;
	}
	return result;
}

int main(){
	int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

```



### 1.2 冒泡排序算法性能

若文件的初始状态是正序的，一趟扫描即可完成排序。所需的关键字比较次数C和记录移动次数M均达到最小值：Cmin = N - 1, Mmin = 0。所以，**冒泡排序最好时间复杂度为O(N)**。
若初始文件是反序的，需要进行 N -1 趟排序。每趟排序要进行 N - i 次关键字的比较(1 ≤ i ≤ N - 1)，且每次比较都必须移动记录三次来达到交换记录位置。在这种情况下，比较和移动次数均达到最大值：
$C_{max} = N(N-1)/2 = O(N^2)$
$M_{max} = 3N(N-1)/2 = O(N^2)$
冒泡排序的最坏时间复杂度为$O(N^2)$。
因此，冒泡排序的平均时间复杂度为$O(N^2)$。
总结起来，其实就是一句话：当数据越接近正序时，冒泡排序性能越好。



冒泡排序就是把小的元素往前调或者把大的元素往后调。比较是相邻的两个元素比较，交换也发生在这两个元素之间。所以相同元素的前后顺序并没有改变，所以冒泡排序是一种**稳定排序算法**。



### 1.3 冒泡排序优化

在上述代码中测试的数据会发现，早在第三趟就已经完成排序，但是还是执行了后面的四五六趟排序。对冒泡排序常见的改进方法是加入**标志性变量exchange**，用于标志某一趟排序过程中是否有数据交换。如果进行**某一趟排序时并没有进行数据交换，则说明所有数据已经有序**，可立即结束排序，避免不必要的比较过程。



```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	for(int i=0; i < result.size()-1; ++i){		//外层循环仅标记趟数
		cout<<"第"<<i+1<<"趟排序:"<<endl;
		/*----------冒泡排序优化代码1-----------*/
		bool bChanged = false;	//交换标记
		/*----------冒泡排序优化代码1-----------*/
		for(int j=0; j < result.size()-1; j++){	//内层循环进行相邻数据交换
			if(result[j+1] < result[j]){
				swap(result[j+1], result[j]);
				/*----------冒泡排序优化代码2-----------*/
				bChanged = true;
				/*----------冒泡排序优化代码2-----------*/
			}
			cout<<"排序中:";
			for(int s=0; s<result.size(); s++){
				cout<<result[s]<<" ";
			}
			cout<<endl;
		}
		/*----------冒泡排序优化代码3-----------*/
		if(bChanged == false)	//如果标志为false,说明本轮遍历没有进行数据交换，即说明已经有序
			break;
		/*----------冒泡排序优化代码3-----------*/
		cout<<"排序结果:";
		for(int s=0; s < result.size(); s++){
			cout<<result[s]<<" ";
		}
		cout<<endl;
	}
	return result;
}

int main(){
	int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

```



## 2. 快速排序

### 2.1 快速排序算法思想及代码实现

快速排序也是一种交换排序。快速排序由C. A. R. Hoare在1962年提出。

它的基本思想是：通过一趟排序将要排序的数据**分割**成独立的两部分：**分割点左边都是比它小的数，右边都是比它大的数**。然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

算法步骤：

- 选取主元
- 小于等于主元的放左边，大于等于主元的放右边
- 分别对左右边递归，即重复（1）、（2）步

```c++
#include <iostream>
#include <vector>
using namespace std;

int division(vector<int> &list, int left, int right){
	int base = list[left];
	while(left < right){
		while(left < right && list[right]>=base)//从序号右端开始向左遍历，直到找到小于base的数
			right--;
		list[left] = list[right];	//找到比base小的元素，将这个元素放到最左边的位置
		while(left < right && list[left]<=base) //从序号左端开始向右遍历，直到找到大于base的数
			left++;
		list[right] = list[left];	//找到比base大的元素，将这个元素放到最右边的位置
	}

	list[left] = base;
	cout << "每一轮：";
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout<<endl;
	return left;
}

void QuickSort(vector<int> &list, int left, int right){
	if(left < right){	//左下标一定小于右下标，否则越界
		int base = division(list, left, right);//对数组进行分割，去除下次分割的基准标号
		QuickSort(list, left, base-1);//左
		QuickSort(list, base+1, right);//右
	}
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1};
	vector<int> test(arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result = test;

	QuickSort(result, 0, result.size() - 1);

	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
```

### 2.2 快速排序算法性能

时间复杂度上：

最好的情况，每次我们运行一次分区，我们会把一个数组分为两个几近相等的片段。这个意思就是每次递归调用处理一半大小的数组。则会有关系式：
$$
T(n)=2T(\frac n 2)+O(n)
$$
解出 $T_{best}(n)=O(nlogn)$。

最坏的情况，在分割后，两子数组总是拥有各为 1 和 n-1 长度的数组，则递归关系式变为：
$$
T(n)=T(n−1)+O(n)+O(1)=T(n−1)+O(n)
$$
解出 $T_{worst}(n)=O(n^2)$。



空间复杂度上：

快速排序在每次分割的过程中，需要 1 个空间存储基准值。而快速排序的大概需要Nlog2N次的分割处理，所以占用空间也是 Nlog2N 个。



算法稳定性上：

在快速排序中，相等元素可能会因为分区而交换顺序，所以它是不稳定的算法。



### 2.3 快速排序细节优化

我们知道主元的大小直接决定快排的效率，因为数组的划分需要依靠主元，理想状态下，给定的主元正好可以把数组分为长度相等的两个子数组，但找到并确定这样的主元还需要耗费额外的时间，如此一来，得不偿失。

快速排序算法有三种选择主元的方法：

1. 取序列中的第一个或最后一个元素作为主元*（前面实现的就是这种）*
2. 取序列中任意一个元素作为主元
3. 选取左，中，右三个元素的 “中值” 为主元




## 3. 直接插入排序

### 3.1 插入排序算法思想及代码实现

每一趟将一个待排序的记录，按照其关键字的大小插入到有序队列的合适位置里，直到全部插入完成。

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> insertSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	// 第1个数肯定是有序的，从第2个数开始遍历，依次插入有序序列
	for (int i = 1; i < result.size(); i++){
		// 取出第i个数，和前i-1个数比较后，插入合适位置
		int temp = result[i];
		// 因为前i-1个数都是从小到大的有序序列，所以只要当前比较的数(res[j])比temp大，就把这个数后移一位
		int j = i - 1;
		for (j; j >= 0 && result[j] > temp; j--){
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
		cout << "第"<<i<<"轮:";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

void main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = insertSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}
```



### 3.2 插入排序算法性能

那么它的算法复杂度如下（参考[维基百科](https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F#.E7.AE.97.E6.B3.95.E5.A4.8D.E6.9D.82.E5.BA.A6)）：

- 时间复杂度
  - 最好情况，序列是升序排列，在这种情况下，只需进行 $n-1$ 比较，即 $T_{best}(n)=O(n)$；
  - 最坏情况，序列是降序排列，那么此时需要进行的比较共有 $\frac 12n(n−1)$ 次，即 $T_{worse}(n)=O(n^2)$；
  - 平均情况，为 $T_{avg}(n)=O(n^2)$。
- 空间复杂度
  - 由程序很容易得我们在排序过程中，需要一个临时变量存储要插入的值，所以空间复杂度为 S(n)=O(1)。

它的算法稳定性：直接插入排序的过程中，不需要改变相等数值元素的位置，所以它是**稳定的**算法。



## 4. 希尔排序

### 4.1 希尔排序算法思想及代码实现

希尔(Shell)排序又称为**缩小增量排序**，它是一种**插入排序**。它**是直接插入排序算法的一种威力加强版**。该方法因DL．Shell于1959年提出而得名。

希尔排序是基于插入排序的以下两点性质而提出改进方法的：（以下摘自[维基百科](https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F)）

- 插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到[线性排序](https://zh.wikipedia.org/w/index.php?title=%E7%BA%BF%E6%80%A7%E6%8E%92%E5%BA%8F&action=edit&redlink=1)的效率
- 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位

希尔排序的**基本思想**是：

把记录按**步长** gap 分组，对每组记录采用**直接插入排序**方法进行排序。
随着**步长逐渐减小**，所分成的组包含的记录越来越多，当步长的值减小到 **1** 时，整个数据合成为一组，构成一组有序记录，则完成排序。

举例：假设有这样一组数[ 13 14 94 33 82 25 59 94 65 23 45 27 73 25 39 10 ]，如果我们以步长为5开始进行排序，我们可以通过将这列表放在有5列的表中来更好地描述算法，这样他们就应该看起来是这样：

`13 14 94 33 82`
`25 59 94 65 23`
`45 27 73 25 39`
`10`

然后我们对每列进行排序：

`10 14 73 25 23`
`13 27 94 33 39`
`25 59 94 65 82`
`45`

将上述四行数字，依序接在一起时我们得到：[ 10 14 73 25 23 13 27 94 33 39 25 59 94 65 82 45 ].这时10已经移至正确位置了，然后再以3为步长进行排序：

`10 14 73`
`25 23 13`
`27 94 33`
`39 25 59`
`94 65 82`
`45`



排序之后变为：

`10 14 13`
`25 23 33`
`27 25 59`
`39 65 73`
`45 94 82`
`94`

最后以1步长进行排序（此时就是简单的插入排序了）。

可想而知，步长的选择是希尔排序的重要部分。算法最开始以一定的步长进行排序，然后会继续以更小的步长进行排序，最终算法以步长为 1 进行排序。当步长为 1 时，算法变为直接插入排序，这就保证了数据一定会被全部排序。

下面以$\frac n{2^i}$作为步长为例进行讲解。

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> ShellSort(vector<int> list){
	vector<int> result;
	result = list;
	int n = result.size();
	for(int gap = n >> 1; gap > 0; gap >>= 1){	//对n进行二分除二处理
		for(int i=gap; i<n; i++){
			int temp = result[i];	//记录i所在的数
			int j;
			for(j = i-gap; j>=0 && result[j]>temp; j -= gap){//把相距为gap的i,j所在数字比较，相当于隔行判断
				result[j+gap] = result[j];
			}
			result[j+gap] = temp;
		}
	}
	return result;
}

void main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = ShellSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}
```



### 4.2 希尔排序算法性能

那么它的算法复杂度如下（参考[维基百科](https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F#.E7.AE.97.E6.B3.95.E5.A4.8D.E6.9D.82.E5.BA.A6)）：

步长的选择是希尔排序的重要部分。只要最终步长为1任何步长序列都可以工作。

算法最开始以一定的步长进行排序。然后会继续以一定步长进行排序，最终算法以步长为1进行排序。当步长为1时，算法变为插入排序，这就保证了数据一定会被排序。
Donald Shell 最初建议步长选择为N/2并且对步长取半直到步长达到1。虽然这样取可以比O(N2)类的算法（插入排序）更好，但这样仍然有减少平均时间和最差时间的余地。可能希尔排序最重要的地方在于当用较小步长排序后，以前用的较大步长仍然是有序的。比如，如果一个数列以步长5进行了排序然后再以步长3进行排序，那么该数列不仅是以步长3有序，而且是以步长5有序。如果不是这样，那么算法在迭代过程中会打乱以前的顺序，那就

不会以如此短的时间完成排序了。

|      步长序列      |     最坏情况下复杂度      |
| :------------: | :---------------: |
| $\frac n{2^i}$ |     $O(n^2)$      |
|    $2^i-1$     | $O(n^{\frac 32})$ |
|    $2^i3^i$    |   $O(nlog^2n)$    |

已知的最好步长序列是由Sedgewick提出的(1, 5, 19, 41, 109,...)，该序列的项来自$9*4^i-9*2^i$和$2^{i+2}*(2^{i+2}-3)+1$这两个算式。这项研究也表明“比较在希尔排序中是最主要的操作，而不是交换。”用这样步长序列的希尔排序比插入排序和堆排序都要快，甚至在小数组中比快速排序还快，但是在涉及大量数据时希尔排序还是比快速排序慢。

它的算法稳定性：希尔排序中相等数据可能会交换位置，所以希尔排序是**不稳定**的算法。

### 4.3 希尔排序和直接插入排序比较

直接插入排序是**稳定的**；而希尔排序是**不稳定**的。

直接插入排序更适合于原始记录基本**有序**的集合。

希尔排序的比较次数和移动次数都要比直接插入排序少，当N越大时，效果越明显。   

在希尔排序中，增量序列gap的取法必须满足：**最后一个步长必须是1**。

直接插入排序也**适用于链式存储结构**；希尔排序**不适用于链式结构**。



## 5. 简单选择排序

### 5.1 简单选择排序算法思想及代码实现

简单选择排序是一种**选择排序**。

**选择排序**：每趟从待排序的记录中选出关键字最小的记录，顺序放在已排序的记录序列末尾，直到全部排序结束为止。



简单排序很简单，它的大致处理流程为：

- 从待排序序列中，找到关键字最小的元素；
- 如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；
- 从余下的 N - 1 个元素中，找出关键字最小的元素，重复(1)、(2)步，直到排序结束。

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectSort(vector<int> list){
	vector<int> result;
	result = list;
	for(int i=0; i<result.size(); i++){
		int index = i;		//标记第一个位置
		for(int j=i+1; j<result.size(); j++){
			if(result[index] > result[j])
				index = j;	//如果比index位置上的数字小，就标记该数字
		}
		swap(result[i], result[index]);	//循环结束后把标记的最小数字所在位置index和i位置交换
		
		cout << "第" << i + 1<< "趟:\t";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = SelectSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
```



### 5.2 简单选择排序算法性能

那么它的算法复杂度如下：

- 时间复杂度

  简单选择排序的比较次数与序列的初始排序无关。 假设待排序的序列有 N 个元素，则比较次数总是$\frac {N (N - 1) }2$。

  简单排序的时间复杂度为 $O(N^2)$。

- 空间复杂度

  - 由程序很容易得我们在排序过程中，需要一个临时变量存储要插入的值，所以空间复杂度为 S(n)=O(1)。



## 6. 堆排序

### 6.1 堆排序算法思想及代码实现

堆排序是利用堆的性质进行的一种选择排序。下面先讨论一下堆。

堆实际上是一棵完全二叉树，其满足性质：任何一结点大于等于或者小于等于其左右子树结点。

堆分为大顶堆和小顶堆，满足 “任何一结点大于等于其左右子树结点” 的称为大顶堆，满足 “任何一结点小于等于其左右子树结点” 的称为小顶堆。由上述性质可知：大顶堆的堆顶肯定是最大的，小顶堆的堆顶是最小的。



堆排序可以归纳出两个操作：

- 根据初始数组去**构造初始堆**（构建一个完全二叉树，保证所有的父结点都比它的孩子结点数值大）。
- 每次**交换第一个和最后一个元素，输出最后一个元素**（最大值），然后把剩下元素**重新调整**为大根堆。

下面举个例子（资源来自[堆排序 - 海子](http://www.cnblogs.com/dolphin0520/archive/2011/10/06/2199741.html)）来说明堆排序的过程（以升序为例）：

（1）
![img](https://61mon.com/images/illustrations/Sort/3.jpg)

给定整型数组：{16, 7, 3, 20, 17, 8}，根据该数组 “构建” 完全二叉树（并不是真的写代码去构建，只是把数组看成完全二叉树去操作）。

程序从最后一个非叶子结点开始，即 3。判断其左右孩子：8，8 比 3 大，把 8 调整上去。

（2）
![img](https://61mon.com/images/illustrations/Sort/4.jpg)

3 结点下无孩子，判断结束。

继续往前一步，至 7 结点，判断其左右孩子：20 和 17，20 是最大的，将其调整上去。

（3）
![img](https://61mon.com/images/illustrations/Sort/5.jpg)

7 结点下无孩子，判断结束。

继续往前一步，至 16 结点，判断其左右孩子：20 和 8，20 是最大的，将其调整上去。

（4）
![img](https://61mon.com/images/illustrations/Sort/6.jpg)

判断 16 结点下左右孩子：7 和 17，17 是最大的，将其调整上去。

（5）
![img](https://61mon.com/images/illustrations/Sort/7.jpg)

16 结点下无孩子，判断结束。

遍历已至头部，结束。

（6）至此数组已经满足大顶堆的性质，接下来的操作就很简单了。
![img](https://61mon.com/images/illustrations/Sort/8.jpg)

看完上面所述的流程你至少有两个疑问：

- 如何确定最后一个非叶子结点？

其实这是有一个公式的，设二叉树结点总数为 n，则最后一个非叶子结点是第$\frac n2$个。

- 数组当中如何确定当前结点的左右孩子位置？

设当前结点下标是 i，则其左孩子的下标是 2i，右孩子的下标是 2i+1。请注意：这是建立在数组下标从 1 开始的情况。若数组下标从 0 开始，则其左右孩子下标还各需多加一个 1。

```c++
#include <iostream>
#include <vector>
using namespace std;

void HeapAdjust(vector<int> &list, int start, int length){
	int parent = start;			//父节点
	int child = 2 * parent + 1;	// 先获得左孩子
	
	while (child <= length){	
		// 如果有右子节点，并且右子节点的值大于左子节点，则选取右子节点，否则选取左节点
		if (child + 1 <= length && list[child] < list[child + 1]){
			child++;
		}
		//如果父节点大于孩子节点则代表调整完毕，直接跳出函数
		if (list[parent] > list[child]){
			break;
		}
		else{ //否则交换父子内容再继续子节点和孙节点比较
			swap(list[parent], list[child]);
			parent = child;//父更新为子节点位置
			child = parent*2+1;//子节点更新为孙节点位置
		}
	}
}

vector<int> HeadSort(vector<int> list){
	int length = list.size();
	// 循环建立初始堆，i从最后一个父节点开始
	for (int i = length/2-1; i >= 0; i--){
		HeapAdjust(list, i, length-1);
	}
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout << endl;
	// 进行n-1次循环，完成排序
	for (int i = length - 1; i > 0; i--){
		// 最后一个元素和第一元素进行交换
		swap(list[0], list[i]);

		// 筛选 R[0] 结点，得到i-1个结点的堆
		HeapAdjust(list, 0, i-1);
		cout << "第" << length - i << "趟排序:";
		for (int i = 0; i < list.size(); i++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = HeadSort(test);
	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
```



### 6.2 堆排序算法性能

堆的存储表示是**顺序的**。因为堆所对应的二叉树为完全二叉树，而完全二叉树通常采用顺序存储方式。

当想得到一个序列中第**k**个最小的元素之前的部分排序序列，最好采用堆排序。



时间复杂度为 $O(nlogn)$，证明如下。

首先计算建堆的时间，也就是下面的代码，

```c++
// 循环建立初始堆，i从最后一个父节点开始
	for (int i = length/2-1; i >= 0; i--){
		HeapAdjust(list, i, length-1);
	}
```

n 个结点，从第 0 层至第 $log_2n$ 层。对于第$i$层的$2^i$个点如果需要往下走$log_2n−i$步，那么把走的所有步相加得， 
$$
T(n) = \sum _{i=0}^{i=log_2n}{2^i(log_2n-i)}= 2n-log_2n-2<2n=O(n)
$$
接下来就是排序的时间，即下面的代码：

```c++
for (int i = length - 1; i > 0; i--){
	// 最后一个元素和第一元素进行交换
	swap(list[0], list[i]);
	// 筛选 R[0] 结点，得到i-1个结点的堆
	HeapAdjust(list, 0, i-1);
```

HeapAdjust() 耗时$logn$，共$n$次，故排序时间为$O(nlogn)$。

综上所述，堆排序时间复杂度为$T(n)=O(n)+O(nlogn)=O(nlogn)$。

算法稳定度：

堆排序是一种**不稳定**的排序方法。

因为在堆的调整过程中，关键字进行比较和交换所走的是该结点到叶子结点的一条路径，因此对于相同的关键字就可能出现排在后面的关键字被交换到前面来的情况。



## 7. 归并排序

### 7.1 归并排序算法思想及代码实现

归并排序是建立在归并操作上的一种有效的排序算法，该算法是采用**分治法（Divide and Conquer）**的一个非常典型的应用。

将待排序序列R[0...n-1]看成是n个长度为1的有序序列，将相邻的有序表成对归并，得到n/2个长度为2的有序表；将这些有序序列再次归并，得到n/4个长度为4的有序序列；如此反复进行下去，最后得到一个长度为n的有序序列。

综上可知：

归并排序其实要做两件事：

（1）“分解”——将序列每次**折半划分**。

（2）“合并”——将划分后的序列段**两两合并后排序**。

```c++
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i=left;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=right){
		if(input[i]<=input[j]){
			temp[k++] = input[i++];
		} else {
			temp[k++] = input[j++];
		}
	}
	while(i<=mid)
		temp[k++]=input[i++];
	while(j<=right)
		temp[k++]=input[j++];
	k=0;
	while(left<=right){
		input[left++] = temp[k++];
		cout<<input[left-1]<<" ";
	}
	cout<<endl;
}

void MergeSort(vector<int> &input, int left, int right, vector<int> temp){
	if(left<right){
		int mid = (left+right)>>1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid+1, right, temp);
		Merge(input, left, mid ,right, temp);
	}
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1};
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	vector<int> temp(result.size());// 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	MergeSort(result, 0, result.size()-1, temp);

	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
```



### 7.2 归并排序算法性能

归并排序的时间复杂度分析：MergeSort()函数用于数组划分，Merge()函数用于合并。

- 合并函数Merge()的时间复杂度为$O(n)$，因为代码中有2个长度为n的循环（非嵌套）
- 划分函数MergeSort()中，简单的分析一下元素长度为n的归并排序所消耗的时间为T(n)：调用MergeSort()函数划分两部分，那每一小部分所花销的时间则是$T[\frac n2]$

最后两部分合并:（用迭代法进行推导）
$$
\begin{align}
T[n]& = 2T[\frac n2]+O(n)
\\令：n=\frac n2\quad &=2(2T[\frac n4]+\frac n2)+n
\\&=2^2T[\frac n{2^2}]+2n
\\令：n=\frac n{2^2}\quad&=2^2(2T[\frac n{2^3}]+\frac n{2^2})+2n
\\&=2^3T[\frac n{2^3}]+3n
\\&……
\\令：n=\frac n{2^{m-1}}\quad&=2^mT[1]+mn
\\经过m次递归后，&当最后平分的不能再平分
\\到最后得到T[1]时，&说明这个公式已经迭代完了（T[1]是常量了）
\\得到：T[\frac n{2^m}]=T[1]\quad &==>\ n=2^m\quad ==>\ m=logn
\\T[n]&=2^mT[1]+mn\qquad 其中m=logn；
\\T[n]&=2^{logn}T[1]+nlogn
\\&=nT[1]+nlogn
\\&=n+nlogn
\end{align}
$$
综上所述：归并排序时间复杂度为：$O(nlogn)$。

因为不管元素在什么情况下都要做这些步骤，所以花销的时间是不变的，所以该算法的最优时间复杂度和最差时间复杂度及平均时间复杂度都是一样的为：$O(nlogn)$。

归并排序的空间复杂度：

归并的空间复杂度就是那个临时的数组和递归时压入栈的数据占用的空间：n+logn；所以空间复杂度为: O(n)

归并排序的算法稳定度：

在归并排序中，相等的元素的顺序不会改变，所以它是**稳定的**算法。



## 8. 基数排序

### 8.1 基数排序算法思想及代码实现

基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数。

算法步骤：

- 将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。
- 从最低位开始，依次进行一次排序。
- 这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。

基数排序的方式可以采用 LSD（Least significant digital）或 MSD（Most significant digital），LSD 的排序方式由键值的最右边开始，而 MSD 则相反，由键值的最左边开始。

不妨通过一个具体的实例来展示一下基数排序是如何进行的。 设有一个初始序列为: R {50, 123, 543, 187, 49, 30, 0, 2, 11, 100}。

我们知道，任何一个阿拉伯数，它的各个位数上的基数都是以 0~9 来表示的，所以我们不妨把 0~9 视为 10 个桶。

我们先根据序列的个位数的数字来进行分类，将其分到指定的桶中。例如：R[0] = 50，个位数上是 0，将这个数存入编号为 0 的桶中。

![img](https://61mon.com/images/illustrations/Sort/10.png)

分类后，我们在从各个桶中，将这些数按照从编号 0 到编号 9 的顺序依次将所有数取出来。这时，得到的序列就是个位数上呈递增趋势的序列。

按照个位数排序： {50, 30, 0, 100, 11, 2, 123, 543, 187, 49}。

接下来，可以对十位数、百位数也按照这种方法进行排序，最后就能得到排序完成的序列。

```c++
#include <iostream>
#include <vector>
using namespace std;

// 求出数组中最大数的位数的函数
int MaxBit(vector<int> input){
	// 数组最大值
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++){
		if (input[i] > max_data){
			max_data = input[i];
		}
	}
	cout<<"max_data:"<<max_data<<endl;
	// 数组最大值的位数
	int bits_num = 0;
	while (max_data){
		bits_num++;
		max_data /= 10;
	}
	cout<<"bits_num:"<<bits_num<<endl;
	return bits_num;
}

vector<int> RadixSort(vector<int> input, int n){
	vector<int> bucket(n);	//存储排序过程中的数据
	vector<int> count(10);	//位计数器，从第0个元素到第9个元素依次用来记录当前比较位是0的有多少个...是9的有多少个数
	int bits_num = MaxBit(input); //求出数组中最大数的位数的函数
	int radix = 1;
	// 从低位往高位循环
	for (int d = 1; d <= bits_num; d++){ 
		// 计数器清0
		for (int i = 0; i < 10; i++){
			count[i] = 0;
		}
 
		// 统计各个桶中的个数
		for (int i = 0; i < n; i++){
			int k=(input[i]/radix)%10;//取每个数字的末尾
			count[k]++;
		}
		cout<<"before:";
		for (int i = 0; i < n; i++){
			cout<<count[i]<<" ";
		}
		cout<<endl;
 
		cout<<"after:   ";
		//索引重分配
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];//count[i]表示第i个桶的右边界索引
			cout<<count[i]<<" ";
		}
		cout<<endl;

		//放入临时数组，从右到左扫描，保证排序稳定性
		for (int i = n - 1; i >= 0; i--){
			int k = (input[i]/radix)%10;
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}
		cout<<"input:";
		// 临时数组复制到 input 中
		for (int i = 0; i < n; i++){
			input[i] = bucket[i];
			cout<<input[i]<<" ";
		}
		cout<<endl;
		radix *= 10;
	}
 
	return input;
}

int main(){
	int arr[] = { 50, 123, 543, 187, 49, 30, 0, 2, 11, 100 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	result = RadixSort(result, result.size());

	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
```



### 8.2 基数排序算法性能

基数排序的时间复杂度是$O(k⋅n)$，其中$n$是排序元素个数，$k$是最大的数字位数。

空间复杂度是使用了两个临时的数组：10 + length；所以空间复杂度：$O(n)$

在基数排序过程中，每次都是将当前位数上相同数值的元素统一“装桶”，并不需要交换位置。所以基数排序是**稳定**的算法。



> 本文参考整理自：
>
> http://cuijiahua.com/blog/2018/01/alogrithm_9.html
>
> https://61mon.com/index.php/archives/193/
>
> http://www.cnblogs.com/jingmoxukong/p/4311237.html