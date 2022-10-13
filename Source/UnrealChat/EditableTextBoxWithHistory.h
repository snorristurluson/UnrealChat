// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "UObject/Object.h"
#include "EditableTextBoxWithHistory.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHAT_API UEditableTextBoxWithHistory : public UEditableTextBox
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> History;

	int32 HistoryIndex = -1;
	
	virtual void OnWidgetRebuilt() override;

	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent);

	virtual void HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod) override;
};
