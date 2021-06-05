#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

//структура "Лес"
struct Forest {
	std::string location;//строковое поле "расположние"
	std::string type;//тип леса
	double fireDanger;//пожароопасность

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
	Forest kind;//вид леса 
	double height;//высота
	int thickness;//полщина
	bool hasHollow;//есть ли в дереве дупло
	int shadowSquare;//площадь тени от дерева
};
