#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HP_Potion.generated.h"

UCLASS()
class HOMWORK6_API AHP_Potion : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHP_Potion();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	float RotationSpeed;


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
