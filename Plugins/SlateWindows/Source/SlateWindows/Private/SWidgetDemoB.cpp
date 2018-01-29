#include "../Public/SWidgetDemoB.h"

void SWdigetDemoB::Onlogin(FString usn, FString pwd)
{
	UE_LOG(LogTemp, Warning, TEXT("¿ªÊ¼µÇÂ½ %s-%s"), *usn, *pwd);
}
