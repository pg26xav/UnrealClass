// PG26Xav 2024


#include "ClassDefault/SpaceInvaderPlayerState.h"

ASpaceInvaderPlayerState::ASpaceInvaderPlayerState(const FObjectInitializer& ObjectInitializer)
{
	ScoreComponent = CreateDefaultSubobject<USIScoreComponent>(TEXT("Score Component"));
}
