// PG26Xav 2024


#include "Spawners/Bullet.h"
#include "ClassDefault/SpaceInvaderPawn.h"
#include "Components/Components/SIScoreComponent.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetSphereRadius(10.0f); 
	RootComponent = CollisionComponent;
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnBulletOverLap);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::DestroyBullet()
{
	Destroy();
}

void ABullet::OnBulletOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!HasAuthority()) return;

	if (OtherActor && OtherActor != this)
	{
		const float dmgDone = UGameplayStatics::ApplyDamage(OtherActor,10.0f,nullptr,this,nullptr);
		TObjectPtr<ASpaceInvaderPawn> OwningSpacePlayer = Cast<ASpaceInvaderPawn>(GetOwner());
		if (IsValid(OwningSpacePlayer))
		{
			const TObjectPtr<APlayerState> PlayerState = OwningSpacePlayer->GetPlayerState();
			if (IsValid(PlayerState))
			{
				TObjectPtr<USIScoreComponent> ScoreComponent = PlayerState->FindComponentByClass<USIScoreComponent>();
				if (IsValid(ScoreComponent))
				{
					ScoreComponent->AddScore(10);
				}
			}
		}
		Destroy();
	}
}

