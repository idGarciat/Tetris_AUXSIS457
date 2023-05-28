// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "kismet/GameplayStatics.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Pieces.h"
#include "Board.generated.h"

class AEscenarioShop;
class APruebaMesh;

UCLASS()
class TETRIS_UE4_API ABoard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Rotate(); // 旋转90度，如果不能旋转则忽略
    void Rotar();
    void MoveLeft();  // 向左移动一格
    void MoveRight(); // 向右移动一格
    void MoveDown(); // 向下移动一格
    void NewPieces(); // 随机产生一个新的形状
    void CheckLine(); // 检查是否某一行可以消除了
    void MoveDownToEnd(); // 向下移动到不能移动为止
public:
    UPROPERTY()
    APieces* CurrentPieces;
    
    UPROPERTY()
    class USoundCue* LineRemoveSoundCue;
    
    UPROPERTY()
    class USoundCue* MoveToEndSoundCue;
    
    UPROPERTY()
    class USoundCue* GameOverSoundCue;
    
    UPROPERTY()
    class USoundCue* GameStartSoundCue;
private:
    enum PiecesStatus { PS_NOT_INITED, PS_MOVING, PS_GOT_BOTTOM};
    PiecesStatus Status = PS_NOT_INITED;
    
    const float CoolDown = 0.5f;
    float CoolLeft = 0.5f;
    bool bGameOver = false;
    
    bool CheckGameOver();


    void SwitchLevel(float direction);
    TArray<FString> levels;

public:
    UPROPERTY()
        ABoard* limite;


    void Builder();

    //The Builder Actor
    UPROPERTY(VisibleAnywhere, Category = "Main")
        class ABlock_Explosivo* Block_Explosivo;
    ////The Engineer Actor
    //UPROPERTY(VisibleAnywhere, Category = "Main")
    class AIngeniero_Bloques* Ingeniero;

    UPROPERTY(VisibleAnywhere, Category = "Main")
        class ABlock_HIelo* Block_HIelo;

    UPROPERTY(VisibleAnywhere, Category = "Main")
        class ABlock_Piedra* Block_Piedra;

    int contador;


    //Factory method

    void Cambiar_Escenario();

    AEscenarioShop* EscenarioShop_1;

    int contador2;


    APruebaMesh* PruebaMesh;
};
