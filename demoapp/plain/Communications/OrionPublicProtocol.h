// OrionPublicProtocol.h was generated by ProtoGen version 2.12.c

#ifndef _ORIONPUBLICPROTOCOL_H
#define _ORIONPUBLICPROTOCOL_H

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \file
 * \mainpage OrionPublic protocol stack
 *
 * The *OrionPublic* protocol is the packet description for the public interface
 * of the Orion gimbal from [Trillium Engineering](http://w3.trilliumeng.com/).
 * The Orion gimbal communicates to users with packets of data transported over
 * asyncrhonous serial, or transported by TCP/IP over ethernet.
 *
 * The protocol version is 1.3.0.a
 */

#include <stdint.h>

//! \return the protocol version string
#define getOrionPublicVersion() "1.3.0.a"
/*!
 * Identifiers of Orion public packets. The purpose of an Orion packet is
 * determined by its ID field to this list.
 */
typedef enum
{
    ORION_PKT_INITIALIZE = 0x00,     
    ORION_PKT_CMD,                   //!< Basic commands for control of gimbal pan and tilt.
    ORION_PKT_UART_CONFIG,           //!< Baud rate and protocol configuration for crown serial ports
    ORION_PKT_LASER_CMD,             //!< Command to fire the laser
    ORION_PKT_RESET,                 //!< Send this packet to cause the gimbal to reset
    ORION_PKT_PRIVATE_05,            //!< Reserved packet identifier
    ORION_PKT_LASER_STATES,          //!< Laser state information
    ORION_PKT_STARTUP_CMD,           //!< Command to run on startup at the end of motor initialization
    ORION_PKT_PRIVATE_08,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_09,            //!< Reserved packet identifier
    ORION_PKT_POSITIONS,             //!< Stored gimbal positions
    ORION_PKT_PRIVATE_1F = 0x1F,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_20,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_21,            //!< Reserved packet identifier
    ORION_PKT_LIMITS,                //!< Pan and tilt limits for current, acceleration, velocity, and position
    ORION_PKT_PRIVATE_23,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_24,            //!< Reserved packet identifier
    ORION_PKT_CLEVIS_VERSION,        //!< Software version for the clevis board
    ORION_PKT_RESET_SOURCE,          //!< Reset information for a processor
    ORION_PKT_BOARD,                 //!< Information for a specific board
    ORION_PKT_CROWN_VERSION,         //!< Software version for the crown board
    ORION_PKT_PAYLOAD_VERSION,       //!< Software version for the payload board
    ORION_PKT_PRIVATE_2A,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_2B,            //!< Reserved packet identifier
    ORION_PKT_TRACKER_VERSION,       //!< Software version for the tracker board (if present)
    ORION_PKT_PRIVATE_2D,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_30,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_33,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_40 = 0x40,     //!< Reserved packet identifier
    ORION_PKT_DIAGNOSTICS,           //!< Electrical diagnostic data
    ORION_PKT_FAULTS,                
    ORION_PKT_PERFORMANCE,           //!< Measurements related to stabilization performance
    ORION_PKT_SOFTWARE_DIAGNOSTICS,  //!< Diagnostic information related to software performance for a processor
    ORION_PKT_VIBRATION,             //!< Platform vibration statistics
    ORION_PKT_NETWORK_DIAGNOSTICS,   //!< Network diagnostics
    ORION_PKT_PRIVATE_47,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_48,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_49,            //!< Reserved packet identifier
    ORION_PKT_CAMERA_SWITCH = 0x60,  //!< Command the gimbal to swtich cameras
    ORION_PKT_CAMERA_STATE,          //!< Command a camera in the gimbal
    ORION_PKT_NETWORK_VIDEO,         //!< Command the IP settings for video delivery
    ORION_PKT_CAMERAS,               //!< Camera settings information
    ORION_PKT_PRIVATE_64,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_65,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_66,            //!< Reserved packet identifier
    ORION_PKT_FLIR_SETTINGS,         //!< FLIR-specific camera settings
    ORION_PKT_APTINA_SETTINGS,       //!< Aptina-specific camera settings
    ORION_PKT_ZAFIRO_SETTINGS,       //!< DRS Zafiro-specific camera settings
    ORION_PKT_HITACHI_SETTINGS,      //!< Hitachi-specific camera settings
    ORION_PKT_BAE_SETTINGS,          //!< BAE-specific camera settings
    ORION_PKT_SONY_SETTINGS,         //!< Sony-specific camera settings
    ORION_PKT_KTNC_SETTINGS,         //!< KTnC-specific camera settings
    ORION_PKT_PRIVATE_70 = 0x70,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_71,            //!< Reserved packet identifier
    ORION_PKT_AUTOPILOT_DATA = 0x80, //!< Autopilot state data, if available
    ORION_PKT_PRIVATE_90 = 0x90,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_91 = 0x91,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_92 = 0x92,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_93 = 0x93,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_94 = 0x94,     //!< Reserved packet identifier
    ORION_PKT_RETRACT_CMD = 0xA0,    //!< Retract or deploy command for a gimbal retraction mechanism
    ORION_PKT_RETRACT_STATUS,        //!< Current gimbal retraction mechanism status
    ORION_PKT_SNPY_A8 = 0xA8,        //!< Reserved Snoopy Board packet identifier
    ORION_PKT_SNPY_A9,               //!< Reserved Snoopy Board packet identifier
    ORION_PKT_SNPY_AA,               //!< Reserved Snoopy Board packet identifier
    ORION_PKT_SNPY_AB,               //!< Reserved Snoopy Board packet identifier
    ORION_PKT_SNPY_AC,               //!< Reserved Snoopy Board packet identifier
    ORION_PKT_SNPY_AD,               //!< Reserved Snoopy Board packet identifier
    ORION_PKT_PRIVATE_B0 = 0xB0,     //!< Reserved packet identifier
    ORION_PKT_DEBUG_STRING,          //!< A human readable text string which is typically used for debugging purposes
    ORION_PKT_USER_DATA,             //!< Packet for sending user data to a serial port in the gimbal
    ORION_PKT_KLV_USER_DATA,         //!< KLV user-specified field settings
    ORION_PKT_PRIVATE_B4,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_C0 = 0xC0,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_C1,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_C2,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_C3,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_CE = 0xCE,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_CF,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_D0,            //!< Reserved packet identifier
    ORION_PKT_GPS_DATA,              //!< Raw GPS data input or output
    ORION_PKT_EXT_HEADING_DATA,      //!< Externally supplied heading information
    ORION_PKT_INS_QUALITY,           //!< Quality of the inertial navigation system
    ORION_PKT_GEOLOCATE_TELEMETRY,   //!< Information needed to locate the gimbal and its imagery
    ORION_PKT_GEOPOINT_CMD,          //!< Command the gimbal to go to Geopoint mode
    ORION_PKT_RANGE_DATA,            //!< Range information from the gimbal to its target
    ORION_PKT_PATH,                  //!< Command the gimbal to path track mode
    ORION_PKT_INS_OPTIONS,           //!< Configuration options for the Inertial Navigation System
    ORION_PKT_STARE_START,           //!< Stare portion of step stare started
    ORION_PKT_STARE_ACK,             //!< Stare acknowledged, clear to move
    ORION_PKT_PRIVATE_DB,            //!< Reserved packet identifier
    ORION_PKT_GEOID_UNDULATION,      //!< Geoid undulation data
    ORION_PKT_PRIVATE_DE = 0xDE,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_DF,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E0,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E1,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E2,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E3,            //!< Reserved packet identifier
    ORION_PKT_NETWORK_SETTINGS,      //!< Change the IP network settings in the gimbal
    ORION_PKT_PRIVATE_E5,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E6,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E7,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E8,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_E9,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_EA,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F0 = 0xF0,     //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F1,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F2,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F3,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F4,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F5,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F6,            //!< Reserved packet identifier
    ORION_PKT_PRIVATE_F7,            //!< Reserved packet identifier
    ORION_PKT_RETRACT_VERSION,       //!< Software version for the retract board (if present)
    ORION_PKT_LENSCTL_VERSION        //!< Software version for the lens control board (if present)
} OrionPktType_t;

/*!
 * Enumeration of gimbal pan and tilt axes.
 */
typedef enum
{
    GIMBAL_AXIS_PAN, //!< The pan axis
    GIMBAL_AXIS_TILT,//!< The tilt axis
    NUM_GIMBAL_AXES  //!< Total number of axes in the gimbal
} GimbalAxis_t;

/*!
 * 3D attitude axis enumeration.
 */
typedef enum
{
    AXIS_ROLL,//!< Roll axis (rotation about x)
    AXIS_PITCH,//!< Pitch axis (rotation about y)
    AXIS_YAW,//!< Yaw axis (rotation about z)
    NUM_AXES //!< Number of attitude axes
} Axis_t;

/*!
 * Enumeration for body axis X, Y, Z arrays.
 */
typedef enum
{
    AXIS_X,  //!< X points forward (away from connector)
    AXIS_Y,  //!< Y points to the right (if X is forward)
    AXIS_Z,  //!< Z points down
    NUM_XYZ  //!< Number of body axes
} BodyAxis_t;

/*!
 * Enumeration for motor stator axes.
 */
typedef enum
{
    STATOR_U,    //!< First field of three phase motor
    STATOR_V,    //!< Second field of three phase motor
    STATOR_W,    //!< Third field of three phase motor
    NUM_STATORS  //!< Number of motor phases
} Stator_t;

/*!
 * Enumeration identifying different boards in the Orion Gimbal.
 */
typedef enum
{
    BOARD_NONE,  //!< Unknown board
    BOARD_CLEVIS,//!< The clevis board (motor control)
    BOARD_CROWN, //!< The crown board (ins and communications)
    BOARD_PAYLOAD,//!< The payload board (camera)
    BOARD_LENSCTRL,//!< The lens control board
    BOARD_MISSCOMP //!< The mission computer
} OrionBoardEnumeration_t;

/*!
 * The mode of operation of the gimbal.
 */
typedef enum
{
    ORION_MODE_DISABLED = 0x00,          //!< disable motor output
    ORION_MODE_FAULT = 0x01,             //!< Gimbal has experienced a fault and motors have been disabled
    ORION_MODE_RATE = 0x10,              //!< Commands give the line of sight angular rate of the camera
    ORION_MODE_GEO_RATE = 0x11,          //!< Inertial rate mode, with bulk motion compensation when valid slant range is available
    ORION_MODE_FFC_AUTO = 0x20,          //!< Commands the gimbal to perform a flat field correction, pan and tilt will drive the IR camera to look at the black body
    ORION_MODE_FFC = ORION_MODE_FFC_AUTO,//!< Legacy FFC mode, alias of ORION_MODE_FFC_AUTO
    ORION_MODE_FFC_MANUAL = 0x21,        //!< Commands the gimbal to perform a flat field correction, pan and tilt will drive the IR camera to the commanded positions. NOTE: The pan/tilt targets specify the payload position, not the boresight position, so the reported angles may not match the command target
    ORION_MODE_SCENE = 0x30,             //!< Commands give the angular rate of the image produced by the camera
    ORION_MODE_TRACK = 0x31,             //!< Commands give the angular rate of the track box in the camera image
    ORION_MODE_NUDGE_TRACK = 0x32,       //!< Nudge the track box by a percentage of FOV
    ORION_MODE_CALIBRATION = 0x40,       //!< Drives the pan and tilt axes to calibrate the stabilizer gyros
    ORION_MODE_POSITION = 0x50,          //!< Commands give the position of the pan and tilt axes with respect to the gimbal mount
    ORION_MODE_POSITION_NO_LIMITS = 0x51,//!< Commands give the position of the pan and tilt axes with respect to the gimbal mount. NOTE: This mode ignores the pan/tilt limits and can result in serious damage to the gimbal if used incorrectly
    ORION_MODE_GEOPOINT = 0x60,          //!< Gimbal is pointing toward a fixed spatial location
    ORION_MODE_PATH = 0x70,              //!< Gimbal is pointing toward a fixed path in space, and may be doing step-stare
    ORION_MODE_DOWN = 0x71,              //!< Gimbal is pointing straight down, and may be doing step-stare
    ORION_MODE_UNKNOWN = 0xFF            //!< Unknown gimbal mode. This is unused in normal operation and is strictly to maintain compatibility with v1.2
} OrionMode_t;

/*!
 * The maximum number of lasers in an Orion gimbal.
 */
typedef enum
{
    MAX_LASERS = 2 //!< Maximum number of lasers in an Orion gimbal.
} OrionMaxLasers_t;

/*!
 * Laser type identifiers.
 */
typedef enum
{
    LASER_TYPE_NONE,             //!< No laser installed
    LASER_TYPE_POINTER,          //!< Laser pointer
    LASER_TYPE_10MJ_MARKER,      //!< Laser marker
    LASER_TYPE_LIGHTWARE,        //!< LightWare LRF
    LASER_TYPE_JENOPTIK_DLEM,    //!< Jenoptik DLEM LRF
    LASER_TYPE_VECTRONIX,        //!< Vectronix LRF
    LASER_TYPE_DESIGNATOR,       //!< Laser designator
    LASER_TYPE_JENOPTIK_DLEM_TEST //!< Jenoptik DLEM LRF test mode
} OrionLaserType_t;

/*!
 * Sources of ranging information.
 */
typedef enum
{
    RANGE_SRC_NONE,          //!< No ranging information
    RANGE_SRC_SKYLINK,       //!< Range information from skylink terrrain lookup
    RANGE_SRC_LASER,         //!< Range information from laser rangefinder
    RANGE_SRC_OTHER,         //!< Other source of range data
    RANGE_SRC_INTERNAL,      //!< Range information is being estimated internally by the gimbal. Note that estimates are not guaranteed be accurate and should only be used as a fallback option.
    RANGE_SRC_INTERNAL_DTED, //!< Range information estimated by the gimbal based on a DTED model
    NUM_RANGE_SRCS           
} RangeDataSrc_t;

/*!
 * The retraction mechanism commands.
 */
typedef enum
{
    RETRACT_CMD_DISABLE, //!< Disable the retract motor
    RETRACT_CMD_DEPLOY,  //!< Move the gimbal to a deployed position
    RETRACT_CMD_RETRACT  //!< Move the gimbal to a retracted position
} OrionRetractCmd_t;

/*!
 * Destination port identifiers
 */
typedef enum
{
    USER_DATA_PORT_ETHERNET = 0, //!< Payload Ethernet connection
    USER_DATA_PORT_PRIMARY = 2,  //!< Primary front-panel RS-232 serial port
    USER_DATA_PORT_FP2,          //!< Front panel FP1 RS-232 serial port
    USER_DATA_PORT_FP1,          //!< Front panel FP2 RS-232 serial port
    USER_DATA_PORT_FP3 = 8,      //!< Front panel FP3 TTL serial port
    USER_DATA_PORT_FP4,          //!< Front panel FP4 TTL serial port
    USER_DATA_PORT_CURRENT = 255 //!< The port referenced is whatever port delivered this packet
} UserDataPort_t;


// The prototypes below provide an interface to the packets.
// They are not auto-generated functions, but must be hand-written

//! \return the packet data pointer from the packet
uint8_t* getOrionPublicPacketData(void* pkt);

//! \return the packet data pointer from the packet, const
const uint8_t* getOrionPublicPacketDataConst(const void* pkt);

//! Complete a packet after the data have been encoded
void finishOrionPublicPacket(void* pkt, int size, uint32_t packetID);

//! \return the size of a packet from the packet header
int getOrionPublicPacketSize(const void* pkt);

//! \return the ID of a packet from the packet header
uint32_t getOrionPublicPacketID(const void* pkt);

#ifdef __cplusplus
}
#endif
#endif
