// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

#include "Cpp_WheeledVehiclePawn.generated.h"

class UVRLeverComponent;
class UArrowComponent;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API ACpp_WheeledVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:

	ACpp_WheeledVehiclePawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __Main)
		UStaticMeshComponent* Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __Main)
		USkeletalMeshComponent* Upper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __Main)
		USceneComponent* Driver_pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		USceneComponent* R_lever_tip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		USceneComponent* L_lever_tip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UStaticMeshComponent* R_lever_base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UStaticMeshComponent* L_lever_base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UVRLeverComponent* L_lever;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UVRLeverComponent* R_lever;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UArrowComponent* Right_arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UArrowComponent* Left_arrow;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* tip3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* tip2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* tip1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* tip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* tip_move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* Right_tip_low;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* Right_tip_up;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* Left_tip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* Left_tip_up;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* Left_tip_low;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UStaticMeshComponent* RIght_tip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tip)
		UPhysicsConstraintComponent* Tip_move_physice;

	

	
	
	float Move_speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	bool Is_right_grip = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	bool Right_grip = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	bool Left_grip = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ik_use)
		FTransform Ik_Transe = FTransform(FVector(0, 6958.0, 3000.0));


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		FTransform R_Control();
	UFUNCTION(BlueprintCallable)
		void Set_driver();
	UFUNCTION(BlueprintCallable)
		void Throttle(float Thr_sp);
	UFUNCTION(BlueprintCallable)
		void Base_Rotation(float Rot_sp);
	
};
