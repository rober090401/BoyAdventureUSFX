// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAnfivio.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AEnemigoAnfivio : public AEnemigo
{
	GENERATED_BODY()
	
public:
	AEnemigoAnfivio();
	// metodo configurar la malla
	void ConfigurarMalla(UStaticMesh* Malla);

};
