#include"SCompoundWidget.h"
#include "AutoLayout.h"
#include "SlateWindows.h"
#include "SlateBasics.h"
#include  "SlateExtras.h"
#include  "SEventTest.h"
#include  "Engine.h"
#pragma once
#define LOCTEXT_NAMESPACE "SWdigetDemoB"
class SWdigetDemoB :public SCompoundWidget
{
public:
	void Onlogin(FString usn, FString pwd);
	TSharedPtr<SAutoLayout> SLayoutPtr;

public:
	SLATE_BEGIN_ARGS(SWdigetDemoB) {}
	SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)

	{
		this->ChildSlot
			[
		//	/*SNew(SEventTest)
		//	.OnStartLogin(this,&SWdigetDemoB::Onlogin)*/
				SAssignNew(SLayoutPtr,SAutoLayout)
			
			
			
			
			];

		for (int32 i = 0; i < 80; i++)
		{
			SLayoutPtr->AddSlot()
				[


					SNew(SButton)
					.Text(FText::FromString(FString::FromInt(i)))

				];
		}

		}


	};




#undef LOCTEXT_NAMESPACE