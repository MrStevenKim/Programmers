#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
	int answer = 0;

	int maxIndex;
	int maxValue;

	for (int i = 0; i < land.size(); i++)
	{
		maxValue = *max_element(land[i].begin(), land[i].end());
		maxIndex = distance(land[i].begin(), find(land[i].begin(), land[i].end(), maxValue));

		// �� ���� ���� maxIndex ��° �� �����ϰ� �ִ밪 ã�Ƽ� answer�� ������Ű��ȴ�. (���� ���� �ٿ� ���� ���� ���� �ÿ��� ����Ǵ� ��Ģ��) // �������� ���� �ٿ� ������ ���� ���ü� �ִ��� ����� �ȵǾ�����.. DP�� Ǯ����ҵ�

		if (i + 1 < land.size())
		{
			land[i + 1].erase(land[i + 1].begin() + maxIndex);
		}


		answer += maxValue;
	}

	return answer;
}


#if 0
int main()
{
	int N, inputData;
	vector<vector<int>> inputLand;
	cin >> N;

	for (int j = 0; j < N; j++)
	{
		vector<int> inputLandVector;
		for (int i = 0; i < 4; i++)
		{
			cin >> inputData;
			inputLandVector.push_back(inputData);
		}

		inputLand.push_back(inputLandVector);
	}
	
	cout << solution(inputLand) << endl;

	return 0;
}

#else

int sol(int n)
{
	if (n <= 0)
		return 0;

	return sol(n - 1) + sol(n);
}
int main()
{
	cout << sol(1) << endl;




}

#endif