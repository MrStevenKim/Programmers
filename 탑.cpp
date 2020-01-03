#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights)
{
	bool checking;
	vector<int> answer;

	for (int top = heights.size() - 1; top >= 0; top--)
	{
		checking = false;

		for (int repeat = top-1; repeat >= 0; repeat--)
		{
			if (heights[repeat] > heights[top]) // �ڽ� ž�� ���̺��� ū ž�� ������
			{
				answer.push_back(repeat + 1); // �ε����� 0���� ���������� ���⼱ 1���� ���� +1
				checking = true;
				break;
			}
			
		}
		
		if (checking == false) // ������������ �ڽ��� ž ���̺��� ���� ž�� ã�� ���Ѵٸ� 0
			answer.push_back(0);
	}

	reverse(answer.begin(), answer.end());// ������ ������ �������� �ֳ� ���� �ε������� �����߱� ������.

	return answer;
}


int main()
{
	vector<int> input;
	vector<int> answer;
	int size;
	int number;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cin >> number;
		input.push_back(number);
	}

	answer = solution(input);

	for (int i = 0; i< answer.size(); i++)
		cout << answer[i] << endl;


	return 0;
}