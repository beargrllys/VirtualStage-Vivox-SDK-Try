// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VivoxCore.h"
#include "Try6UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRY6_API UTry6UserWidget : public UUserWidget
{
	GENERATED_BODY()

		virtual bool Initialize();

		UPROPERTY(meta = (BindWidget))
			class UButton* LogoutButton;

		UFUNCTION()
			void LogoutButtonClicked();


};
