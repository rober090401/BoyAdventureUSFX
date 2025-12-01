// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorPlataformaMadera.h"

// Sets default values
AConstructorPlataformaMadera::AConstructorPlataformaMadera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instanciamos la plataforma de madera en el mundo
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		PlataformaConstruida = Mundo->SpawnActor<APlataformaMadera>();
	}

}
//para construir el material
void AConstructorPlataformaMadera::ConstruirMaterial()
{
	if (PlataformaConstruida)
	{
		// El constructor de APlataformaMadera ya asigna el material de madera,
		// pero aquí podrías reforzarlo o cambiarlo dinámicamente si quieres.
	}


}
//para construir la resitencia 
void AConstructorPlataformaMadera::ConstruirResistencia()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->Tags.Add("Resistencia:50");
	}

}
// para construir el tamaño
void AConstructorPlataformaMadera::ConstruirTamano()
{
	if (PlataformaConstruida)
	{
		PlataformaConstruida->SetActorScale3D(FVector(1.5f, 1.5f, 0.5f));
	}
}
// para obtener la plataforma construida
APlataforma* AConstructorPlataformaMadera::ObtenerPlataforma()
{
	return PlataformaConstruida;
}

// Called when the game starts or when spawned
void AConstructorPlataformaMadera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructorPlataformaMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

