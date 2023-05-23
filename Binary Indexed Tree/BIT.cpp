#include<iostream>
#include<vector>
using namespace std;
// ������ʵ������״����Ĺ���
// ��״�������ɾ�Ĳ鶼Ϊ (log(n))�ĸ��Ӷ�
// ��Ҫһ��ͼƬ��������״������߼�
// ����ʹ��һ��vector<int> ��ά����״���������
vector<int> BIT;
//��ʼ����������������״����Ĵ�С
void Init(int x) {
	BIT.resize(x, 0);
}
int LowBit(int x) {
	return x & (-x); //������жϵ�ǰ�±�����������ĵ�һ��1�Ƕ��٣���3�Ķ�����Ϊ0011�����Ծ���0001���
					//����x=0011 & 1101 = 0001
					//x=1000 & 1000 = 1000
					//x=1001 & 0111 = 0001
}
// ʹ�ø��µ�ʱ��Ҫʹ��pos+1
void Update(int pos) {
	while (pos < BIT.size()) {
		BIT[pos] += 1;
		pos += LowBit(pos);  // �ܵ�Ӱ���Ԫ���������Ķ������������ɵ�
	}
}
int Query(int pos) {
	int total = 0;
	while (pos > 0) {
		total += BIT[pos];
		pos -= LowBit(pos); //�Ӹߵ������
	}
	return total;
}
int main() {


}