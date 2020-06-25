#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	vector<bool> check;
	int count = 0;

	for (int i = 0; i < progresses.size(); i++)
		check.push_back(false);

	while(true)
	{

		for (int j = 0; j < speeds.size(); j++)
			progresses[j] += speeds[j]; // �Ϸ� ���� �ӵ� ��ŭ ������ ������Ŵ

		for (int i = 0; i < progresses.size(); i++) // �۾��� 100%�� �Ǿ����� �� �������� üũ��
		{
			if (progresses[i] >= 100)
			{
				if (i == 0)
				{
					if (check[i] != true)
					{
						count++;
						check[i] = true;
					}
				}
				else
				{
					if (check[i - 1] == true)
					{
						if (check[i] != true)
						{
							count++;
							check[i] = true;
						}
					}
				}
			}
		}

		if (count != 0)
		{
			answer.push_back(count); // ���ߵ� �۾� �� ��ǲ
			count = 0;
		}

		int a = 0;
		for (int i = 0; i < check.size(); i++)
		{
			if (check[i] == true)
				a++;
		}

		if (a == progresses.size())
			break;

	}

	return answer;
}

int main()
{
	vector<int> progresses;
	vector<int> speeds;
	vector<int> result;

	int processNum;
	int speedNum;
	
	int inputData;

	cin >> processNum >> speedNum;

	for (int i = 0; i < processNum; i++)
	{
		cin >> inputData;
		progresses.push_back(inputData);
	}

	for (int i = 0; i < speedNum; i++)
	{
		cin >> inputData;
		speeds.push_back(inputData);
	}
	
	result = solution(progresses, speeds);

	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	


	return 0;
}