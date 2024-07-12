// PG26Xav 2024



#include "UnrealClassWon/Public/Defaults/HelloWorldGameInstance.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(HelloWorldLog)

void UHelloWorldGameInstance::Init()
{
	Super::Init();

	if (IsValid(GEngine))
	{
		// printing on screen
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, DebugColor, *DebugMessage);

		// logging in output log
		UE_LOGFMT(HelloWorldLog, Display, "Hello {Name}'s World", ("Name","Xav"));
	}
}

