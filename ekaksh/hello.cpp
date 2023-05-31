#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <iostream>
#include <cmath>
#include<cstdlib>
#include <time.h>
using namespace std;



void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<double> > > dataset)
{
	// Make a CSV file with one or more columns of integer values
	// Each column of data is represented by the pair <column name, column data>
	//   as std::pair<std::string, std::vector<int>>
	// The dataset is represented as a vector of these columns
	// Note that all columns should be the same size

	// Create an output filestream object
	std::ofstream myFile(filename);

	// Send column names to the stream
	for(int j = 0; j < dataset.size(); ++j)
	{
		myFile << dataset.at(j).first;
		if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
	}
	myFile << "\n";

	// Send data to the stream
	for(int i = 0; i < dataset.at(0).second.size(); ++i)
	{
		for(int j = 0; j < dataset.size(); ++j)
		{
			myFile << dataset.at(j).second.at(i);
			if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
		}
		myFile << "\n";
	}

	// Close the file
	myFile.close();
}

int main()
{
	int ibin;
	double delx = 0.1;

	vector<double> xcount;
	int Nbins = 100;
	xcount.resize(Nbins);

	for(ibin = 0; ibin< Nbins; ibin++)
	{
		xcount[ibin]= 0;
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++)
	{
		double x = (double)(rand()+ 0.5)/RAND_MAX;
		x = -log(x);
		ibin = floorl(x/delx);
		xcount[ibin] += 1;
		return x
	}


	// Wrap into a vector
	std::vector<std::pair<std::string, std::vector<double> > > vals = {{"xcount", xcount}, {"value x", x}};

	// Write the vector to CSV
	write_csv("exp.csv", vals);

	return 0;
}
