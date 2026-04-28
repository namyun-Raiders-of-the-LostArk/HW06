#include "HP_Potion.h"


AHP_Potion::AHP_Potion()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion_HP.M_Potion_HP"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

// Called when the game starts or when spawned
void AHP_Potion::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(300.0f, 300.0f, 300.0f));//XYZ 로 위치 시키겠다 (로케이션)
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));//피치 요 롤 y z x
	
}

void AHP_Potion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)) 
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

