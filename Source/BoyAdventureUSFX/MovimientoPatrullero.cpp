// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoPatrullero.h"
#include "Enemigo.h"

MovimientoPatrullero::MovimientoPatrullero()
{
}

MovimientoPatrullero::~MovimientoPatrullero()
{
}

void MovimientoPatrullero::Mover(AEnemigo* Enemigo, float DeltaTime)
{
    if (Enemigo)
    {
        FVector Posicion = Enemigo->GetActorLocation(); // Definir la variable Posicion correctamente

        // Actualizar la posición en el eje Y
        Posicion.Y += Velocidad * Direccion * DeltaTime;

        // Verificar si se alcanzan los límites
        if (Posicion.Y >= LimiteMaxY)
        {
            Direccion = -1; // Cambiar dirección hacia atrás
        }
        else if (Posicion.Y <= LimiteMinY)
        {
            Direccion = 1; // Cambiar dirección hacia adelante
        }

        // Aplicar la nueva posición
        Enemigo->SetActorLocation(Posicion);
    }
}

