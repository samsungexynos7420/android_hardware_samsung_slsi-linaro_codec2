/*
 *
 * Copyright 2019 Samsung Electronics S.LSI Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef EXYNOS_VP8DEC_FILTER_H
#define EXYNOS_VP8DEC_FILTER_H

#include "Exynos_CodecDecBase_Filter.h"

#define LOG_ON
#include "ExynosLog.h"

class ExynosVp8DecFilter : public ExynosCodecDecBaseFilter /*, public std::enable_shared_from_this<ExynosVp8DecFilter>*/ {
public:
    ExynosVp8DecFilter(uint32_t id, bool isSecure = false) : ExynosCodecDecBaseFilter(id, isSecure) {
        mObjName = "ExynosVp8DecFilter";
        mbLogOff = false;
        mThreadPool->setObjName(mObjName);
        mCodecType = ExynosVideoCodec::Type::VP8DEC;
    }

    ~ExynosVp8DecFilter() = default;

private:
    /* override function on ExynosCodecBaseFilter */

    /* add function for ExynosVp8DecFilter */
};

#endif // EXYNOS_VP8DEC_FILTER_H
