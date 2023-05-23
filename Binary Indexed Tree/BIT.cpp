#include<iostream>
#include<vector>
using namespace std;
// 本代码实现了树状数组的功能
// 树状数组的增删改查都为 (log(n))的复杂度
// 需要一个图片来解释树状数组的逻辑
// 现在使用一个vector<int> 来维护树状数组的内容
vector<int> BIT;
//初始化函数用来调整树状数组的大小
void Init(int x) {
	BIT.resize(x, 0);
}
int LowBit(int x) {
	return x & (-x); //这个是判断当前下标从右往左数的第一个1是多少，即3的二进制为0011，所以就由0001组成
					//其中x=0011 & 1101 = 0001
					//x=1000 & 1000 = 1000
					//x=1001 & 0111 = 0001
}
// 使用更新的时候要使用pos+1
void Update(int pos) {
	while (pos < BIT.size()) {
		BIT[pos] += 1;
		pos += LowBit(pos);  // 受到影响的元素是由它的二进制码所构成的
	}
}
int Query(int pos) {
	int total = 0;
	while (pos > 0) {
		total += BIT[pos];
		pos -= LowBit(pos); //从高到低相加
	}
	return total;
}
int main() {


}