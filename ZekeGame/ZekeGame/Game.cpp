#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"


Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_model);
}

bool Game::Start() {
	m_model = NewGO<SkinModelRender>(0, "model");
	m_model->Init(L"Assets/modelData/Test.cmo");
	m_model->SetPosition(CVector3::Zero());

	camera = new GameCamera;

	return true;
}


void Game::Update() {
	static CVector3 pos = CVector3::Zero();
	if (g_pad[0].IsPress(enButtonDown)) {
		pos.x += 50.0f;
	}

	if (g_pad[0].IsTrigger(enButtonA)) {
		CEffect* efk = NewGO<CEffect>(0, "efk");
		efk->SetPosition({ 0.f,0.f,1000.f });
		CQuaternion r = CQuaternion::Identity();
		r.SetRotationDeg(CVector3::AxisY(), 0.f);
		efk->SetRotation(r);
		efk->Play(L"Assets/effect/Laser01.efk");
	}

	m_model->SetPosition(pos);
	camera->SetTarget(CVector3::Zero());
	camera->SetPosition({ 0.0f, 350.0f, 1000.0f });
	camera->Update();
}

void Game::Render() {
}

void Game::PostRender() {
}