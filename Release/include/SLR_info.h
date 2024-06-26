#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"../include/Common_data.h"

class SLRClass: public Grammar_set {
public:
	const char* readSLRGrammarFile = "./src/textFile/SLR/SLRGrammarText.txt";
	const char* readSLRExpressionFile = "./src/textFile/SLR/SLRExpressionWord.txt";
	SLRClass() {};
	
	//求项目集的闭包
	items_Node itemsNodeClosure(const items_Node& oriNode);
	//初始项目集 接收x的goto项目集
	items_Node itemsNodeGoto(const items_Node& oriNode, std::string X);
	//检测两个项目集是否相同
	bool itemsNodeCheckSame(const items_Node& oriNode, const items_Node& nextNode);
	//SLR分析表的构造
	void SLRAnaTableConstruct(items_Node& oriNode);
	//VTN 取出表达式中Vt和Vn
	void constructVTN();
	//格式化输出分析表
	void printSLRTabel();
	//SLR分析预测程序
	void SLR_predict(std::string inputExpression);
	//SLR分析 并输出栈
	void SLR_predict_AnalyseStack(std::string inputExpression);
	//启动SLR分析
	void run_ReadExp_SLR();

private:

	std::vector<items_Node>itemsNodeSet{};			//所有项目集
	std::unordered_map<int, std::vector<std::pair<std::string, std::string>>>Action;		//Action表
	std::unordered_map<int, std::vector<std::pair<std::string, std::string>>>Goto;		//Goto表
	std::stack<int>State_Stack;						//状态栈	int型方便处理 多位数状态 
	std::stack<std::string>Symbol_Stack;			//符号栈
	std::vector<std::string>VNT;
};