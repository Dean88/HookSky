#include "DebugMenuPanel.h"

bool UDebugMenuPanel::Initialize()
{
	Super::Initialize();

	//CBEnableAA->OnCheckStateChanged.
	//OnAAEnableChanged.Broadcast(CBEnableAA, true);
	//	OnAAEnableChanged.
	//	HitButton->TouchStartedDelegate.BindUObject(this, &UAlphaHitButton::SlateHandleTouchStarted);
	//OnAAEnableChangedDelegate.BindUObject(this, &UDebugMenuPanel::);
//	CBEnableAA = SNew(SCheckBox)
//		;
// 		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
// 		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
// 		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
// 		.OnHovered_UObject(this, &ThisClass::SlateHandleHovered)
// 		.OnUnhovered_UObject(this, &ThisClass::SlateHandleUnhovered)
// 		.ButtonStyle(&WidgetStyle)
// 		.ClickMethod(ClickMethod)
// 		.TouchMethod(TouchMethod)
// 		.IsFocusable(IsFocusable)
// 		;
//	CBEnableAA = SNew(SCheckBox);
	
//	FMenuBuilder MenuBuilder(true, NULL);
//
// 	// get the curve data
// 	//if (CurrentlySelectedObject.IsValid())
// 	{
// 		MenuBuilder.BeginSection("HumanRigDetails_SetupSpineLabel", LOCTEXT("SetupSpine_Heading", "Add Spine"));
// 		{
// 			MenuBuilder.AddWidget(
// 				SNew(SVerticalBox)
// 
// 				+ SVerticalBox::Slot()
// 				.AutoHeight()
// 				.Padding(3)
// 				[
// 					SNew(SHorizontalBox)
// 
// 					+ SHorizontalBox::Slot()
// 				.AutoWidth()
// 				.Padding(2, 0)
// 				[
// 					SNew(STextBlock)
// 					.Text(LOCTEXT("SetupSpine_0", "Top Node"))
// 				]
// 			+ SHorizontalBox::Slot()
// 				.AutoWidth()
// 				.Padding(2, 0)
// 				[
// 					SNew(SEditableTextBox)
// 					.Text(this, &FHumanRigDetails::OnGetNodeInputText, 0)
// 				.OnTextCommitted(this, &FHumanRigDetails::OnNodeInputTextCommitted, 0)
// 				.SelectAllTextWhenFocused(true)
// 				.RevertTextOnEscape(true)
// 				.MinDesiredWidth(30.f)
// 				]
// 				]
// 
// 			+ SVerticalBox::Slot()
// 				.AutoHeight()
// 				.Padding(3)
// 				[
// 					SNew(SHorizontalBox)
// 
// 					+ SHorizontalBox::Slot()
// 				.AutoWidth()
// 				.Padding(2, 0)
// 				[
// 					SNew(STextBlock)
// 					.Text(LOCTEXT("SetupSpine_1", "End Node"))
// 				]
// 			+ SHorizontalBox::Slot()
// 				.AutoWidth()
// 				.Padding(2, 0)
// 				[
// 					SNew(SEditableTextBox)
// 					.Text(this, &FHumanRigDetails::OnGetNodeInputText, 1)
// 				.OnTextCommitted(this, &FHumanRigDetails::OnNodeInputTextCommitted, 1)
// 				.SelectAllTextWhenFocused(true)
// 				.RevertTextOnEscape(true)
// 				.MinDesiredWidth(30.f)
// 				]
// 				]
// 			+ SVerticalBox::Slot()
// 				.AutoHeight()
// 				.Padding(3)
// 				[
// 					SNew(SButton)
// 					.Text(LOCTEXT("HumanRig_SetupSpineButton", "Setup"))
// 				.OnClicked(this, &FHumanRigDetails::SetupSpineButtonClicked)
// 				]
// 			,
// 				FText()
// 				);
// 		}
// 		MenuBuilder.EndSection();
// 	}
// 
// 	MenuBuilder.MakeWidget();


	if (CBEnableAA)
	{
		CBEnableAA->OnCheckStateChanged.AddDynamic(this, &UDebugMenuPanel::ProcessCheckBoxEnableAAChanged);
	}
	if (CBHighScreenQuality)
	{
		CBHighScreenQuality->OnCheckStateChanged.AddDynamic(this, &UDebugMenuPanel::ProcessCheckBoxHighScreenQualityChanged);
	}
	if (CBMiddleScreenQuality)
	{
		CBMiddleScreenQuality->OnCheckStateChanged.AddDynamic(this, &UDebugMenuPanel::ProcessCheckBoxMiddleScreenQualityChanged);
	}
	if (CBLowScreenQuality)
	{
		CBLowScreenQuality->OnCheckStateChanged.AddDynamic(this, &UDebugMenuPanel::ProcessCheckBoxLowScreenQualityChanged);
	}
	
	return true;
}

void UDebugMenuPanel::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	if (ImageBackground)
	{
		ImageBackground->ReleaseSlateResources(bReleaseChildren);
	}
	if (CBEnableAA)
	{
		CBEnableAA->ReleaseSlateResources(bReleaseChildren);
	}
	if (CBHighScreenQuality)
	{
		CBHighScreenQuality->ReleaseSlateResources(bReleaseChildren);
	}
	if (CBMiddleScreenQuality)
	{
		CBMiddleScreenQuality->ReleaseSlateResources(bReleaseChildren);
	}
	if (CBLowScreenQuality)
	{
		CBLowScreenQuality->ReleaseSlateResources(bReleaseChildren);
	}
}

void UDebugMenuPanel::NativeConstruct()
{
	Super::NativeConstruct();
}

void UDebugMenuPanel::TestFunction()
{

}

void UDebugMenuPanel::ProcessCheckBoxEnableAAChanged(bool EnableAA)
{
	OnAAEnableChangedDelegate.Broadcast(CBEnableAA, EnableAA);
}

void UDebugMenuPanel::ProcessCheckBoxHighScreenQualityChanged(bool IsChecked)
{
	CBHighScreenQuality->SetCheckedState(ECheckBoxState::Checked);
	CBMiddleScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);
	CBLowScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);

	OnHighScreenQualityChangedDelegate.Broadcast(CBHighScreenQuality, IsChecked);
}

void UDebugMenuPanel::ProcessCheckBoxMiddleScreenQualityChanged(bool IsChecked)
{
	CBHighScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);
	CBMiddleScreenQuality->SetCheckedState(ECheckBoxState::Checked);
	CBLowScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);

	OnMiddleScreenQualityChangedDelegate.Broadcast(CBMiddleScreenQuality, IsChecked);
}

void UDebugMenuPanel::ProcessCheckBoxLowScreenQualityChanged(bool IsChecked)
{
	CBHighScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);
	CBMiddleScreenQuality->SetCheckedState(ECheckBoxState::Unchecked);
	CBLowScreenQuality->SetCheckedState(ECheckBoxState::Checked);

	OnLowScreenQualityChangedDelegate.Broadcast(CBLowScreenQuality, IsChecked);
}