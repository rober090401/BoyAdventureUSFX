// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZonaSeguraInterface.h"
#include "ZonaProxy.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API AZonaProxy : public AActor, public IZonaSeguraInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZonaProxy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// implementacion del metodo de la interfaz
	virtual bool EstaEnZonaSegura(AActor* ActorARevisar) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* ZonaColision;

	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* ParticulaVisual;

	FTimerHandle TimerDesactivacion;
	FTimerHandle TimerActivacion;

	void ActivarZona();
	void DesactivarZona();

};
