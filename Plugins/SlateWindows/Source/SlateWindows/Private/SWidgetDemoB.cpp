#include "../Public/SWidgetDemoB.h"

void SWdigetDemoB::Onlogin(FString usn, FString pwd)
{
	UE_LOG(LogTemp, Warning, TEXT("��ʼ��½ %s-%s"), *usn, *pwd);
}
