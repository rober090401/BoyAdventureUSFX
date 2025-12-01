// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorPlataformaPiedra.h"

// Sets default values
AConstructorPlataformaPiedra::AConstructorPlataformaPiedra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Instanciamos la plataforma de madera en el mundo
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		PlataformaConstruida = Mundo->SpawnActor<APlataformaPiedra>();
	}
}

void AConstructorPlataformaPiedra::ConstruirMaterial()
{
	if (PlataformaConstruida)
	{
		// El constructor de APlataformaMadera ya asigna el material de madera,
		// pero aquí podrías reforzarlo o cambiarlo dinámicamente si quieres.
	}

}

void AConstructorPlataformaPiedra::ConstruirResistencia()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->Tags.Add("Resistencia:100");
	}

}

void AConstructorPlataformaPiedra::ConstruirTamano()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

}

APlataforma* AConstructorPlataformaPiedra::ObtenerPlataforma()
{
	return PlataformaConstruida;
}

// Called when the game starts or when spawned
void AConstructorPlataformaPiedra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructorPlataformaPiedra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

