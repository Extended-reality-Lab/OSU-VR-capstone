// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cpp_Vehicle_BFL.generated.h"

class UArrowComponent;
/**
 * 
 */

UENUM(BlueprintType)
enum LeverEnum
{
	Rotated_Left,
	Rotated_Right,
	Rotated_Forward,
	Rotated_back,
	Not_rotated
	
	
};


UCLASS()
class VREXPPLUGINEXAMPLE_API UCpp_Vehicle_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:


	UFUNCTION(BlueprintCallable, Category = "Stuff", 
		Meta = (ExpandEnumAsExecs = "Branches"))
		static void Get_lever_direction(FTransform Lever_base, FTransform Forword_arrow,
			FVector Lever_tip, TEnumAsByte<LeverEnum>& Branches);

};
