/**
 * @file Lab6_cdoss4.cpp
 * @author Christian Doss
 * @date 2026-10-12
 * @brief Compare static arrays and vectors for processing student scores.
 */

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void arraySolution();

float calculateAverage(const int arr[], int size);

int findMax(const int arr[], int size);

int findMin(const int arr[], int size);

void vectorSolution();

float calculateAverage(const vector <int> & vec);

int findMax(const vector <int> & vec);

int findMin(const vector <int>& vec);

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */

int main()
{
	arraySolution();

	cout << "" << endl;

	vectorSolution();

	return 0;
}

/**
 * @brief Calculates statistics using a fixed-size static array.
 * @param None.
 * @return None (void).
 */

void arraySolution()
{
	const int SIZE = 10;
	
	int scores[SIZE];
	
	int scoreInput = 0;

	cout << "Static Array Solution" << endl;

	for (int i = 0; i < SIZE; ++i)
	{
		do
		{
			cout << "Enter Score " << (i + 1) << " (0-100): ";

			cin >> scoreInput;

			if (scoreInput < 0 || scoreInput > 100)
			{
				cout << "Invalid Score. Please enter score." << endl;
			}
		} 
		
		while (scoreInput < 0 || scoreInput > 100);
		scores[i] = scoreInput;
	}

	cout << "Array Statistics" << endl;

	cout << "Average Score: " << calculateAverage(scores, SIZE) << endl;

	cout << "Highest Score: " << findMax(scores, SIZE) << endl;

	cout << "Lowest Score: " << findMin(scores, SIZE) << endl;

}

/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None.
 * @return None (void).
 */

void vectorSolution()
{
	vector<int> scores;
	int scoreInput = 0;

	cout << "Dynamic Vector Solution" << endl;

	while (true)
	{
		cout << "Enter score (0-100) or -1 to finish: ";
		cin >> scoreInput;

		if (scoreInput == -1)
		{
			break;
		}

		if (scoreInput < 0 || scoreInput > 100)
		{
			cout << "INVALID SCORE" << endl;
		}

		else
		{
			scores.push_back(scoreInput);
		}
	}

	if (scores.empty()) 
	{
		cout << "\nNo valid scores were entered." << endl;

		return;

	}

	cout << "Vector Statistics" << endl;

	cout << "Average Score: " << calculateAverage(scores) << endl;

	cout << "Highest Score: " << findMax(scores) << endl;

	cout << "Lowest Score: " << findMin(scores) << endl;


	sort(scores.begin(), scores.end());

	cout << "Sorted Scores: ";

	for (size_t i = 0; i < scores.size(); ++i) 
	{
		cout << scores[i] << " ";
	}

	cout << endl;

}

/**
 * @brief Calculates the average of the scores in an array.
 * @param arr The static array containing integer scores.
 * @param size The total number of elements in the array.
 * @return The average score as a float.
 */

float calculateAverage(const int arr[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i) 
	{
		sum += arr[i];
	}

	return static_cast<float>(sum) / size;
}

/**
 * @brief Finds the highest score in an array.
 * @param arr The static array containing integer scores.
 * @param size The total number of elements in the array.
 * @return The highest integer score.
 */

int findMax(const int arr[], int size)
{
	int highest = arr[0];

	for (int i = 1; i < size; ++i) 
	{
		if (arr[i] > highest) 
		{
			highest = arr[i];
		}
	}

	return highest;
}

/**
 * @brief Finds the lowest score in an array.
 * @param arr The static array containing integer scores.
 * @param size The total number of elements in the array.
 * @return The lowest integer score.
 */
int findMin(const int arr[], int size)
{
	int lowest = arr[0];
	for (int i = 1; i < size; ++i) 
	{
		if (arr[i] < lowest) 
		{
			lowest = arr[i];
		}
	}

	return lowest;
}

/**
 * @brief Calculates the average of the scores in a vector.
 * @param vec The vector containing integer scores.
 * @return The average score as a float.
 */

float calculateAverage(const vector<int>& vec)
{
	int sum = 0;

	for (size_t i = 0; i < vec.size(); ++i) 
	{
		sum += vec[i];
	}

	return static_cast<float>(sum) / vec.size();
}

/**
 * @brief Finds the highest score in a vector.
 * @param vec The vector containing integer scores.
 * @return The highest integer score.
 */

int findMax(const vector<int>& vec)
{
	int highest = vec[0];

	for (size_t i = 1; i < vec.size(); ++i) 
	{
		if (vec[i] > highest) {
			highest = vec[i];
		}
	}

	return highest;
}

/**
 * @brief Finds the lowest score in a vector.
 * @param vec The vector containing integer scores.
 * @return The lowest integer score.
 */

int findMin(const vector<int>& vec)
{
	int lowest = vec[0];

	for (size_t i = 1; i < vec.size(); ++i) 
	{
		if (vec[i] < lowest) 
		{
			lowest = vec[i];
		}
	}

	return lowest;
}