// Fill out your copyright notice in the Description page of Project Settings.


#include "CreadorEnemigosAnfivios.h"
#include "EnemigoAnfivio.h"


AActor* ACreadorEnemigosAnfivios::CrearEnemigo()
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        FActorSpawnParameters ParametrosSpawn;
        ParametrosSpawn.Owner = this;
        ParametrosSpawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector Ubicacion = GetActorLocation();
        FRotator Rotacion = GetActorRotation();

        AEnemigoAnfivio* EnemigoAnfivio = Mundo->SpawnActor<AEnemigoAnfivio>(AEnemigoAnfivio::StaticClass(), Ubicacion, Rotacion, ParametrosSpawn);
        if (EnemigoAnfivio)
        {
            UE_LOG(LogTemp, Warning, TEXT("Enemigo anfibio creado en %s"), *Ubicacion.ToString());
        }
        return EnemigoAnfivio;
    }
    return nullptr;
}
