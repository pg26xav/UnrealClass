// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SIScoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEINVADERS_API USIScoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USIScoreComponent();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void AddScore(const int32 scoreToAdd);

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Score;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
