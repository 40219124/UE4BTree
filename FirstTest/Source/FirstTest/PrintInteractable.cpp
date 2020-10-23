// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintInteractable.h"

void APrintInteractable::DoInteract() {

	switch (function) {
	case PrintFunction::INORDER:
		printResult = "InOrder";
		break;
	case PrintFunction::PREORDER:
		printResult = "PreOrder";
		break;
	case PrintFunction::POSTORDER:
		printResult = "PostOrder";
		break;
	}

}
