// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

	virtual void Activar();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//class UStaticMeshComponent* MallaPlataforma;
	UStaticMeshComponent* MallaPlataforma;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
