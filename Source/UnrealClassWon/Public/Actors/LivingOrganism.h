// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DamageInterface.h"
#include "LivingOrganism.generated.h"

class UHealthComponent;
class UStaticMeshComponent;
class UArrowComponent;

// single cast delegates
DECLARE_DELEGATE_OneParam(FMySingleDelegateType, float);
DECLARE_DELEGATE_RetVal(bool, FMySingleDelegateTypeWithReturnType)

//multicaset delegates
DECLARE_MULTICAST_DELEGATE(FMyMulticastDelegate);

//dynamic
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDynamicDelegateWithTwoParams, float, MyFloat, bool, MyBool);
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(int32, FDynamicDelegateRetvalWithTwoParams, int32, MyFirstInt, int32, MySecondInt);

//dynamic multicast delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyDynamicMulticastDelegate);

UCLASS()
class UNREALCLASSWON_API ALivingOrganism : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingOrganism();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//override damage
	void DoDamage_Implementation(float DmgAmt) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly);
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UArrowComponent> Nose;

	UFUNCTION(BlueprintNativeEvent)
	void Move();

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category = "Movement")
	float MovementSpeed;

	// BlueprintNativeEvent hides from designers
	UFUNCTION(BlueprintImplementableEvent)
	void DoSomething();

	// Delegates
	// Single
	FMySingleDelegateType SingleDele;
	FMySingleDelegateTypeWithReturnType SingleReturnDele;

	// Multicast
	FMyMulticastDelegate MulticastDele;

	// Dynamic
	UPROPERTY()
	FDynamicDelegateWithTwoParams DynamicDelegateWithTwoParams;
	UPROPERTY()
	FDynamicDelegateRetvalWithTwoParams DynamicDeleRetValWithTwoParams;

	// Dynamic Multicast
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FMyDynamicMulticastDelegate DynamicMulticastDele;

	//timer
	UFUNCTION()
	void CallEvents();

	UFUNCTION()
	void OnHealthUpdated(float oldHealth, float newHealth);

	UFUNCTION()
	void OnLivingOrganismHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
};
