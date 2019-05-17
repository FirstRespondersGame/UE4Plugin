// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUserEvent.h"
#include "Enums/ModioFilterType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetUserEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserEventsResult,
    FModioResponse,
    Response,
    const TArray<FModioUserEvent> &,
    UserEvents);

UCLASS()
class MODIO_API UCallbackProxy_GetUserEvents : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioFilterType> FilterType;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserEventsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserEventsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetUserEvents *GetUserEvents(UObject *WorldContext, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserEventsDelegate(FModioResponse Response, const TArray<FModioUserEvent> &UserEvents);
};