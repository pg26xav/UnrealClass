// PG26Xav 2024


#include "ClassDefault/SpaceInvaderGameStateBase.h"
#include "Blueprint/UserWidget.h"

void ASpaceInvaderGameStateBase::EndGame_Implementation()
{
	EndGameClient();
}

void ASpaceInvaderGameStateBase::EndGameClient_Implementation()
{
	TObjectPtr<APlayerController> PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(EndScreen)) return;
	TObjectPtr<UUserWidget> EndGameScreen = CreateWidget<UUserWidget>(PlayerController,EndScreen);
	EndGameScreen->AddToViewport();
}
