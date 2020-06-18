// Fill out your copyright notice in the Description page of Project Settings.


#include "BiTreeNode.h"

using namespace std;

BiTreeNode::BiTreeNode()
{
}

BiTreeNode::~BiTreeNode()
{
}

void BiTreeNode::Insert(Direction& dir, vector<BiTreeNode*>& nodes, int inValue)
{
	if (value == NULL)
	{
		value = inValue;
	}
	else if (inValue < value)
	{
		if (leftNode == nullptr)
		{
			leftNode = new BiTreeNode();
		}
		ChangeVector(Orders::GoLEFT, nodes);
	}
	else if (inValue > value)
	{
		if (rightNode == nullptr)
		{
			rightNode = new BiTreeNode();
		}
		ChangeVector(Orders::GoRIGHT, nodes);
	}
	else
	{
		count++;
	}
}

void BiTreeNode::Remove(Direction& dir, vector<BiTreeNode*>& nodes, int inValue)
{

}

bool BiTreeNode::Exists(Direction& dir, vector<BiTreeNode*>& nodes, int inValue)
{
	bool outBool = false;
	if (value == NULL) 
	{
		return outBool;
	}
	else if (inValue == value)
	{
		outBool = true;
	}
	else if (inValue < value) 
	{
		if (leftNode != nullptr) 
		{
			ChangeVector(Orders::GoLEFT, nodes);
		}
	}
	else 
	{
		if (rightNode != nullptr) 
		{
			ChangeVector(Orders::GoRIGHT, nodes);
		}
	}

	return outBool;
}

int BiTreeNode::Count(Direction& dir, vector<BiTreeNode*>& nodes, int inValue)
{
	int outCount = 0;
	if (value == NULL)
	{
		return outCount;
	}
	else if (inValue == value)
	{
		outCount = count;
	}
	else if (inValue < value)
	{
		if (leftNode != nullptr)
		{
			ChangeVector(Orders::GoLEFT, nodes);
		}
	}
	else
	{
		if (rightNode != nullptr)
		{
			ChangeVector(Orders::GoRIGHT, nodes);
		}
	}

	return outCount;
}

string BiTreeNode::InOrder(Direction& dir, vector<BiTreeNode*>& nodes)
{
	string outString = "";

	Orders order = GetOrders(dir);
	ChangeVector(order, nodes);

	switch (order)
	{
	case Orders::GoLEFT:
		lastState = Direction::DESCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoRIGHT:
		outString = value;
		lastState = Direction::ASCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoUP:
		lastState = Direction::STOP;
		dir = Direction::ASCEND;
		break;
	}

	return outString;
}

string BiTreeNode::PreOrder(Direction& dir, vector<BiTreeNode*>& nodes)
{
	string outString = "";

	Orders order = GetOrders(dir);
	ChangeVector(order, nodes);

	switch (order)
	{
	case Orders::GoLEFT:
		outString = value;
		lastState = Direction::DESCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoRIGHT:
		lastState = Direction::ASCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoUP:
		lastState = Direction::STOP;
		dir = Direction::ASCEND;
		break;
	}

	return outString;
}

string BiTreeNode::PostOrder(Direction& dir, vector<BiTreeNode*>& nodes)
{
	string outString = "";

	Orders order = GetOrders(dir);
	ChangeVector(order, nodes);

	switch (order)
	{
	case Orders::GoLEFT:
		lastState = Direction::DESCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoRIGHT:
		lastState = Direction::ASCEND;
		dir = Direction::DESCEND;
		break;
	case Orders::GoUP:
		outString = value;
		lastState = Direction::STOP;
		dir = Direction::ASCEND;
		break;
	}

	return outString;
}

Orders BiTreeNode::GetOrders(Direction dir, bool riToLe)
{
	Orders returnOrders;

	switch (dir)
	{
	case Direction::DESCEND:
		if (leftNode != nullptr && lastState != Direction::DESCEND)
		{
			returnOrders = Orders::GoLEFT;
		}
		else if (rightNode != nullptr && lastState != Direction::ASCEND)
		{
			returnOrders = Orders::GoRIGHT;
		}
		else
		{
			returnOrders = Orders::GoUP;
		}
		break;
	case Direction::ASCEND:
		if (rightNode != nullptr && lastState != Direction::ASCEND)
		{
			returnOrders = Orders::GoRIGHT;
		}
		else
		{
			returnOrders = Orders::GoUP;
		}
		break;
	}

	return returnOrders;
}

void BiTreeNode::ChangeVector(Orders order, vector<BiTreeNode*>& nodes)
{
	switch (order)
	{
	case Orders::GoLEFT:
		nodes.push_back(leftNode);
		break;
	case Orders::GoRIGHT:
		nodes.push_back(rightNode);
		break;
	case Orders::GoUP:
		nodes.pop_back();
		break;
	}
}
