// PG26Xav 2024


#include "Actors/Predator.h"

void APredator::DoDamage_Implementation(float DmgAmt)
{
	Super::DoDamage_Implementation(DmgAmt);
}

void APredator::OnHealthUpdated(float oldHealth, float newHealth)
{
	Super::OnHealthUpdated(oldHealth, newHealth);
}

void APredator::OnPredatorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}
