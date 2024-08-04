// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SpaceInvaderGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvaderGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> EndScreen;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void EndGame();

	UFUNCTION(NetMulticast, Reliable)
	void EndGameClient();
};
