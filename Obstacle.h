#pragma once

#include <vector>
#include <utility>
#include <ctime>


class Obstacle : public Entity
{
public:
	Obstacle();
	Obstacle(int inum, int count, int lnum[], int lpr[]);	//标准构造函数
	~Obstacle();	//析构函数
	int Drop();	//掉落函数,返回掉落物实体编号

	bool existence;//存在判定变量

private:
	int num;	//障碍物实体编号

	std::vector <std::pair<int, int>> litters;	//掉落物实体编号,概率
};

