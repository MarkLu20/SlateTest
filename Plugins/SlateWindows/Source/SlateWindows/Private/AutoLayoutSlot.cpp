// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoLayoutSlot.h"

void UAutoLayoutSlot::SynchronizeProperties()
{

}

void UAutoLayoutSlot::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	Slot = NULL;
}

void UAutoLayoutSlot::BuildSlot(TSharedRef<SAutoLayout> InAutoLayOut)
{

	Slot = &InAutoLayOut->AddSlot()[

		InAutoLayOut

	];
}



