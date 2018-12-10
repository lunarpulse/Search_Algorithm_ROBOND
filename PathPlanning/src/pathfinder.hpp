#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/* TODO: Define a Map class
   Inside the map class, define the mapWidth, mapHeight and grid as a 2D vector
*/

/*
 * =============================================================================
 *        Class:  Map
 *  Description:  class, define the mapWidth, mapHeight and grid as a 2D vector
 * =============================================================================
 */
class Map
{
	public:
		/* ====================  LIFECYCLE     ================================== */
		Map (int width, int height, vector<vector<int>> gridIn);                             /* constructor      */
		Map ( const Map &other );   /* copy constructor */
		~Map ();                            /* destructor       */

		/* ====================  ACCESSORS     ====================== */

		/* ====================  MUTATORS      ====================== */

		vector<vector<int> > get_grid();
		/* ====================  OPERATORS     ====================== */

		Map& operator = (const Map &other ); /*assignment operator*/

	protected:
		/* ====================  METHODS       ====================== */

		/* ====================  DATA MEMBERS  ====================== */

	private:
		/* ====================  METHODS       ====================== */

		/* ====================  DATA MEMBERS  ====================== */
		int mapWidth, mapHeight;
		vector<vector<int> > grid;

}; /* -----  end of class Map  ----- */

/* TODO: Define a Planner class
   Inside the Planner class, define the start, goal, cost, movements, and movements_arrows
   Note: The goal should be defined it terms of the mapWidth and mapHeight
*/

/*
 * =============================================================================
 *        Class:  Planner
 *  Description: Planner class 
 * =============================================================================
 */
class Planner
{
	public:
		/* ====================  LIFECYCLE     ================================== */
		Planner (int startIn[], int goalIn[], int costIn, string movements_arrowsIn[] , vector<vector<int>> movementsIn );                             /* constructor      */
		Planner ( const Planner &other );   /* copy constructor */
		~Planner ();                            /* destructor       */

		/* ====================  ACCESSORS     ====================== */
		
		/* ====================  MUTATORS      ====================== */

		string get_start();
		string get_goal();
		int get_cost();
		vector<vector<int> > get_movements();
		string get_movements_arrows();
		/* ====================  OPERATORS     ====================== */

		Planner& operator = (const Planner &other ); /*assignment operator*/

	protected:
		/* ====================  METHODS       ====================== */

		/* ====================  DATA MEMBERS  ====================== */

	private:
		/* ====================  METHODS       ====================== */

		/* ====================  DATA MEMBERS  ====================== */
		int start[2], goal[2], cost;
		string movements_arrows[4];
                vector<vector<int> > movements;

}; /* -----  end of class Planner  ----- */

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
