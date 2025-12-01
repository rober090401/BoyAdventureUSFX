// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaMadera.h"

APlataformaMadera::APlataformaMadera()
{
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));

    if (MaterialAsset.Succeeded())
    {
        MallaPlataforma->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
    }
}

