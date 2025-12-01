// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreadorEnemigos.h"
#include "CreadorEnemigosTerrestres.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API ACreadorEnemigosTerrestres : public ACreadorEnemigos
{
	GENERATED_BODY()
	
public:

	virtual AActor* CrearEnemigo() override;

};
