// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SlateWindowsStyle.h"

class FSlateWindowsCommands : public TCommands<FSlateWindowsCommands>
{
public:

	FSlateWindowsCommands()
		: TCommands<FSlateWindowsCommands>(TEXT("SlateWindows"), NSLOCTEXT("Contexts", "SlateWindows", "SlateWindows Plugin"), NAME_None, FSlateWindowsStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};