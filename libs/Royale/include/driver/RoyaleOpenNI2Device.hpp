/****************************************************************************\
* Copyright (C) 2017 Infineon Technologies
*
* THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
* KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
\****************************************************************************/

#pragma once

#include <royale.hpp>
#include <OpenNI.h>
#include <Driver/OniDriverAPI.h>

#include "RoyaleOpenNI2DepthStream.hpp"

#include <map>

namespace royale
{
    namespace openni2
    {
        class RoyaleOpenNI2Device : public oni::driver::DeviceBase
        {
        public:
            //royale device properties
            enum{
                ONI_DEVICE_PROPERTY_ROAYLE_USECASE = 200, //royale::String
            };
            
            enum RoyaleUseCase{
                MODE_9_5FPS_2000,
                MODE_9_10FPS_1000,
                MODE_9_15FPS_700,
                MODE_9_25FPS_450,
                MODE_5_35FPS_600,
                MODE_5_45FPS_500,
                MODE_MIXED_30_5,
                MODE_MIXED_50_5
            };
            
            static royale::String getUseCaseString(RoyaleUseCase uc){
                return indexToUseCaseString((int)uc);
            }
            
            static royale::String indexToUseCaseString(int idx){
                switch (idx) {
                    case 0:
                        return "MODE_9_5FPS_2000";
                        break;
                    case 1:
                        return "MODE_9_10FPS_1000";
                        break;
                    case 2:
                        return "MODE_9_15FPS_700";
                        break;
                    case 3:
                        return "MODE_9_25FPS_450";
                        break;
                    case 4:
                        return "MODE_5_35FPS_600";
                        break;
                    case 5:
                        return "MODE_5_45FPS_500";
                        break;
                    case 6:
                        return "MODE_MIXED_30_5";
                        break;
                    case 7:
                    default:
                        return "MODE_MIXED_50_5";
                        break;
                }
            }
            
            RoyaleOpenNI2Device (std::unique_ptr<royale::ICameraDevice> camera, oni::driver::DriverServices &driverServices);
            OniStatus getSensorInfoList (OniSensorInfo **pSensors, int *numSensors) override;
            oni::driver::StreamBase *createStream (OniSensorType sensorType) override;
            void destroyStream (oni::driver::StreamBase *pStream) override;
            OniStatus  getProperty (int propertyId, void *data, int *pDataSize) override;
            OniStatus setProperty (int propertyId, const void *data, int dataSize) override;

            // for use by the stream
            royale::ICameraDevice &getCamera();

            // Called by the stream
            OniStatus GetVideoMode (OniVideoMode *pVideoMode);
            OniStatus SetVideoMode (OniVideoMode *pVideoMode);

            // noncopyable
            RoyaleOpenNI2Device (const RoyaleOpenNI2Device &) = delete;
            void operator= (const RoyaleOpenNI2Device &) = delete;
        private:
            std::unique_ptr<royale::ICameraDevice> m_camera;
            int m_numSensors;
            OniSensorInfo m_sensors[1];
            oni::driver::DriverServices &m_driverServices;
            RoyaleOpenNI2DepthStream m_stream;

            royale::Vector<royale::String> useCases;
            std::map<std::string, OniVideoMode> m_videoModes; // usecase to video mode mapping
        };

    } // namespace openni2
} // namespace royale
