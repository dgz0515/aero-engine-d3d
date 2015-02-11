#include "AEroEngine.h"
#include "WLFAnimation.h"

WLFAnimation::WLFAnimation(AERO_ANIMATION_DESC desc) : AEAnimation(desc) {
    for (INT i = 0; i < MAX_FRAME_COUNT; i++) {
        xShiftTable[i] = 0;
        attackJudgeTable[i] = nullptr;
        bodyJudgeTable[i] = nullptr;
        spriteCreateTable[i] = nullptr;
        cameraShakeTable[i] = nullptr;
        giveSpeedTable[i] = { 0.0f, 0.0f };
        cancelTable[i] = nullptr;
    }
    isTurn = FALSE;
    hitGroundAction = -1;
}

WLFAnimation::~WLFAnimation() {
    for (INT i = 0; i < MAX_FRAME_COUNT; i++) {
        if (attackJudgeTable[i]) {
            delete attackJudgeTable[i];
            attackJudgeTable[i] = nullptr;
        }
        if (bodyJudgeTable[i]) {
            delete bodyJudgeTable[i];
            bodyJudgeTable[i] = nullptr;
        }
        if (spriteCreateTable[i]) {
            delete spriteCreateTable[i];
            spriteCreateTable[i] = nullptr;
        }
        if (cameraShakeTable[i]) {
            delete cameraShakeTable[i];
            cameraShakeTable[i] = nullptr;
        }
    }
}

VOID WLFAnimation::addXShiftForFrame(INT index, INT xShift) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    xShiftTable[index] = xShift;
}

VOID WLFAnimation::addAttackJudgeForFrame(INT index, WLFAttackJudgeArea* attackJudgeArea) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    attackJudgeTable[index] = attackJudgeArea;
}

VOID WLFAnimation::addBodyJudgeForFrame(INT index, WLFBodyJudgeArea* bodyJudgeArea) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    bodyJudgeTable[index] = bodyJudgeArea;
}

VOID WLFAnimation::addSpriteCreateForFrame(INT index, WLFSpriteCreatePoint* spriteCountPoint) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    spriteCreateTable[index] = spriteCountPoint;
}

VOID WLFAnimation::addCameraShakeForFrame(INT index, WLFCameraShakeOptions* cameraShakeOptions) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    cameraShakeTable[index] = cameraShakeOptions;
}

VOID WLFAnimation::addCancelForFrame(INT index, WLFCancelOptions* cancelOptions) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    cancelTable[index] = cancelOptions;
}

VOID WLFAnimation::giveSpeedForFrame(INT index, XMFLOAT2 vec) {
    if (index < 0 || index >= frameCount) {
        // Error
        return;
    }
    giveSpeedTable[index] = vec;
}