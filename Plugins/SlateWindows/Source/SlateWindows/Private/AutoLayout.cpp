#include "../Public/AutoLayout.h"

void SAutoLayout::OnArrangeChildren(const FGeometry & AllotteGeometry, FArrangedChildren & ArrangeChildren) const
{
	//areaSize �����ĳߴ�
	FVector2D areaSize = AllotteGeometry.GetLocalSize();
	float startX = ContentMargin.Left;
	float startY = ContentMargin.Top;
	float currentMaxHeight = 0.0f;
	for (int32 ChilIndex = 0; ChilIndex < Children.Num(); ChilIndex++)
	{
		const SBoxPanel::FSlot &CurChild = Children[ChilIndex];
	const	EVisibility ChildVisibility = CurChild.GetWidget()->GetVisibility();
	//��ȡԪ�صĳߴ�
	FVector2D size = CurChild.GetWidget()->GetDesiredSize();
	//Accepts �����ж�һ��Ԫ���Ƿ�������
	if (ArrangeChildren.Accepts(ChildVisibility))
	{
		if (size.Y>currentMaxHeight)
		{
			currentMaxHeight = size.Y;
		}
//�ж�StartX�Ƿ񳬹������Ŀ�ȡ�
		if (startX+size.Y<areaSize.X)
		{
			ArrangeChildren.AddWidget(ChildVisibility, AllotteGeometry.MakeChild(CurChild.GetWidget(), FVector2D(startX, startY),FVector2D(startX,startY)));
			startX += ContentMargin.Right;
			startX += size.X;


		}
		else
		{
			//������Ⱥ󣬽�startx����Ϊ�����
			startX = ContentMargin.Left;

			//ͬʱstartY����һ�߶�
			startY += currentMaxHeight + ContentMargin.Bottom;
			ArrangeChildren.AddWidget(ChildVisibility, AllotteGeometry.MakeChild(CurChild.GetWidget(), FVector2D(startX, startY), FVector2D(size.X, size.Y)));
			startX += size.X + ContentMargin.Right;
			currentMaxHeight = size.Y;
		}
	}
	}
}

void SAutoLayout::Construct(const FArguments & InArgs)
{

	const int32 NumSlots = InArgs.Slots.Num();
	ContentMargin = InArgs._ContentMargin.Get();
	for (int32 SlotIndex = 0; SlotIndex < NumSlots; SlotIndex++)
	{
		Children.Add(InArgs.Slots[SlotIndex]);
	}
	
}
