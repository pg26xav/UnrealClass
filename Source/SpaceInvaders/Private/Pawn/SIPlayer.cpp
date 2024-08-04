// PG26Xav 2024


#include "Pawn/SIPlayer.h"


// Sets default values
ASIPlayer::ASIPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASIPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASIPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASIPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

