// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "FModioModEditor.generated.h"

USTRUCT(BlueprintType)
struct FModioModEditor
{
  GENERATED_BODY()
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
};