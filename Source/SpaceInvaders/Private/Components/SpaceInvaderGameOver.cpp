// PG26Xav 2024


#include "Components/SpaceInvaderGameOver.h"

void USpaceInvaderGameOver::Restart()
{
	GetWorld()->GetGameInstance()->ReturnToMainMenu();
}
