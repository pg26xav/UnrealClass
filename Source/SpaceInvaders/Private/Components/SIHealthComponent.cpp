// PG26Xav 2024


#include "Components/SIHealthComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
USIHealthComponent::USIHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicatedByDefault(true);

	// ...
}

void USIHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DmageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Health -= Damage;
	if (Health <= 0.0f) GetOwner()->Destroy();
}


// Called when the game starts
void USIHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	// ...
	
}

void USIHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USIHealthComponent, Health);
}


// Called every frame
void USIHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

