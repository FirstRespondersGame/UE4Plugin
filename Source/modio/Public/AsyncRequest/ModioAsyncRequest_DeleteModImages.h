// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when images were deleted from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModImages : public FModioAsyncRequest
{
public:
  static void Response(void *Object, ModioResponse ModioResponse );

protected:
  FModioAsyncRequest_DeleteModImages( FModioSubsystem* Modio, FModioGenericDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioGenericDelegate ResponseDelegate;
};