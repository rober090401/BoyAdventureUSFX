// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoyAdventureUSFXGameMode.generated.h"

class AObstaculoPared;
class AParedMetal;
class ATrampaSierra;

UCLASS(minimalapi)
class ABoyAdventureUSFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABoyAdventureUSFXGameMode();

	// Función para mover el actor aleatoriamente
	void MoverActorAleatoriamente();

public:
	virtual void BeginPlay() override;

private:
	// Variables miembro inicializadas en el constructor
	AObstaculoPared* Obstaculo = nullptr;
	AParedMetal* ParedMetal01 = nullptr;

	ATrampaSierra* ts01 = nullptr;
	ATrampaSierra* ts02 = nullptr;

private:
	FTimerHandle MovimientoTimer;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Intervalo = 4.0f;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	FVector RangoMovimiento = FVector(500.0f, 500.0f, 0.0f); // Solo X e Y

	UPROPERTY()
	class AZonaProxy* Zona1;

	UPROPERTY()
	class AZonaProxy* Zona2;

	FTimerHandle TimerProxy;

	void GenerarZonasSeguras();
};