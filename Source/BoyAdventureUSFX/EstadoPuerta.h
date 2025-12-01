// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EstadoPuerta.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstadoPuerta : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOYADVENTUREUSFX_API IEstadoPuerta
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Abrir(class APuerta* Puerta) = 0;
	virtual void Cerrar(class APuerta* Puerta) = 0;
	virtual void Interactuar(class APuerta* Puerta) = 0;
};
