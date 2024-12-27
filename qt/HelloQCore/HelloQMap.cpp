#include "HelloQMap.h"

#include <QVector>
#include <QDebug>

void HelloQMap::QMapTest()
{
	QMap<int, QVector<float>> map;
	int cnt = 20;
	while (cnt--)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (map.contains(i))
			{
				map[i].push_back(i * 1.0);
			}
			else
			{
				QVector<float> vec;
				vec.push_back(i * 1.0);
				map.insert(i, vec);
			}
		}
	}

	for (auto iter = map.begin(); iter != map.end(); ++iter)
	{
		auto value = iter.value();
		auto key = iter.key();
	}

}
