
#include <stdio.h>
#define N 4

// 2���� �迭 ������ ���ǥ
int cost[4][4] = { { 0, 10, 75, 94},
                  {-1,  0, 35, 50},
                  {-1, -1,  0, 80},
                  {-1, -1, -1,  0}
};

// ��߿�(s)���� ������(d)������ �ּ� ����� ����մϴ�.
int minCost(int s, int d)
{
    if (s == d || s == d - 1)
        return cost[s][d];
    int minValue = cost[s][d];
    // �ּڰ��� ã�� ���ؼ� ��� �߰� ���� ���ؼ� ����غ��ϴ�.
    for (int i = s + 1; i < d; i++)
    {
        // s�� ������ i�� �������� �ּ� ��ݰ�
        // i�� ������ d�� �������� �ּ� ����� ��
        int temp = minCost(s, i) + minCost(i, d);
        if (temp < minValue)
            minValue = temp;
    }
    return minValue;
}

int main()
{
    int s = 0;
    int d = 3;
    printf("%d�� ������ %d�� �������� �ּ� ����� %d�Դϴ�.\n",
        s, d, minCost(s, d));
    return 0;
}