// PG26Xav 2024


#include "Components/Components/SIScoreComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
USIScoreComponent::USIScoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
	// ...
}

void USIScoreComponent::AddScore_Implementation(const int32 scoreToAdd)
{
	Score += scoreToAdd;
}


// Called when the game starts
void USIScoreComponent::BeginPlay()
{
	Super::BeginPlay();
	Score = 0;
	// ...
	
}


// Called every frame
void USIScoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USIScoreComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USIScoreComponent, Score);
}

