#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define  N  3

using std::cout;
using std::endl;
using std::vector;

vector<vector<int> > subsets(vector<int> &num) {
    vector<vector<int>> path(1, vector<int>());
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
        int n = path.size();
	
		for (int j = 0; j < n; j++){
			path.push_back(path[j]);
			path.back().push_back(num[i]);
		}
	}
	
	return path;
}


int _tmain(int argc, _TCHAR* argv[])
{	
	vector<int> num;
	for (int i = 0; i < N; i++) {
		num.push_back(i+1);
	}

	vector<vector<int> > temp(subsets(num));
	for(int i = 0; i < temp.size(); i++) {
		
		cout << "[";

		for(int j = 0; j < temp[i].size(); j++) {
			cout << temp[i][j] << " ";
		}
		
		//i为0的时候，temp[i].size()为0，并不会进入第二层for循环，导致之前的“[”被删除。
		if(i == 0)
			cout << "[";
		
		cout << "\b" << "]" << endl;
	}
	return 0;
}