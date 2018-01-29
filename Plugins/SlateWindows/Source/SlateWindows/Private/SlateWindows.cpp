// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SlateWindows.h"
#include  "SWdigetDemoA.h"
#include  "SWidgetDemoB.h"
#include "SlateWindowsStyle.h"
#include "SlateWindowsCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName SlateWindowsTabName("SlateWindows");

#define LOCTEXT_NAMESPACE "FSlateWindowsModule"

void FSlateWindowsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSlateWindowsStyle::Initialize();
	FSlateWindowsStyle::ReloadTextures();

	FSlateWindowsCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSlateWindowsCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FSlateWindowsModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FSlateWindowsModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FSlateWindowsModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SlateWindowsTabName, FOnSpawnTab::CreateRaw(this, &FSlateWindowsModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FSlateWindowsTabTitle", "SlateWindows"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FSlateWindowsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FSlateWindowsStyle::Shutdown();

	FSlateWindowsCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(SlateWindowsTabName);
}

TSharedRef<SDockTab> FSlateWindowsModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FSlateWindowsModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("SlateWindows.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			/*SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)*/
			SNew(SWdigetDemoB)
			
	
	
		];
}

void FSlateWindowsModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(SlateWindowsTabName);
}

void FSlateWindowsModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FSlateWindowsCommands::Get().OpenPluginWindow);
}

void FSlateWindowsModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FSlateWindowsCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateWindowsModule, SlateWindows)