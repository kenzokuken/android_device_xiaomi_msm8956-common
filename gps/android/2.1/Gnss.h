/*
 * Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
 * Not a Contribution
 */
/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2_0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2_0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
Changes from Qualcomm Innovation Center are provided under the following license:

Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#ifndef ANDROID_HARDWARE_GNSS_V2_1_GNSS_H
#define ANDROID_HARDWARE_GNSS_V2_1_GNSS_H

#include <AGnss.h>
#include <AGnssRil.h>
#include <GnssConfiguration.h>
#include <GnssMeasurement.h>
#include <GnssBatching.h>
#include <GnssGeofencing.h>
#include <GnssNi.h>
#include <GnssDebug.h>
#include <GnssAntennaInfo.h>

#include <android/hardware/gnss/2.1/IGnss.h>
#include <android/hardware/gnss/measurement_corrections/1.1/IMeasurementCorrections.h>
#include <MeasurementCorrections.h>
#include <GnssVisibilityControl.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

#include "GnssAPIClient.h"

namespace android {
namespace hardware {
namespace gnss {
namespace V2_1 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
using ::android::hardware::gnss::V1_0::GnssLocation;
using IMeasurementCorrectionsV1_0 =
        ::android::hardware::gnss::measurement_corrections::V1_0::IMeasurementCorrections;
using IMeasurementCorrectionsV1_1 =
        ::android::hardware::gnss::measurement_corrections::V1_1::IMeasurementCorrections;
using ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl;

struct Gnss : public IGnss {
    static Gnss* getInstance();

    /*
     * Methods from ::android::hardware::gnss::V1_0::IGnss follow.
     * These declarations were generated from Gnss.hal.
     */
    Return<bool> setCallback(const sp<V1_0::IGnssCallback>& callback)  override;
    Return<bool> start()  override;
    Return<bool> stop()  override;
    Return<void> cleanup()  override;
    Return<bool> injectLocation(double latitudeDegrees,
                                double longitudeDegrees,
                                float accuracyMeters)  override;
    Return<bool> injectTime(int64_t timeMs,
                            int64_t timeReferenceMs,
                            int32_t uncertaintyMs) override;
    Return<void> deleteAidingData(V1_0::IGnss::GnssAidingData aidingDataFlags)  override;
    Return<bool> setPositionMode(V1_0::IGnss::GnssPositionMode mode,
                                 V1_0::IGnss::GnssPositionRecurrence recurrence,
                                 uint32_t minIntervalMs,
                                 uint32_t preferredAccuracyMeters,
                                 uint32_t preferredTimeMs)  override;
    Return<sp<V1_0::IAGnss>> getExtensionAGnss() override;
    Return<sp<V1_0::IGnssNi>> getExtensionGnssNi() override;
    Return<sp<V1_0::IGnssMeasurement>> getExtensionGnssMeasurement() override;
    Return<sp<V1_0::IGnssConfiguration>> getExtensionGnssConfiguration() override;
    Return<sp<V1_0::IGnssGeofencing>> getExtensionGnssGeofencing() override;
    Return<sp<V1_0::IGnssBatching>> getExtensionGnssBatching() override;

    Return<sp<V1_0::IAGnssRil>> getExtensionAGnssRil() override;

    inline Return<sp<V1_0::IGnssNavigationMessage>> getExtensionGnssNavigationMessage() override {
        return nullptr;
    }

    inline Return<sp<V1_0::IGnssXtra>> getExtensionXtra() override {
        return nullptr;
    }

    Return<sp<V1_0::IGnssDebug>> getExtensionGnssDebug() override;

    // Methods from ::android::hardware::gnss::V1_1::IGnss follow.
    Return<bool> setCallback_1_1(const sp<V1_1::IGnssCallback>& callback) override;
    Return<bool> setPositionMode_1_1(V1_0::IGnss::GnssPositionMode mode,
            V1_0::IGnss::GnssPositionRecurrence recurrence,
            uint32_t minIntervalMs, uint32_t preferredAccuracyMeters,
            uint32_t preferredTimeMs, bool lowPowerMode) override;
    Return<sp<V1_1::IGnssMeasurement>> getExtensionGnssMeasurement_1_1() override;
    Return<sp<V1_1::IGnssConfiguration>> getExtensionGnssConfiguration_1_1() override;
    Return<bool> injectBestLocation(const GnssLocation& location) override;

    // Methods from ::android::hardware::gnss::V2_0::IGnss follow.
    Return<bool> setCallback_2_0(const sp<V2_0::IGnssCallback>& callback) override;
    Return<sp<V2_0::IAGnss>> getExtensionAGnss_2_0() override;
    Return<sp<V2_0::IAGnssRil>> getExtensionAGnssRil_2_0() override;

    Return<sp<V2_0::IGnssConfiguration>> getExtensionGnssConfiguration_2_0() override;
    Return<sp<IMeasurementCorrectionsV1_0>> getExtensionMeasurementCorrections() override;
    Return<sp<IMeasurementCorrectionsV1_1>> getExtensionMeasurementCorrections_1_1() override;
    Return<sp<V2_0::IGnssMeasurement>> getExtensionGnssMeasurement_2_0() override;

    Return<bool> injectBestLocation_2_0(
            const ::android::hardware::gnss::V2_0::GnssLocation& location) override;

    Return<sp<V2_0::IGnssBatching>> getExtensionGnssBatching_2_0() override;
    Return<sp<V2_0::IGnssDebug>> getExtensionGnssDebug_2_0() override;
    Return<sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl>>
            getExtensionVisibilityControl() override;

    // Methods from ::android::hardware::gnss::V2_1::IGnss follow.
    Return<bool> setCallback_2_1(const sp<V2_1::IGnssCallback>& callback) override;
    Return<sp<V2_1::IGnssMeasurement>> getExtensionGnssMeasurement_2_1() override;
    Return<sp<V2_1::IGnssConfiguration>> getExtensionGnssConfiguration_2_1() override;
    Return<sp<V2_1::IGnssAntennaInfo>> getExtensionGnssAntennaInfo() override;

    // These methods are not part of the IGnss base class.
    GnssAPIClient* getApi();
    Return<bool> setGnssNiCb(const sp<IGnssNiCallback>& niCb);
    Return<bool> updateConfiguration(GnssConfig& gnssConfig);
    ILocationControlAPI* getLocationControlApi();

    // Callback for ODCPI request
    void odcpiRequestCb(const OdcpiRequestInfo& request);

    // ILocationControlAPI callbacks
    void onCtrlResponseCb(LocationError error, uint32_t id) {}
    void onCtrlCollectiveResponseCb(size_t count, LocationError* errors, uint32_t* ids) {}

 private:
     Gnss();
    ~Gnss();

    struct GnssDeathRecipient : hidl_death_recipient {
        GnssDeathRecipient(sp<Gnss> gnss) : mGnss(gnss) {
        }
        ~GnssDeathRecipient() = default;
        virtual void serviceDied(uint64_t cookie, const wp<IBase>& who) override;
        sp<Gnss> mGnss;
    };

 private:
    sp<GnssDeathRecipient> mGnssDeathRecipient = nullptr;

    sp<V1_0::IGnssNi> mGnssNi = nullptr;
    sp<V1_0::IGnssGeofencing> mGnssGeofencingIface = nullptr;
    sp<V1_0::IAGnss> mAGnssIface = nullptr;
    sp<V1_0::IGnssCallback> mGnssCbIface = nullptr;
    sp<V1_0::IGnssNiCallback> mGnssNiCbIface = nullptr;
    sp<V1_1::IGnssCallback> mGnssCbIface_1_1 = nullptr;
    sp<V2_0::IAGnss> mAGnssIface_2_0 = nullptr;
    sp<V2_0::IAGnssRil> mGnssRil = nullptr;
    sp<V2_0::IGnssBatching> mGnssBatching = nullptr;
    sp<V2_0::IGnssDebug> mGnssDebug = nullptr;
    sp<V2_0::IGnssCallback> mGnssCbIface_2_0 = nullptr;
    sp<V2_1::IGnssCallback> mGnssCbIface_2_1 = nullptr;
    sp<V2_1::IGnssMeasurement> mGnssMeasurement = nullptr;
    sp<V2_1::IGnssConfiguration> mGnssConfig = nullptr;
    sp<V2_1::IGnssAntennaInfo> mGnssAntennaInfo = nullptr;
    sp<IMeasurementCorrectionsV1_1> mGnssMeasCorr = nullptr;
    sp<IGnssVisibilityControl> mVisibCtrl = nullptr;

    GnssAPIClient* mApi = nullptr;
    GnssConfig mPendingConfig;
    ILocationControlAPI* mLocationControlApi = nullptr;
    static Gnss* mGnssInstance;
};

extern "C" V1_0::IGnss* HIDL_FETCH_IGnss(const char* name);

}  // namespace implementation
}  // namespace V2_1
}  // namespace gnss
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_GNSS_V2_1_GNSS_H
