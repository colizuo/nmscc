#pragma once

#include <nms/core.h>

namespace nms::test
{

struct AssertFailed: public IException
{};


inline void assert_eq(bool bFlag) {
    if (!bFlag) {
        NMS_THROW(AssertFailed{});
    }
}

template<class A, class B>
void assert_eq(const A& a, const B& b) {
    if (!(a == b)) {
        NMS_THROW(AssertFailed{});
    }
}

template<class A, class B>
void assert_neq(const A& a, const B& b) {
    if (a == b) {
        NMS_THROW(AssertFailed{});
    }
}

}
