

#include "SWdigetDemoA.h"

FReply SWdigetDemoA::OnLoginButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("loginbutton"));
	return FReply::Handled();
}
