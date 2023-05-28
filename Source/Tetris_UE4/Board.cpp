// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "EscenarioShop_1.h"
#include "PruebaMesh.h"

#include "Block_Explosivo.h"
#include "Ingeniero_Bloques.h"
#include "Block_HIelo.h"
#include "Block_Piedra.h"

#include "Sound/SoundCue.h"



// Sets default values
ABoard::ABoard()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<USoundCue> LineRemove_Sound(TEXT("SoundCue'/Game/Sounds/line-remove_Cue.line-remove_Cue'"));
    if(LineRemove_Sound.Succeeded())
    {
        LineRemoveSoundCue = LineRemove_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> MoveToEnd_Sound(TEXT("SoundCue'/Game/Sounds/force-hit_Cue.force-hit_Cue'"));
    if(MoveToEnd_Sound.Succeeded())
    {
        MoveToEndSoundCue = MoveToEnd_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> GameStart_Sound(TEXT("SoundCue'/Game/Sounds/start_Cue.start_Cue'"));
    if(GameStart_Sound.Succeeded())
    {
        GameStartSoundCue = GameStart_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> GameOver_Sound(TEXT("SoundCue'/Game/Sounds/gameover_Cue.gameover_Cue'"));
    if(GameOver_Sound.Succeeded())
    {
        GameOverSoundCue = GameOver_Sound.Object;
    }

    levels.Add("Default");
    levels.Add("Map1");
    levels.Add("Map2");




    TArray<AActor*> cantidad;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), cantidad);
    if (cantidad.Num() > 1)
    {
        //If exist at least one of them, set the instance with the first found one
        limite = Cast<ABoard>(cantidad[0]);
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Ya existe el board"), *limite->GetName()));
        //Then Destroy this Actor
        Destroy();
    }

}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
    for(TActorIterator<APieces> it(GetWorld()); it; ++it)
    {
        if(it->GetFName() == TEXT("DissmissPieces"))
        {
            it->Dismiss();
            it->Destroy();
        }
    }



    Block_Explosivo = GetWorld()->SpawnActor<ABlock_Explosivo>(FVector(1000, 1000, 1000),FRotator(0,0,0));
    Block_HIelo = GetWorld()->SpawnActor<ABlock_HIelo>(FVector(1000, 1000, 1000), FRotator(0, 0, 0));
    Ingeniero = GetWorld()->SpawnActor<AIngeniero_Bloques>(AIngeniero_Bloques::StaticClass());

    contador = 0;
    contador2 = 0;

    EscenarioShop_1 = GetWorld()->SpawnActor<AEscenarioShop_1>(AEscenarioShop_1::StaticClass());

}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    if(bGameOver)
    {
        return;
    }

    switch(Status)
    {
        case PS_NOT_INITED:
            NewPieces();
            CoolLeft = CoolDown;
            Status = PS_MOVING;
            break;
        case PS_MOVING:
            CoolLeft -= DeltaTime;
            if(CoolLeft <= 0.0f)
            {
                MoveDown();
            }
            break;
        case PS_GOT_BOTTOM:
            CoolLeft -= DeltaTime;
            if(CoolLeft <= 0.0f)
            {
                if(CurrentPieces)
                {
                    CurrentPieces->Dismiss();
                    CurrentPieces->Destroy();
                }
                CurrentPieces = nullptr;
                NewPieces();
                CoolLeft = CoolDown;
                Status = PS_MOVING;
            }
            break;
        default:
            break;
    }
}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Rotate", IE_Pressed, this, &ABoard::Rotate);
    PlayerInputComponent->BindAction("Rotar", IE_Pressed, this, &ABoard::Rotar);

    PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ABoard::MoveLeft);
    PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABoard::MoveRight);
    PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &ABoard::MoveDown);
    PlayerInputComponent->BindAction("MoveDownToEnd", IE_Pressed, this, &ABoard::MoveDownToEnd);


    //PlayerInputComponent->BindAction("NewPieces", IE_Pressed, this, &ABoard::NewPieces);
    //PlayerInputComponent->BindAction("CheckLine", IE_Pressed, this, &ABoard::CheckLine);


    //PlayerInputComponent->BindAxis("ChangeLevel", this, &ABoard::SwitchLevel);

    PlayerInputComponent->BindAction("Builder", IE_Pressed, this, &ABoard::Builder);

    PlayerInputComponent->BindAction("Escenario", IE_Pressed, this, &ABoard::Cambiar_Escenario);
}


void ABoard::Rotate()
{
    if(CurrentPieces && Status != PS_GOT_BOTTOM)
    {
        CurrentPieces->TestRotate();
    }
}

void ABoard::Rotar()
{
    if (CurrentPieces && Status != PS_GOT_BOTTOM)
    {
        CurrentPieces->Rotar();
    }

}

void ABoard::MoveLeft()
{
    if(CurrentPieces)
    {
        CurrentPieces->MoveLeft();
        if(Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveRight()
{
    if(CurrentPieces)
    {
        CurrentPieces->MoveRight();
        if(Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveDown()
{
    if(CurrentPieces)
    {
        if(!CurrentPieces->MoveDown())
        {
            Status = PS_GOT_BOTTOM;
        }
        CoolLeft = CoolDown;
    }
}

void ABoard::NewPieces()
{
    CheckLine();
    if(CurrentPieces)
    {
        CurrentPieces->Dismiss();
        CurrentPieces->Destroy();
    }
    
    FVector Location(0.0, 5.0, 195.0);
    FRotator Rotation(0.0, 0.0, 0.0);
    CurrentPieces = GetWorld()->SpawnActor<APieces>(Location, Rotation);
    bGameOver = CheckGameOver();
    if(bGameOver)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game Over!!!!!!!!"));
        if(GameOverSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameOverSoundCue, GetActorLocation(), GetActorRotation());
        }
    }
}

void ABoard::CheckLine()
{
    auto MoveDownFromLine = [this](int z){
        FVector Location(0.0f, 0.0f, 5.0*z + 100.0);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        FVector Extent(4.5f, 49.5f, 95.0+4.5-5.0*z);
        CollisionShape.SetBox(Extent);
        DrawDebugBox(GetWorld(), Location, Extent, FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        if(GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam))
        {
            for(auto&& Result: OutOverlaps)
            {
                FVector NewLocation = Result.GetActor()->GetActorLocation();
                NewLocation.Z -= 10.0f;
                Result.GetActor()->SetActorLocation(NewLocation);
            }
        }
    };
    
    int z = 0;
    while(z < 20)
    {
        FVector Location(0.0f, 0.0f, 10.0f * z + 5.0f);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        CollisionShape.SetBox(FVector(4.0f, 49.0f, 4.0f));
        //DrawDebugBox(GetWorld(), Location, FVector(4.5f, 49.5f, 4.5f), FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        bool b = GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam);
        if(!b || OutOverlaps.Num() < 10)
        {
            ++z;
            continue;
        }
        else // this line is full, remove the line
        {
            UE_LOG(LogTemp, Warning, TEXT("Find FULL LINE at z=%d"), z);
            for(auto&& Result: OutOverlaps)
            {
                Result.GetActor()->Destroy();
            }
            MoveDownFromLine(z);
            
            if(LineRemoveSoundCue)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), LineRemoveSoundCue, GetActorLocation(), GetActorRotation());
            }
        }
    }
}

void ABoard::MoveDownToEnd()
{
    if(!CurrentPieces)
    {
        return;
    }
    
    while(CurrentPieces->MoveDown())
    {

    }
    
    if(MoveToEndSoundCue)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveToEndSoundCue, GetActorLocation(), GetActorRotation());
    }
    
    switch(Status)
    {
        case PS_MOVING:
            Status = PS_GOT_BOTTOM;
            CoolLeft = CoolDown;
            break;
        case PS_GOT_BOTTOM:
            break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("Wrong status for MoveDownToEnd"));
            break;
    }
}

bool ABoard::CheckGameOver()
{
    if(!CurrentPieces)
    {
        UE_LOG(LogTemp, Warning, TEXT("NoPieces"));
        return true;
    }
    
    return CurrentPieces->CheckWillCollision([](FVector OldVector){ return OldVector; });
}

void ABoard::SwitchLevel(float direction)
{
    if (direction)
    {
        FString current = GetWorld()->GetMapName();
        current.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

        for (int i = 0; i < levels.Num(); i++)
        {
            if (current == levels[1])
            {
                if (i == 0 && direction < 0)
                {
                    i = levels.Num();
                    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("i =levels.num")));
                }
                if (i == levels.Num() - 1 && direction > 0)
                {
                    i = levels.Num() - 1;
                    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("i =-1")));
                }
                UGameplayStatics::OpenLevel(GetWorld(), FName(levels[i + direction]));
                break;
            }

        }

    }
}

void ABoard::Builder()
{

    contador = contador + 1;

    if (contador == 1)
    {
        Ingeniero->SetConstructorBloque(Block_Explosivo);
        Ingeniero->ConstruirBloque();

        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
        ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
        BloqueGeneral->BloqueCaracteristicas();

    }
    else if (contador ==2){
        Ingeniero->SetConstructorBloque(Block_HIelo);
        Ingeniero->ConstruirBloque();


        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
        ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
        BloqueGeneral->BloqueCaracteristicas();
        contador = 0;

    }
    //else if (contador == 3) {
    //    Ingeniero->SetConstructorBloque(Block_Piedra);
    //    Ingeniero->ConstruirBloque();


    //    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
    //    ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
    //    BloqueGeneral->BloqueCaracteristicas();
    //    contador = 0;
    //}

    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
    //ABloqueGeneral* BloqueGeneral = Ingeniero->GetBloqueGeneral();
    //BloqueGeneral->BloqueCaracteristicas();

}

void ABoard::Cambiar_Escenario()
{
    contador2 = contador2 + 1;
    if (contador2 == 1) {

        AEscenario* Escenario = EscenarioShop_1->OrdenarEscenario("Escenario_1");
    }
    else if (contador2 == 2) {
        AEscenario* Escenario = EscenarioShop_1->OrdenarEscenario("Escenario_2");
    }
    else if (contador2 == 3){
        AEscenario* Escenario = EscenarioShop_1->OrdenarEscenario("Escenario_3");

        contador2 = 0;

        PruebaMesh = GetWorld()->SpawnActor<APruebaMesh>(FVector(100,100,100),FRotator(90,270,90));

    }


    

}
