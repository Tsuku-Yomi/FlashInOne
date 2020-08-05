#include "Obstacle.h"


Obstacle::Obstacle()
{
	num = 0;
	existence = false;
	litters.clear();
}




Obstacle::Obstacle(int inum, int count, int lnum[], int lpr[])
{//分别表示传入:障碍物实体编号,掉落物数量,掉落物实体编号数组,掉落物概率数组

	num = inum;
	litters.clear();//清空掉落表
	if (num)//当障碍物实体编号不为0时
	{
		for (int judge = 0; judge < count; judge++)
		{
			litters.push_back(std::make_pair(lnum[judge], lpr[judge]));//传入掉落物实体编号,掉落物概率
		}
		existence = true;
	}
	else existence = false;
}


Obstacle::~Obstacle()
{
	num = 0;
	existence = false;
	litters.clear();
}


bool Obstacle::Drop(int* item_1, int* item_2)//掉落函数
{
	int result = 0;//抽奖结果变量
	bool multiple = false;//掉落多物品变量
	if (num)
	{
		int total = 0;//概率总数
		int size = 0;//容器大小
		int judge = 0;//判断条件
		size = (int)litters.size();//获取容器元素个数
		for (judge = 0; judge < size; judge++)
		{
			total += litters[judge].second;//总概率
		}
		srand((unsigned)time(NULL));//产生随机种子
		result = (int)rand();//刷新rand函数?
		result = (int)(((double)rand() / RAND_MAX) * total);//获取随机结果
		multiple = result % 2;//利用随机结果获取是否掉落多物品
		for (judge = 0, total = litters[0].second; judge < size; judge++)
		{
			if (result <= total)//若结果小于当前概率
			{
				break;//则此时judge为选中的掉落物于掉落表中的位置
			}
			else total += litters[judge].second;//否则排除
		}
		*item_1 = litters[judge].first;//返回抽中的掉落物实体编号
		if (multiple)
		{//若掉落多个物品(2个)
			result = (int)(((double)rand() / RAND_MAX) * total);
			for (judge = 0, total = litters[0].second; judge < size; judge++)
			{
				if (result <= total)
				{
					break;
				}
				else total += litters[judge].second;
			}
			*item_2 = litters[judge].first;
		}
		else *item_2 = 0;//无物品(即掉落金币)
	}
	else
	{
		*item_1 = 0;
		*item_2 = 0;
	}
	existence = false;
	return multiple;
}
