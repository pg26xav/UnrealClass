// PG26Xav 2024


#include "Spawners/EnemySpawner.h"
#include "Characters/Enemy.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority()) GetWorldTimerManager().SetTimer(SpawnTimer, this, &ThisClass::Spawn, SpawnDelay, true);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::Spawn()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AEnemy>(EnemyToSpawn, GetActorLocation() + FVector(0.0f,100.f,0.0f), FRotator::ZeroRotator, SpawnParams);
}

