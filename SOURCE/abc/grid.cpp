#include "grid.h"
void Grid::load_grid()
{
    for(int i=0;i<GRID_SIZE;i++)
    {
        for(int j=0;j<GRID_SIZE;j++)
            grid[i][j]=rand()%5;
    }
    // Remove any Matches
    vector<int>tmp(6,0); // Store coordinates
    while(point_move(tmp))
        update_grid(tmp);
}

bool Grid::valid_move(int x0, int y0, int x1, int y1)
{
    // Check if move is valid
    if( (x0+1==x1 && y0==y1) || (x0-1==x1 && y0==y1) || (x0==x1 && y0+1==y1) ||(x0==x1 && y0-1==y1))
    {
        swap(grid[x0][y0],grid[x1][y1]);
        return true;
    }
    else
        return false;
}

int Grid::get_shape(int i,int j)
{
    return grid[i][j];
}

bool Grid::point_move(vector<int>&tmp)
{
    int x,y;
    for(int i=0;i<GRID_SIZE;i++)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            x=i;
            y=j;
            // Check Horizontal
        if(x<GRID_SIZE-2 && grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x+2][y])
        {
            tmp[0]=x;tmp[1]=x+1;tmp[2]=x+2;
            tmp[3]=y;tmp[4]=y;tmp[5]=y;
            return true;
        }
        else if(x<GRID_SIZE-1 && x>0 && grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x-1][y])
        {
            tmp[0]=x-1;tmp[1]=x;tmp[2]=x+1;
            tmp[3]=y;tmp[4]=y;tmp[5]=y;
            return true;
        }
        else if(x>1 && grid[x][y]==grid[x-1][y] && grid[x][y]==grid[x-2][y])
        {
            tmp[0]=x-2;tmp[1]=x-1;tmp[2]=x;
            tmp[3]=y;tmp[4]=y;tmp[5]=y;
            return true;
        }
        // Check Vertical
        else if(y<GRID_SIZE-2 && grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y+2])
        {
            tmp[0]=x;tmp[1]=x;tmp[2]=x;
            tmp[3]=y;tmp[4]=y+1;tmp[5]=y+2;
            return true;
        }
        else if(y<GRID_SIZE-1 && y>0 && grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y-1])
        {
            tmp[0]=x;tmp[1]=x;tmp[2]=x;
            tmp[3]=y-1;tmp[4]=y;tmp[5]=y+1;
            return true;
        }
        else if(y>1 && grid[x][y]==grid[x][y-1] && grid[x][y]==grid[x][y-2])
        {
            tmp[0]=x;tmp[1]=x;tmp[2]=x;
            tmp[3]=y-2;tmp[4]=y-1;tmp[5]=y;
            return true;
        }

        }
    }
    return false;
}

void Grid::update_grid(vector<int>&pos)
{
    int num=rand()%5;
    if(pos[0]==pos[2]) // Horizontal Match, Row is Constant
    {
        int j=pos[0];
        while(j>0)
        {
            grid[j][pos[3]]=grid[j-1][pos[3]];
            grid[j][pos[4]]=grid[j-1][pos[4]];
            grid[j][pos[5]]=grid[j-1][pos[5]];
            j--;
        }
        grid[0][pos[3]]= ++num % 5;
        grid[0][pos[4]]= ++num % 5;
        grid[0][pos[5]]= ++num % 5;

    }
    else // Vertical Match , Column is constant
    {
        int column=pos[3];
        int j=pos[2];
        while(j>2)
        {
            grid[j][column]=grid[j-3][column];
            j--;
        }
        grid[0][column]= ++num % 5;
        grid[1][column]= ++num % 5;
        grid[2][column]= ++num % 5;
    }
}
