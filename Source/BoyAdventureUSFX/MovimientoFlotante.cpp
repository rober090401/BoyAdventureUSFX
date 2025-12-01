// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoFlotante.h"
#include "Enemigo.h"

MovimientoFlotante::MovimientoFlotante()
{
}

MovimientoFlotante::~MovimientoFlotante()
{
}

void MovimientoFlotante::Mover(AEnemigo* Enemigo, float DeltaTime)
{
    if (Enemigo)
    {
        FVector Posicion = Enemigo->GetActorLocation();

        // Actualizar la posición en el eje Y
        Posicion.Z += Velocidad * Direccion * DeltaTime;

        // Verificar si se alcanzan los límites
        if (Posicion.Z >= LimiteMaxZ)
        {
            Direccion = -1; // Cambiar dirección hacia atrás
        }
        else if (Posicion.Z <= LimiteMinZ)
        {
            Direccion = 1; // Cambiar dirección hacia adelante
        }

        // Aplicar la nueva posición
        Enemigo->SetActorLocation(Posicion);

    }
}

