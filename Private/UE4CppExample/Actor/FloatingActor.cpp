// Fill out your copyright notice in the Description page of Project Settings.


#include "UE4CppExample/Actor/FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor() : runningTime{ 0 }, speed{ 0 }, height{ 0 }
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	staticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereAsset.Succeeded())
	{
		staticMesh->SetStaticMesh(SphereAsset.Object);
		staticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		staticMesh->SetWorldScale3D(FVector(0.8f));
	}
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	float deltaHeight = (FMath::Sin(runningTime + DeltaTime) - FMath::Sin(runningTime));
	newLocation.Z += deltaHeight * height * speed;
	runningTime += DeltaTime * speed;
	SetActorLocation(newLocation);
}

