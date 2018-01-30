#include "SEditableTextBox.h"
#include  "SlateWindowsStyle.h"
#include  "SlateBasics.h"
#pragma once

#define LOCTEXT_NAMESPACE "DymicSlot"


class DymicSlot :public SCompoundWidget
{
private:
	FReply OnLoginButtonCicked();
	FReply ChageSlotProperty(int type);
	SHorizontalBox::FSlot *ButtonSlot;//¶¨ÒåÖ¸Õë
	


public:
	SLATE_BEGIN_ARGS(DymicSlot) {}
	//SLATE_EVENT(FloginDelegate, OnStartLogin)
		SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)

	{
			

		/*	this->ChildSlot
				[*/

			//		SNew(SVerticalBox)
			//		+SVerticalBox::Slot().VAlign(VAlign_Top)
			//	[
			//	
	  //               SNew(SHorizontalBox)
			//		 +SHorizontalBox::Slot().HAlign(HAlign_Center)
			//	.Expose(ButtonSlot)
			//	[
			//	
			//	     SNew(SButton)
			//	     .Text(LOCTEXT("an","androdid"))
			//	
			//	
			//	]
			//	
			//	
			//	]
			//+SVerticalBox::Slot().AutoHeight
			//	[
			//	SNew(SHorizontalBox)
			//	+SHorizontalBox::Slot()
			//	[
			//	
			//	SNew(SButton)
			//	//.OnClicked(this,&DymicSlot::ChageSlotProperty,0)
			//	.Text(LOCTEXT("0","Left"))
			//	
			//	]
			//+SHorizontalBox::Slot()
			//	[
			//	SNew(SButton)
			//	//.OnClicked(this,&DymicSlot::ChageSlotProperty,1)
			//	.Text(LOCTEXT("1","Right"))
			//	
			//	]
			//+SHorizontalBox::Slot()
			//	[
			//	SNew(SButton)
			//	//.OnClicked(this,&DymicSlot::ChageSlotProperty,2)
			//	.Text(LOCTEXT("2","Center"))
			//	
			//	
			//	]
			//+SHorizontalBox::Slot()
			//	[
			//	
			//	SNew(SButton)
			//	//.OnClicked(this,&DymicSlot::ChageSlotProperty,3)
			//	.Text(LOCTEXT("3","Fill"))
			//	
			//	
			//	]
			//	
			//	
			//	]

				
				/*];*/

	}

};
#undef LOCTEXT_NAMESPACE