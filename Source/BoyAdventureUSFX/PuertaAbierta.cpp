// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaAbierta.h"
#include "Puerta.h"
#include "PuertaCerrada.h"

// Sets default values
APuertaAbierta::APuertaAbierta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APuertaAbierta::Abrir(APuerta* Puerta)
{
	UE_LOG(LogTemp, Warning, TEXT("La puerta ya está abierta"));
}

void APuertaAbierta::Cerrar(APuerta* Puerta)
{
	Puerta->CambiarEstado(Puerta->EstadoCerrado);
	Puerta->MallaPuerta->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f)); // cerrada
	UE_LOG(LogTemp, Warning, TEXT("Cerrando la puerta..."));
}

void APuertaAbierta::Interactuar(APuerta* Puerta)
{
	Cerrar(Puerta);
}

// Called when the game starts or when spawned
void APuertaAbierta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuertaAbierta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

