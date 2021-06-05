#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

//��������� "���"
struct Forest {
	std::string location;//��������� ���� "�����������"
	std::string type;//��� ����
	double fireDanger;//���������������

	Forest(){
		this->location="";
		this->type="";
		this->fireDanger=0;
	}

	Forest(const Forest&forest){
		this->fireDanger=forest.fireDanger;
		this->type=forest.type;
		this->location=forest.location;
	}

	Forest(std::string location, std::string type, double fireDanger){
		this->location=location;
		this->fireDanger=fireDanger;
		this->type=type;
	}

	bool operator==(const Forest& forest){
		return this->type==forest.type;
	}
};

struct Tree {
	Forest kind;//��� ���� 
	double height;//������
	int thickness;//�������
	bool hasHollow;//���� �� � ������ �����
	int shadowSquare;//������� ���� �� ������
};
