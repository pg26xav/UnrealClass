// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpaceInvaderGameOver.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API USpaceInvaderGameOver : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Restart();
	
};
