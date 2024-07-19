// PG26Xav 2024


#include "Controllers/SpaceInvaderController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"

void ASpaceInvaderController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IsValid(InputComponent))
	{
		TObjectPtr<UEnhancedInputLocalPlayerSubsystem> EnhancedInputLocalPlayerSubsystem
		= GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

		if (IsValid(EnhancedInputLocalPlayerSubsystem))
		{
			// Adds Character Movement Mapping Context
			EnhancedInputLocalPlayerSubsystem->AddMappingContext(PlayerMovementMappingContext, 0);

			if (TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
			{
				if(IsValid(horiMoveAction)) EnhancedInputComponent->BindAction(horiMoveAction, ETriggerEvent::Triggered, this, &ThisClass::MoveHorizontal);
				if (IsValid(vertMoveAction)) EnhancedInputComponent->BindAction(vertMoveAction, ETriggerEvent::Triggered, this, &ThisClass::MoveVertical);
			}
		}
	}
}

void ASpaceInvaderController::MoveHorizontal(const FInputActionValue& Value)
{
	const float AxisValue = Value.Get<float>();

	if (TObjectPtr<APawn> ControlledPawn = GetPawn()) ControlledPawn->AddMovementInput({1.0f, 0.0f, 0.0f}, AxisValue);
}

void ASpaceInvaderController::MoveVertical(const FInputActionValue& Value)
{
	const float AxisValue = Value.Get<float>();

	if (TObjectPtr<APawn> ControlledPawn = GetPawn()) ControlledPawn->AddMovementInput({0.0f, 1.0f, 0.0f}, AxisValue);
}
