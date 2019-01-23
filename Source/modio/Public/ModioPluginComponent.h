#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "ModioSchemas.h"

#include "ModioPluginComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), DisplayName = "ModioPlugin")
class UModioPluginComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void OnRegister() override;
	void OnUnregister() override;

	/* onEmailRequest */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDelegate,
		int32
	);
	static FModioPlugin_OnEmailRequestDelegate OnEmailRequestDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailRequest"))
	FModioPlugin_OnEmailRequestDynamicDelegate OnEmailRequestDynamicDelegate;

	/* onEmailExchange */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDelegate,
		int32
	);
	static FModioPlugin_OnEmailExchangeDelegate OnEmailExchangeDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailExchange"))
	FModioPlugin_OnEmailExchangeDynamicDelegate OnEmailExchangeDynamicDelegate;
	
	/* onModDownload */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnModDownloadDelegate,
		int32
	);
	static FModioPlugin_OnModDownloadDelegate OnModDownloadDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnModDownloadDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModDownload"))
	FModioPlugin_OnModDownloadDynamicDelegate OnModDownloadDynamicDelegate;

	/* onGetAuthenticatedUser */
	DECLARE_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnGetAuthenticatedUserDelegate,
		int32,
		FString
	);
	static FModioPlugin_OnGetAuthenticatedUserDelegate OnGetAuthenticatedUserDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnGetAuthenticatedUserDynamicDelegate,
		int32,
		response_code,
		FString,
		username
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnGetAuthenticatedUser"))
	FModioPlugin_OnGetAuthenticatedUserDynamicDelegate OnGetAuthenticatedUserDynamicDelegate;

	/* onGetAllMods */
	DECLARE_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnGetAllModsDelegate,
		int32,
		TArray<FModioMod>
	);
	static FModioPlugin_OnGetAllModsDelegate OnGetAllModsDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnGetAllModsDynamicDelegate,
		int32,
		response_code,
		TArray<FModioMod>,
		mods
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnGetAllMods"))
	FModioPlugin_OnGetAllModsDynamicDelegate OnGetAllModsDynamicDelegate;
	
	/* onAddMod */
	DECLARE_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnAddModDelegate,
		int32,
		FModioMod
	);
	static FModioPlugin_OnAddModDelegate OnAddModDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
		FModioPlugin_OnAddModDynamicDelegate,
		int32,
		response_code,
		FModioMod,
		mod
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnAddMod"))
	FModioPlugin_OnAddModDynamicDelegate OnAddModDynamicDelegate;
private:
	void OnEmailRequestDelegate_Handler(int32 response_code);
	void OnEmailExchangeDelegate_Handler(int32 response_code);
	void OnModDownloadDelegate_Handler(int32 response_code);
	void OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FString username);
	void OnGetAllModsDelegate_Handler(int32 response_code, TArray<FModioMod> mods);
	void OnAddModDelegate_Handler(int32 response_code, FModioMod mod);
};