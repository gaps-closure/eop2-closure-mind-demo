// printOrionPublic.h was generated by ProtoGen version 2.12.c

#ifndef _PRINTORIONPUBLIC_H
#define _PRINTORIONPUBLIC_H

#include "OrionPublicPacket.h"
#include <QString>

//! Generate a string that describes the contents of a Date_t structure
QString textPrintDate_t(QString prename, const Date_t* user);

//! Generate a string that describes the contents of a OrionCmd_t structure
QString textPrintOrionCmd_t(QString prename, const OrionCmd_t* user);

//! Generate a string that describes the contents of a OrionStartupCmd_t structure
QString textPrintOrionStartupCmd_t(QString prename, const OrionStartupCmd_t* user);

//! Generate a string that describes the contents of a OrionStartupCmd packet
QString textPrintOrionStartupCmdPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionPositions_t structure
QString textPrintOrionPositions_t(QString prename, const OrionPositions_t* user);

//! Generate a string that describes the contents of a OrionPositions packet
QString textPrintOrionPositionsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionFlirSettings_t structure
QString textPrintOrionFlirSettings_t(QString prename, const OrionFlirSettings_t* user);

//! Generate a string that describes the contents of a OrionFlirSettings packet
QString textPrintOrionFlirSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionAptinaSettings_t structure
QString textPrintOrionAptinaSettings_t(QString prename, const OrionAptinaSettings_t* user);

//! Generate a string that describes the contents of a OrionAptinaSettings packet
QString textPrintOrionAptinaSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionZafiroSettings_t structure
QString textPrintOrionZafiroSettings_t(QString prename, const OrionZafiroSettings_t* user);

//! Generate a string that describes the contents of a OrionZafiroSettings packet
QString textPrintOrionZafiroSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionHitachiSettings_t structure
QString textPrintOrionHitachiSettings_t(QString prename, const OrionHitachiSettings_t* user);

//! Generate a string that describes the contents of a OrionHitachiSettings packet
QString textPrintOrionHitachiSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionSonySettings_t structure
QString textPrintOrionSonySettings_t(QString prename, const OrionSonySettings_t* user);

//! Generate a string that describes the contents of a OrionSonySettings packet
QString textPrintOrionSonySettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionKtncSettings_t structure
QString textPrintOrionKtncSettings_t(QString prename, const OrionKtncSettings_t* user);

//! Generate a string that describes the contents of a OrionKtncSettings packet
QString textPrintOrionKtncSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionUartConfig_t structure
QString textPrintOrionUartConfig_t(QString prename, const OrionUartConfig_t* user);

//! Generate a string that describes the contents of a OrionUartConfig packet
QString textPrintOrionUartConfigPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionLimitsData_t structure
QString textPrintOrionLimitsData_t(QString prename, const OrionLimitsData_t* user);

//! Generate a string that describes the contents of a OrionLimitsData packet
QString textPrintOrionLimitsDataPacket(const void* pkt);

//! Generate a string that describes the contents of a InsOptions_t structure
QString textPrintInsOptions_t(QString prename, const InsOptions_t* user);

//! Generate a string that describes the contents of a InsOptions packet
QString textPrintInsOptionsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionNetworkByteSettings_t structure
QString textPrintOrionNetworkByteSettings_t(QString prename, const OrionNetworkByteSettings_t* user);

//! Generate a string that describes the contents of a OrionNetworkByteSettings packet
QString textPrintOrionNetworkByteSettingsPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionNetworkByteVideo_t structure
QString textPrintOrionNetworkByteVideo_t(QString prename, const OrionNetworkByteVideo_t* user);

//! Generate a string that describes the contents of a OrionNetworkByteVideo packet
QString textPrintOrionNetworkByteVideoPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionCameras_t structure
QString textPrintOrionCameras_t(QString prename, const OrionCameras_t* user);

//! Generate a string that describes the contents of a OrionCameras packet
QString textPrintOrionCamerasPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionClevisVersion_t structure
QString textPrintOrionClevisVersion_t(QString prename, const OrionClevisVersion_t* user);

//! Generate a string that describes the contents of a OrionClevisVersion packet
QString textPrintOrionClevisVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionCrownVersion_t structure
QString textPrintOrionCrownVersion_t(QString prename, const OrionCrownVersion_t* user);

//! Generate a string that describes the contents of a OrionCrownVersion packet
QString textPrintOrionCrownVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionPayloadVersion_t structure
QString textPrintOrionPayloadVersion_t(QString prename, const OrionPayloadVersion_t* user);

//! Generate a string that describes the contents of a OrionPayloadVersion packet
QString textPrintOrionPayloadVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionTrackerVersion_t structure
QString textPrintOrionTrackerVersion_t(QString prename, const OrionTrackerVersion_t* user);

//! Generate a string that describes the contents of a OrionTrackerVersion packet
QString textPrintOrionTrackerVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionRetractVersion_t structure
QString textPrintOrionRetractVersion_t(QString prename, const OrionRetractVersion_t* user);

//! Generate a string that describes the contents of a OrionRetractVersion packet
QString textPrintOrionRetractVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionLensCtlVersion_t structure
QString textPrintOrionLensCtlVersion_t(QString prename, const OrionLensCtlVersion_t* user);

//! Generate a string that describes the contents of a OrionLensCtlVersion packet
QString textPrintOrionLensCtlVersionPacket(const void* pkt);

//! Generate a string that describes the contents of a OrionBoard_t structure
QString textPrintOrionBoard_t(QString prename, const OrionBoard_t* user);

//! Generate a string that describes the contents of a OrionBoard packet
QString textPrintOrionBoardPacket(const void* pkt);

#endif
