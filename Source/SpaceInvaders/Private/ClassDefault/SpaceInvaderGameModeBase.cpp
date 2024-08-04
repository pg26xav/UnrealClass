// PG26Xav 2024


#include "ClassDefault/SpaceInvaderGameModeBase.h"
#include "ClassDefault/SpaceInvaderGameStateBase.h"
#include "ClassDefault/SpaceInvaderHUD.h"
#include "ClassDefault/SpaceInvaderPawn.h"
#include "ClassDefault/SpaceInvaderPlayerState.h"
#include "Controllers/SpaceInvaderController.h"
#include "ClassDefault/SpaceInvaderHUD.h"

ASpaceInvaderGameModeBase::ASpaceInvaderGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = ASpaceInvaderGameStateBase::StaticClass();
	PlayerControllerClass = ASpaceInvaderController::StaticClass();
	PlayerStateClass = ASpaceInvaderPlayerState::StaticClass();
	DefaultPawnClass = ASpaceInvaderPawn::StaticClass();
	HUDClass = ASpaceInvaderHUD::StaticClass();
}
