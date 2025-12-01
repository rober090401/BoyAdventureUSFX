// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreadorEnemigos.h"
#include "CreadorEnemigosAnfivios.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API ACreadorEnemigosAnfivios : public ACreadorEnemigos
{
	GENERATED_BODY()
	
public:
	virtual AActor* CrearEnemigo() override;
};
