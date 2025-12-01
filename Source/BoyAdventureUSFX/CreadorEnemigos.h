// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreadorEnemigos.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API ACreadorEnemigos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreadorEnemigos();

	// metodo virtual puro para crear enemigos
	virtual AActor* CrearEnemigo() PURE_VIRTUAL(ACreadorEnemigos::CrearEnemigo, return nullptr;);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
