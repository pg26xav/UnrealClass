// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/LivingOrganism.h"
#include "Predator.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLASSWON_API APredator : public ALivingOrganism
{
	GENERATED_BODY()

public:
	//override damage
	virtual void DoDamage_Implementation(float DmgAmt) override;
	
	virtual void OnHealthUpdated(float oldHealth, float newHealth) override;

	UFUNCTION()
	void OnPredatorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
