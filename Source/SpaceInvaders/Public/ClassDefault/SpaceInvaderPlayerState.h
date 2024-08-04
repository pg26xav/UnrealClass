// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/Components/SIScoreComponent.h"
#include "GameFramework/PlayerState.h"
#include "SpaceInvaderPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvaderPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASpaceInvaderPlayerState(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USIScoreComponent> ScoreComponent;
	
};
