// PG26Xav 2024

#include "Actors/LivingOrganism.h"
#include "Components/UHealthComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Logging/StructuredLog.h"
#include "TimerManager.h"

// Sets default values
ALivingOrganism::ALivingOrganism()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Living Organism Health Component"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Body"));
	SetRootComponent(Body);
	
	Nose = CreateDefaultSubobject<UArrowComponent>(TEXT("Nose"));
	Nose->SetupAttachment(RootComponent);

	//simulate physics setup
	Body->SetSimulatePhysics(true);
	//tells the static mesh component to react to collision events
	Body->SetNotifyRigidBodyCollision(true);
	// constraint plane
	Body->SetConstraintMode(EDOFMode::XYPlane);
}

// Called when the game starts or when spawned
void ALivingOrganism::BeginPlay()
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

void ALivingOrganism::DoDamage_Implementation(float DmgAmt)
{
	if(IsValid(HealthComponent))
	{
		HealthComponent->UpdateHealth(DmgAmt);
	}
}

// Called every frame
void ALivingOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ALivingOrganism::CallEvents()
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

void ALivingOrganism::OnHealthUpdated(float oldHealth, float newHealth)
{
	if(newHealth <= 0.0f)
	{
		Destroy();
	}
}

void ALivingOrganism::OnLivingOrganismHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
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

void ALivingOrganism::Move_Implementation()
{
	UE_LOGFMT(LogTemp, Display, "Moving");
	const FVector Velocity = Nose->GetForwardVector() * MovementSpeed;
	Body->AddForce(Velocity * Body->GetMass(), NAME_None, true);
}

