// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ALivingOrganismSpawner.generated.h"

class ALivingOrganism;
DECLARE_LOG_CATEGORY_EXTERN(LivingOrganism,Log,All);

UCLASS()
class UNREALCLASSWON_API ALivingOrganismSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALivingOrganismSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Spawn parameters")
	TSubclassOf<ALivingOrganism> OrganismToSpawn;

	void Spawn();

	UFUNCTION()
	void MyFloatFunction(float p1);

	UFUNCTION()
	bool MyBoolRetFunction();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnSFX();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnVFX();

	UFUNCTION()
	void MyFloatBoolFunction(float p1, bool p2);

	UFUNCTION()
	int32 Add(int32 p1, int32 p2);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayExplosion();
};
