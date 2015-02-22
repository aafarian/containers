#include <iostream>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int findWaste(int height,int width,int spaceHeight,int spaceWidth)
{
	int totalWaste = spaceHeight*spaceWidth - height*width;
	
	cout << endl;
	cout << "totalWaste is " << totalWaste << endl;
	return totalWaste;
}




int main(int argc, char** argv) {
	
	int rows, cols, height1, height2, height3, width1, width2, width3, edge, smallestWaste;
	int spaceUnder, spaceSide, heightUnder, widthUnder, heightSide, widthSide, sideFullHeight, sideFullWidth, under, side, sideFull;
	
	
	cout << "Hello, welcome to my program. " << endl << endl;
	cout << "Please enter the rows: ";
	cin >> rows;
	cout << "Please enter the columns: ";
	cin >> cols;
	edge = cols;
	cout << endl;
	cout << "Here is your container! " << endl << endl;
	
	    char box[rows][cols];
	
	    for (int r=0; r < rows; ++r)
		{
			for (int c=0; c < cols; ++c)
			{
				box[r][c] = '.';
			}
	    }
	    for (int r=0; r < rows; ++r)
		{
			cout << "        ";
			for (int c=0; c < cols; ++c)
			{
				cout << box[r][c] << "  ";
			}
			cout << endl << endl;
	    }
	    
	    cout << "Please enter the height of the first object: ";
	    cin >> height1;
	    
	    cout << "Please enter the width of the first object: ";
	    cin >> width1;
	    
	    cout << endl;
	    
	    cout << "Inserting a " << height1 << "x" << width1 << " object... " << endl << endl;
	    
	    for (int i=0; i < height1; ++i)
	    {
	    	for (int j=0; j < width1; ++j)
	    	{
	    		box[i][j] = 'A';
	    	}
	    }
	    
	    	for (int r=0; r < rows; ++r)
			{
				cout << "        ";
				for (int c=0; c < cols; ++c)
				{
					cout << box[r][c] << "  ";
				}
				cout << endl << endl;
	    	}
	    
	    
		
			cout << "Please enter the height of the second object: ";
	    	cin >> height2;
	    
	    	cout << "Please enter the width of the second object: ";
	    	cin >> width2;
	    
	    	cout << endl;
	    
	    	cout << "Inserting a " << height2 << "x" << width2 << " object... " << endl << endl;
	    
	        
	        heightUnder = rows - height1;
	        widthUnder = width1;
	        
	        
	        heightSide = height1;
	        widthSide = cols - width1;
	        
	        sideFullHeight = rows;
	        sideFullWidth = cols - width1;
	        
	        
	        under = findWaste(height2, width2, heightUnder, widthUnder);
	        if (under == 0 || under > 0 && under < smallestWaste)
	        {
	        	smallestWaste = under;
	        	under = 1;
	        }
	        
	        
	        side = findWaste(height2, width2, heightSide, widthSide);
	        if(side == 0 || side > 0 && side < smallestWaste)
	        {
	        	smallestWaste = side;
	        	under = 0;
	        	side = 1;
	        }
	        
	        
	        sideFull = findWaste(height2, width2, sideFullHeight, sideFullWidth);
	        if (sideFull == 0 || sideFull > 0 && sideFull < smallestWaste)
	        {
	        	smallestWaste = sideFull;
	        	under = 0;
	        	side = 0;
	        	sideFull = 1;
	        }
	        
	        if (under == 1)
	        {
	        	for (int i=height1; i < height1 + height2; ++i)
	    		{
	    			for (int j=0; j < width2; ++j)
	    			{
	    				box[i][j] = 'B';
	    			}
	    		}
	        }
	        
	        if (side == 1)
	        {
	        	for (int i=0; i < height2; ++i)
	    		{
	    			for (int j=width1; j < width1 + width2; ++j)
	    			{
	    				box[i][j] = 'B';
	    			}
	    		}
	        }
	        
	        if (sideFull == 1)
	        {
	        	for (int i=0; i < height2; ++i)
	    		{
	    			for (int j=width1; j < width1 + width2; ++j)
	    			{
	    				box[i][j] = 'B';
	    			}
	    		}
	        }
	        
	        
	        
	        for (int r=0; r < rows; ++r)
			{
				cout << "        ";
				for (int c=0; c < cols; ++c)
				{
					cout << box[r][c] << "  ";
				}
				cout << endl << endl;
	    	}
	        
	        
		
				cout << "Please enter the height of the third object: ";
	    		cin >> height3;
	    
	    		cout << "Please enter the width of the third object: ";
	    		cin >> width3;
	    
	    		cout << endl;
	    
	    		cout << "Inserting a " << height3 << "x" << width3 << " object... " << endl << endl;
	    		
	    		
	    
	    
			for (int r=0; r < rows; ++r)
			{
				cout << "        ";
				for (int c=0; c < cols; ++c)
				{
					cout << box[r][c] << "  ";
				}
				cout << endl << endl;
	    	}
		
		cout << endl << edge;
	
		
	
	return 0;
}
