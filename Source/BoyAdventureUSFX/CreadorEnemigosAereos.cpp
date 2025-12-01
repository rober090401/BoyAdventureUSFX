// Fill out your copyright notice in the Description page of Project Settings.

#include "CreadorEnemigosAereos.h"
#include "EnemigoAereo.h"

AActor* ACreadorEnemigosAereos::CrearEnemigo()
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        FVector Ubicacion(600.0f, -500.0f, 600.0f); // posición inicial
        FRotator Rotacion(0.0f, 0.0f, 0.0f);
        FActorSpawnParameters Parametros;
        Parametros.Owner = this;
        Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        // Aquí sí se crea el enemigo aéreo
        AEnemigoAereo* NuevoEnemigo = Mundo->SpawnActor<AEnemigoAereo>(
            AEnemigoAereo::StaticClass(),
            Ubicacion,
            Rotacion,
            Parametros
        );

        return NuevoEnemigo;
    }
    return nullptr;
}