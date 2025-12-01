// Fill out your copyright notice in the Description page of Project Settings.


#include "Puerta.h"
#include "Components/StaticMeshComponent.h"
#include "EstadoPuerta.h"
#include "PuertaAbierta.h"
#include "PuertaCerrada.h"
#include "BoyAdventureUSFXCharacter.h"

// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize properties
	MallaPuerta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPuerta"));
	RootComponent = MallaPuerta;
	MallaPuerta->SetupAttachment(RootComponent);

	//Asigna una apariencia a la malla de la puerta
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaPuerta(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));

	if (ObjetoMallaPuerta.Succeeded())
	{
		MallaPuerta->SetStaticMesh(ObjetoMallaPuerta.Object);
		// Aquí le das grosor con escala
		//MallaPuerta->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
		// X = largo, Y = ancho, Z = grosor

	}


	// inicializamos los estados de la puerta
	EstadoAbierto = NewObject<APuertaAbierta>();
	EstadoCerrado = NewObject<APuertaCerrada>();

	// Estado inicial
	EstadoActual = EstadoCerrado;

}

void APuerta::CambiarEstado(IEstadoPuerta* NuevoEstado)
{
	EstadoActual = NuevoEstado;
}

void APuerta::Interactuar()
{
	EstadoActual->Interactuar(this);
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

