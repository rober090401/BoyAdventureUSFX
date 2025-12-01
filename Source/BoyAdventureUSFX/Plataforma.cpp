// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Initialize properties
	MallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	RootComponent = MallaPlataforma;
	MallaPlataforma->SetupAttachment(RootComponent);

	//Asigna una apariencia a la malla del obstáculo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaPlataforma(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (ObjetoMallaPlataforma.Succeeded())
	{
		MallaPlataforma->SetStaticMesh(ObjetoMallaPlataforma.Object);
		// Aquí le das grosor con escala
		MallaPlataforma->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
		// X = largo, Y = ancho, Z = grosor

	}

}

void APlataforma::Activar()
{
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

