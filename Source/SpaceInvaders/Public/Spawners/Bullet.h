// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/DamageType.h"
#include "Bullet.generated.h"

class UDamageType;
UCLASS()
class SPACEINVADERS_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly)
	float Speed = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 0.5f;

	void DestroyBullet();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionComponent;

	UFUNCTION()
	void OnBulletOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	FTimerHandle LifeSpanTimer;
};
