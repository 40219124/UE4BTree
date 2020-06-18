// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class BiTreeNode;
enum class Direction;
/**
 * 
 */
class FIRSTTEST_API BiTreeFunctions
{
public:
	BiTreeFunctions();
	~BiTreeFunctions();

	void Insert(int value);
	void Remove(int value);
	bool Exists(int value);
	int Count(int value);

	std::string InOrder();
	std::string PreOrder();
	std::string PostOrder();

private:
	BiTreeNode* root = nullptr;
	std::vector<BiTreeNode*> queue;
	Direction direction;
};
