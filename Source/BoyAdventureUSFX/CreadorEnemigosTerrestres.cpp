// Fill out your copyright notice in the Description page of Project Settings.


#include "CreadorEnemigosTerrestres.h"
#include "EnemigoTerrestre.h" // tu clase concreta de enemigo terrestre

AActor* ACreadorEnemigosTerrestres::CrearEnemigo()
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        // Definir ubicación y rotación del spawn
        FVector Ubicacion(500.0f, -600.0f, 300.0f); // más bajo para simular que está en el suelo
        FRotator Rotacion(0.0f, 0.0f, 0.0f);
        FActorSpawnParameters Parametros;
        Parametros.Owner = this;
        Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        // Crear el enemigo terrestre
        AEnemigoTerrestre* NuevoEnemigo = Mundo->SpawnActor<AEnemigoTerrestre>(
            AEnemigoTerrestre::StaticClass(),
            Ubicacion,
            Rotacion,
            Parametros
        );

        return NuevoEnemigo;
    }
    return nullptr;
}
