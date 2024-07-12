// PG26Xav 2024

#include "Actors/ALivingOrganismSpawner.h"
#include "Actors/LivingOrganism.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(LivingOrganism);

// Sets default values
ALivingOrganismSpawner::ALivingOrganismSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ALivingOrganismSpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void ALivingOrganismSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALivingOrganismSpawner::Spawn()
{
	// Spawning

	if (!IsValid(OrganismToSpawn))
	{
		return;
	}

	TObjectPtr<UWorld> World = GetWorld();

	if (IsValid(World))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        
		TObjectPtr<ALivingOrganism> NewOrganism = World->SpawnActor<ALivingOrganism>(OrganismToSpawn, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);
		if (IsValid(NewOrganism))
		{
			NewOrganism->Move();
			NewOrganism->DoSomething();

			// Binding Delegates
			NewOrganism->SingleDele.BindUObject(this, &ALivingOrganismSpawner::MyFloatFunction);
			NewOrganism->SingleReturnDele.BindUObject(this, &ThisClass::MyBoolRetFunction);
			NewOrganism->MulticastDele.AddUObject(this, &ThisClass::SpawnSFX);
			NewOrganism->MulticastDele.AddUObject(this, &ThisClass::SpawnVFX);
			NewOrganism->DynamicDelegateWithTwoParams.BindDynamic(this, &ThisClass::MyFloatBoolFunction);
			NewOrganism->DynamicDeleRetValWithTwoParams.BindDynamic(this, &ThisClass::Add);
			NewOrganism->DynamicMulticastDele.AddUniqueDynamic(this, &ThisClass::PlayExplosion);
		}
	}
}

void ALivingOrganismSpawner::MyFloatFunction(float p1)
{
	UE_LOGFMT(LivingOrganism, Display, "single cast {0}", p1);
}

bool ALivingOrganismSpawner::MyBoolRetFunction()
{
	UE_LOGFMT(LivingOrganism, Display, "single cast ret value called");
	return false;
}

void ALivingOrganismSpawner::MyFloatBoolFunction(float p1, bool p2)
{
	UE_LOGFMT(LivingOrganism, Display, "dynamic delegate with 2 params called {0} and {1}", p1, p2);
}

int32 ALivingOrganismSpawner::Add(int32 p1, int32 p2)
{
	UE_LOGFMT(LivingOrganism, Display, "dynamic delegate with 2 params and ret value called {0} and {1}", p1, p2);
	return p1 + p2;
}