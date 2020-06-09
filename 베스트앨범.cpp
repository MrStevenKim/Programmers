#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <tuple>
using namespace std;

/*
 * ���� �뷡�� ���� ����� �帣���� ���� ����
 * �帣 ������ ���� ����� �뷡�� ���� ����
 * �帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ������ȣ�� ���� �뷡���� ����
 */

struct aa
{
	string first;
	int second;
	bool operator<(const aa &c) const
	{
		return second > c.second;
	}
};

struct bb
{
	int first;
	int second;
	bool operator<(const bb &c) const
	{
		if(second==c.second)
		{
			return first < c.first;
		}
		return second > c.second;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	int size = genres.size();

	unordered_map<string, int> hash;
	vector <aa> vec;

	for(int i = 0; i<size; i++)
	{
		hash[genres[i]] += plays[i];
	}

	for (auto pair : hash)
	{
		vec.push_back({pair.first,pair.second});
	}

	sort(vec.begin(), vec.end());

	for(auto iter : vec)
	{
		vector<bb> tmp;
		for(int i = 0; i<size;i++)
		{
			if(iter.first == genres[i])
			{
				tmp.push_back({i,plays[i]});
			}
		}
		
		sort(tmp.begin(), tmp.end());


	
	

		//
		int cnt = 0;
		for (auto t : tmp)
		{
			cnt++;
			if (cnt > 2) break;
			answer.push_back(t.first);
			cout << t.first << endl;
		}
	}
	
	return answer;
}
int main()
{
	vector<string> genres;
	vector<int> plays;
	vector<int> result;
	int num, input_plays;
	string input_genres;
	
	cin >> num;

	for(int i = 0;i<num; i++)
	{
		cin >> input_genres;
		cin >> input_plays;

		genres.push_back(input_genres);
		plays.push_back(input_plays);
	}


	result = solution(genres, plays);
	

	return 0;
}