
#pragma once


#include <iostream>
#include <vector>

#include "AStarAlgorithm.cpp"

namespace AStar
{

	struct node
	{
		int x, y;
		
		node* parent = nullptr;

		node(int _x, int _y) { x = _x; y = _y; };
		void SetParent(node* aParent) { parent = aParent; };

	};


	struct AStarSettings
	{
		std::vector<int>	inaccessible;

		AStarSettings() {};
		AStarSettings(std::vector<int> inaccessible_ints) { inaccessible = inaccessible_ints; };
		
		bool IsAccessible(const int& anInt) {
			for (auto&&i : inaccessible) { if (anInt == i) return false; }
			return true;
		}

	};


	struct AStarResult
	{
		std::vector<std::vector<int>> map2d;

		AStarResult()
		{
			map2d = {
					{ 1, 1, 0 },
					{ 0, 1, 0 },
					{ 0, 1, 1 },
					{ 1, 1, 0 },
					{ 1, 1, 1 },
					{ 0, 0, 0 }
					};

		};


		void Print()
		{
			for (int y = 0; y < map2d.size(); y++)
			{
				for (auto&& x : map2d[y])
				{
					std::cout << x << " ";
				}
				std::cout << std::endl;
			}
		};
	};
	






	class AStarEngine
	{
	private:
		AStar::AStarSettings			m_settings;
		std::vector<AStar::node>		m_closed_set;
		std::vector<AStar::node>		m_open_set;

	public:

		AStar::AStarEngine::AStarEngine(AStar::AStarSettings settings) { m_settings = settings; };

		AStarResult GetPath(AStar::node path_start, AStar::node path_end, const std::vector< std::vector<int> >& map_data)
			{



				m_open_set.push_back(path_start);






				while (!m_open_set.empty())
				{
					node* parent_node = m_open_set



				}


				node* parent_node = &path_start;

				AStar::node node_up(path_start.x, path_start.y + 1),
							node_down(path_start.x, path_start.y - 1),
							node_right(path_start.x + 1, path_start.y),
							node_left(path_start.x - 1, path_start.y);
							
				std::vector<node> adjacent_nodes = { node_up, node_down, node_right, node_left };
				
				for (auto&& i : adjacent_nodes)
				{
					if (i.x < map_data[0].size() && i.y < map_data.size())
					{
						if (m_settings.IsAccessible(map_data[i.y][i.x]))
						{
							i.SetParent(parent_node);
							m_open_set.push_back(i);
						}
					}

				}
				m_closed_set.push_back(m_open_set[0]);

				m_open_set.erase(m_open_set.begin());

				

							

			
			
			


			
			

			};

	};








}