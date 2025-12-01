// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorPlataformaHielo.h"

// Sets default values
AConstructorPlataformaHielo::AConstructorPlataformaHielo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		PlataformaConstruida = Mundo->SpawnActor<APlataformaHielo>();
	}

}

void AConstructorPlataformaHielo::ConstruirMaterial()
{
	if (PlataformaConstruida)
	{
		// El constructor de APlataformaMadera ya asigna el material de madera,
		// pero aquí podrías reforzarlo o cambiarlo dinámicamente si quieres.
	}

}

void AConstructorPlataformaHielo::ConstruirResistencia()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->Tags.Add("Resistencia:30");
	}

}

void AConstructorPlataformaHielo::ConstruirTamano()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

}

APlataforma* AConstructorPlataformaHielo::ObtenerPlataforma()
{
	return PlataformaConstruida;
}

// Called when the game starts or when spawned
void AConstructorPlataformaHielo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructorPlataformaHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

