#include "Obstacle.h"


Obstacle::Obstacle()//空构造函数
{
	num = 0;//障碍物实体编号=0
	existence = false;//该障碍物不存在
	litters.clear();//清空掉落表
}




Obstacle::Obstacle(int inum, int count, int lnum[], int lpr[])
{//分别表示传入:障碍物实体编号,掉落物数量,掉落物实体编号数组,掉落物概率数组

	num = inum;//输入障碍物实体编号
	litters.clear();//清空掉落表
	if (num)//当障碍物实体编号不为0时
	{
		for (int judge = 0; judge < count; judge++)
		{
			litters.push_back(std::make_pair(lnum[judge], lpr[judge]));//传入掉落物实体编号,掉落物概率
		}
		existence = true;//该障碍物存在
	}
	else existence = false;//该障碍物不存在
}


Obstacle::~Obstacle()//析构函数,释放内存
{
	num = 0;//障碍物实体编号=0
	existence = false;//该障碍物不存在
	litters.clear();//清空掉落表
}


int Obstacle::Drop()//掉落函数
{
	int result = 0;//抽奖结果变量
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
		for (judge = 0, total = litters[0].second; judge < size; judge++)
		{
			if (result <= total)//若结果小于当前概率
			{
				break;//则此时judge为选中的掉落物于掉落表中的位置
			}
			else total += litters[judge].second;//否则排除
		}
		result = litters[judge].first;//返回抽中的掉落物实体编号
	}
	else result = 0;
	delete this;//删除该类
	return result;
}