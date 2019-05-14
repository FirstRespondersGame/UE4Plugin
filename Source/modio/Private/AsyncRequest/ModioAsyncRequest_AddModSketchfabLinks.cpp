#include "AsyncRequest/ModioAsyncRequest_AddModSketchfabLinks.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_AddModSketchfabLinks::FModioAsyncRequest_AddModSketchfabLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_AddModSketchfabLinks::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_AddModSketchfabLinks* ThisPointer = (FModioAsyncRequest_AddModSketchfabLinks*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}