#include "../Public/DymicSlot.h"

FReply DymicSlot::OnLoginButtonCicked()
{
	return FReply::Handled();
}

FReply DymicSlot::ChageSlotProperty(int type)
{
	switch (type)
	{
	case 0:
		ButtonSlot->HAlign(HAlign_Left);
		break;
	case 1:
		ButtonSlot->HAlign(HAlign_Right);
		break;
	case 2:
		ButtonSlot->HAlign(HAlign_Center);
		break;
	case 3:
		ButtonSlot->HAlign(HAlign_Fill);
		break;
	
	}
	return FReply::Handled();
}
