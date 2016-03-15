#pragma once

#include "IState.h"

// MAT: I decided I want to use references
// I just haven't got around to changing to the code :)

class CStateMachine {
public:
	CStateMachine() :
		m_pCurrentState(nullptr),
		m_bInTransition(false) {
	}

	virtual ~CStateMachine() {

	}

	void ChangeState(IState* value) {
		Transition(value);
	}

	IState* GetCurrentState() {
		return m_pCurrentState;
	}

	const IState* GetCurrentState() const {
		return m_pCurrentState;
	}

private:
	void Transition(IState* pState) {
		if (pState == nullptr) {
			return;
		}

		if (m_pCurrentState == pState || m_bInTransition) {
			return;
		}

		m_bInTransition = true;

		if (m_pCurrentState != nullptr) {
			m_pCurrentState->Exit();
		}

		m_pCurrentState = pState;
		m_pCurrentState->Enter();

		m_bInTransition = false;
	}

	IState* m_pCurrentState;
	bool m_bInTransition;
};
