// PG26Xav 2024


#include "Characters/Enemy.h"
#include "Components/SIHealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	HealthComponent = CreateDefaultSubobject<USIHealthComponent>(TEXT("Health Component"));
	HealthComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(HealthComponent))
	{
		OnTakeAnyDamage.AddUniqueDynamic(HealthComponent.Get(), &USIHealthComponent::TakeDamage);
	}
	
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		const float dmgDone = UGameplayStatics::ApplyDamage(OtherActor,10.0f,nullptr, this,nullptr);
		Destroy();
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

