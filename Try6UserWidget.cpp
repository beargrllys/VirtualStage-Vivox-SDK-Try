// Fill out your copyright notice in the Description page of Project Settings.


#include "Try6UserWidget.h"
#include "Components/Button.h"
#include "Try6GameInstance.h"

FVivoxCoreModule* vModule;


bool UTry6UserWidget::Initialize()
{

	Super::Initialize();

	LogoutButton->OnClicked.AddDynamic(this, &UTry6UserWidget::LogoutButtonClicked);

	return false;
}

void UTry6UserWidget::LogoutButtonClicked()
{
	UTry6GameInstance.

	UE_LOG(LogTemp, Warning, TEXT("Logout Done!"));

}
