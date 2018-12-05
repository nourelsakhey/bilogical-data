#pragma once
#include"sequence.h"
#include"RNA.h"
#include<iostream>
using namespace std;


class RNA;
enum DNA_type { promoter, motif, tail, noncoding };

class DNA:public sequence
{
private:
	DNA_type type;
	DNA *complemantary_strand;
	int start_char;
	int end_char;

public:
	DNA();
	DNA(char*seq,DNA_type atype,int length);
	DNA(DNA &rhs);
	void print();
	RNA convert_to_RNA();
	void build_complemantary_strand();
	void set_endchar(int x);
	void set_startchar(int y);
	int get_endchar();
	int get_startchar();


	~DNA();
};

