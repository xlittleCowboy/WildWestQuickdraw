// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyWidget.h"

void UCowboyWidget::LoadNextLevel()
{
	TArray<FName> LevelsNames = GetLevelsNames();
	for(int32 i = 0; i < LevelsNames.Num(); i++)
	{
		if (LevelsNames[i].ToString() == UGameplayStatics::GetCurrentLevelName(this) && i != LevelsNames.Num() - 1)
		{
			UGameplayStatics::OpenLevel(this, LevelsNames[i + 1]);
		}
	}
}

void UCowboyWidget::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}
