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
#ifndef EXYNOS_C2_H263DEC_COMPONENT_H
#define EXYNOS_C2_H263DEC_COMPONENT_H

#include <memory>
#include <vector>

#include "Exynos_C2_DecComponent.h"
#include "Exynos_H263Dec_Filter.h"
#include "Exynos_CSC_Filter.h"

#define LOG_ON
#include "ExynosLog.h"

class ExynosC2H263DecComponent : public ExynosC2DecComponent/*, public std::enable_shared_from_this<ExynosC2H263DecComponent>*/ {
public:
    class H263DecParamIntf;

    ExynosC2H263DecComponent(c2_node_id_t id, const std::shared_ptr<H263DecParamIntf> &intfImpl);

    ~ExynosC2H263DecComponent() {
        mParamIntf.reset();
    }

    /* add function for ExynosC2H263DecComponent */
    bool init(std::weak_ptr<C2Component> wkComponent);

private:
    /* override function on ExynosC2DecComponent */
    void onUpdateC2Config(std::shared_ptr<C2Buffer> c2buffer, std::shared_ptr<ExynosBuffer> buffer,
                          std::vector<std::unique_ptr<C2Param>> &inCconfig,
                          std::vector<std::unique_ptr<C2Param>> &outConfig) override;
    c2_status_t onSetup() override;

    /* disable default constructor */
    ExynosC2H263DecComponent() = delete;
};

#ifdef __cplusplus
extern "C" {
#endif

EXYNOS_EXPORT_REF ::C2ComponentFactory* CreateCodec2Factory();
EXYNOS_EXPORT_REF void DestroyCodec2Factory(::C2ComponentFactory *factory);

#ifdef __cplusplus
}
#endif

#endif // EXYNOS_C2_H263DEC_COMPONENT_H
