// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallAEnemigoAcuatico(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule''"));

	if (ObjetoMallAEnemigoAcuatico.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallAEnemigoAcuatico.Object);
		//MallaEnemigo->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));

		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Cargar el material
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));

	if (MaterialAsset.Succeeded())
	{
		MallaEnemigo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}

void AEnemigoAcuatico::ConfigurarMalla(UStaticMesh* Malla)
{
    if (RootComponent)
    {
        UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this);
        MeshComponent->SetStaticMesh(Malla);
        MeshComponent->SetupAttachment(RootComponent);
        MeshComponent->RegisterComponent();
    }
}

