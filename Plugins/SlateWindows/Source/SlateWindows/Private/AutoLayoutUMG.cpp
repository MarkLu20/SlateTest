// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoLayoutUMG.h"

const FText UAutoLayoutUMG::GetPaletteCategory()
{
	return  FText::FromString(FString(TEXT("Sanwu")));
}

UClass * UAutoLayoutUMG::GetSlotClass() const
{
	return UAutoLayoutSlot::StaticClass();
}

void UAutoLayoutUMG::OnSlotAdded(UPanelSlot * Slot)
{
	if (MyAutoLayout.IsValid())
	{
		CastChecked<UAutoLayoutSlot>(Slot)->BuildSlot(MyAutoLayout.ToSharedRef());
	}
}

void UAutoLayoutUMG::OnSlotRemoved(UPanelSlot * Slot)
{
}

void UAutoLayoutUMG::ReleaseSlateResources(bool bRelesaseChildren)
{
	Super::ReleaseSlateResources(bRelesaseChildren);
}

TSharedRef<SWidget> UAutoLayoutUMG::RebuildWidget()
{
	MyAutoLayout = SNew(SAutoLayout);
	for (UPanelSlot *PanelSlot :Slots)
	{
		if (UAutoLayoutSlot *TypedSlot = Cast<UAutoLayoutSlot>(PanelSlot))
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyAutoLayout.ToSharedRef());

		}
	}
	return CreateDesignerOutline(MyAutoLayout.ToSharedRef());


}





