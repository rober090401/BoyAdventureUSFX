// Fill out your copyright notice in the Description page of Project Settings.


#include "CreadorEnemigosAcuaticos.h"
#include "EnemigoAcuatico.h"

AActor* ACreadorEnemigosAcuaticos::CrearEnemigo()
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        FActorSpawnParameters ParametrosSpawn;
        ParametrosSpawn.Owner = this;
        ParametrosSpawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector Ubicacion = GetActorLocation();
        FRotator Rotacion = GetActorRotation();

        AEnemigoAcuatico* EnemigoAcuatico = Mundo->SpawnActor<AEnemigoAcuatico>(AEnemigoAcuatico::StaticClass(), Ubicacion, Rotacion, ParametrosSpawn);
        if (EnemigoAcuatico)
        {
            UE_LOG(LogTemp, Warning, TEXT("Enemigo acuático creado en %s"), *Ubicacion.ToString());
        }
        return EnemigoAcuatico;
    }
    return nullptr;
}

