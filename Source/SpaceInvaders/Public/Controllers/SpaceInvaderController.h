// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceInvaderController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvaderController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;
	
};
