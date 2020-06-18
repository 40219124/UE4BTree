// Fill out your copyright notice in the Description page of Project Settings.


#include "BiTreeFunctions.h"
#include "BiTreeNode.h"

using namespace std;

BiTreeFunctions::BiTreeFunctions()
{
}

BiTreeFunctions::~BiTreeFunctions()
{
}

void BiTreeFunctions::Insert(int value)
{
	if (root == nullptr) 
	{
		root = new BiTreeNode();
	}

	queue.push_back(root);
	int precount = queue.size();
	while (true) 
	{
		queue.back()->Insert(direction, queue, value);
		if (queue.size() == precount) {
			break;
		}
		else 
		{
			precount = queue.size();
		}
	}

	queue.clear();
}

void BiTreeFunctions::Remove(int value)
{
}

bool BiTreeFunctions::Exists(int value)
{
	if (root == nullptr) {
		return false;
	}

	bool returnBool = false;

	queue.push_back(root);
	int precount = queue.size();
	while (true)
	{
		returnBool = queue.back()->Exists(direction, queue, value);
		if (queue.size() == precount) {
			break;
		}
		else
		{
			precount = queue.size();
		}
	}

	return returnBool;
}

int BiTreeFunctions::Count(int value)
{
	if (root == nullptr) {
		return false;
	}

	int returnInt = false;

	queue.push_back(root);
	int precount = queue.size();
	while (true)
	{
		returnInt = queue.back()->Count(direction, queue, value);
		if (queue.size() == precount) {
			break;
		}
		else
		{
			precount = queue.size();
		}
	}

	return returnInt;
}

string BiTreeFunctions::InOrder()
{
	if (root == nullptr) {
		return "";
	}

	string outString = "";
	direction = Direction::DESCEND;
	queue.push_back(root);

	while (queue.size() > 0) {
		string s = queue.back()->InOrder(direction, queue);
		if (s != "")
		{
			if (outString != "") {
				outString += ", ";
			}
			outString += s;
		}
	}

	outString += ".";

	return outString;
}

string BiTreeFunctions::PreOrder()
{
	if (root == nullptr) {
		return "";
	}

	string outString = "";
	direction = Direction::DESCEND;
	queue.push_back(root);

	while (queue.size() > 0) {
		string s = queue.back()->PreOrder(direction, queue);
		if (s != "")
		{
			if (outString != "") {
				outString += ", ";
			}
			outString += s;
		}
	}

	outString += ".";

	return outString;
}

string BiTreeFunctions::PostOrder()
{
	if (root == nullptr) {
		return "";
	}

	string outString = "";
	direction = Direction::DESCEND;
	queue.push_back(root);

	while (queue.size() > 0) {
		string s = queue.back()->PostOrder(direction, queue);
		if (s != "")
		{
			if (outString != "") {
				outString += ", ";
			}
			outString += s;
		}
	}

	outString += ".";

	return outString;
}
