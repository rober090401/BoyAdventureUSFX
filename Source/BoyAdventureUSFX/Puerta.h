// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puerta.generated.h"

class IEstadoPuerta;
class APuertaAbierta;
class APuertaCerrada;

UCLASS()
class BOYADVENTUREUSFX_API APuerta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuerta();

	IEstadoPuerta* EstadoActual;

	UPROPERTY()
	APuertaAbierta* EstadoAbierto;

	UPROPERTY()
	APuertaCerrada* EstadoCerrado;

	void CambiarEstado(IEstadoPuerta* NuevoEstado);

	UFUNCTION(BlueprintCallable)
	void Interactuar();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// componente  de la colision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	class UBoxComponent* CollisionBox;
	//malla de la puerta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Puerta")
	UStaticMeshComponent* MallaPuerta;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
