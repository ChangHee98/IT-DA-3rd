#include<iostream>
using namespace std;
//a,b�� �Էµɶ� a<b�϶��� �������� ���� ���� �� �ݴ��϶��� ����ε� ���� ������ ����
int main(void) {
	int n, m;
	int fri[501][500] = { {0} };
	int f, s, j, count = 0, i, k = 0;
	int tmp[500] = { 0 }, tmp2[500] = { 0 };
	cin >> n;
	cin >> m;
	for (i = 0; i < m; i++) {
		j = 0;
		cin >> f >> s;
		while (fri[f][j] != 0) {
			j++;
		}
		fri[f][j] = s;
	}
	j = 0;
	f = 0;
	while (fri[1][j] != 0) {
		tmp2[f++] = tmp[j++] = fri[1][j];
		count++;
	}
	k = i = s = 0;
	for (i = 0; i < j; i++) {
		k = 0;
		bool a = true;
		while (fri[tmp[i]][k] != 0) {
			f = 0;
			while (tmp2[f] != 0) {
				if (fri[tmp[i]][k] == tmp2[f]) {
					a = false;
					break;
				}
				f++;
			}
			if (fri[tmp[i]][k] != 0 && a) {
				count++;
				tmp2[s] = fri[tmp[i]][k];
				s++;
			}
			k++;
		}
	}
	cout << count;
	return 0;
}