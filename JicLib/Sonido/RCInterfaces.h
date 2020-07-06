#pragma once
#include <Windows.h>
#include <D3D11.h> 
#include <D3DX11.h> 
#include <DirectXMath.h>
#include <dinput.h>
#include <memory>
#include <atlbase.h>

#include "RCMacros.h"


using namespace DirectX;


	template<typename T>
	class ComPtr : public CComPtr<T>
	{
	public:
		ComPtr()
		{ }

		ComPtr(_In_opt_ T* value)
			: CComPtr(value)
		{ }

		T* Get() const
		{
			return *this;
		}

		template<typename Q>
		HRESULT As(_Outptr_ Q** result) const
		{
			return QueryInterface(result);
		}
	};

	__interface DECLDIR IRCInputDevice
	{
		LPDIRECTINPUTDEVICE8 InitializeDevice(HWND hwnd);

		virtual char* getState();	
		virtual void Update(float time);
		virtual LPDIRECTINPUTDEVICE8 getDevice();
	};

	__interface DECLDIR IRCGraphicsDevice
	{
		virtual HRESULT Initialize();

		virtual D3D_DRIVER_TYPE getDriverType();
		virtual D3D_FEATURE_LEVEL getFeatureLevel();

		virtual ID3D11RasterizerState* getRasterizer();
		virtual IDXGISwapChain* getSwapChain();
		virtual ID3D11RenderTargetView* getRenderTerget();
		virtual ID3D11DepthStencilView* getDepthStencilView();
		virtual D3D11_VIEWPORT getViewPort();
		virtual ID3D11Texture2D* getDepthStencil();
		virtual ID3D11Device* getDevice();
		virtual ID3D11DeviceContext* getDeviceContext();

		virtual HWND getWindowHandle();

		virtual void Clear(XMFLOAT4 Color, UINT clearFlag,FLOAT depth, UINT8 stencil);
		virtual void Present(UINT sysncInterval, UINT flags);

		virtual HWND InitializeWindow(void** game, LPCTSTR str_Title,int int_XPos, int int_YPos, int int_Width, int int_Height, WNDPROC WinProc, int colorBrush = COLOR_BTNFACE);
	};

	__interface DECLDIR IRCGame
	{
		virtual IRCGraphicsDevice* getGraphicsDevice();
		virtual void Initialize();

		virtual void setClearColor(XMFLOAT4 color);
	};
	__interface DECLDIR IRCGameComponent
	{
		virtual IRCGame* getGame();
		virtual void setGame(IRCGame* game);
	
		virtual void Initialize();

	};

	__interface DECLDIR IRC3DGameComponent
	{
		virtual XMFLOAT3 getPosition();
		virtual XMFLOAT3 getScale();
		virtual XMVECTOR getOrientation();
		virtual XMMATRIX getWorld();

		virtual void setPosition(XMFLOAT3 newPosition);
		virtual void setScale(XMFLOAT3 newScale);
		virtual void setOrientation(XMVECTOR newOrientation);

		virtual void Translate(XMFLOAT3 distance);
		virtual void Rotate(XMVECTOR axis, float angle);
	};

	__interface DECLDIR IRCCamera
	{
		virtual XMMATRIX getProjection();
		virtual XMMATRIX getView();

		virtual void setWorldUp(XMFLOAT3 up);
		virtual void setWidth(UINT newWidth);
		virtual void setHeight(UINT newHeight);
	};

	__interface DECLDIR IUpdateable
	{
		virtual void Update(float time);

		virtual bool getEnabled();
		virtual void setEnabled(bool value);
	};

	__interface DECLDIR IDrawable
	{
		virtual void Draw(float time);	

		virtual bool getVisible();
		virtual void setVisible(bool value);
	};

	__interface DECLDIR IRCGraphicsResource
	{
		virtual IRCGraphicsDevice* getGraphicsDevice();
	};