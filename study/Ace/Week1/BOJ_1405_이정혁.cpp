#include<iostream>
#include<vector>

using namespace std;

int movement[4][2] = { {1,0},{-1,0} ,{0,1},{0,-1} };
int n, L, R, U, D;
bool visit[33][33]; //�˳��� 33����
double result;
vector<double> v;

/*
bfs�� �����Ϸ��ٰ� �׸��׷����� dfs�� ��ȯ , ���������� Ž���ؼ� �ö󰡴°� ������ �� ����.
������ �湮ó��,,, �׷� �ȹ�Ե�,,, ���������� n �� ���������� ��� Ȯ�� ���ؼ� ������ָ��
��,,, length�� n�϶� return�� �ϸ� �ȵǷ���... ->�̰� ������ �ƴϰ� �Ҽ��� �������� ����...
*/
void dfs(int x, int y,int length, double value) {
	if (length == 0) { // length�� �����̸� return
		result += value;
		return;
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];
		if (visit[nx][ny] == false) { //���� �ʾ����� ���� 
			dfs(nx, ny, --length, value * v[i]); //1�� �����̴� ���̴� --length , value ���ٰ� ����Ȯ�� v[i] ���ϱ� , ������ ũ�� ���� ��������̵� Ȯ���� �˾Ƽ� ����� �ɰ���.
			length++; // dfs���� ���°Ŵ� �ٽ� ++
			visit[nx][ny] = false; // ���� �������̾���ϴ� falseó��
		}
	}
}

int main(void) {
	cin >> n >> L >> R >> D >> U;
	v.emplace_back(L * 0.01);
	v.emplace_back(R * 0.01);
	v.emplace_back(D * 0.01);
	v.emplace_back(U * 0.01);
	dfs(15, 15, n, 1.0); //�߰��� 15�� (15,15) ��
	cout<<fixed; // �ƿ� ������ �̰� �Ҽ��� ��
	cout.precision(10); //10 ������ 9�ڸ����� ���´ٰ� ��.
	cout << result;
	return 0;
}