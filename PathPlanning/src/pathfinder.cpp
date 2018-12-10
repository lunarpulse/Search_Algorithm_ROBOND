#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "pathfinder.hpp"

using namespace std;

/* TODO: Define a Map class
   Inside the map class, define the mapWidth, mapHeight and grid as a 2D vector
*/

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

	vector<vector<int> >
Map::get_grid ()
{
	return grid;
}		/* -----  end of method Map::get_grid  ----- */

/* TODO: Define a Planner class
   Inside the Planner class, define the start, goal, cost, movements, and movements_arrows
   Note: The goal should be defined it terms of the mapWidth and mapHeight
*/

/*
 *------------------------------------------------------------------------------
 *       Class:  Planner
 *      Method:  Planner
 * Description:  constructor
 *------------------------------------------------------------------------------
 */
Planner::Planner (int startIn[], int goalIn[], int costIn,
		  string  movements_arrowsIn[],
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
//  movements_arrows.assign (movements_arrowsIn.begin (), movements_arrowsIn.end ());
//  movements.assign (movementsIn.begin (), movementsIn.end ());
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
//  movements_arrows.assign (other.movements_arrows.begin (), other.movements_arrows.end ());
//  movements.assign (other.movements.begin (), other.movements.end ());

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

	string
Planner::get_start ()
{
	string startstring("");
	startstring =to_string( start[0]) + " , " +to_string(start[1]);
	return startstring;
}		/* -----  end of method Planner::get_start  ----- */

	string
Planner::get_goal (  )
{
	string goalstring("");
        goalstring=to_string( this->goal[0]) + " , " +to_string( goal[1]);
	return goalstring;
}		/* -----  end of method Planner::get_goal  ----- */

	int
Planner::get_cost (  )
{
	return  cost;
}		/* -----  end of method Planner::get_cost  ----- */

	string
Planner::get_movements_arrows(  )
{
	return movements_arrows[0] +" , " +movements_arrows[1] +" , " +movements_arrows[2] +" , " +movements_arrows[3] ;
}		/* -----  end of method Planner::get_movements  ----- */

	vector<vector<int>>
Planner::get_movements ()
{
	return movements;
}		/* -----  end of method Planner::get_movements  ----- */

/* TODO: Define a print2DVector function which will print 2D vectors of any data type
   Example
   
   Input: 
   vector<vector<int> > a{{ 1, 0 },{ 0, 1 }};
   print2DVector(a);
   vector<vector<string> > b{{ "a", "b" },{ "c", "d" }};
   print2DVector(b);
   
   Output:
   1 0
   0 1
   a b
   c d
   Hint: You need to use templates
*/
template<typename T>
void
print2DVector (vector < vector < T> >vec)
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

int
main ()
{
  // Instantiate map and planner objects
  const int
    width = 6, height = 5;
  vector < vector < int >>
  grid = { {0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0}
  };

  Map*
    map = new Map (width, height, grid);

  int
  start[2] = { 0, 0 };
  int
  goal[2] = { height - 1, width - 1 };
  int
    cost = 1;

  string
  movements_arrows[4] = { "^", "<", "v", ">" };

  vector < vector < int >>
    movements
  {
    {
    -1, 0},
    {
    0, -1},
    {
    1, 0},
    {
  0, 1}};
  Planner*
    planner = new Planner (start, goal, cost, movements_arrows, movements);

  // Print classes variables
  cout << "Map:" << endl;
  print2DVector (map->get_grid());
  cout << "Start: " << planner->get_start() << endl;
  cout << "Goal: " << planner->get_goal()<< endl;
  cout << "Cost: " << planner->get_cost() << endl;
  cout << "Robot Movements: " << planner->get_movements_arrows()<< endl;
  cout << "Delta:" << endl;
  print2DVector (planner->get_movements());

  return 0;
}
