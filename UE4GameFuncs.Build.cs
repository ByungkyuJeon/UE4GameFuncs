// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE4GameFuncs : ModuleRules
{
	public UE4GameFuncs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
