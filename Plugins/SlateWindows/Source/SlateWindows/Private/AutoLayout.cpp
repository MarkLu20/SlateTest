#include "../Public/AutoLayout.h"

void SAutoLayout::OnArrangeChildren(const FGeometry & AllotteGeometry, FArrangedChildren & ArrangeChildren) const
{
	//areaSize 容器的尺寸
	FVector2D areaSize = AllotteGeometry.GetLocalSize();
	float startX = ContentMargin.Left;
	float startY = ContentMargin.Top;
	float currentMaxHeight = 0.0f;
	for (int32 ChilIndex = 0; ChilIndex < Children.Num(); ChilIndex++)
	{
		const SBoxPanel::FSlot &CurChild = Children[ChilIndex];
	const	EVisibility ChildVisibility = CurChild.GetWidget()->GetVisibility();
	//获取元素的尺寸
	FVector2D size = CurChild.GetWidget()->GetDesiredSize();
	//Accepts 用于判断一个元素是否参与计算
	if (ArrangeChildren.Accepts(ChildVisibility))
	{
		if (size.Y>currentMaxHeight)
		{
			currentMaxHeight = size.Y;
		}
//判断StartX是否超过容器的宽度。
		if (startX+size.Y<areaSize.X)
		{
			ArrangeChildren.AddWidget(ChildVisibility, AllotteGeometry.MakeChild(CurChild.GetWidget(), FVector2D(startX, startY),FVector2D(startX,startY)));
			startX += ContentMargin.Right;
			startX += size.X;


		}
		else
		{
			//超过宽度后，将startx设置为最左边
			startX = ContentMargin.Left;

			//同时startY增加一高度
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
