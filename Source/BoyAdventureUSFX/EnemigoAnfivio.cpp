// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAnfivio.h"

AEnemigoAnfivio::AEnemigoAnfivio()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallAEnemigoAnfivio(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));

	if (ObjetoMallAEnemigoAnfivio.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallAEnemigoAnfivio.Object);
		//MallaEnemigo->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));

		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Cargar el material
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));

	if (MaterialAsset.Succeeded())
	{
		MallaEnemigo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}

void AEnemigoAnfivio::ConfigurarMalla(UStaticMesh* Malla)
{
	if (RootComponent)
	{
		UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this);
		MeshComponent->SetStaticMesh(Malla);
		MeshComponent->SetupAttachment(RootComponent);
		MeshComponent->RegisterComponent();
	}
}

