// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Cpp_WheeledVehiclePawn.generated.h"

class UVRLeverComponent;

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
		USceneComponent* R_lever_base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		USceneComponent* L_lever_base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UVRLeverComponent* L_lever;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		UVRLeverComponent* R_lever;
	
	float Move_speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	bool Is_right_grip = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ik_use)
		FTransform Ik_Transe = FTransform(FVector(0, 6958.0, 3000.0));

	UFUNCTION(BlueprintCallable)
		FTransform R_Control();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
