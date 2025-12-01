// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "MovimientoFlotante.h"

AEnemigoAereo::AEnemigoAereo() : AEnemigo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallAEnemigoAereo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));

	if (ObjetoMallAEnemigoAereo.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallAEnemigoAereo.Object);

		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Cargar el material
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_ColorGrid_LowSpec.M_ColorGrid_LowSpec'"));

	if (MaterialAsset.Succeeded())
	{
		MallaEnemigo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}

}
void AEnemigoAereo::BeginPlay()
{
	Super::BeginPlay();
	SetEstrategiaMovimiento(new MovimientoFlotante());
}
