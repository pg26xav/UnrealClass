// PG26Xav 2024


#include "Actors/Alien.h"
#include "Logging/StructuredLog.h"
#include "Components/UHealthComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AAlien::AAlien()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle CallEventHandle;
	GetWorld()->GetTimerManager().SetTimer(CallEventHandle,  this, &ThisClass::CallEvents, 1.0f);
	if(IsValid(HealthComponent))
	{
		HealthComponent->OnHealthUpdated.AddUniqueDynamic(this, &ThisClass::OnHealthUpdated);
	}
	OnActorHit.AddUniqueDynamic(this, &ThisClass::OnLivingOrganismHit);
	
}

// Called every frame
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlien::DoDamage_Implementation(float DmgAmt)
{
	if(IsValid(HealthComponent))
	{
		HealthComponent->UpdateHealth(DmgAmt);
	}
}

void AAlien::Move_Implementation()
{
	Super::Move_Implementation();
}

void AAlien::OnHealthUpdated(float oldHealth, float newHealth)
{
	if(newHealth <= 0.0f)
	{
		Destroy();
	}
}

void AAlien::OnAlienHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (SelfActor == OtherActor)
	{
		return;
	}

	if(OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_DoDamage(OtherActor, 5.0f);
	}
}

void AAlien::CallEvents()
{
	SingleDele.ExecuteIfBound(25.0f);
	if (SingleReturnDele.IsBound())
	{
		UE_LOGFMT(LogTemp,Display,"Return Value from single delegate {0}",SingleReturnDele.Execute());
	}
	
	MulticastDele.Broadcast();
	DynamicDelegateWithTwoParams.ExecuteIfBound(20.0f, true);
	if (DynamicDeleRetValWithTwoParams.IsBound())
	{
		UE_LOGFMT(LogTemp, Display, "Return Value from Dynamic Delegate : {0}", DynamicDeleRetValWithTwoParams.Execute(5,10));
	}
	DynamicMulticastDele.Broadcast();
}

