// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaHielo.h"

APlataformaHielo::APlataformaHielo()
{

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));

    if (MaterialAsset.Succeeded())
    {
        MallaPlataforma->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
    }
}
