#include "SEditableTextBox.h"
#include  "SlateBasics.h"
#pragma once

#define LOCTEXT_NAMESPACE "SEventTest"
DECLARE_DELEGATE_TwoParams(FloginDelegate, FString, FString);

class SEventTest :public SCompoundWidget
{
public:
	FReply OnLoginButtonClicked();
	FloginDelegate OnloginDelegate;
	TSharedPtr<SButton> LoginButtonPtr; 
	TSharedPtr<SEditableTextBox> UserNamePtr;
	TSharedPtr<SEditableTextBox> PasswordPtr;
	

public:
	SLATE_BEGIN_ARGS(SEventTest) {}
	SLATE_EVENT(FloginDelegate,OnStartLogin)
	SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)

	{
		OnloginDelegate = InArgs._OnStartLogin;
		this->ChildSlot.Padding(50,50,50,50)
			[
			SNew(SVerticalBox)
			+SVerticalBox::Slot().AutoHeight()
			[
			SAssignNew(UserNamePtr,SEditableTextBox)
			.HintText(LOCTEXT("username", "UserName"))
			
			
			
			
			]
		+SVerticalBox::Slot().AutoHeight()
			[
			SAssignNew(PasswordPtr,SEditableTextBox)
			.HintText(LOCTEXT("password", "Password"))
			
			
			]
		+SVerticalBox::Slot().AutoHeight()
			[
			
			SAssignNew(LoginButtonPtr,SButton)
			.OnClicked(this,&SEventTest::OnLoginButtonClicked)
			.Text(LOCTEXT("login","µÇÂ¼"))
			
			]
			];

	}

	};
#undef LOCTEXT_NAMESPACE