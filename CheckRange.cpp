/*
	* THE FUNCTION IS USED TO CHECK THE MAXIMUM RANGE FOR A DFA
	* THE INPUT INCLUDES DFA TRANSITION TABLE, NUMBER OF STATES, NUMBER OF SYMBOLS (CHARATER).
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argv, char* argc[])
{
	char* file;
	int state_num;
	int symbol_num;
	file=argc[1];
	state_num=atoi(argc[2]);	
	symbol_num=atoi(argc[3]);

	ifstream in;
	in.open(file);

	int i,j,k,l;
	int** T;
	T= new int* [symbol_num];
	for(i=0;i<symbol_num;i++)
		T[i]=new int [state_num];

	while(in)
	{
		for(j=0;j<state_num;j++)
			for(i=0;i<symbol_num;i++)
				in>>T[i][j];
	}
	in.close();

	vector <int> vec;
	int MAX_R=0;

	for(i=0;i<symbol_num;i++)
	{
		for(j=0;j<state_num;j++)	
			if(find(vec.begin(),vec.end(),T[i][j])==vec.end())
				vec.push_back(T[i][j]);

		int sizeofu;
		sizeofu=vec.size();
		if(MAX_R<sizeofu)	
			MAX_R=sizeofu;
		vec.erase(vec.begin(),vec.end());
	}		
	cout<<"The maximun range is "<<MAX_R<<endl;
}
