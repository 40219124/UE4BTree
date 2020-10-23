// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class Direction { NONE = -1, DESCEND, ASCEND, STOP };
enum class Orders { NONE = -1, GoLEFT, GoRIGHT, GoUP};
UENUM()
enum  PrintFunction { NONE = -1, INORDER, PREORDER, POSTORDER };

/**
 *
 */
class FIRSTTEST_API BiTreeNode
{
public:
	BiTreeNode();
	~BiTreeNode();

	void Insert(Direction& dir, std::vector<BiTreeNode*>& nodes, int value);
	void Remove(Direction& dir, std::vector<BiTreeNode*>& nodes, int value);
	bool Exists(Direction& dir, std::vector<BiTreeNode*>& nodes, int value);
	int Count(Direction& dir, std::vector<BiTreeNode*>& nodes, int value);

	std::string InOrder(Direction& dir, std::vector<BiTreeNode*>& nodes);
	std::string PreOrder(Direction& dir, std::vector<BiTreeNode*>& nodes);
	std::string PostOrder(Direction& dir, std::vector<BiTreeNode*>& nodes);


private:
	BiTreeNode* leftNode = nullptr;
	BiTreeNode* rightNode = nullptr;
	int value = NULL;
	int count = 0;
	Direction lastState = Direction::DESCEND;

	Orders GetOrders(Direction dir, bool riToLe = false);
	void ChangeVector(Orders order, std::vector<BiTreeNode*>& nodes);
};
