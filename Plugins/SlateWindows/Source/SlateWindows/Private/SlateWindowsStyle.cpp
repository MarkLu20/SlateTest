// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SlateWindowsStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "SlateGameResources.h"
#include "IPluginManager.h"

TSharedPtr< FSlateStyleSet > FSlateWindowsStyle::StyleInstance = NULL;

void FSlateWindowsStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FSlateWindowsStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FSlateWindowsStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("SlateWindowsStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FSlateWindowsStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("SlateWindowsStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("SlateWindows")->GetBaseDir() / TEXT("Resources"));

	Style->Set("SlateWindows.OpenPluginWindow", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));
	Style->Set("BG", new IMAGE_BRUSH(TEXT("bg"), FVector2D(1022,1024)));
	FMargin Button1Margin(2.0 / 1.0f, 2.0 / 10.0f, 2.0 / 10.0f, 2.0 / 10.0f);

	Style->Set("UI.Button1", FButtonStyle().SetNormal(BOX_BRUSH("Button_N", Button1Margin))
		.SetHovered(BOX_BRUSH("Button_H", Button1Margin))
		.SetPressed(BOX_BRUSH("Button_N", Button1Margin))
		.SetDisabled(BOX_BRUSH("Button_N", Button1Margin))

	);
	Style->Set("UI.InputLineText", FEditableTextBoxStyle().SetBackgroundImageNormal(BOX_BRUSH("Button_N", Button1Margin))
		.SetBackgroundImageFocused(BOX_BRUSH("Button_N", Button1Margin))
	);
	//Style->Set();

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FSlateWindowsStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FSlateWindowsStyle::Get()
{
	return *StyleInstance;
}
