// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AEnemy;

UCLASS()
class SPACEINVADERS_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Spawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Spawn Parameters")
	TSubclassOf<AEnemy> EnemyToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnDelay;

private:
	FTimerHandle SpawnTimer;
	
};
