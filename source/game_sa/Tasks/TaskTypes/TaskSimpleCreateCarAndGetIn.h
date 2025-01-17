#pragma once

#include "TaskSimple.h"

class CTaskSimpleCreateCarAndGetIn : public CTaskSimple {
public:
    CVector   m_Pos;
    int32     m_nModel;
    CVehicle* m_CreatedVeh;
    CVector   m_VehCreationPos;
    uint32    m_nTimeMs;
    uint32    m_nWaitTime;
    bool      m_bWaitTimeSet;
    bool      m_bResetWaitTime;

public:
    static constexpr auto Type = TASK_SIMPLE_CREATE_CAR_AND_GET_IN;

    CTaskSimpleCreateCarAndGetIn(CVector const& pos, int32 model);
    ~CTaskSimpleCreateCarAndGetIn() override;

    CTask* Clone() override { return new CTaskSimpleCreateCarAndGetIn{ *this }; }
    eTaskType GetTaskType() override { return Type; };
    bool MakeAbortable(CPed* ped, eAbortPriority priority, CEvent const* event) override;
    bool ProcessPed(CPed* ped) override;

private:
    void CleanupCreatedVehicle();

    friend void InjectHooksMain();
    static void InjectHooks();
    CTaskSimpleCreateCarAndGetIn* Constructor(CVector const& pos, int32 model) { this->CTaskSimpleCreateCarAndGetIn::CTaskSimpleCreateCarAndGetIn(pos, model); return this; }
    CTaskSimpleCreateCarAndGetIn* Destructor() { this->CTaskSimpleCreateCarAndGetIn::~CTaskSimpleCreateCarAndGetIn(); return this; }
    CTask * Clone_Reversed() { return CTaskSimpleCreateCarAndGetIn::Clone(); }
    auto GetTaskType_Reversed() { return CTaskSimpleCreateCarAndGetIn::GetTaskType(); }
    bool MakeAbortable_Reversed(CPed * ped, eAbortPriority priority, CEvent const* event) { return CTaskSimpleCreateCarAndGetIn::MakeAbortable(ped, priority, event); }
    bool ProcessPed_Reversed(CPed * ped) { return CTaskSimpleCreateCarAndGetIn::ProcessPed(ped); }
};
VALIDATE_SIZE(CTaskSimpleCreateCarAndGetIn, 0x34);
