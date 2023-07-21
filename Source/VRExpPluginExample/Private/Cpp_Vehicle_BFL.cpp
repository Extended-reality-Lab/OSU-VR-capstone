// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_Vehicle_BFL.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"


float UCpp_Vehicle_BFL::Get_lever_direction(FTransform Lever_base, FTransform Forword_arrow,
	FVector Lever_tip, TEnumAsByte<LeverEnum>& Branches)
{
	FVector Base_location = Lever_base.GetLocation();
	FVector Arrow_Driection = Forword_arrow.GetRotation().GetForwardVector();
	FVector Point_onplan = UKismetMathLibrary::ProjectPointOnToPlane(Lever_tip, 
		Base_location,Lever_base.GetRotation().GetUpVector());
	float Move_Speed = UKismetMathLibrary::Vector_Distance(Point_onplan, Base_location);
	if (Move_Speed < 10) {
		// Minimum rotation threshold 
		Branches = Not_rotated;
		return Move_Speed;
	}

	FVector Left_OR_Right = UKismetMathLibrary::Cross_VectorVector(Point_onplan - Base_location, 
																Arrow_Driection);
	if (Left_OR_Right.Z == 0) {
		// not rotation at all
		Branches = Not_rotated;
		return Move_Speed;
	}

	// forward or back
	float Forwad_or_back_tmp = FVector::DotProduct((UKismetMathLibrary::Normal(Arrow_Driection, 0.001)),
		UKismetMathLibrary::Normal(Point_onplan - Base_location, 0.001));
	float Forwad_or_back = UKismetMathLibrary::RadiansToDegrees(UKismetMathLibrary::Acos(Forwad_or_back_tmp));;


	if (Forwad_or_back >= 45 && Forwad_or_back <= 135) {
		// Left or Right rotation
		if (Left_OR_Right.Z < 0) {
			// Go right
			Branches = Rotated_Right;
			return Move_Speed;
		}
		else {
			// Go Left
			Branches = Rotated_Left;
			return Move_Speed;
		}
	}
	else {
		// Forwad or Back rotation
		if (Forwad_or_back >= 45) {
			// Go back
			Branches = Rotated_back;
			return Move_Speed;
		}
		else {
			// Go Forward
			Branches = Rotated_Forward;
			return Move_Speed;
		}
	}
}
