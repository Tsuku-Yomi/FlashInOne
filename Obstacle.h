#pragma once

#include <vector>
#include <utility>
#include <ctime>


class Obstacle : public Entity
{
public:
	Obstacle();	//�չ��캯��
	Obstacle(int inum, int count, int lnum[], int lpr[]);	//��׼���캯��
	~Obstacle();//��������
	int Drop();	//���亯��,���ص�����ʵ����

	bool existence;//�����ж� 

private:
	int num;	//�ϰ���ʵ����

	std::vector <std::pair<int, int>> litters;	//������ʵ����,����
};

