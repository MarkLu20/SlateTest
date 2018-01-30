#pragma once
#include "SBoxPanel.h"

class SAutoLayout :public SBoxPanel
{
	///自动排序的容器组件
public:
	class FSlot :public SBoxPanel::FSlot
	{
	public:
		FSlot()
			  :SBoxPanel::FSlot() {}
		FSlot &AutoHeight()
		{
			SizeParam = FAuto();
			return *this;
		
		
		}
		FSlot &MaxHeight(const TAttribute<float> &InMaxHeight)
		{
		
		
			MaxSize = InMaxHeight;
			return *this;
		
		}
		FSlot &FillHeight(const TAttribute<float> &StretchCoefficent)
		{
		
			SizeParam = FStretch(StretchCoefficent);
			return *this;
		
		}
		FSlot &Padding(float Uniform)
		{
		
			SlotPadding = FMargin(Uniform);
			return *this;
		
		
		}
		FSlot &Padding(float Left, float Top, float Right, float Bottom)
		{
		
			SlotPadding = FMargin(Left, Top, Right, Bottom);
			return *this;



		
		}
		FSlot &Padding(const TAttribute<FMargin>::FGetter &InDeleGate)
		{
		
			SlotPadding.Bind(InDeleGate);
			return *this;
		
		}
		FSlot &HAlign(EHorizontalAlignment InHAlignment)
		{
		
			HAlignment = InHAlignment;
			return *this;
		
		}
		FSlot &VAlign(EVerticalAlignment InVAlignment)
		{
		
			VAlignment = InVAlignment;
			return *this;
		
		}
		FSlot &Padding(TAttribute<FMargin> InPadding)
		{
		
			SlotPadding = InPadding;
			return *this;
		
		}
		FSlot &operator[](TSharedRef<SWidget> InWidget)
		{
			SBoxPanel::FSlot::operator[](InWidget);
			return *this;
		
		
		}
		FSlot &Expose(FSlot *& outVarToInit)
		{
			outVarToInit = this;
			return *this;
		
		}



	};
	static FSlot &Slot()
	{
	
		return *(new FSlot());
	
	}

public:

	virtual void OnArrangeChildren(const FGeometry &AllotteGeometry, FArrangedChildren &ArrangeChildren) const override;
public:
	SLATE_BEGIN_ARGS(SAutoLayout) {}
	SLATE_ATTRIBUTE(FMargin,ContentMargin)
	SLATE_SUPPORTS_SLOT(SAutoLayout::FSlot)
	//SLATE_EVENT(FloginDelegate, OnStartLogin)
	SLATE_END_ARGS()
		FORCEINLINE SAutoLayout() :SBoxPanel(Orient_Horizontal)
	{}

	
	public:
		void Construct(const FArguments &InArgs);
		FSlot &AddSlot()
		{
		
			SAutoLayout::FSlot &NewSlot = *new FSlot();
			this->Children.Add(&NewSlot);
			return NewSlot;
		
		}

private:
	FMargin ContentMargin;

};