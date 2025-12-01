// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoyAdventureUSFXGameMode.h"
#include "BoyAdventureUSFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ObstaculoPared.h"
#include "ParedMetal.h"
#include "TrampaSierra.h"
#include "CreadorEnemigosTerrestres.h"
#include "CreadorEnemigosAereos.h"
#include "CreadorEnemigosAcuaticos.h"
#include "CreadorEnemigosAnfivios.h"
#include "Plataforma.h"
#include "DirectorPlataforma.h"
#include "ConstructorPlataformaMadera.h"
#include "ConstructorPlataformaPiedra.h"
#include "ConstructorPlataformaHielo.h"
#include "ConstructorPlataformaTrampa.h"
#include "Puerta.h"
#include "ZonaProxy.h"

ABoyAdventureUSFXGameMode::ABoyAdventureUSFXGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    // Inicializar variables miembro
    Obstaculo = nullptr;
    ParedMetal01 = nullptr;
    ts01 = nullptr;
    ts02 = nullptr;
    Zona1 = nullptr;
    Zona2 = nullptr;
}

void ABoyAdventureUSFXGameMode::BeginPlay()
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        // Crear trampas y obstáculos
        FVector UTS01(100.0f, -500.0f, 500.0f);
        FRotator RTS01(0.0f, 0.0f, 0.0f);

        ts01 = Mundo->SpawnActor<ATrampaSierra>(ATrampaSierra::StaticClass(), UTS01, RTS01);
        if (ts01)
        {
            UE_LOG(LogTemp, Warning, TEXT("Trampa sierra 01 creada exitosamente"));
        }

        FVector UTS02(400.0f, -500.0f, 400.0f);
        FRotator RTS02(0.0f, 0.0f, 0.0f);

        ts02 = Mundo->SpawnActor<ATrampaSierra>(ATrampaSierra::StaticClass(), UTS02, RTS02);
        if (ts02)
        {
            UE_LOG(LogTemp, Warning, TEXT("Trampa sierra 02 creada exitosamente"));
        }

        FVector Ubicacion(0.0f, 0.0f, 400.0f);
        FRotator Rotacion(0.0f, 0.0f, 0.0f);

        FActorSpawnParameters ParametrosSpawn;
        ParametrosSpawn.Owner = this;
        ParametrosSpawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        Obstaculo = Mundo->SpawnActor<AObstaculoPared>(AObstaculoPared::StaticClass(), Ubicacion, Rotacion, ParametrosSpawn);
        if (Obstaculo)
        {
            UE_LOG(LogTemp, Warning, TEXT("Obstáculo creado exitosamente"));
        }

        FVector Ubicacion01(200.0f, -300.0f, 400.0f);
        FRotator Rotacion02(0.0f, 0.0f, 0.0f);

        ParedMetal01 = Mundo->SpawnActor<AParedMetal>(AParedMetal::StaticClass(), Ubicacion01, Rotacion02);

		// Crear enemigos utilizando el patrón Factory Method y Strategy
        FVector UbicacionTerrestre(-700.0f, -800.0f, 700.0f);
        FRotator RotacionTerrestre(0.0f, 90.0f, 0.0f);
        FTransform TransformTerrestre(RotacionTerrestre, UbicacionTerrestre);

        ACreadorEnemigosTerrestres* CreadorTerrestre = Mundo->SpawnActor<ACreadorEnemigosTerrestres>(ACreadorEnemigosTerrestres::StaticClass(), TransformTerrestre);
        if (CreadorTerrestre)
        {
            AActor* EnemigoTerrestre = CreadorTerrestre->CrearEnemigo();
            if (EnemigoTerrestre)
            {
                UE_LOG(LogTemp, Warning, TEXT("Enemigo terrestre creado exitosamente"));
            }
        }

        FVector UbicacionAerea(-700.0f, -900.0f, 600.0f);
        FRotator RotacionAerea(0.0f, 0.0f, 0.0f);
        FTransform TransformAereo(RotacionAerea, UbicacionAerea);

        ACreadorEnemigosAereos* CreadorAereo = Mundo->SpawnActor<ACreadorEnemigosAereos>(ACreadorEnemigosAereos::StaticClass(), TransformAereo);
        if (CreadorAereo)
        {
            AActor* EnemigoAereo = CreadorAereo->CrearEnemigo();
            if (EnemigoAereo)
            {
                UE_LOG(LogTemp, Warning, TEXT("Enemigo aéreo creado exitosamente"));
            }
        }

        // Crear enemigos acuáticos
        FVector UbicacionAcuatica(-500.0f, -200.0f, 300.0f);
        FRotator RotacionAcuatica(0.0f, 0.0f, 0.0f);
        FTransform TransformAcuatica(RotacionAcuatica, UbicacionAcuatica);

        ACreadorEnemigosAcuaticos* CreadorAcuatico = Mundo->SpawnActor<ACreadorEnemigosAcuaticos>(ACreadorEnemigosAcuaticos::StaticClass(), TransformAcuatica);
        if (CreadorAcuatico)
        {
            CreadorAcuatico->CrearEnemigo();
        }

        // Crear enemigos anfibios
        FVector UbicacionAnfibia(-700.0f, -1100.0f, 400.0f);
        FRotator RotacionAnfibia(0.0f, 0.0f, 0.0f);
        FTransform TransformAnfibio(RotacionAnfibia, UbicacionAnfibia);

        ACreadorEnemigosAnfivios* CreadorAnfibio = Mundo->SpawnActor<ACreadorEnemigosAnfivios>(ACreadorEnemigosAnfivios::StaticClass(), TransformAnfibio);
        if (CreadorAnfibio)
        {
            CreadorAnfibio->CrearEnemigo();
        }

        // Crear el Director
        ADirectorPlataforma* Director = Mundo->SpawnActor<ADirectorPlataforma>();

        // Builder de madera
        AConstructorPlataformaMadera* BuilderMadera = Mundo->SpawnActor<AConstructorPlataformaMadera>();
        Director->ConstruirPlataforma(BuilderMadera);
        APlataforma* PlataformaMadera = BuilderMadera->ObtenerPlataforma();

        if (PlataformaMadera)
        {
            // Posicionar la plataforma en el mundo
            PlataformaMadera->SetActorLocation(FVector(-700.0f, -100.0f, 170.0f));
            UE_LOG(LogTemp, Warning, TEXT("Plataforma de madera spawneada en el mundo"));
        }

        // Builder de piedra
        AConstructorPlataformaPiedra* BuilderPiedra = Mundo->SpawnActor<AConstructorPlataformaPiedra>();
        Director->ConstruirPlataforma(BuilderPiedra);
        APlataforma* PlataformaPiedra = BuilderPiedra->ObtenerPlataforma();

        if (PlataformaPiedra)
        {
            PlataformaPiedra->SetActorLocation(FVector(-700.0f, -300.0f, 200.0f));
            UE_LOG(LogTemp, Warning, TEXT("Plataforma de piedra spawneada en el mundo"));
        }

        // Builder de hielo
        AConstructorPlataformaHielo* BuilderHielo = Mundo->SpawnActor<AConstructorPlataformaHielo>();
        Director->ConstruirPlataforma(BuilderHielo);
        APlataforma* PlataformaHielo = BuilderHielo->ObtenerPlataforma();

        if (PlataformaHielo)
        {
            PlataformaHielo->SetActorLocation(FVector(-700.0f, -500.0f, 300.0f));
            UE_LOG(LogTemp, Warning, TEXT("Plataforma de hielo spawneada en el mundo"));
        }

        // Builder de trampa
        AConstructorPlataformaTrampa* BuilderTrampa = Mundo->SpawnActor<AConstructorPlataformaTrampa>();
        Director->ConstruirPlataforma(BuilderTrampa);
        APlataforma* PlataformaTrampa = BuilderTrampa->ObtenerPlataforma();

        if (PlataformaTrampa)
        {
            PlataformaTrampa->SetActorLocation(FVector(-700.0f, -700.0f, 400.0f));
            UE_LOG(LogTemp, Warning, TEXT("Plataforma trampa spawneada en el mundo"));
        }

        FVector UbicacionPuerta(-700.0f, -800.0f, 200.0f);
        FRotator RotacionPuerta(0.0f, 90.0f, 0.0f);

        APuerta* Puerta = Mundo->SpawnActor<APuerta>(APuerta::StaticClass(), UbicacionPuerta, RotacionPuerta);

        if (Puerta)
        {
            UE_LOG(LogTemp, Warning, TEXT("Puerta spawneada correctamente"));
        }

        // Configurar temporizador para movimiento aleatorio
        GetWorld()->GetTimerManager().SetTimer(
            MovimientoTimer,
            this,
            &ABoyAdventureUSFXGameMode::MoverActorAleatoriamente,
            Intervalo,
            true
        );
    }
}


void ABoyAdventureUSFXGameMode::GenerarZonasSeguras()
{
    // Eliminar zonas anteriores si existen
    if (Zona1) Zona1->Destroy();
    if (Zona2) Zona2->Destroy();

    // Crear la primera zona
    FTransform Transform1(FRotator::ZeroRotator, FVector(FMath::RandRange(-1100.f, 1100.f), FMath::RandRange(-1100.f, 1100.f), 135.f));
    Zona1 = GetWorld()->SpawnActor<AZonaProxy>(AZonaProxy::StaticClass(), Transform1);

    // Crear la segunda zona
    FTransform Transform2(FRotator::ZeroRotator, FVector(FMath::RandRange(-1100.f, 1100.f), FMath::RandRange(-1100.f, 1100.f), 135.f));
    Zona2 = GetWorld()->SpawnActor<AZonaProxy>(AZonaProxy::StaticClass(), Transform2);
}

void ABoyAdventureUSFXGameMode::MoverActorAleatoriamente()
{
    if (Obstaculo)
    {
        FVector PosicionActual = Obstaculo->GetActorLocation();

        float NuevoX = FMath::RandRange(-RangoMovimiento.X, RangoMovimiento.X);
        float NuevoY = FMath::RandRange(-RangoMovimiento.Y, RangoMovimiento.Y);

        FVector NuevaPosicion = FVector(NuevoX, NuevoY, PosicionActual.Z);

        Obstaculo->SetActorLocation(NuevaPosicion);
    }
}