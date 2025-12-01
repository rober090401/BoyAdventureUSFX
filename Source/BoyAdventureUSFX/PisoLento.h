// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPiso.h"
#include "Notificador.h"
#include "PisoLento.generated.h"

class ACharacter;

UCLASS()
class BOYADVENTUREUSFX_API APisoLento : public AObstaculoPiso, public INotificador
{
	GENERATED_BODY()
	
public:
	APisoLento();

protected:
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnMeshEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
    TArray<IObserver*> Observadores;

public:
    // Implementación de INotificador
    virtual void Attach(IObserver* Observer) override;
    virtual void Detach(IObserver* Observer) override;
    virtual void Notify(AActor* Actor, bool bEntrando) override;


 };