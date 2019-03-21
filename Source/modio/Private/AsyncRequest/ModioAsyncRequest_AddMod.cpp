#include "AsyncRequest/ModioAsyncRequest_AddMod.h"

FModioAsyncRequest_AddMod::FModioAsyncRequest_AddMod( FModioSubsystem *Modio, FAddModDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_AddMod::Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioMod Mod;
  InitializeMod( Mod, ModioMod );
  
  FModioAsyncRequest_AddMod* ThisPointer = (FModioAsyncRequest_AddMod*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, Mod );
  
  ThisPointer->Done();
}