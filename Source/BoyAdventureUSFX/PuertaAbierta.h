// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstadoPuerta.h"
#include "PuertaAbierta.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API APuertaAbierta : public AActor, public IEstadoPuerta
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuertaAbierta();

	virtual void Abrir(APuerta* Puerta) override;
	virtual void Cerrar(APuerta* Puerta) override;
	virtual void Interactuar(APuerta* Puerta) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
