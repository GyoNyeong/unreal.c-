// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cpp_Project : ModuleRules
{
	public Cpp_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
