// ***********************************************************************
// Filename         : Timer.h
// Author           : LIZHENG
// Created          : 2014-10-126
// Description      : 还有问题，在Windows下select调用不正常
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-10-26
//
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_TIMER_H
#define ZL_TIMER_H
#include "Define.h"
#include "base/Timestamp.h"
#include "base/NonCopy.h"
NAMESPACE_ZL_NET_START

using zl::base::Timestamp;
class TimerQueue;

class Timer
{
    friend class TimerQueue;
public:
    typedef std::function<void()> TimerCallBack;

    typedef int32_t  TimerID;
public:
    explicit Timer(TimerQueue *tqueue);
    Timer(TimerQueue *tqueue, const Timestamp& when);
    Timer(TimerQueue *tqueue, size_t millsec);
    ~Timer();

    void wait();
    void async_wait(TimerCallBack callback);
    void trigger();

    Timestamp expires_at(const Timestamp& expiry_time);
    Timestamp expires_at() const;
    Timestamp expires_from_now(size_t millsec_time);
    size_t    expires_from_now() const;

    size_t cancel();
private:
    TimerQueue    *timerQueue_;
    Timestamp     when_;
    TimerCallBack callback_; 
};

inline bool operator<(const Timer& lhs, const Timer& rhs)
{
    return lhs.expires_at() < rhs.expires_at();
}

NAMESPACE_ZL_NET_END
#endif  /* ZL_TIMER_H */