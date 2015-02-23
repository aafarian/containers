#include <iostream>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int findWaste(int height,int width,int spaceHeight,int spaceWidth)
{
	if (spaceHeight > height || spaceHeight == height)
	{
	    if (spaceWidth > width || spaceWidth == width)
	    {
			int totalWaste = spaceHeight*spaceWidth - height*width;
	
			return totalWaste;
		}
	}
	
	int noFit = -12345;
	
	return noFit;
	
}

void cinSafeInt(int &val)
{
	cin >> val;
	
	if (cin.fail())
	{
        cin.clear();
        cin.ignore(100,'\n');
    }
}



int main(int argc, char** argv) {
	
	int rows=0, cols=0, height1=0, height2=0, height3=0, width1=0, width2=0, width3=0, smallestWaste=200, underFull=0;
	int spaceUnder=0, spaceSide=0, heightUnder=0, widthUnder=0, heightSide=0, widthSide=0, sideFullHeight=0, sideFullWidth=0, under=0, side=0, sideFull=0, underFullHeight=0, underFullWidth=0;
	int sideFull3=0, underFull3=0, sideUnderHeight=0, sideUnderWidth=0, sideUnder3=0, under3=0, mustFit=0, choice=1;
	
	cout << " ------------------------------------------------------------------" << endl;
	cout << "|             Hello, welcome to my container program!!             |" << endl;
	cout << " ------------------------------------------------------------------" << endl;
	
do
{
	cout << endl << endl;
	
	do
	{
		cout << "All right, let's make the container. " << endl << endl;
		cout << "Please enter the rows (maximum 30): ";
		cinSafeInt(rows);
	
		if (rows < 1 || rows > 30)
		{
			cout << "Please enter a valid number of rows. Choose from 1 - 30. " << endl << endl;
		}
	
	} while (rows < 1 || rows > 30);
	
	do
	{
		cout << "Please enter the columns (maximum 30): ";
		cinSafeInt(cols);
	
		if (cols < 1 || cols > 30)
		{
			cout << "Please enter a valid number of columns. Choose from 1 - 30. " << endl << endl;
		}
	
	cout << endl;
	
	
	} while ((cols < 1 || cols > 30));
	
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
	    
	    
	do
	{
	    cout << endl;
	    cout << "Let's add the first object into the container. " << endl << endl;
	    
	    do
		{
			cout << "Please enter the height of the first object (maximum 30): ";
	    	cinSafeInt(height1);
	    	
	    	if (height1 < 1 || height1 > 30)
			{
				cout << "Please enter a valid height. Choose from 1 - 30. " << endl << endl;
			}
	    	

		} while (height1 < 1 || height1 > 30);
	    
	    
	    do
		{
			cout << "Please enter the width of the first object (maximum 30): ";
	    	cinSafeInt(width1);
	    	
	    	if (width1 < 1 || width1 > 30)
			{
				cout << "Please enter a valid width. Choose from 1 - 30. " << endl << endl;
			}
	    	

		} while (width1 < 1 || width1 > 30);
	    
	    
	    cout << endl;
	    
	    cout << "Inserting a " << height1 << "x" << width1 << " object... " << endl << endl;
	    
	    mustFit = findWaste(height1, width1, rows, cols);
	    
	    if (mustFit < 0)
	    {
	    	cout << "I'm sorry, but that object doesn't fit in the space you created. " << endl << endl;
	    }
	    
	} while (mustFit < 0 || mustFit == 0);
	    
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
	    
	   	do
		{
			cout << endl;
			cout << "Let's add the second object into the container. " << endl << endl;
			  	
	    	do
			{
				cout << "Please enter the height of the second object (maximum 30): ";
	    		cinSafeInt(height2);
	    	
	    		if (height2 < 1 || height2 > 30)
				{
					cout << "Please enter a valid height. Choose from 1 - 30. " << endl << endl;
				}
	    	

			} while (height2 < 1 || height2 > 30);
	    
	    
	  	    do
			{
				cout << "Please enter the width of the second object (maximum 30): ";
	    		cinSafeInt(width2);
	    		
	    		if (width2 < 1 || width2 > 30)
				{
					cout << "Please enter a valid width. Choose from 1 - 30. " << endl << endl;
				}
	    	

			} while (width2 < 1 || width2 > 30);
	    	
	    	
	    	
	    	
	    	
	    	
	    
	    	cout << endl;
	    
	    	cout << "Inserting a " << height2 << "x" << width2 << " object... " << endl << endl;
	    
	        
	        heightUnder = rows - height1;
	        widthUnder = width1;
	        
	        
	        heightSide = height1;
	        widthSide = cols - width1;
	        
	        sideFullHeight = rows;
	        sideFullWidth = cols - width1;
	        
	        underFullHeight = rows - height1;
	        underFullWidth = cols;
	        
	        
	        
	        
	        under = findWaste(height2, width2, heightUnder, widthUnder);
	        if (under == 0 || under > 0)
	        {
	        	smallestWaste = under;
	        	under = 1;
	        }
	        
	        
	        side = findWaste(height2, width2, heightSide, widthSide);
	        if (side == 0 || (side > 0 && side < smallestWaste))
	        {
	        	smallestWaste = side;
	        	under = 0;
	        	side = 1;
	        }
	        
	        
	        sideFull = findWaste(height2, width2, sideFullHeight, sideFullWidth);
	        if (sideFull == 0 || (sideFull > 0 && sideFull < smallestWaste))
	        {
	        	smallestWaste = sideFull;
	        	under = 0;
	        	side = 0;
	        	sideFull = 1;
	        }
	        
	        underFull = findWaste(height2, width2, underFullHeight, underFullWidth);
	        if (underFull == 0 || (underFull > 0 && underFull < smallestWaste))
	        {
	        	smallestWaste = underFull;
	        	under = 0;
	        	side = 0;
	        	sideFull = 0;
	        	underFull = 1;
	        }   
	    
	        
	        if (under < 0 && side < 0 && sideFull < 0 && underFull < 0)
	    	{
	    		cout << "I'm sorry, but that object doesn't fit in the space you created. " << endl << endl;
	    	}
	        
	    } while (under < 0 && side < 0 && sideFull < 0 && underFull < 0);
	        
	        
	        
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
	        
	        if (underFull == 1)
	        {
	        	for (int i=height1; i < height1 + height2; ++i)
	    		{
	    			for (int j=0; j < width2; ++j)
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
	    	
	        
	        do
		    {
		        cout << endl;
		    	cout << "Let's add the third and final object into the container. " << endl << endl;
		
				do
				{
					cout << "Please enter the height of the third object (maximum 30): ";
	    			cinSafeInt(height3);
	    	
	    			if (height3 < 1 || height3 > 30)
					{
						cout << "Please enter a valid height. Choose from 1 - 30. " << endl << endl;
					}
	    		
	
				} while (height3 < 1 || height3 > 30);
	    	
	    	
	  	    	do
				{
					cout << "Please enter the width of the third object (maximum 30): ";
	    			cinSafeInt(width3);
	    			
	    			if (width3 < 1 || width3 > 30)
					{
						cout << "Please enter a valid width. Choose from 1 - 30. " << endl << endl;
					}
	    		

				} while (width3 < 1 || width3 > 30);
	    
	    		cout << endl;
	    
	    		cout << "Inserting a " << height3 << "x" << width3 << " object... " << endl << endl;
	    		
	    		if (under == 1)
	    		{
	    			sideUnder3 = -12345;
	    					
							underFullWidth = (cols - (width2));
							underFullHeight = (rows - height1);
							
							if (width1 == width2)
	    					{
	    						underFullHeight = (rows-(height1+height2));
								underFullWidth = (cols);	
	    					}
	    					
	    					heightUnder = (rows - (height1+height2));
	    					widthUnder = (cols);
	    					
	    					
	    					sideFullHeight = (rows);
	    					sideFullWidth = (cols-width1);
	    					
	    					
	    					smallestWaste = 2000;
	    					
	    					underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    					
	    						if (underFull3 == 0 || underFull3 > 0)
	        					{
	        						smallestWaste = underFull3;
	        						underFull3 = 1;
	        					}
	    					
	    					
	    					sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    					
								if (sideFull3 == 0 || (sideFull3 > 0 && sideFull3 < smallestWaste))
	        					{
	        						smallestWaste = sideFull3;
	        						underFull3 = 0;
	        						sideFull3 = 1;
	        					}
	    						
	    					under3 = findWaste(height3, width3, heightUnder, widthUnder);
	    						
								if (under3 == 0 || (under3 > 0 && under3 < smallestWaste))
								{
									smallestWaste = under3;
									underFull3 = 0;
									sideFull3 = 0;
									under3 = 1;
								}
							 
							 
							 if (width1 == width2 && (height1 + height2) == rows)
	    					 {
	    						sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    						if (sideFull3 == 0 || sideFull3 > 0)
	    						{
	    							for (int i=0; i < height3; ++i)
	    							{
	    								for (int j=width1; j < width1 + width3; ++j)
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    					 	}
	    					 }
	    			
	    			if ((width2 < width1 || width2 == width1))
	    			{
	    				if (height3 == (rows-(height1+height2)))
	    				{
	    					underFullHeight = rows-(height1+height2);
	    					underFullWidth = cols;
	    					
	    					underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    					
	    					if (underFull3 == 0 || underFull3 > 0)
	    					{
	    					
	    						for (int i=(height1 + height2); i < height1 + height2 + height3; ++i)
	    						{
	    							for (int j=0; j < width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    						underFull3 = 0;
	    						sideFull3 = 0;
	    						under3 = 0;
	    						sideUnder3 = 0;
	    					}
	    				}
	    				
	    				
	    				else
	    				{
	    					if (width1 > width2)
	    					{
	    						underFullHeight = 0;
	    						for (int i = 0; i < rows; i++)
	    						{
	    							for (int j = width2; j < width2 + 1; j++)
	    							{
	    								if (box[i][j] == '.')
	    								{
	    									underFullHeight++;
	    								}
	    							}
	    						}
	    					}
							 
							 	
	    					 if (underFull3 == 1)
							 {
							 	for (int i=(rows - underFullHeight); i < height1 + height3; ++i)
	    						{
	    							for (int j=width2; j < width2+width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
							 }	
							 
							 if (sideFull3 == 1)
							 {
							 	for (int i=0; i < height3; ++i)
	    						{
	    							for (int j=width1; j < width1 + width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}	
							 	
							 }
							 
							 if (under3 == 1)
							 {
							 	for (int i=(height1 + height2); i < height1 + height2 + height3; ++i)
							 	{
							 		for (int j=0; j<width3; ++j)
							 		{
							 			box[i][j] = 'C';
							 		}
							 	}
							 }	 
	    					
	    				}
	    				
	    			}
	    			
	    			
	    		}
	    		
	    		
	    		if (side == 1)
	    		{
	    			
	    			under3 = -12345;
							
							if (height1 > height2)
	    					{
	    						sideFullWidth = 0;
	    						for (int i = height2; i < height2 + 1; i++)
	    						{
	    							for (int j = 0; j < cols; j++)
	    							{
	    								if (box[i][j] == '.')
	    								{
	    									sideFullWidth++;
	    								}
	    							}
	    						}
	    					}
	    					
	    					sideFullHeight = (rows - (height2));
	    					sideFullWidth = (cols - width1);
	    					
							if (height1 == height2)
	    					{
	    						sideFullWidth = (cols-(width1+width2));	
	    						sideFullHeight = rows;
	    					}
	    					
	    					
	    					underFullWidth = (cols);
	    					underFullHeight = (rows-height1);
	    					
	    					sideUnderHeight = rows;
	    					sideUnderWidth = (cols - (width1 + width2));
	    					
	    					smallestWaste = 2000;
	    					
	    					underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    					
	    						if (underFull3 == 0 || underFull3 > 0)
	        					{
	        						smallestWaste = underFull3;
	        						underFull3 = 1;
	        					}
	    					
	    					
	    					sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    					
								if (sideFull3 == 0 || (sideFull3 > 0 && sideFull3 < smallestWaste))
	        					{
	        						smallestWaste = sideFull3;
	        						underFull3 = 0;
	        						sideFull3 = 1;
	        					}
	        					
	        				sideUnder3 = findWaste(height3, width3, sideUnderHeight, sideUnderWidth);
	        					
	        					if (sideUnder3 == 0 || (sideUnder3 > 0 && sideUnder3 < smallestWaste))
	        					{
	        						smallestWaste = sideFull3;
	        						underFull3 = 0;
	        						sideFull3 = 0;
	        						sideUnder3 = 1;
	        					}
	        					
	        					
	        				if ((height2 < height1 || height2 == height1))
	    					{
	    						if (width3 == (cols-(width1+width2)))
	    						{	
	    					
	    							sideFullWidth = cols-(width1+width2);
	    							sideFullHeight = rows;
	    					
	    							sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    					
	    							if (sideFull3 == 0 || sideFull3 > 0)
	    							{
	    								for (int i=0; i < height3; ++i)
	    								{
	    									for (int j=(width1 + width2); j < width1 + width2 + width3; ++j) 
	    									{
	    										box[i][j] = 'C';
	    									}
	    								}
	    								sideFull3 = 0;
	    								underFull3 = 0;
	    								sideUnder3 = 0;
	    								under3 = 0;
	    							}
	    						}
	        				
	    							
	    					 if (sideFull3 == 1)
							 {
							 	for (int i = height2; i < height2 + height3; ++i)
	    						{    
	    							for (int j = width1; j < width1 + width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
							 }	
							 
							 if (underFull3 == 1)
							 {
							 	for (int i=height1; i < height1 + height3; ++i)
	    						{
	    							for (int j=0; j < width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}	
							 	
							 }
							 
							 if (sideUnder3 == 1)
							 {
							 	for (int i=0; i < height3; ++i)
	    						{
	    							for (int j=(width1 + width2); j < width1 + width2 + width3; ++j)
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}	
							 	
							 }
							 
							 if (height1 == height2 && (width1 + width2) == cols)
	    					 {
	    					  	underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    						if (underFull3 == 0 || underFull3 > 0)
	    						{
	    							for (int i=height1; i < height1+height3; ++i)
	    							{
	    								for (int j=0; j < width3; ++j)
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    						}
	    					}		
	    			}
	    		}
	    		
	    		if (sideFull == 1)
	    		{
	    			smallestWaste = 2000;
	    			sideFullHeight = rows;
	    			sideFullWidth = cols - (width1 + width2);
	    			sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    			
	    			if (sideFull3 == 0 || sideFull3 > 0)
	    			{
	    				smallestWaste = sideFull3;
	    				sideFull3 = 1;
	    			}
	    			
	    			sideUnderHeight = (rows - height2);
	    			sideUnderWidth = cols;
	    			sideUnder3 = findWaste(height3, width3, sideUnderHeight, sideUnderWidth);
	    			
	    			if (sideUnder3 == 0 || (sideUnder3 > 0 && sideUnder3 < smallestWaste))
	    			{
	    				smallestWaste = sideUnder3;
	    				sideFull3 = 0;
	    				sideUnder3 = 1;
	    			}
	    			
	    			
	    			heightUnder = height2 - height1;
	    			widthUnder = width1;
	    			under3 = findWaste(height3, width3, heightUnder, widthUnder);
	    			
	    			if (under3 == 0 || (under3 > 0 && under3 < smallestWaste))
	    			{
	    				smallestWaste = under3;
	    				sideFull3 = 0;
	    				sideUnder3 = 0;
	    				under3 = 1;
	    			}
	    			
	    			underFullHeight = rows - height1;
	    			underFullWidth = width1;
	    			underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    			
	    			if (underFull3 == 0 || (underFull3 > 0 && underFull3 < smallestWaste))
	    			{
	    				smallestWaste = underFull3;
	    				sideFull3 = 0;
	    				sideUnder3 = 0;
	    				under3 = 0;
	    				underFull3 = 1;
	    			}
	    			
					if ((width1 + width2 < cols))
	    			{
	    				if (width3 == cols - (width1 + width2))
	    				{	
	    					if (sideFull3 == 0 || sideFull3 > 0)
	    					{
	    						for (int i=0; i < height3; ++i)
	    						{
	    							for (int j=(width1 + width2); j < width1 + width2 + width3; ++j) 
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    						sideFull3 = 0;
	    						sideUnder3 = 0;
	    						under3 = 0;
	    						underFull3 = 0;
	    					}
	    				}	
	    				
	    			}
	    			
	    			if (sideFull3 == 1)
	    			{
	    				if (sideFull3 == 0 || sideFull3 > 0)
	    					{
	    						for (int i=0; i < height3; ++i)
	    						{
	    							for (int j=(width1 + width2); j < width1 + width2 + width3; ++j) 
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    					}
	    			}
	    			
	    			if (sideUnder3 == 1)
	    			{
	    				if (sideUnder3 == 0 || sideUnder3 > 0)
	    					{
	    						for (int i= height2; i < height2 + height3; ++i)
	    						{
	    							for (int j=0; j < width3; ++j) 
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    					}
	    			}
	    			
	    			if (under3 == 1)
	    			{
	    				if (under3 == 0 || under3 > 0)
	    					{
	    						for (int i=height1; i < (height1 + height3); ++i)
	    						{
	    							for (int j=0; j < width3; ++j) 
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    					}
	    			}
	    			
	    			if (underFull3 == 1)
	    			{
	    				if (underFull3 == 0 || underFull3 > 0)
	    					{
	    						for (int i=height1; i < (height1 +height3); ++i)
	    						{
	    							for (int j=0; j < width3; ++j) 
	    							{
	    								box[i][j] = 'C';
	    							}
	    						}
	    					}
	    			}
	    			
	    			
	    				
	    		}
	    		
	    		if (underFull == 1)
	    		{
	    				
	    				smallestWaste = 2000;
	    				sideFullHeight = rows - (height1 + height2);
	    				sideFullWidth = cols;
	    				sideFull3 = findWaste(height3, width3, sideFullHeight, sideFullWidth);
	    				
	    				if (sideFull3 == 0 || sideFull3 > 0)
	    				{
	    					smallestWaste = sideFull3;
	    					sideFull3 = 1;
	    				}
	    				
	    				sideUnderHeight = rows;
	    				sideUnderWidth = (cols - width2);
	    				sideUnder3 = findWaste(height3, width3, sideUnderHeight, sideUnderWidth);
	    				
	    				if (sideUnder3 == 0 || (sideUnder3 > 0 && sideUnder3 < smallestWaste))
	    					{
	    						smallestWaste = sideUnder3;
	    						sideFull3 = 0;
	    						sideUnder3 = 1;
	    					}
	    				
	    				heightUnder = height1;
	    				widthUnder = width2 - width1;
	    				under3 = findWaste(height3, width3, heightUnder, widthUnder);
	    			
	    					if (under3 == 0 || (under3 > 0 && under3 < smallestWaste))
	    					{
	    						smallestWaste = under3;
	    						sideFull3 = 0;
	    						sideUnder3 = 0;
	    						under3 = 1;
	    					}
	    				
	    				underFullHeight = height1;
	    				underFullWidth = cols - width1;
	    				underFull3 = findWaste(height3, width3, underFullHeight, underFullWidth);
	    			
	    					if (underFull3 == 0 || (underFull3 > 0 && underFull3 < smallestWaste))
	    					{
	    						smallestWaste = underFull3;
	    						sideFull3 = 0;
	    						sideUnder3 = 0;
	    						under3 = 0;
	    						underFull3 = 1;
	    					}
	    					
	    					if ((height1 + height2 < rows))
	    					{
	    						if (height3 == (rows - (height1 + height2)))
	    						{
	    							if (sideFull3 == 0 || sideFull3 > 0)
	    							{
	    								for (int i = height1 + height2; i < height1 + height2 + height3; ++i)
	    								{
	    									for (int j=0; j < width3; ++j) 
	    									{
	    										box[i][j] = 'C';
	    									}
	    								}
	    								
	    							}
	    							
	    							sideFull3 = 0;
	    							sideUnder3 = 0;
	    							under3 = 0;
	    							underFull3 = 0;
	    					    }
	    					}
	    					
	    					if (sideFull3 == 1)
	    					{
	    						if (sideFull3 == 0 || sideFull3 > 0)
	    						{
	    							for (int i=(height1 + height2); i < height1 + height2 + height3; ++i)
	    							{
	    								for (int j=0; j < width3; ++j) 
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    						}
	    					}
	    					
	    					if (sideUnder3 == 1)
	    					{
	    						if (sideUnder3 == 0 || sideUnder3 > 0)
	    						{
	    							for (int i=0; i < height3; ++i)
	    							{
	    								for (int j = width2; j < width2 + width3; ++j) 
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    						}
	    					}
	    					
	    					if (under3 == 1)
	    					{
	    						if (under3 == 0 || under3 > 0)
	    						{
	    							for (int i=0; i < height3; ++i)
	    							{
	    								for (int j=width1; j < width1 + width3; ++j) 
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    						}
	    					}
	    					
	    					if (underFull3 == 1)
	    					{
	    						if (underFull3 == 0 || underFull3 > 0)
	    						{
	    							for (int i=0; i < height3; ++i)
	    							{
	    								for (int j = width1; j < (width1 + width3); ++j) 
	    								{
	    									box[i][j] = 'C';
	    								}
	    							}
	    						}
	    					}
	    				
	    			
	    		}
	    		
	    		if (under3 < 0 && sideFull3 < 0 && underFull3 < 0 && sideUnder3 < 0)
	    		{	
	    			cout << "I'm sorry, but that object doesn't fit in the space you created. " << endl << endl;
	    		}
	    		
	    	} while (under3 < 0 && sideFull3 < 0 && underFull3 < 0 && sideUnder3 < 0);
	    
	    
			for (int r=0; r < rows; ++r)
			{
				cout << "        ";
				for (int c=0; c < cols; ++c)
				{
					cout << box[r][c] << "  ";
				}
				cout << endl << endl;
	    	}
	    	
	    	cout << "All 3 objects have been inserted! " << endl << endl;
	    	
	    	cout << "Would you like to try again? (Press 1 to try again, any other number to quit) ";
			cinSafeInt (choice);
			
}while (choice == 1);	
		
	
	return 0;
}
