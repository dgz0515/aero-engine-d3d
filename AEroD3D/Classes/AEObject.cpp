#include <d3d11_1.h>
#include "AEAnimation.h"
#include "AEObject.h"

AEObject::AEObject(AERO_OBJECT_DESC desc) {
    oid = desc.oid;
    name = desc.name;
    type = desc.type;
    for (INT i = 0; i < MAX_ANIM_COUNT; i++) {
        animTable[i] = nullptr;
    }
}

VOID AEObject::addAnimationAt(INT slot, AEAnimation* _anim) {
    if (slot < 0 || slot >= MAX_ANIM_COUNT) {
        // Error
        return;
    }
    animTable[slot] = _anim;
}