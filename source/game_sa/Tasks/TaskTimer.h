/*
    Plugin-SDK file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "Timer.h"

class CTaskTimer {
public:
    uint32 m_nStartTime;
    int32  m_nInterval;
    bool   m_bStarted;
    bool   m_bStopped;

public:
    static void InjectHooks();

    // 0x420E10
    inline CTaskTimer(uint32 start, uint32 interval) {
        m_nStartTime = start;
        m_nInterval = interval;
        m_bStarted = true;
    }

    inline CTaskTimer() {
        m_nStartTime = 0;
        m_nInterval = 0;
        m_bStarted = false;
        m_bStopped = false;
    }

    inline bool Start(int32 interval) {
        if (interval >= 0) {
            m_nStartTime = CTimer::GetTimeInMS();
            m_nInterval = interval;
            m_bStarted = true;
            return true;
        }
        return false;
    }

    void StartIfNotAlready(uint32 interval) { // NOTSA
        if (!m_bStarted) {
            m_nStartTime = CTimer::GetTimeInMS();
            m_nInterval = (int32)interval;
            m_bStarted = true;
        }
    }

    inline bool Stop() {
        if (m_bStarted) {
            m_bStopped = true;
            m_nInterval -= CTimer::GetTimeInMS() - m_nStartTime;
            return true;
        }
        return false;
    }

    inline bool Reset() {
        if (m_bStarted) {
            if (m_bStopped) {
                m_nStartTime = CTimer::GetTimeInMS();
                m_bStopped = false;
            }
            return true;
        }
        return false;
    }

    bool IsOutOfTime();
};

VALIDATE_SIZE(CTaskTimer, 0xC);
