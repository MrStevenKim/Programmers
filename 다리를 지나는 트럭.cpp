#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int truck_num = truck_weights.size();
	int answer = 0; // �ٸ��� �ǳʴµ� �� �ɸ��� �ð��� ��
	int now_weight = 0; // ���� �ٸ����� ������ ������ ��
	int now_truck = 0; // ���� �ٸ����� �ǳʰ� �ִ� Ʈ���� ���
	
	while (truck_weights.size() != 0) // ������ ���� Ʈ���� 0�� �ƴϸ� �ݺ�
	{
		while(now_weight < weight) // ���� �ٸ� ���� ������ ���԰� �ѵ� �̸��̸� �ݺ�
		{
			answer++; // �ٸ� �ö� �� ���� �� Ʈ���� 1�� �ɸ�
			now_weight += truck_weights.front(); // �Ǿտ� ����߿� Ʈ���� ���� ����
			truck_weights.erase(truck_weights.begin()); // �Ǿտ� ������� Ʈ���� �ٸ��� �ö����� �Ǿ� ����
			now_truck++;
			if (truck_weights.size() == 0)
				break;
		}
		
		// �ٸ� ���� ���̻� ������ �� ���� ���԰� �ȴٸ� ���� ���� ����
		answer = answer + bridge_length; // 1�ʴ� �Ÿ�1�� ������ �� ������ �ٸ��� ��ŭ ����
		now_weight = 0; // �� �ǳ����� ���� �ٸ� ���� ����ġ 0 �ʱ�ȭ
		
		now_truck = 0; // �� �ǳ����� ���� �ٸ��� Ʈ�� 0��� �ʱ�ȭ

	}
	

	return answer;
}


int main()
{
	int bridge_length;
	int weight;
	vector<int> truck_weights;
	int truck_num;
	int input_buffer;

	cin >> bridge_length;
	cin >> weight;
	cin >> truck_num;

	for (int i = 0; i < truck_num; i++)
	{
		cin >> input_buffer;
		truck_weights.push_back(input_buffer);
	}

	cout << solution(bridge_length, weight, truck_weights);

	return 0;
}