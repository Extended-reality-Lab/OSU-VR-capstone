// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Cpp_Vehicle_BFL.h"

void UCpp_Vehicle_BFL::Get_lever_direction(FTransform Lever_base, FTransform Forword_arrow,
	FVector Lever_tip, TEnumAsByte<LeverEnum>& Branches)
{
	FVector Base_location = Lever_base.GetLocation();
	FVector Arrow_Driection = Forword_arrow.GetRotation().GetUpVector();
	FVector Point_onplan = UKismetMathLibrary::ProjectPointOnToPlane(Lever_tip, 
		Base_location,Lever_base.GetRotation().GetUpVector());

	float Move_Speed = UKismetMathLibrary::Vector_Distance(Point_onplan, Base_location);
	if (Move_Speed < 10) {
		return;
	}

	FVector Left_Right = UKismetMathLibrary::Cross_VectorVector(Point_onplan - Base_location, 
																Arrow_Driection);
	if (Left_Right.Z == 0) {
		return;
	}


	Point_onplan - Base_location;
	


}
