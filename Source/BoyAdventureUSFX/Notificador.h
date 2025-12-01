// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Observer.h"
#include "Notificador.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNotificador : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOYADVENTUREUSFX_API INotificador
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//metotos de la interfaz
	//virtual ~INotificador() = default;

	virtual void Attach(IObserver* Observer) = 0;
	virtual void Detach(IObserver* Observer) = 0;
	virtual void Notify(AActor* Actor, bool bEntrando) = 0;

};
