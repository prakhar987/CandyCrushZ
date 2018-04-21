#include <bits/stdc++.h>
#define GRID_SIZE 8
using namespace std;
class Grid {
   public:
      void load_grid();
      int get_shape(int i,int j); // Since Grid is Private
      bool valid_move(int,int,int,int);
      bool point_move(vector<int>&);
      void update_grid(vector<int>&);
   private:
     vector<vector<int>>grid=vector<vector<int>>(GRID_SIZE,vector<int>(GRID_SIZE,0));
};
