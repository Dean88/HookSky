// Copyright 1998-2017 Moba, Inc. All Rights Reserved.

/*===================================================================================
CustomScalabilityFunctionLibrary.h: Custom class for handling scalability settings,
this will be used in game's MOBA setting page to custom control saclability
=====================================================================================*/

#pragma once

#include "CustomScalabilityFunctionLibrary.h"
#include "HAL/IConsoleManager.h"

//SetGroupQualityLevel(TEXT("AntiAliasingQuality"), Var->GetInt(), CVarAntiAliasingQuality_NumLevels->GetInt());


#define CUSTOM_RESOLUTION_VALUE_LOW 50
#define CUSTOM_RESOLUTION_VALUE_MIDDLE 75
#define CUSTOM_RESOLUTION_VALUE_HIGH 100
#define CUSTOM_RESOLUTION_TYPE_THRESHOLD 5

// static void SetCustomGroupQualityLevel(const TCHAR* InGroupName, int32 InQualityLevel, int32 InNumLevels)
// {
// 	check(InNumLevels > 0);
// 	const int32 MaxLevel = InNumLevels - 1;
// 	InQualityLevel = FMath::Clamp(InQualityLevel, 0, MaxLevel);
// 
// 	//	UE_LOG(LogConsoleResponse, Display, TEXT("  %s %d"), InGroupName, InQualityLevel);
// 
// 	if (InQualityLevel == MaxLevel)
// 	{
// 		ApplyCVarSettingsGroupFromIni(InGroupName, TEXT("Cine"), *GScalabilityIni, ECVF_SetByScalability);
// 	}
// 	else
// 	{
// 		ApplyCVarSettingsGroupFromIni(InGroupName, InQualityLevel, *GScalabilityIni, ECVF_SetByScalability);
// 	}
//
ECustomScalabilityQualityLevel UCustomScalabilityBlueprintFunctionLibrary::GetCustomResolutionQualityLevel()
{
	static IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));
	float Resolution = CVar->GetFloat();
	if (Resolution >= CUSTOM_RESOLUTION_VALUE_HIGH - CUSTOM_RESOLUTION_TYPE_THRESHOLD)
	{
		return ECustomScalabilityQualityLevel::High;
	}
	else if(Resolution >= CUSTOM_RESOLUTION_VALUE_MIDDLE - CUSTOM_RESOLUTION_TYPE_THRESHOLD)
	{
		return ECustomScalabilityQualityLevel::Middle;
	}
	else if (Resolution >= CUSTOM_RESOLUTION_VALUE_LOW - CUSTOM_RESOLUTION_TYPE_THRESHOLD)
	{
		return ECustomScalabilityQualityLevel::Low;
	}
	else
	{
		return ECustomScalabilityQualityLevel::Low;
	}
}

void UCustomScalabilityBlueprintFunctionLibrary::SetCustomResoutionQualityLevel(ECustomScalabilityQualityLevel CustomResolutionLevel)
{
	float NewResolution = CUSTOM_RESOLUTION_VALUE_HIGH;

	switch (CustomResolutionLevel)
	{
	case ECustomScalabilityQualityLevel::High:
		NewResolution = CUSTOM_RESOLUTION_VALUE_HIGH;
		break;
	case ECustomScalabilityQualityLevel::Middle:
		NewResolution = CUSTOM_RESOLUTION_VALUE_MIDDLE;
		break;
	case ECustomScalabilityQualityLevel::Low:
		NewResolution = CUSTOM_RESOLUTION_VALUE_LOW;
		break;
	default:
		NewResolution = CUSTOM_RESOLUTION_VALUE_HIGH;
		break;
	}

	//NewResolution = FMath::Clamp(InResolutionQualityLevel, Scalability::MinResolutionScale, Scalability::MaxResolutionScale);

	//	UE_LOG(LogConsoleResponse, Display, TEXT("  ResolutionQuality %.2f"), "", NewResolution);

	static IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));

	// if it wasn't created yet we either need to change the order or store like we do for ini loading
	check(CVar);

	CVar->Set(NewResolution, ECVF_SetByScalability);
}

/** Load and return the custom screen quality level from saved file*/
ECustomScalabilityQualityLevel UCustomScalabilityBlueprintFunctionLibrary::GetCustomScreenQualityLevel()
{
	//just temp only support resolution feature now
	return GetCustomResolutionQualityLevel();
}

/** Set and saved the custom screen quality level from saved file*/
void UCustomScalabilityBlueprintFunctionLibrary::SetCustomScreenQualityLevel(ECustomScalabilityQualityLevel CustomScreenQualityLevel)
{
	//just temp only support resolution feature now
	SetCustomResoutionQualityLevel(CustomScreenQualityLevel);
}

/** Load and return the custom particle quality level from saved file*/
ECustomScalabilityQualityLevel UCustomScalabilityBlueprintFunctionLibrary::GetCustomParticleQualityLevel()
{
	return ECustomScalabilityQualityLevel::High;
}

/** Set and saved the custom particle quality level from saved file*/
void UCustomScalabilityBlueprintFunctionLibrary::SetCustomParticleQualityLevel(ECustomScalabilityQualityLevel CustomParticlenQualityLevel)
{
	switch (CustomParticlenQualityLevel)
	{
	case ECustomScalabilityQualityLevel::Low:

		break;
	case ECustomScalabilityQualityLevel::Middle:

		break;
	case ECustomScalabilityQualityLevel::High:

		break;
	default:
		break;
	}
}

/** Load and return AA state whether is enable from saved file */
bool UCustomScalabilityBlueprintFunctionLibrary::IsEngineEnableAA()
{
	return false;
}

/** Enable Engine AA and store this state into saved file */
void UCustomScalabilityBlueprintFunctionLibrary::EnableEngineAA(bool EnableAA)
{

}

/** Load and return sound state whether is enable from saved file */
bool UCustomScalabilityBlueprintFunctionLibrary::IsEngineEnableSound()
{
	return false;
}

/** Enable Engine sound and store this state into saved file */
void UCustomScalabilityBlueprintFunctionLibrary::EnableEngineSound(bool EnableSound)
{

}

/** Load and return music state whether is enable from saved file */
bool UCustomScalabilityBlueprintFunctionLibrary::IsEngineEnableMusic()
{
	return false;
}

/** Enable Engine music and store this state into saved file */
void UCustomScalabilityBlueprintFunctionLibrary::EnableEngineMusic(bool EnableMusic)
{

}
