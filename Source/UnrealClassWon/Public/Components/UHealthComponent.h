#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "UHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthEvent, float, OldHealth, float, NewHealth);

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UNREALCLASSWON_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UHealthComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 10.0f;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float Delta);

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthUpdated;
};
