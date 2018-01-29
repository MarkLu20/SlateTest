#include"SCompoundWidget.h"
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

public:
	SLATE_BEGIN_ARGS(SWdigetDemoB) {}
	SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)

	{
		this->ChildSlot
			[
			SNew(SEventTest)
			.OnStartLogin(this,&SWdigetDemoB::Onlogin)
			
			
			
			
			];


		}


	};




#undef LOCTEXT_NAMESPACE