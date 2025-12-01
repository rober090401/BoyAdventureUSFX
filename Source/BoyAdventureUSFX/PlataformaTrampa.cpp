// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaTrampa.h"

APlataformaTrampa::APlataformaTrampa()
{
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));

    if (MaterialAsset.Succeeded())
    {
        MallaPlataforma->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
    }
}
