// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovimientoEstrategia.h"

/**
 * 
 */
class BOYADVENTUREUSFX_API MovimientoPatrullero : public IMovimientoEstrategia
{
public:
	MovimientoPatrullero();
	~MovimientoPatrullero();

	virtual void Mover(AEnemigo* Enemigo, float DeltaTime) override;

private:
	float Velocidad = 50.0f;
	bool DireccionDerecha = true;
	float LimiteMinY = -300.0f; // Límite mínimo en el eje Y
	float LimiteMaxY = 300.0f;  // Límite máximo en el eje Y
	int Direccion = 1;          // Dirección del movimiento (1 = hacia adelante, -1 = hacia atrás)


};
