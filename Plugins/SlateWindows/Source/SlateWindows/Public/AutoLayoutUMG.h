// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include  "AutoLayout.h"
#include  "AutoLayoutSlot.h"
#include  "SCompoundWidget.h"
#include "AutoLayoutUMG.generated.h"

/**
 * 
 */
UCLASS()
class SLATEWINDOWS_API UAutoLayoutUMG : public UPanelWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SanWu")
		FMargin ContenMargin;

public:
#if WITH_EDITOR

	virtual const FText GetPaletteCategory()override;

#endif
protected:
	//UPanelWidget
	virtual UClass *GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot *Slot)override;
	virtual void OnSlotRemoved(UPanelSlot *Slot)override;
	//End UPanelWidget
	virtual void ReleaseSlateResources(bool bRelesaseChildren) override;
	virtual TSharedRef<SWidget> RebuildWidget()override;
public:
	TSharedPtr<SAutoLayout> MyAutoLayout;
	
	
	
	
};
