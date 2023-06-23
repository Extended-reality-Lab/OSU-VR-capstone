// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_WheeledVehiclePawn.h"
#include "VRExpansionPlugin//Public/Interactibles/VRLeverComponent.h"
#include "VRExpansionPlugin/Public/VRBaseCharacter.h"
#include "Kismet/GameplayStatics.h"

ACpp_WheeledVehiclePawn::ACpp_WheeledVehiclePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));

	Upper = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Upper"));

	Driver_pos = CreateDefaultSubobject<USceneComponent>(TEXT("Driver_set"));

	R_lever_base = CreateDefaultSubobject<USceneComponent>(TEXT("R_lever_base"));
	
	L_lever_base = CreateDefaultSubobject<USceneComponent>(TEXT("L_lever_base"));

	L_lever = CreateDefaultSubobject<UVRLeverComponent>(TEXT("L_lever"));

	R_lever = CreateDefaultSubobject<UVRLeverComponent>(TEXT("R_lever"));

	R_lever_base->SetupAttachment(Upper);
	L_lever_base->SetupAttachment(Upper);

	Upper->SetupAttachment(Base);

	Driver_pos->SetupAttachment(Upper);
	
	L_lever->SetupAttachment(L_lever_base);

	R_lever->SetupAttachment(R_lever_base);

}

FTransform ACpp_WheeledVehiclePawn::R_Control()
{
	if (!Is_right_grip) {
		return Ik_Transe;
	}



	return FTransform();
}

void ACpp_WheeledVehiclePawn::BeginPlay()
{
	
	ACharacter* get_player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LLLLLLLLLLLLLLLLLL %f"), GetWorld()->TimeSeconds));
	if (AVRBaseCharacter* player = Cast<AVRBaseCharacter>(get_player))
	{
		player->SetSeatedMode(Driver_pos, true, player->VRProxyComponent->GetRelativeTransform(), FTransform(), 40.0, 20.0, true);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("World delta for current frame equals %f"), GetWorld()->TimeSeconds));
	}
	
	


	//.bool AVRBaseCharacter::SetSeatedMode(USceneComponent * SeatParent, bool bSetSeatedMode, FTransform TargetTransform
	//, FTransform InitialRelCameraTransform, float AllowedRadius, float AllowedRadiusThreshold, bool bZeroToHead, EVRConjoinedMovementModes PostSeatedMovementMode)
	//SetSeatedMode
	//AVRBaseCharacter::SetSeatedMode(*Driver_pos,);

}
