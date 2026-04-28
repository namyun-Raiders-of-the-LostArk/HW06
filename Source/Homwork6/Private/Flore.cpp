#include "Flore.h"


AFlore::AFlore()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_CobbleStone_Rough.M_CobbleStone_Rough"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 200.0f;   // 초당 이동 속도
	MaxRange = 700.0f;    // 시작 위치에서 최대 이동 거리
	MoveDirection = 1.0f; // 처음엔 + 방향
}


void AFlore::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(500.0f, 500.0f, 500.0f));//XYZ 로 위치 시키겠다 (로케이션)
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));//피치 요 롤 y z x
	StartLocation = GetActorLocation(); // 시작 위치 저장
}


void AFlore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();

	float MoveAmount = MoveSpeed * DeltaTime; 
	CurrentLocation.X += MoveAmount * MoveDirection;

	float Distance = CurrentLocation.X - StartLocation.X;

	if (Distance >= MaxRange)
	{
		CurrentLocation.X = StartLocation.X + MaxRange;
		MoveDirection = -1.0f;
	}
	else if (Distance <= 0.0f)
	{
		CurrentLocation.X = StartLocation.X;
		MoveDirection = 1.0f;
	}

	SetActorLocation(CurrentLocation);
}

