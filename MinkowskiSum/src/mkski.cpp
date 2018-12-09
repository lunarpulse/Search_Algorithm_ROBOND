#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Print 2D vectors coordinate values
void
print2DVector (vector < vector < int > >vec)
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

// *** Check for duplicate coordinates inside a 2D vector and delete them*** //
vector < vector < int >>
delete_duplicate (vector < vector < int > >C)
{
  set < vector < int >>s (C.begin (), C.end ());

  vector < vector < int >>R;
  R.assign (s.begin (), s.end ());

  return R;

}

// *** Compute the Minkowski Sum of two vectors***//
vector < vector < int >>
minkowski_sum (vector < vector < int > >A, vector < vector < int > >B)
{

  vector < vector < int >>C;
for (const auto a:A)
    {
    for (const auto b:B)
	{
	  vector < int >R = { a[0] + b[0], a[1] + b[1] };
	  C.push_back (R);
	}
    }

  C = delete_duplicate (C);
  return C;
}

int
main ()
{
  // *** Define the coordinates of triangle A and B using 2D vectors*** //
  vector < vector < int >>A = { {1, 0}, {0, 1}, {0, -1}, };
  vector < vector < int >>B = { {0, 0}, {1, 1}, {1, -1}, };
  // Compute the minkowski sum of triangle A and B
  vector < vector < int >>C;
  C = minkowski_sum (A, B);

  // Print the resulting vector
  print2DVector (C);

  return 0;
}
