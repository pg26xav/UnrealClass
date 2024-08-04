// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceInvaderPlayer.generated.h"

struct FInputActionValue;
class ABullet;
class UInputAction;
class USIHealthComponent;

UCLASS()
class SPACEINVADERS_API ASpaceInvaderPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceInvaderPlayer();

	UFUNCTION()
	void Shoot(const FInputActionValue& Value);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USIHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<ABullet> BulletToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TObjectPtr<USceneComponent> ShootPOS;
	
	virtual void Destroyed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};