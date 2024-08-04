// PG26Xav 2024


#include "ClassDefault/SpaceInvaderPawn.h"
#include "Spawners/Bullet.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/SIHealthComponent.h"
#include "ClassDefault/SpaceInvaderGameStateBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpaceInvaderPawn::ASpaceInvaderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<USIHealthComponent>(TEXT("Health Component"));
	HealthComponent->SetIsReplicated(true);
	ShootPOS = CreateDefaultSubobject<USceneComponent>(TEXT("Shoot POS"));
	ShootPOS->SetupAttachment(RootComponent);
	
}

void ASpaceInvaderPawn::Shoot_Implementation(const FInputActionValue& Value)
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	spawnParams.Owner = this;
	GetWorld()->SpawnActor<ABullet>(BulletToSpawn, ShootPOS->GetComponentLocation(), FRotator::ZeroRotator, spawnParams);
}

void ASpaceInvaderPawn::Destroyed()
{
	Super::Destroyed();

	TObjectPtr<ASpaceInvaderGameStateBase> GameState = GetWorld()->GetGameState<ASpaceInvaderGameStateBase>();
	if (HasAuthority() && IsValid(GameState)) GameState->EndGame();
}

// Called when the game starts or when spawned
void ASpaceInvaderPawn::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(HealthComponent))
	{
		OnTakeAnyDamage.AddUniqueDynamic(HealthComponent.Get(), &USIHealthComponent::TakeDamage);
		OnActorBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnOverlapBegin);
	}
}

void ASpaceInvaderPawn::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this) UGameplayStatics::ApplyDamage(OtherActor,1.0f,nullptr, this, nullptr);
}

// Called every frame
void ASpaceInvaderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceInvaderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	if (IsValid(Input))
	{
		if (IsValid(FireAction))
		{
			Input->BindAction(FireAction, ETriggerEvent::Triggered, this, &ThisClass::Shoot);
		}
	}
}

