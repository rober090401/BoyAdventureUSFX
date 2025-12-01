// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaCerrada.h"
#include "Puerta.h"
#include "PuertaAbierta.h"

// Sets default values
APuertaCerrada::APuertaCerrada()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APuertaCerrada::Abrir(APuerta* Puerta)
{
	Puerta->CambiarEstado(Puerta->EstadoAbierto);
	Puerta->MallaPuerta->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f)); // abierta

	UE_LOG(LogTemp, Warning, TEXT("Abriendo la puerta..."));
}

void APuertaCerrada::Cerrar(APuerta* Puerta)
{
	UE_LOG(LogTemp, Warning, TEXT("La puerta ya está cerrada."));
}

void APuertaCerrada::Interactuar(APuerta* Puerta)
{
	Abrir(Puerta);
}

// Called when the game starts or when spawned
void APuertaCerrada::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuertaCerrada::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

