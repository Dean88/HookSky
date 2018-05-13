// Copyright 1998-2017 Moba, Inc. All Rights Reserved.

/*===================================================================================
	CustomScalabilityFunctionLibrary.h: Custom class for handling scalability settings,
	this will be used in game's MOBA setting page to custom control saclability
=====================================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Classes/Kismet/BlueprintFunctionLibrary.h"

#include "CustomScalabilityFunctionLibrary.generated.h"

//add custom scalability level, just simple and have three level according to the setting UI page
UENUM(BlueprintType)
	enum class ECustomScalabilityQualityLevel : uint8
{
	/** Resolution: 50%
		Dynamic Shadow: Off
		Particle: 
	*/
	Low,

	/** Resolution: 70%
		Dynamic Shadow: half effect
		Particle:
	*/
	Middle,

	/** Resolution: 100%
		Dynamic Shadow: full effect, soft shadow
		Particle:
	*/
	High,
};

// add custom scalability level, just simple and have three level according to the setting UI page
// UENUM(BlueprintType)
// enum class ECustomResolutionLevelValue : uint8
// {
// 	LowResolution = 50,
// 	MiddleResolution = 75,
// 	HighResolution = 100,

	
// };
//#define CUSTOM_RESOLUTION_TYPE_THRESHOLD 5

UCLASS()
class ENGINE_API UCustomScalabilityBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Load and return the custom screen quality level from saved file*/
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static ECustomScalabilityQualityLevel GetCustomScreenQualityLevel();

	/** Set and saved the custom screen quality level from saved file*/
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static void SetCustomScreenQualityLevel(ECustomScalabilityQualityLevel CustomScreenQualityLevel);

	/** Load and return the custom particle quality level from saved file*/
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static ECustomScalabilityQualityLevel GetCustomParticleQualityLevel();

	/** Set and saved the custom particle quality level from saved file*/
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static void SetCustomParticleQualityLevel(ECustomScalabilityQualityLevel CustomParticlenQualityLevel);

	/** Load and return AA state whether is enable from saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static bool IsEngineEnableAA();

	/** Enable Engine AA and store this state into saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static void EnableEngineAA(bool EnableAA);

	/** Load and return sound state whether is enable from saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static bool IsEngineEnableSound();

	/** Enable Engine sound and store this state into saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static void EnableEngineSound(bool EnableSound);

	/** Load and return music state whether is enable from saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static bool IsEngineEnableMusic();

	/** Enable Engine music and store this state into saved file */
	UFUNCTION(BlueprintCallable, Category = "Scalability")
	static void EnableEngineMusic(bool EnableMusic);

// 	/** Custom Minimum single axis scale for render resolution */
// 	static const float CustomMinResolutionScale = 50.0f;
// 
// 	/** Custom Maximum single axis scale for render resolution */
// 	static const float CustomMaxResolutionScale = 100.0f;

protected:
	static ECustomScalabilityQualityLevel GetCustomResolutionQualityLevel();
	static void SetCustomResoutionQualityLevel(ECustomScalabilityQualityLevel CustomResolutionLevel);
};
