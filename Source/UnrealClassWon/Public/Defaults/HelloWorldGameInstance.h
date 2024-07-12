// PG26Xav 2024

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HelloWorldGameInstance.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_EXTERN(HelloWorldLog,Log,All);

UCLASS()
class UNREALCLASSWON_API UHelloWorldGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color", meta = (DisplayName = "Designer's Head"))
	FColor DebugColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Message")
	FString DebugMessage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool MyBool;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "TestCondition >= 10"))
	int32 MyInt;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0", ClampMax = "10", DisplayThumbnail = "true"))
	int32 TestCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText LocalizedText;
};
