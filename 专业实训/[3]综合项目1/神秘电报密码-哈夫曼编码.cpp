#include<bits/stdc++.h>
using namespace std;
#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1
typedef struct
{
	double weight;
	int parent;
	int lchild;
	int rchild;
	char value;
}HNodeType;
typedef struct
{
	int bit[MAXBIT];
	int start;
}HCodeType;
HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n) {
	int i, j, x1, x2;
	double m1, m2;
	for (i = 0; i < 2 * n - 1; i++)
	{
		HuffNode[i].weight = 0;
		HuffNode[i].parent = -1;
		HuffNode[i].rchild = -1;
		HuffNode[i].lchild = -1;
	}
	for (i = 0; i < n; i++)
	{
		cin >> HuffNode[i].value >> HuffNode[i].weight;
	}
	for (i = 0; i < n - 1; i++) {
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if (HuffNode[j].weight < m1 && HuffNode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if (HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
			{
				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = m1 + m2;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
	}
}
void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n) {
	HCodeType cd;
	int i, j, c, p;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = HuffNode[c].parent;
		while (p != -1)
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = HuffNode[c].parent;
		}
		for (j = cd.start + 1; j < n; j++)
			HuffCode[i].bit[j] = cd.bit[j];
		HuffCode[i].start = cd.start;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int i, j, n;
		cin >> n;
		HuffmanTree(HuffNode, n);
		HuffmanCode(HuffCode, n);
		for (i = 0; i < n; i++)
		{
			cout << HuffNode[i].value << ": ";
			for (j = HuffCode[i].start + 1; j < n; j++)
			{
				cout << HuffCode[i].bit[j];
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}