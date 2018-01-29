// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SlateWindowsCommands.h"

#define LOCTEXT_NAMESPACE "FSlateWindowsModule"

void FSlateWindowsCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "SlateWindows", "Bring up SlateWindows window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
