// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Int64.h"
#include "ModioHWrapper.h"
#include "FModioFilehash.h"
#include "FModioDownload.h"
#include "FModioModfile.generated.h"

USTRUCT(BlueprintType)
struct FModioModfile
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 VirusStats;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 VirusPositive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateScanned;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FInt64 Filesize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Version;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString VirustotalHash;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Changelog;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString MetadataBlob;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioFilehash Filehash;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioDownload Download;
};

extern void InitializeModfile(FModioModfile &modfile, const ModioModfile &modio_modfile);