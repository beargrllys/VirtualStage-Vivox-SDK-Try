// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VivoxCore.h"
#include "Try6GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TRY6_API UTry6GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	virtual void Logout();
	
};
