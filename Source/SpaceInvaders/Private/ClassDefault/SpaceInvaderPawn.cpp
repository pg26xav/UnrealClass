// PG26Xav 2024


#include "ClassDefault/SpaceInvaderPawn.h"

// Sets default values
ASpaceInvaderPawn::ASpaceInvaderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceInvaderPawn::BeginPlay()
{
	Super::BeginPlay();
	
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

}

