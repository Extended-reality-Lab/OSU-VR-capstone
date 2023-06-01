// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Cpp_WheeledVehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API ACpp_WheeledVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __Main)
	//	UStaticMeshComponent* R_base_Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		USceneComponent* R_lever_base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		USceneComponent* L_lever_base;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
		//VRlevel
	ACpp_WheeledVehiclePawn();

	float Move_speed = 0;

	



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	bool Is_right_grip = false;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = lever_vir)
	//VRlever

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ik_use)
		FTransform Ik_Transe = FTransform(FVector(0, 6958.0, 3000.0));

	UFUNCTION(BlueprintCallable)
		FTransform R_Control();
};
