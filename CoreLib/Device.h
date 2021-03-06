#pragma once
#include "Window.h"
class Device : public Window
{
public:
	ID3D11Device* m_pd3dDevice;	// 디바이스 객체
	// 디바이스 컨텍스트 = 화면 출력에 필요한 모든 정보를 가진 구조체, GDI에 의해 관리
	ID3D11DeviceContext* m_pImmediateContext;// 다비이스 컨텍스트 객체
	IDXGISwapChain* m_pSwapChain;	// 스왑체인 객체
	ID3D11RenderTargetView* m_pRenderTargetView;// 메인 랜더타켓 뷰

	D3D_FEATURE_LEVEL       m_FeatureLevel;	// Direct3D 특성레벨 속성값	
	DXGI_SWAP_CHAIN_DESC	m_SwapChainDesc;	// 스왑체인 속성값
	D3D11_VIEWPORT			m_ViewPort;	// 뷰 포트 속성값
public:
	HRESULT InitDevice();
	virtual bool CreateDevice();
	virtual bool CreateRenderTargetView();
	virtual bool SetViewport();

	virtual bool CleanupDevice();
public:
	Device()
	{
		m_pd3dDevice = nullptr;
		m_pImmediateContext = nullptr;
		m_pSwapChain = nullptr;
		m_pRenderTargetView = nullptr;
	}
	virtual ~Device() {}
};
