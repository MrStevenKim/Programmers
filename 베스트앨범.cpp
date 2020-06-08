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

bool compare(pair<string,int> a, pair<string,int> b)
{
	return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> result;
	int size = genres.size();
	
	unordered_map<string, int> myMap;
	vector<pair<string,int>> vec;
	
	// ����� �帣 ������Ű�� ���� ����� �帣�� ã�� ����
	for(int i = 0; i<size; i++)
	{
		myMap[genres.at(i)] += plays.at(i);
	}

	for(auto pair:myMap)
	{
		vec.push_back(make_pair(pair.first, pair.second));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i).first << vec.at(i).second << endl;

	// ���� ����� �帣�� ã�� ���� ���⼭ �帣�߿��� ���ũ�� ū�� ������ result�� push_back ��Ű��!

	
	return result;
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
	
	for(int i = 0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}