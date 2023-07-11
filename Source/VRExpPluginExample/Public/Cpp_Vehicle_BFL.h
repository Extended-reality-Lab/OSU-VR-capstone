// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cpp_Vehicle_BFL.generated.h"

class UArrowComponent;
/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API UCpp_Vehicle_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UENUM(BlueprintType)
		enum class LeverEnum : uint8
	{
		Left,
		Right,
		F
	};

	UFUNCTION(BlueprintCallable)
		FTransform Lever_Control(bool is_grab, FTransform Lever_tip,
			UArrowComponent Arrow, UStaticMeshComponent* Mesh_ToMove, FTransform IK_Trans);

};
