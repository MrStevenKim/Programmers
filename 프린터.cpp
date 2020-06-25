#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	int size = priorities.size();
	int offset = 0;
	queue<int> myQueue;
	queue<int> resultQueue;
	for (int i = 0; i < size; i++)
	{
		int maxValue;
		if(priorities.size() > 0)
			maxValue = *max_element(priorities.begin(), priorities.end());
		
		for (int j = 0; j < priorities.size(); j++)
		{
			if (priorities[j] == maxValue)
			{
				if (myQueue.size() > 0)
				{
					// �� ���� ���� ���� �ǵڷ� �ִ´�.
					int temp = myQueue.front();
					myQueue.pop();
					myQueue.push(j); // ���� �߰��� ���� �ε����� ť�� push
					myQueue.push(temp);
				}
				else
					myQueue.push(j);
				
			}
		}
		
		for (vector<int>::iterator it = priorities.begin(); it != priorities.end();)
		{
			if (*it == maxValue)
			{
				it = priorities.erase(it); // ��� �ش� �ε����� ��� ó���ؾ����� ����ؾ��ҵ�??????
			
			}

			else
				it++;
		}

		while (true)
		{
			if (myQueue.size() == 0)
				break;

			resultQueue.push(myQueue.front());
			myQueue.pop();
		}
	
	}

	for (int i = 0; i < resultQueue.size(); i++)
	{
		// �ش� ���� ��ġ
	}

	return answer;
}

int main()
{
	int printNum;
	vector<int> priorities;
	int location;
	int inputData;

	cin >> printNum;

	for (int i = 0; i < printNum; i++)
	{
		cin >> inputData;
		priorities.push_back(inputData);
	}

	cin >> location;

	cout << solution(priorities, location) << endl;

	return 0;
}