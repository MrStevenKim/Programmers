#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
	int answer = 0;
	bool checked[1000]; // 1~999
	checked[0] = true; // 000 �� ������ �� ������ ������ ���õǾ��ٰ� �����ص�.

	for(int i = 0; i < baseball.size(); i++)
	{
		baseball[i][0]; // 0: ���ڸ��� , 1: ��Ʈ����ũ�� ��, 2: ���� ��
	}
	return answer;
}

int main()
{
	int n;
	vector<int> query;
	vector<vector<int>> querys;
	int input;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> input;
		query.push_back(input); // ������ ���ڸ���
		cin >> input;
		query.push_back(input); // ��Ʈ����ũ ��
		cin >> input;
		query.push_back(input); // ���� ��

		querys.push_back(query); // ���� ���� �߰�
		
	}

	cout << solution(querys);
	
	return 0;
}