// Fill out your copyright notice in the Description page of Project Settings.


#include "Try6GameInstance.h"


FVivoxCoreModule* vModule;
ILoginSession& curLogSec;

void UTry6GameInstance::Init()
{
	Super::PostInitProperties();
	UE_LOG(LogClass,Warning, TEXT("%s"), TEXT("Game Instance Init!!"));

	vModule = static_cast<FVivoxCoreModule*>(&FModuleManager::Get().LoadModuleChecked(TEXT("VivoxCore")));
	UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("VivoxCore Module Loaded!!"));


	IClient& MyVoiceClient(vModule->VoiceClient());
	MyVoiceClient.Initialize();

	AccountId Account = AccountId("jisang2336-te04-dev", "jisang2336-Te04-dev-Admin", "mt1s.vivox.com");
	ILoginSession& MyLoginSession(MyVoiceClient.GetLoginSession(Account));
	curLogSec = MyLoginSession;
	bool IsLoggedIn = false;
	// 로그인이 완료되면 델리게이트가 실행되도록 설정합니다.
	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;
	OnBeginLoginCompleted.BindLambda([this, &IsLoggedIn](VivoxCoreError Error)
		{
			if (VxErrorSuccess == Error)
			{
				IsLoggedIn = true;
				// 이 부울 값은 참조용이며, 사용자가 로그인되었습니다.
			}
		});
	// 사용자에게 Vivox에 로그인하도록 요청합니다.
	MyLoginSession.BeginLogin("https://mt1s.www.vivox.com/api2", MyLoginSession.GetLoginToken("chap633", FTimespan(0,0,90)), OnBeginLoginCompleted);
}

void UTry6GameInstance::Logout()
{
	curLogSec.Logout();
}
