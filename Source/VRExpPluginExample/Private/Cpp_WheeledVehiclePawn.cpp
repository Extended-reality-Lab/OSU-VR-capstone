// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_WheeledVehiclePawn.h"
#include "VRExpansionPlugin//Public/Interactibles/VRLeverComponent.h"
#include "VRExpansionPlugin/Public/VRBaseCharacter.h"
#include "Components/ArrowComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosVehicleMovementComponent.h"
#include "Kismet/GameplayStatics.h"

ACpp_WheeledVehiclePawn::ACpp_WheeledVehiclePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));

	Upper = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Upper"));

	Driver_pos = CreateDefaultSubobject<USceneComponent>(TEXT("Driver_set"));

	R_lever_base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("R_lever_base"));
	
	L_lever_base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("L_lever_base"));

	L_lever = CreateDefaultSubobject<UVRLeverComponent>(TEXT("L_lever"));

	R_lever = CreateDefaultSubobject<UVRLeverComponent>(TEXT("R_lever"));

	tip3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moveable_Tip3"));

	tip2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moveable_Tip2"));

	tip1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moveable_Tip1"));

	tip = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moveable_Tip"));

	tip_move = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("tip_move"));

	Right_tip_low = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right_tip_low"));

	Right_tip_up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right_tip_up"));

	Left_tip = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left_tip"));

	Left_tip_up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left_tip_up"));

	Left_tip_low = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left_tip_low"));

	RIght_tip = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RIght_tip"));

	Tip_move_physice = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Tip_move_physice"));

	Right_arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("R_arrow"));

	Left_arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("L_arrow"));

	R_lever_tip = CreateDefaultSubobject<USceneComponent>(TEXT("RLever_tip"));

	L_lever_tip = CreateDefaultSubobject<USceneComponent>(TEXT("LLever_tip"));

	RootComponent = GetMesh();

	Base->SetupAttachment(GetMesh());

	Upper->SetupAttachment(Base);

	R_lever_base->SetupAttachment(Upper);
	L_lever_base->SetupAttachment(Upper);

	tip3->SetupAttachment(Upper);
	tip2->SetupAttachment(tip3);
	tip1->SetupAttachment(tip2);
	tip->SetupAttachment(tip1);

	tip_move->SetupAttachment(tip);
	RIght_tip->SetupAttachment(tip_move);
	Right_tip_low->SetupAttachment(tip_move);
	Right_tip_up->SetupAttachment(tip_move);
	Left_tip->SetupAttachment(tip_move);
	Left_tip_low->SetupAttachment(tip_move);
	Left_tip_up->SetupAttachment(tip_move);

	Tip_move_physice->SetupAttachment(tip1);

	Driver_pos->SetupAttachment(Upper);
	L_lever->SetupAttachment(L_lever_base);
	R_lever->SetupAttachment(R_lever_base);

	
	Right_arrow->SetupAttachment(R_lever_base);
	Left_arrow->SetupAttachment(L_lever_base);

	R_lever_tip->SetupAttachment(R_lever);

	L_lever_tip->SetupAttachment(L_lever);


	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
	{
		/*if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMapping.IsNull())
			{
				InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), Priority);
			}
		}*/
	}


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

	Set_driver();
	Super::BeginPlay();
	//.bool AVRBaseCharacter::SetSeatedMode(USceneComponent * SeatParent, bool bSetSeatedMode, FTransform TargetTransform
	//, FTransform InitialRelCameraTransform, float AllowedRadius, float AllowedRadiusThreshold, bool bZeroToHead, EVRConjoinedMovementModes PostSeatedMovementMode)
	//SetSeatedMode
	//AVRBaseCharacter::SetSeatedMode(*Driver_pos,);

}

void ACpp_WheeledVehiclePawn::Set_driver()
{

	AVRBaseCharacter* player;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			player = Cast<AVRBaseCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player != nullptr)
	{
		player->SetSeatedMode(Driver_pos, true, player->VRProxyComponent->GetRelativeTransform(), FTransform(), 40.0, 20.0, true);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("in set")));
	}

		}, 3, false);
}

void ACpp_WheeledVehiclePawn::Throttle(float val)
{
	
	//GetVehicleMovementComponent()->SetThrottleInput(0);
	if (val < 0) {//go back
		
		GetVehicleMovementComponent()->SetThrottleInput(0);
		GetVehicleMovementComponent()->SetBrakeInput(-val);
	}
	else if(val >0) {//go forword 
		GetVehicleMovementComponent()->SetBrakeInput(0);
		GetVehicleMovementComponent()->SetThrottleInput(val);
	}
	else {
		GetVehicleMovementComponent()->SetBrakeInput(0);
	}
}

void ACpp_WheeledVehiclePawn::Base_Rotation(float val)
{
	//set rotation 
	
	FTransform tmp = GetActorTransform();
	if (TeleportTo(tmp.GetLocation(),
		FRotator(tmp.GetRotation().X, tmp.GetRotation().Y, tmp.GetRotation().Z + val),
		false, false)) {

		TeleportEnumToFlag(ETeleportType::TeleportPhysics);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("true")));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("false")));
	}
	}
	
		

	/*SetActorRotation(FQuat(FRotator(
		tmp.GetRotation().X, tmp.GetRotation().Y, tmp.GetRotation().Z + val)));*/

	




