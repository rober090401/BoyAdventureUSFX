// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovimientoEstrategia.h"
#include "Enemigo.h"

/**
 * 
 */
class BOYADVENTUREUSFX_API MovimientoFlotante : public IMovimientoEstrategia
{
public:
	MovimientoFlotante();
	~MovimientoFlotante();

	virtual void Mover(AEnemigo* Enemigo, float DeltaTime) override;
private:
	float LimiteMinZ = 100.0f; // Límite mínimo en el eje Y
	float LimiteMaxZ = 500.0f;  // Límite máximo en el eje Y
	float Velocidad = 50.0f;   // Velocidad de movimiento
	int Direccion = 1;          // Dirección del movimiento (1 = hacia adelante, -1 = hacia atrás)

};
