// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorPlataforma.h"
#include "DirectorPlataforma.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API ADirectorPlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorPlataforma();
	// Orquesta la construcción de una plataforma
	void ConstruirPlataforma(IConstructorPlataforma* Constructor)
	{
		if (Constructor)
		{
			Constructor->ConstruirMaterial();
			Constructor->ConstruirResistencia();
			Constructor->ConstruirTamano();
		}
	}


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
