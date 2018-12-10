#include "Sequence.h"
Sequence::Sequence()
{

}
Sequence::Sequence(int length)
{
	seq = new char[length];
	size = length;
}
Sequence::Sequence(Sequence& rhs)
{
	rhs.seq = seq;
}
Sequence::~Sequence()
{
	delete seq;
}
char* Align(Sequence * s1, Sequence * s2)
{
	int** arr;
	arr = new int*[s1->size+1];

	for (int i = 0; i < s1->size+1; i++)
		arr[i] = new int[s2->size+1];
	for (int i = 0; i < s1->size+1; i++)
	{
		for (int j = 0; j < s1->size + 1; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (s1->seq[i - 1] == s2->seq[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
			{
				if (arr[i - 1][j] > arr[i][j - 1])
					arr[i][j] = arr[i - 1][j];
				else
					arr[i][j] = arr[i][j - 1];
			}

		}
	}
	char* arr_2;
	arr_2 = new char[arr[s1->size + 1][s2->size + 1]];
}