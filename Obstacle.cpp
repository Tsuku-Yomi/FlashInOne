#include "Obstacle.h"


Obstacle::Obstacle()//�չ��캯��
{
	num = 0;//�ϰ���ʵ����=0
	existence = false;//���ϰ��ﲻ����
	litters.clear();//��յ����
}




Obstacle::Obstacle(int inum, int count, int lnum[], int lpr[])
{//�ֱ��ʾ����:�ϰ���ʵ����,����������,������ʵ��������,�������������

	num = inum;//�����ϰ���ʵ����
	litters.clear();//��յ����
	if (num)//���ϰ���ʵ���Ų�Ϊ0ʱ
	{
		for (int judge = 0; judge < count; judge++)
		{
			litters.push_back(std::make_pair(lnum[judge], lpr[judge]));//���������ʵ����,���������
		}
		existence = true;//���ϰ������
	}
	else existence = false;//���ϰ��ﲻ����
}


Obstacle::~Obstacle()//��������,�ͷ��ڴ�
{
	num = 0;//�ϰ���ʵ����=0
	existence = false;//���ϰ��ﲻ����
	litters.clear();//��յ����
}


int Obstacle::Drop()//���亯��
{
	int result = 0;//�齱�������
	if (num)
	{
		int total = 0;//��������
		int size = 0;//������С
		int judge = 0;//�ж�����
		size = (int)litters.size();//��ȡ����Ԫ�ظ���
		for (judge = 0; judge < size; judge++)
		{
			total += litters[judge].second;//�ܸ���
		}
		srand((unsigned)time(NULL));//�����������
		result = (int)rand();//ˢ��rand����?
		result = (int)(((double)rand() / RAND_MAX) * total);//��ȡ������
		for (judge = 0, total = litters[0].second; judge < size; judge++)
		{
			if (result <= total)//�����С�ڵ�ǰ����
			{
				break;//���ʱjudgeΪѡ�еĵ������ڵ�����е�λ��
			}
			else total += litters[judge].second;//�����ų�
		}
		result = litters[judge].first;//���س��еĵ�����ʵ����
	}
	else result = 0;
	delete this;//ɾ������
	return result;
}