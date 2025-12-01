// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConstructorPlataforma.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstructorPlataforma : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOYADVENTUREUSFX_API IConstructorPlataforma
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    // Métodos que cada Builder concreto debe implementar
    virtual void ConstruirMaterial() = 0;
    virtual void ConstruirResistencia() = 0;
    virtual void ConstruirTamano() = 0;

    // Devuelve la plataforma construida
    virtual class APlataforma* ObtenerPlataforma() = 0;


};
