#pragma once

#include <unordered_map>
#include <aidl/android/hardware/soundtrigger3/BnSoundTriggerHw.h>

namespace aidl::android::hardware::soundtrigger3 {

using namespace ::aidl::android::media::soundtrigger;
using ::ndk::ScopedAStatus;

class SoundTriggerHw : public BnSoundTriggerHw {
public:
    SoundTriggerHw();
    ~SoundTriggerHw();

    ScopedAStatus getProperties(Properties *aidlProperties) override;

    ScopedAStatus registerGlobalCallback(
        const std::shared_ptr<ISoundTriggerHwGlobalCallback> &callback) override;

    ScopedAStatus loadSoundModel(const SoundModel &model,
                                 const std::shared_ptr<ISoundTriggerHwCallback> &callback,
                                 int32_t *handle) override;

    ScopedAStatus loadPhraseSoundModel(const PhraseSoundModel &model,
                                       const std::shared_ptr<ISoundTriggerHwCallback> &callback,
                                       int32_t *handle) override;

    ScopedAStatus unloadSoundModel(int32_t handle) override;

    ScopedAStatus startRecognition(int32_t modelHandle, int32_t deviceHandle,
                                   int32_t ioHandle, const RecognitionConfig &config) override;

    ScopedAStatus stopRecognition(int32_t handle) override;

    ScopedAStatus forceRecognitionEvent(int32_t handle) override;

    ScopedAStatus queryParameter(int32_t handle, ModelParameter modelParams,
                                 std::optional<ModelParameterRange> *aidlRange) override;

    ScopedAStatus getParameter(int32_t handle, ModelParameter modelParams,
                               int32_t *aidlParameters) override;

    ScopedAStatus setParameter(int32_t handle, ModelParameter modelParams,
                               int32_t value) override;
};

} // namespace aidl::android::hardware::soundtrigger3
