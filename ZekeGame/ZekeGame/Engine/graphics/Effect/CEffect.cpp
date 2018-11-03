#include "stdafx.h"
#include "CEffect.h"

CEffect::CEffect() {

}

CEffect::~CEffect(){
	ES_SAFE_RELEASE(m_effect);
}


bool CEffect::Start() {
	return true;
}

void CEffect::Update() {
	g_graphicsEngine->GetEffectEngine().GetEffekseerManager().SetScale(m_handle, m_scale.x, m_scale.y, m_scale.z);
	if (!IsPlay()) {
		DeleteGO(this);
	}
}

void CEffect::Render() {
}


void CEffect::Play(const wchar_t* filepath) {
	m_effect = Effekseer::Effect::Create(&(g_graphicsEngine->GetEffectEngine().GetEffekseerManager()), (const EFK_CHAR*)filepath);
	m_handle = g_graphicsEngine->GetEffectEngine().GetEffekseerManager().Play(m_effect, m_position.x, m_position.y, m_position.z);
}

void CEffect::Stop() {
	g_graphicsEngine->GetEffectEngine().GetEffekseerManager().StopEffect(m_handle);
}