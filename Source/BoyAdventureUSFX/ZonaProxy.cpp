// Fill out your copyright notice in the Description page of Project Settings.


#include "ZonaProxy.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AZonaProxy::AZonaProxy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Componente de colisión: Caja (Box)
	ZonaColision = CreateDefaultSubobject<UBoxComponent>(TEXT("ZonaColision"));
	RootComponent = ZonaColision;
	ZonaColision->SetBoxExtent(FVector(200.f, 200.f, 700.f));
	ZonaColision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ZonaColision->SetCollisionResponseToAllChannels(ECR_Ignore);
	ZonaColision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	ZonaColision->SetGenerateOverlapEvents(true);

	// Sistema de partículas
	ParticulaVisual = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticulaVisual"));
	ParticulaVisual->SetupAttachment(RootComponent);
	ParticulaVisual->bAutoActivate = false;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'")); 
	if (ParticleAsset.Succeeded())
	{
		ParticulaVisual->SetTemplate(ParticleAsset.Object);
	}

}

// Called when the game starts or when spawned
void AZonaProxy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZonaProxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AZonaProxy::EstaEnZonaSegura(AActor* ActorARevisar)
{
	if (!ActorARevisar || !ZonaColision) return false;
	return ZonaColision->IsOverlappingActor(ActorARevisar);
}

void AZonaProxy::ActivarZona()
{
	// Posición aleatoria dentro del rango
	FVector NuevaPosicion = FVector(
		FMath::RandRange(-1100.f, 1100.f),
		FMath::RandRange(-1100.f, 1100.f),
		GetActorLocation().Z
	);

	SetActorLocation(NuevaPosicion);

	// Activar visual
	if (ParticulaVisual)
	{
		ParticulaVisual->SetActive(true, true);     // reset y activa
		ParticulaVisual->SetVisibility(true);
		ParticulaVisual->ActivateSystem(true);      // forzar activación
	}

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	// Timer para desactivar
	GetWorldTimerManager().SetTimer(TimerDesactivacion, this, &AZonaProxy::DesactivarZona, 5.0f, false);

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Zona segura ACTIVADA"));
}

void AZonaProxy::DesactivarZona()
{
	if (ParticulaVisual)
	{
		ParticulaVisual->DeactivateSystem();
		ParticulaVisual->SetVisibility(false);
		ParticulaVisual->SetActive(false);
	}

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	// Timer para volver a activar
	GetWorldTimerManager().SetTimer(TimerActivacion, this, &AZonaProxy::ActivarZona, 3.0f, false);

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Zona segura DESACTIVADA"));
}


