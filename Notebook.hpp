#include<string.h>
#include"Direction.hpp"
#include<iostream>
using namespace std;                                            //this for me  //to check this why not work without namespace
using namespace ariel;

namespace ariel{
    class Notebook
    {
    
    public:
        	void write(int page,int row,int col,Direction d,string str);
			string read(int page,int row,int col,Direction d,int size);
			void erase(int page,int row,int col,Direction d,int size);
			void show(int page);

    };
}