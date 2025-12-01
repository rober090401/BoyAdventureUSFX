// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorPlataforma.h"
#include "PlataformaMadera.h"
#include "ConstructorPlataformaMadera.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API AConstructorPlataformaMadera : public AActor, public IConstructorPlataforma
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructorPlataformaMadera();

	// Implementación de la interfaz
	virtual void ConstruirMaterial() override;
	virtual void ConstruirResistencia() override;
	virtual void ConstruirTamano() override;
	virtual APlataforma* ObtenerPlataforma() override;
private:
	APlataformaMadera* PlataformaConstruida;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
