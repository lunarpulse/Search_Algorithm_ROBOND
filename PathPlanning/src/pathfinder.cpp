#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "pathfinder.hpp"
#include <fstream>
#include "matplotlibcpp.h" //Graph Library

using namespace std;
namespace plt = matplotlibcpp;

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  Map
 * Description:  constructor
 *------------------------------------------------------------------------------
 */
Map::Map (int width, int height, vector < vector < int >>gridIn)
{
  mapWidth = width;
  mapHeight = height;
  grid.assign (gridIn.begin (), gridIn.end ());
}				/* -----  end of method Map::Map  (constructor)  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  Map
 * Description:  copy constructor
 *------------------------------------------------------------------------------
 */
Map::Map (const Map & other)
{
  mapWidth = other.mapWidth;
  mapHeight = other.mapHeight;
  grid.assign (other.grid.begin (), other.grid.end ());
}				/* -----  end of method Map::Map  (copy constructor)  ---- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  ~Map
 * Description:  destructor
 *------------------------------------------------------------------------------
 */
Map::~Map ()
{
}				/* -----  end of method Map::~Map  (destructor)  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  operator =
 * Description:  assignment operator
 *------------------------------------------------------------------------------
 */
Map & Map::operator = (const Map & other)
{
  if (this != &other)
    {
    }
  return *this;
}				/* -----  end of method Map::operator =  (assignment operator)  --- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  get_mapHeight
 *------------------------------------------------------------------------------
 */
inline int
     Map::get_mapHeight () const
     {
       return mapHeight;
     }				/* -----  end of method Map::get_mapHeight  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  set_mapHeight
 *------------------------------------------------------------------------------
 */
     inline void Map::set_mapHeight (int value)
{
  mapHeight = value;
  return;
}				/* -----  end of method Map::set_mapHeight  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  get_mapWidth
 *------------------------------------------------------------------------------
 */
inline int
     Map::get_mapWidth () const
     {
       return mapWidth;
     }				/* -----  end of method Map::get_mapWidth  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  set_mapWidth
 *------------------------------------------------------------------------------
 */
     inline void Map::set_mapWidth (int value)
{
  mapWidth = value;
  return;
}				/* -----  end of method Map::set_mapWidth  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  get_grid
 *------------------------------------------------------------------------------
 */
inline vector < vector < int >>
     Map::get_grid () const
     {
       return grid;
     }				/* -----  end of method Map::get_grid  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  set_grid
 *------------------------------------------------------------------------------
 */
	inline
void Map::set_grid (vector < vector < int >>value)
{
  grid = value;
  return;
}				/* -----  end of method Map::set_grid  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  get_heuristic
 *------------------------------------------------------------------------------
 */
inline vector<vector<int>>
Map::get_heuristic (  ) const
{
	return heuristic;
}		/* -----  end of method Map::get_heuristic  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  set_heuristic
 *------------------------------------------------------------------------------
 */
	inline void
Map::set_heuristic ( vector<vector<int>> value )
{
	heuristic	= value;
	return ;
}		/* -----  end of method Map::set_heuristic  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  get_map
 *------------------------------------------------------------------------------
 */
inline vector<vector<double>>
Map::get_map (  ) const
{
	return map;
}		/* -----  end of method Map::get_map  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Map
 *      Method:  set_map
 *------------------------------------------------------------------------------
 */
	inline void
Map::set_map ( vector<vector<double>> value )
{
	map	= value;
	return ;
}		/* -----  end of method Map::set_map  ----- */

	void
Map::Set_Heuristic ( vector<vector<int>> heuristicIn )
{
	heuristic.assign (heuristicIn.begin (), heuristicIn.end ());
	return ;
}		/* -----  end of method Map::Set_Heuristic  ----- */

vector<vector<double> > Map::GetMap(string mapFile)
{
	vector<vector<double> > mymap(mapHeight, vector<double>(mapWidth));
	ifstream myReadFile;
	myReadFile.open(mapFile);

	while (!myReadFile.eof()) {
		for (int i = 0; i < mapHeight; i++) {
			for (int j = 0; j < mapWidth; j++) {
				myReadFile >> mymap[i][j];
			}
		}
	}
	return mymap;
}
vector<vector<int> > Map::MaptoGrid()
{
	vector<vector<int> > grid(mapHeight, vector<int>(mapWidth));
	for (int x = 0; x < mapHeight; x++) {
		for (int y = 0; y < mapWidth; y++) {
			if (map[x][y] == 0) //unkown state
				grid[x][y] = 1;

			else if (map[x][y] > 0) //Occupied state
				grid[x][y] = 1;

			else //Free state
				grid[x][y] = 0;
		}
	}

	return grid;
}

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  Planner
 * Description:  constructor
 *------------------------------------------------------------------------------
 */
Planner::Planner (int startIn[], int goalIn[], int costIn,
		  string movements_arrowsIn[],
		  vector < vector < int >>movementsIn)
{
  start[0] = startIn[0];
  start[1] = startIn[1];

  goal[0] = goalIn[0];
  goal[1] = goalIn[1];

  cost = costIn;
  movements_arrows[0] = movements_arrowsIn[0];
  movements_arrows[1] = movements_arrowsIn[1];
  movements_arrows[2] = movements_arrowsIn[2];
  movements_arrows[3] = movements_arrowsIn[3];
  movements = movementsIn;
}				/* -----  end of method Planner::Planner  (constructor)  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  Planner
 * Description:  copy constructor
 *------------------------------------------------------------------------------
 */
Planner::Planner (const Planner & other)
{
  start[0] = other.start[0];
  start[1] = other.start[1];

  goal[0] = other.goal[0];
  goal[1] = other.goal[1];

  cost = cost;
  movements = other.movements;
  movements_arrows[0] = other.movements_arrows[0];
  movements_arrows[1] = other.movements_arrows[1];
  movements_arrows[2] = other.movements_arrows[2];
  movements_arrows[3] = other.movements_arrows[3];

}				/* -----  end of method Planner::Planner  (copy constructor)  ---- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  ~Planner
 * Description:  destructor
 *------------------------------------------------------------------------------
 */
Planner::~Planner ()
{
}				/* -----  end of method Planner::~Planner  (destructor)  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  operator =
 * Description:  assignment operator
 *------------------------------------------------------------------------------
 */
Planner & Planner::operator = (const Planner & other)
{
  if (this != &other)
    {
    }
  return *this;
}				/* -----  end of method Planner::operator =  (assignment operator)  --- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_start
 *------------------------------------------------------------------------------
 */
inline const int *
     Planner::get_start () const
     {
       return start;
     }				/* -----  end of method Planner::get_start  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_start
 *------------------------------------------------------------------------------
 */
     inline void Planner::set_start (int value[2])
{
  start[0] = value[0];
  start[1] = value[1];
  return;
}				/* -----  end of method Planner::set_start  ----- */


/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_goal
 *------------------------------------------------------------------------------
 */
inline const int *
     Planner::get_goal () const
     {
       return goal;
     }				/* -----  end of method Planner::get_goal  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_goal
 *------------------------------------------------------------------------------
 */
     inline void Planner::set_goal (int value[2])
{
  goal[0] = value[0];
  goal[0] = value[0];
  return;
}				/* -----  end of method Planner::set_goal  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_cost
 *------------------------------------------------------------------------------
 */
inline int
     Planner::get_cost () const
     {
       return cost;
     }				/* -----  end of method Planner::get_cost  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_cost
 *------------------------------------------------------------------------------
 */
     inline void Planner::set_cost (int value)
{
  cost = value;
  return;
}				/* -----  end of method Planner::set_cost  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_movements_arrows
 *------------------------------------------------------------------------------
 */
inline const string *
     Planner::get_movements_arrows () const
     {
       return movements_arrows;
     }				/* -----  end of method Planner::get_movements_arrows  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_movements_arrows
 *------------------------------------------------------------------------------
 */
     inline void Planner::set_movements_arrows (string value[4])
{
  movements_arrows[0] = value[0];
  movements_arrows[1] = value[1];
  movements_arrows[2] = value[2];
  movements_arrows[3] = value[3];
  return;
}				/* -----  end of method Planner::set_movements_arrows  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_movements
 *------------------------------------------------------------------------------
 */
inline vector < vector < int >>
     Planner::get_movements () const
     {
       return movements;
     }				/* -----  end of method Planner::get_movements  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_movements
 *------------------------------------------------------------------------------
 */
     inline void Planner::set_movements (vector < vector < int >>value)
{
  movements = value;
  return;
}				/* -----  end of method Planner::set_movements  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  get_path
 *------------------------------------------------------------------------------
 */
inline vector<vector<int>>
Planner::get_path (  ) const
{
	return path;
}		/* -----  end of method Planner::get_path  ----- */

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  set_path
 *------------------------------------------------------------------------------
 */
	inline void
Planner::set_path ( vector<vector<int>> value )
{
	path	= value;
	return ;
}		/* -----  end of method Planner::set_path  ----- */

	void
Planner::Path_push_back ( vector<int> input )
{
	path.push_back(input);
	return ;
}		/* -----  end of method Planner::Path_push_back  ----- */

void
Planner::set_heuristic(Map* map){
  vector<vector<int>> heuristic;
  for(int i = 0; i < map->get_mapHeight(); i++)
  {
    vector<int> row_heuristic;
    for(int j = 0; j < map->get_mapWidth(); j++)
    {
      row_heuristic.push_back( goal[0] - i + goal[1] - j );
    }
    heuristic.push_back(row_heuristic);
  }
  map->Set_Heuristic(heuristic); 
}
string
Planner::get_string_start ()
{
  string startstring ("");
  startstring = to_string (start[0]) + " , " + to_string (start[1]);
  return startstring;
}				/* -----  end of method Planner::get_string_start  ----- */

string
Planner::get_string_goal ()
{
  string goalstring ("");
  goalstring = to_string (this->goal[0]) + " , " + to_string (goal[1]);
  return goalstring;
}				/* -----  end of method Planner::get_string_goal  ----- */

string
Planner::get_string_movements_arrows ()
{
  return movements_arrows[0] + " , " + movements_arrows[1] + " , " +
    movements_arrows[2] + " , " + movements_arrows[3];
}				/* -----  end of method Planner::get_string_movements  ----- */

vector < vector < int >>
Planner::get_string_movements ()
{
  return movements;
}				/* -----  end of method Planner::get_string_movements  ----- */

template < typename T > void
print2DVectorUnsorted (vector < vector < T > >vec)
{
  // Sorting the vector for grading purpose
  //sort (vec.begin (), vec.end ());
for (const auto v:vec)
    {
    for (const auto p:v)
	{
	  cout << p << "  ";
	}
      cout << endl;
    }
}

template < typename T > void
print2DVector (vector < vector < T > >vec)
{
  // Sorting the vector for grading purpose
  sort (vec.begin (), vec.end ());
for (const auto v:vec)
    {
    for (const auto p:v)
	{
	  cout << p << "  ";
	}
      cout << endl;
    }
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  BFS_shortestPath
 *  Description: search a route in a map with a planner
 * =============================================================================
 */
void
BFS_shortestPath(Map * map, Planner * planner)
{

  const int mapGridXsize = map->get_grid ().size ();
  const int mapGridYsize = map->get_grid ()[0].size ();
  const int movment_size = planner->get_movements ().size ();

  vector < vector < int >>explored (map->get_mapHeight (),
				    vector < int >(map->get_mapWidth (), 0));
  explored[planner->get_start ()[0]][planner->get_start ()[1]] = 1;

  vector < vector <int>>action(map->get_mapHeight (),
				    vector < int >(map->get_mapWidth (), -1));
  vector < vector < int >>expanded (map->get_mapHeight (),
				    vector < int >(map->get_mapWidth (), -1));
  int x = planner->get_start ()[0];
  int y = planner->get_start ()[1];
  int g = 0;
  int f = g + map->get_heuristic()[x][y];

  vector < vector < int >>open;
  open.push_back ( {f, g, x, y});

  const int *planGoal;
  planGoal = planner->get_goal ();

  bool foundGoal = false;
  bool resignSearch = false;

  int x2, y2, seq = 0;

  while (!foundGoal && !resignSearch )
    {
      if (open.size () == 0)
	{
	  resignSearch = true;
	  cout << "No open route, giving up the search!" << endl;
	}
      else
	{
	  sort (open.begin (), open.end ());
	  reverse (open.begin (), open.end ());
	  vector < int >next;
	  next = open.back ();	// the last one to the next vector
	  open.pop_back ();	// remove the poped one to the next

	  expanded[next[2]][next[3]] = seq++;

	  if (next[2] == planGoal[0] && next[3] == planGoal[1])
	    {
	     foundGoal= true;
	     cout <<  "[" << next[0] << ", " << next[1] << ", " << next[2] << ", " << next[3] <<
		"]" << endl;
	    }
	  else
	    {
	      for (int i = 0; i < movment_size; ++i)
		{
		  x = next[2];
		  y = next[3];
		  g = next[1];
//		  f = next[0];

		  x2 = x + planner->get_movements ()[i][0];
		  y2 = y + planner->get_movements ()[i][1];
		  if (x2 >= 0 && x2 < mapGridXsize && y2 >= 0
		      && y2 < mapGridYsize)
		    {
		      if (explored[x2][y2] ==
			  0 and map->get_grid ()[x2][y2] == 0)
			{
				int newG = g + planner->get_cost ();
				int newF = newG + map->get_heuristic()[x2][y2];
			  open.push_back (
					   {
					   newF, newG, x2, y2}
			  );
			  explored[x2][y2] = 1;
			  action[x2][y2] = i; 
			}
		    }
		}
	    }

	}
    }
  
  print2DVector (expanded);
  print2DVector (action);
  int pX, pY;
  pX = planGoal[0];
  pY = planGoal[1]; 
  vector < vector <string>>arrows(map->get_mapHeight (),
		  vector < string>(map->get_mapWidth (),"-"));
  arrows[pX][pY] = "*";

  while ( pX != planner->get_start()[0] || pY!= planner->get_start()[1]){
	  x2 = pX - planner->get_movements ()[action[pX][pY]][0];
	  y2 = pY - planner->get_movements ()[action[pX][pY]][1];
	  arrows[x2][y2] = planner->get_movements_arrows()[action[pX][pY]] ;
	  planner->Path_push_back({x2,y2});
	  pX = x2;
	  pY = y2;
  }

  print2DVectorUnsorted (arrows);
  return;
}				/* -----  end of function search  ----- */
/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  BFS_search_expand
 *  Description: search a route in a map with a planner
 * =============================================================================
 */
void
BFS_search_expand (Map * map, Planner * planner)
{

  const int mapGridXsize = map->get_grid ().size ();
  const int mapGridYsize = map->get_grid ()[0].size ();
  const int movment_size = planner->get_movements ().size ();

  vector < vector < int >>explored (map->get_mapHeight (),
				    vector < int >(map->get_mapWidth (), 0));
  explored[planner->get_start ()[0]][planner->get_start ()[1]] = 1;
  vector < vector < int >>expanded (map->get_mapHeight (),
				    vector < int >(map->get_mapWidth (), -1));

  int x = planner->get_start ()[0];
  int y = planner->get_start ()[1];
  int g = 0;

  vector < vector < int >>open;
  open.push_back ( { g, x, y});

  const int *planGoal;
  planGoal = planner->get_goal ();

  bool foundGoal = false;
  bool resignSearch = false;

  int x2, y2, seq = 0;

  while (!foundGoal && !resignSearch )
    {
      if (open.size () == 0)
	{
	  resignSearch = true;
	  cout << "No open route, giving up the search!" << endl;
	}
      else
	{
	  sort (open.begin (), open.end ());
	  reverse (open.begin (), open.end ());
	  vector < int >next;
	  next = open.back ();	// the last one to the next vector
	  open.pop_back ();	// remove the poped one to the next


	  expanded[next[1]][next[2]] = seq++;

	  if (next[1] == planGoal[0] && next[2] == planGoal[1])
	    {
	     foundGoal= true;
	     cout << "[" << next[0] << ", " << next[1] << ", " << next[2] <<
		"]" << endl;
	    }
	  else
	    {
	      for (int i = 0; i < movment_size; ++i)
		{
		  x = next[1];
		  y = next[2];
		  g = next[0];
		  x2 = x + planner->get_movements ()[i][0];
		  y2 = y + planner->get_movements ()[i][1];
		  if (x2 >= 0 && x2 < mapGridXsize && y2 >= 0
		      && y2 < mapGridYsize)
		    {
		      if (explored[x2][y2] ==
			  0 and map->get_grid ()[x2][y2] == 0)
			{
			  open.push_back (
					   {
					   g + planner->get_cost (), x2, y2}
			  );
			  explored[x2][y2] = 1;
			}
		    }
		}
	    }

	}
    }

  print2DVector (expanded);
  return;
}				/* -----  end of function search  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  BFS_search
 *  Description: search a route in a map with a planner
 * =============================================================================
 */
void
BFS_search (Map * map, Planner * planner)
{

  const int mapGridXsize = map->get_grid ().size ();
  const int mapGridYsize = map->get_grid ()[0].size ();
  const int movment_size = planner->get_movements ().size ();

  vector < vector < int >>explored (map->get_mapHeight (),
				    vector < int >(map->get_mapWidth ()));
  explored[planner->get_start ()[0]][planner->get_start ()[1]] = 1;

  int x = planner->get_start ()[0];
  int y = planner->get_start ()[1];
  int g = 0;

  vector < vector < int >>open;
  open.push_back (
		   {
		   g, x, y});
  const int *planGoal;
  planGoal = planner->get_goal ();

  bool foundGoal = false;
  bool resignSearch = false;

  int x2, y2;

  while (!foundGoal && !resignSearch)
    {
      if (open.size () == 0)
	{
	  resignSearch = true;
	  cout << "No open route, giving up the search!" << endl;
	}
      else
	{
	  sort (open.begin (), open.end ());
	  reverse (open.begin (), open.end ());
	  vector < int >next;
	  next = open.back ();	// the last one to the next vector
	  open.pop_back ();	// remove the poped one to the next

	  if (next[1] == planGoal[0] && next[2] == planGoal[1])
	    {
	      foundGoal = true;
	      cout << "[" << next[0] << ", " << next[1] << ", " << next[2] <<
		"]" << endl;
	    }
	  else
	    {
	      for (int i = 0; i < movment_size; ++i)
		{
		  x = next[1];
		  y = next[2];
		  g = next[0];
		  x2 = x + planner->get_movements ()[i][0];
		  y2 = y + planner->get_movements ()[i][1];
		  if (x2 >= 0 && x2 < mapGridXsize && y2 >= 0
		      && y2 < mapGridYsize)
		    {
		      if (explored[x2][y2] ==
			  0 and map->get_grid ()[x2][y2] == 0)
			{
			  open.push_back (
					   {
					   g + planner->get_cost (), x2, y2}
			  );
			  explored[x2][y2] = 1;
			}
		    }
		}
	    }

	}
    }
  return;
}				/* -----  end of function search  ----- */

void visualization(Map* map, Planner* planner)
{

	plt::title("Path");
	plt::xlim(0, map->get_mapHeight());
	plt::ylim(0, map->get_mapWidth());
        int map_height = map->get_mapHeight();
	int map_width = map->get_mapWidth();

	for (double x = 0; x < map_height; x++) {
		cout << "Remaining Rows= " << map_height - x << endl;
		for (double y = 0; y < map_width; y++) {
			if (map->get_map()[x][y] == 0) { 
				plt::plot({ x }, { y }, "g.");
			}
			else if (map->get_map()[x][y] > 0) { 
				plt::plot({ x }, { y }, "k.");
			}
			else { 
				plt::plot({ x }, { y }, "r.");
			}
		}
	}


	plt::plot({ (double)planner->get_start()[0] }, { (double)planner->get_start()[1] }, "bo");
	plt::plot({ (double)planner->get_goal()[0] }, { (double)planner->get_goal()[1] }, "b*");

	int path_size = planner->get_path().size();
	for (int i = 0; i < path_size; i++) {
		plt::plot({ (double)planner->get_path()[i][0] }, { (double)planner->get_path()[i][1] }, "b.");
	}


	plt::save("./Images/Path.png");
	plt::clf();
}

int
main ()
{
  // Instantiate map and planner objects
  const int width = 150, height = 300;
  vector < vector < int >>grid = {
    {
     0, 1, 0, 0, 0, 0},
    {
     0, 1, 0, 0, 0, 0},
    {
     0, 1, 0, 0, 0, 0},
    {
     0, 1, 0, 0, 0, 0},
    {
     0, 0, 0, 1, 1, 0}
  };

  Map *map = new Map (width, height, grid);
  map->set_map( map->GetMap("./resource/map.txt"));
  map->set_grid( map->MaptoGrid());

  int start[2] = {
    230, 145 
  };
  int goal[2] = {
    60, 50 
  };
  int cost = 1;

  string movements_arrows[4] = {
    "^", "<", "v", ">"
  };

  vector < vector < int >>movements
  {
    {
    -1, 0},
    {
    0, -1},
    {
    1, 0},
    {
  0, 1}};
  Planner *planner =
    new Planner (start, goal, cost, movements_arrows, movements);
  planner->set_heuristic(map);
  print2DVectorUnsorted (map->get_heuristic());

  // Print classes variables
  cout << "Map:" << endl;
  print2DVector (map->get_grid ());
  cout << "Start: " << planner->get_string_start () << endl;
  cout << "Goal: " << planner->get_string_goal () << endl;
  cout << "Cost: " << planner->get_cost () << endl;
  cout << "Robot Movements: " << planner->get_string_movements_arrows () <<
    endl;
  cout << "Delta:" << endl;
  print2DVector (planner->get_movements ());

//  BFS_search (map, planner);
  BFS_shortestPath(map, planner);
  visualization(map, planner);
  return 0;
}
