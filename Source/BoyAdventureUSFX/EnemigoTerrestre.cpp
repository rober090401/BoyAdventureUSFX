// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre.h"
#include "MovimientoPatrullero.h"

AEnemigoTerrestre::AEnemigoTerrestre() : AEnemigo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallAEnemigoTerrestre(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));

	if (ObjetoMallAEnemigoTerrestre.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallAEnemigoTerrestre.Object);
		MallaEnemigo->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));

		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Cargar el material
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_CobbleStone_Rough.M_CobbleStone_Rough'"));

	if (MaterialAsset.Succeeded())
	{
		MallaEnemigo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
	
}
void AEnemigoTerrestre::BeginPlay()
{
	Super::BeginPlay();
	SetEstrategiaMovimiento(new MovimientoPatrullero());
}
