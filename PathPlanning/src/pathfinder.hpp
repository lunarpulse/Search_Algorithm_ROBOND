#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

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
  Map (int width, int height, vector < vector < int >>gridIn);	/* constructor      */
    Map (const Map & other);	/* copy constructor */
   ~Map ();			/* destructor       */

  /* ====================  ACCESSORS     ====================== */

  inline int get_mapHeight () const;
  inline void set_mapHeight (int value);
  inline int get_mapWidth () const;
  inline void set_mapWidth (int value);
  inline vector<vector<int>> get_grid (  ) const;
  inline void set_grid (vector < vector < int >>value);
  inline vector<vector<int>> get_heuristic (  ) const;
  inline void set_heuristic ( vector<vector<int>> value );
  /* ====================  MUTATORS      ====================== */

  void Set_Heuristic ( vector<vector<int>> heuristicIn );
  /* ====================  OPERATORS     ====================== */

    Map & operator = (const Map & other);	/*assignment operator */

protected:
  /* ====================  METHODS       ====================== */

  /* ====================  DATA MEMBERS  ====================== */

private:
  /* ====================  METHODS       ====================== */

  /* ====================  DATA MEMBERS  ====================== */
  int mapWidth, mapHeight;
  vector < vector < int >> grid;
  vector < vector < int >> heuristic;
};				/* -----  end of class Map  ----- */

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
  Planner (int startIn[], int goalIn[], int costIn, string movements_arrowsIn[], vector < vector < int >>movementsIn);	/* constructor      */
    Planner (const Planner & other);	/* copy constructor */
   ~Planner ();			/* destructor       */

  /* ====================  ACCESSORS     ====================== */

  inline const int *get_start () const;
  inline void set_start (int value[2] );
  inline const int* get_goal () const;
  inline void set_goal (int value[2]);
  inline int get_cost () const;
  inline void set_cost (int value);
  inline const string *get_movements_arrows () const;
  inline void set_movements_arrows (string value[] );
  inline vector < vector < int >>get_movements () const;
  inline void set_movements (vector < vector < int >>value);
  /* ====================  MUTATORS      ====================== */
  void set_heuristic(Map* map);
  string get_string_start ();
  string get_string_goal ();
  string get_movements_string_arrows ();
  string get_string_movements_arrows ();
  vector < vector < int >> get_string_movements ();
  /* ====================  OPERATORS     ====================== */

    Planner & operator = (const Planner & other);	/*assignment operator */

protected:
  /* ====================  METHODS       ====================== */

  /* ====================  DATA MEMBERS  ====================== */

private:
  /* ====================  METHODS       ====================== */

  /* ====================  DATA MEMBERS  ====================== */
  int start[2], goal[2], cost;
  string movements_arrows[4];
    vector < vector < int >>movements;

};				/* -----  end of class Planner  ----- */
