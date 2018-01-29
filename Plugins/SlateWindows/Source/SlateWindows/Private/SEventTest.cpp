#include "../Public/SEventTest.h"

FReply SEventTest::OnLoginButtonClicked()
{
	FString usn = UserNamePtr->GetText().ToString();
	FString pwd = PasswordPtr->GetText().ToString();
	OnloginDelegate.ExecuteIfBound(usn, pwd);
	return FReply::Handled();
}
