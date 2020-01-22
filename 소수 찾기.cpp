#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool PrimeCheck(int input)
{
	if (input <= 1)
		return false;

	for(int i=2; i<=sqrt(input);i++) // input�� �����ٱ����� Ȯ���ϸ� input�� �Ҽ����� �˼� ����
	{
		if ((input % i) == 0)
			return false;
	}

	return true; // ������� ���� �Ҽ�Ȯ��
}

int solution(string numbers)
{
	int answer = 0;
	const int numbers_length = numbers.length(); // ���� ��ŭ ��� �����Ҽ� �ִ��� �������� ��:) "12" ���̰� 2�� 1�� �����ϴ� ��� , 2�� �����ϴ� ��찡 ����.
	vector<string> prime_party_strings;
	string temp;
	vector<char> divide_number;
	vector<int> result;
	vector<int> idx;

	for(int i =0; i < numbers_length; i++)
		divide_number.push_back(numbers[i]); // �� �ڸ��� �����ֱ�

	
		for (int i = 1; i <= numbers_length; i++)
		{
			/*for (int j = 0; j < i; j++)
			{
				idx.push_back(1);
			}

			for (int k = 0; k < numbers_length - i; k++)
			{
				idx.push_back(0);
			}

			sort(idx.begin(), idx.end());

			do
			{
				for (int j = 0; j < numbers_length; j++)
				{
					if (idx[j] == 1)
					{
						temp += divide_number[j];
					}
				}

				result.push_back(stoi(temp));
				temp.clear();

			} while (next_permutation(idx.begin(), idx.end()));*/

			idx.clear();
			
			for (int j = 0; j < i; j++)
				idx.push_back(1);

			for (int j = 0; j < divide_number.size() - i; j++)
				idx.push_back(0);

			sort(idx.begin(), idx.end());

			do
			{
				for(int j=0;j<idx.size();j++)
				{
					if(idx[j] == 1)
					{
						temp += divide_number[j];
					}
				}

				result.push_back(stoi(temp));
				
				temp = "";
				temp.clear();
				
			} while (next_permutation(idx.begin(), idx.end()));

			
		}
	

	sort(result.begin(), result.end());

	result.erase(unique(result.begin(), result.end()), result.end()); // �ߺ����� 111 �Է������� 1 1 1 11 11 11 �̷��� ����

	for(const auto& i : result)
	{
		cout << i << " ";
		
		if (PrimeCheck(i) == true)
			answer++;
	}
	
	
	return answer;
}
int main()
{
	string input_str;

	cin >> input_str;

	cout << solution(input_str) << endl;

	return 0;
}

