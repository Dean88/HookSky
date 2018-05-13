#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Image.h"
#include "CheckBox.h"
#include "DebugMenuPanel.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDebugMenuPanelCheckBoxChangeDelegate, UCheckBox*, CheckBox, bool, IsChecked);

UCLASS()
class HOOKSKY_API UDebugMenuPanel : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

public:
	virtual bool Initialize()override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UFUNCTION(BlueprintCallable)
	void TestFunction();

	UFUNCTION()
	void ProcessCheckBoxEnableAAChanged(bool EnableAA);
	UFUNCTION()
	void ProcessCheckBoxHighScreenQualityChanged(bool EnableAA);
	UFUNCTION()
	void ProcessCheckBoxMiddleScreenQualityChanged(bool EnableAA);
	UFUNCTION()
	void ProcessCheckBoxLowScreenQualityChanged(bool EnableAA);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UImage* ImageBackground = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UCheckBox* CBEnableAA = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UCheckBox* CBHighScreenQuality = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UCheckBox* CBMiddleScreenQuality = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UCheckBox* CBLowScreenQuality = nullptr;

	UPROPERTY(BlueprintAssignable, Category = "DebugMenuPanel")
	FDebugMenuPanelCheckBoxChangeDelegate OnAAEnableChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "DebugMenuPanel")
	FDebugMenuPanelCheckBoxChangeDelegate OnHighScreenQualityChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "DebugMenuPanel")
	FDebugMenuPanelCheckBoxChangeDelegate OnMiddleScreenQualityChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "DebugMenuPanel")
	FDebugMenuPanelCheckBoxChangeDelegate OnLowScreenQualityChangedDelegate;

};