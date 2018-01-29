#include"SCompoundWidget.h"
#include "SlateWindows.h"
#include "SlateBasics.h"
#include  "SlateExtras.h"
#include  "Engine.h"
#pragma once
#define LOCTEXT_NAMESPACE "SWdigetDemoA"
class SWdigetDemoA :public SCompoundWidget
{
public:

	FReply OnLoginButtonClicked();

public:
	SLATE_BEGIN_ARGS(SWdigetDemoA) {}
	SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)

	{
		{
			this->ChildSlot
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
				[
				SNew(SButton)
				//.Text("first","FistText")
				
				]
			       +SVerticalBox::Slot()
					   [
					   
					   SNew(SHorizontalBox)
					   +SHorizontalBox::Slot()
					   [
					   SNew(SButton)
					   
					   ]
				   + SHorizontalBox::Slot()
					   [
					   
					   SNew(SButton)
					   
					   ]
				   +SHorizontalBox::Slot()
					   [
					   
					   SNew(SButton)
					   .Text(LOCTEXT("first","lastButton"))
					   .OnClicked(this,&SWdigetDemoA::OnLoginButtonClicked)
					   ]

					   
					   ]




				];

		}

	
	};




};
#undef LOCTEXT_NAMESPACE