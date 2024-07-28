// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "GameFramework/Actor.h"
#include "Alien.generated.h"


class UHealthComponent;
class UStaticMeshComponent;
class UArrowComponent;
UCLASS()
class UNREALCLASSWON_API AAlien : public ALivingOrganism
{
	GENERATED_BODY()
	AAlien();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//override damage
	virtual void DoDamage_Implementation(float DmgAmt) override;
	
	void Move_Implementation();
	
	float MovementSpeed;
	
	virtual void OnHealthUpdated(float oldHealth, float newHealth) override;
	
	void OnAlienHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	//timer
	virtual void CallEvents() override;
};
