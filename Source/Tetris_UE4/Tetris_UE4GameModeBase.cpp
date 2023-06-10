// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris_UE4GameModeBase.h"
#include "Board.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "Libro/Builder_Main.h"
#include "Libro/Singleton_Main.h"


#include "Block_Explosivo.h"
#include "Ingeniero_Bloques.h"
#include "Block_HIelo.h"

#include "EscenarioShop_1.h"
#include "EscenarioShop_2.h"

#include "Libro/Observer_Main.h"


#include "Libro/StarShipFacade_Main.h"
#include "CuboGeneralFacade.h"
#include "CubosFacade.h"

#include "BloqueObedece.h"
#include "Senalador.h"

#include "OldBoard.h"

#include "Libro/FactoryMethod_Main.h"
#include "EngineUtils.h"




ATetris_UE4GameModeBase::ATetris_UE4GameModeBase()
{
    DefaultPawnClass = ABoard::StaticClass();
}

void ATetris_UE4GameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    for(TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        //UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if(it->GetFName() == TEXT("BoardCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

    //GetWorldTimerManager().SetTimer(Cronometro, this, &ATetris_UE4GameModeBase::cambiar, 03.0f, true, 2.0f);


    //GetWorld()->SpawnActor<ASingleton_Main>(ASingleton_Main::StaticClass());
    //GetWorld()->SpawnActor<ABuilder_Main>(ABuilder_Main::StaticClass());


 //   	for (int i = 0; i <= 2; i++)
	//{
	//	ABoard* Aparecio = GetWorld() -> SpawnActor<ABoard>(ABoard::StaticClass());
	//	if (Aparecio)
	//	{
	//		//If the Spawn succeeds, set the Spawned inventory to the local one and log the success string
	//		Board = Aparecio;
	//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s El board está apareciendo"),*Board->GetName()));
	//	}
	//}




    //Patrón Builder

    //Aparece el builder Builder and Engineer
    //Block_Explosivo = GetWorld()->SpawnActor<ABlock_Explosivo>(ABlock_Explosivo::StaticClass());
    //Block_HIelo = GetWorld()->SpawnActor<ABlock_HIelo>(ABlock_HIelo::StaticClass());
    //Ingeniero = GetWorld()->SpawnActor<AIngeniero_Bloques>(AIngeniero_Bloques::StaticClass());



    //int random = FMath::FRandRange(1,5);                 //elegir el tipo de bloque de manera aleatoria
    //
    //if (random == 1)
    //{
    //    Ingeniero->SetConstructorBloque(Block_Explosivo);
    //    Ingeniero->ConstruirBloque();
    //}
    //else {
    //    Ingeniero->SetConstructorBloque(Block_HIelo);
    //    Ingeniero->ConstruirBloque();
    //}
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El numero random"), random));
    //ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
    //BloqueGeneral->BloqueCaracteristicas();


    ////Set the Builder for the Engineer and create the buildings
    //Ingeniero->SetConstructorBloque(Block_Explosivo);
    //Ingeniero->ConstruirBloque();
    ////Get the Engineer's Lodging and Logs the created buildings
    //ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
    //BloqueGeneral->BloqueCaracteristicas();

    //Ingeniero->SetConstructorBloque(Block_HIelo);
    //Ingeniero->ConstruirBloque();
    //BloqueGeneral->BloqueCaracteristicas();




    //Factory_Method
    
    //GetWorld()->SpawnActor<AFactoryMethod_Main>(AFactoryMethod_Main::StaticClass());

    //Haciendo aparecer los generadores de escenarios
    //AEscenarioShop* EscenarioShop_1 = GetWorld() -> SpawnActor<AEscenarioShop_1>(AEscenarioShop_1::StaticClass());
    //AEscenarioShop* EscenarioShop_2 = GetWorld()->SpawnActor<AEscenarioShop_2>(AEscenarioShop_2::StaticClass());


    //Definiendo los escenarios
    //AEscenario* Escenario = EscenarioShop_1->OrdenarEscenario("Escenario_3");
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("El escenario es %s"),*Escenario->GetNombreEscenario()));


    //Observer

    //GetWorld()->SpawnActor<AObserver_Main>(AObserver_Main::StaticClass());


    //Facade

    //GetWorld()->SpawnActor<AStarShipFacade_Main>(AStarShipFacade_Main::StaticClass());

        //Create the Ship Facade Actor
    //ACubosFacade* CubosFacade = GetWorld()->SpawnActor<ACubosFacade>(ACubosFacade::StaticClass());
    //Execute the needed tasks

    //CubosFacade->Saltar();



    //Patron Observer
    //Spawn the Clock Tower
    //ASenalador* Senalador = GetWorld()->SpawnActor<ASenalador>(ASenalador::StaticClass());
    //Spawn the first Subscriber and set its Clock Tower
    //ABloqueObedece* BloqueObedece = GetWorld()->SpawnActor<ABloqueObedece>(ABloqueObedece::StaticClass());
    //BloqueObedece->DefinirSenalador(Senalador);

    //Change the time of the Clock Tower, so the Subscribers can execute their own routine
    //Senalador->DefinirEstado("Estado2");
    //Senalador->DefinirEstado("Estado2");
    //Senalador->DefinirEstado("Estado3");


    ////Patron State
    //// 
    ////Create the Slot Machine and set its Dollars Amount to 100
    //AOldBoard* OldBoard = GetWorld() -> SpawnActor<AOldBoard>(AOldBoard::StaticClass()); OldBoard->Inicializar(100);

    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OldBoard->GetEstado() -> ToString()));

    ////Insert coin and Pull the lever
    //OldBoard->InsertarCubo();
    //OldBoard->JalarPalanca();

    //// Log the current Slot Machine state
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OldBoard->GetEstado() -> ToString()));


    ////Insert coin, Pull the lever, then insert coin again
    //OldBoard->InsertarCubo();
    //OldBoard->JalarPalanca();
    //OldBoard->InsertarCubo();

    //// Log the current Slot Machine state
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *OldBoard->GetEstado()->ToString()));

    //Pull the lever
    //OldBoard->JalarPalanca();
    //Add 100 Dollars
    //OldBoard->RellenarBloques(100);
    //Insert coin and Pull the lever
    //OldBoard->InsertarCubo();
    //OldBoard->JalarPalanca();
    //Log the current Slot Machine state
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OldBoard->GetEstado() -> ToString()));



}

void ATetris_UE4GameModeBase::cambiar()
{

    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT(" Cronometro")));

}
