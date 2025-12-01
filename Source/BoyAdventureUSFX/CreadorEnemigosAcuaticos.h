// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreadorEnemigos.h"
#include "CreadorEnemigosAcuaticos.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API ACreadorEnemigosAcuaticos : public ACreadorEnemigos
{
	GENERATED_BODY()

public:
	virtual AActor* CrearEnemigo() override;
};
