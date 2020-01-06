#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) // 3 7 8 10 ����.. ����
{
	int answer = 0;
	vector<int> student(n+2,1); // n+2�� �ϴ� ������ 0�� n��° �ε����� �߰������ν� ó���� ���� �ϱ� ������.
	student[0] = student[n + 1] = 0; // 0�� n��° 0���� �ʱ�ȭ
	for(int i = 0; i < reserve.size(); i++)
		student[reserve[i]]++; // ���� ü���� ó��

	for (int i = 0; i < lost.size(); i++)
		student[lost[i]]--; // �������� ü���� ó��
	
	for(int i = 1; i<student.size()-1; i++)
	{
		if(student[i] >= 2) // i��° �л��� ü������ 2���̻� �����ϰ� ������
		{
			if(i-1 != 0) // 0��° ����
			{
				student[i - 1]++;
				student[i]--;
			}
		}
	}

	for(int i = 1; i<student.size()-1; i++)
	{
		if (student[i] >= 1)
			answer++;
	}

	return answer;
}

int main()
{
	int n;
	int lost_num;
	int reserve_num;
	int input;
	vector<int> lost;
	vector<int> reserve;
	cin >> n;

	cin >> lost_num;
	for(int i = 0; i < lost_num ; i++)
	{
		cin >> input;
		lost.push_back(input);
	}

	cin >> reserve_num;
	
	for(int i = 0 ; i< reserve_num; i++)
	{
		cin >> input;
		reserve.push_back(input);
	}

	cout << solution(n, lost, reserve);

	return 0;
}