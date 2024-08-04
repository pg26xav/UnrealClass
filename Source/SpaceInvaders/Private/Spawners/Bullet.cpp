// PG26Xav 2024


#include "Spawners/Bullet.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Pawn/SpaceInvaderPlayer.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetSphereRadius(10.0f); 
	RootComponent = CollisionComponent;
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBulletOverLap);
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
		TObjectPtr<ASpaceInvaderPlayer> OwningSpacePlayer = Cast<ASpaceInvaderPlayer>(GetOwner());
		if (IsValid(OwningSpacePlayer))
		{
			const TObjectPtr<APlayerState> PlayerState = OwningSpacePlayer->GetPlayerState();
		}
		Destroy();
	}
}

