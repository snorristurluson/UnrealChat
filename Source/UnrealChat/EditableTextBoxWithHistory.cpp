// Fill out your copyright notice in the Description page of Project Settings.


#include "EditableTextBoxWithHistory.h"

#include "Widgets/Input/SEditableTextBox.h"

void UEditableTextBoxWithHistory::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	MyEditableTextBlock->SetOnKeyDownHandler(FOnKeyDown::CreateUObject(this, &UEditableTextBoxWithHistory::OnKeyDown));
}

FReply UEditableTextBoxWithHistory::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	if (History.IsEmpty())
	{
		return FReply::Unhandled();
	}
	
	if (KeyEvent.GetKey() == EKeys::Up)
	{
		HistoryIndex--;
		if (HistoryIndex < 0)
		{
			HistoryIndex = 0;
		}
		SetText(History[HistoryIndex]);
	} else if (KeyEvent.GetKey() == EKeys::Down)
	{
		HistoryIndex++;
		if (HistoryIndex >= History.Num())
		{
			SetText(FText());
			HistoryIndex = History.Num();
		} else
		{
			SetText(History[HistoryIndex]);
		}
	}

	return FReply::Unhandled();
}

void UEditableTextBoxWithHistory::HandleOnTextCommitted(const FText& InText, ETextCommit::Type CommitMethod)
{
	Super::HandleOnTextCommitted(InText, CommitMethod);
	if (CommitMethod == ETextCommit::OnEnter)
	{
		History.Add(InText);
		if (History.Num() > 10)
		{
			History.RemoveAt(0);
		}
		HistoryIndex = History.Num();
	}
}
