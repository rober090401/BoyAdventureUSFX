// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorPlataformaTrampa.h"

// Sets default values
AConstructorPlataformaTrampa::AConstructorPlataformaTrampa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		PlataformaConstruida = Mundo->SpawnActor<APlataformaTrampa>();
	}
}

void AConstructorPlataformaTrampa::ConstruirMaterial()
{
	if (PlataformaConstruida)
	{
		// El constructor de APlataformaMadera ya asigna el material de madera,
		// pero aquí podrías reforzarlo o cambiarlo dinámicamente si quieres.
	}

}

void AConstructorPlataformaTrampa::ConstruirResistencia()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->Tags.Add("Resistencia:100");
	}

}

void AConstructorPlataformaTrampa::ConstruirTamano()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

}

APlataforma* AConstructorPlataformaTrampa::ObtenerPlataforma()
{
	return PlataformaConstruida;
}

// Called when the game starts or when spawned
void AConstructorPlataformaTrampa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructorPlataformaTrampa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

