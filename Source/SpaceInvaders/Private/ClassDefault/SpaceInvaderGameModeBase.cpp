// PG26Xav 2024


#include "ClassDefault/SpaceInvaderGameModeBase.h"
#include "ClassDefault/SpaceInvaderGameStateBase.h"
#include "ClassDefault/SpaceInvaderPawn.h"
#include "ClassDefault/SpaceInvaderPlayerState.h"
#include "Controllers/SpaceInvaderController.h"

ASpaceInvaderGameModeBase::ASpaceInvaderGameModeBase()
{
	GameStateClass = ASpaceInvaderGameStateBase::StaticClass();
	PlayerControllerClass = ASpaceInvaderController::StaticClass();
	PlayerStateClass = ASpaceInvaderPlayerState::StaticClass();
	DefaultPawnClass = ASpaceInvaderPawn::StaticClass();
}
