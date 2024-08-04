// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SIHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEINVADERS_API USIHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USIHealthComponent();

	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DmageType, class AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(Replicated, BlueprintReadOnly)
	float Health;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float MaxHealth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
