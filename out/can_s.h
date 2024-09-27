/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 39.4.5 Tue Jul  2 20:17:46 2024.
 */

#ifndef CAN_S_H
#define CAN_S_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define CAN_S_OCT_GPS_STATS_FRAME_ID (0x81u)
#define CAN_S_OCT_GPS_LAT_LONG_FRAME_ID (0x80u)
#define CAN_S_VCU_PING_FRAME_ID (0x40u)
#define CAN_S_VCU_PING_ACK_FRAME_ID (0x41u)
#define CAN_S_VCU_TS_ON_FRAME_ID (0x42u)
#define CAN_S_VCU_PDM_FRAME_ID (0x104u)
#define CAN_S_VCU_SENSORS_FRAME_ID (0x100u)
#define CAN_S_VCU_STATE_FRAME_ID (0x101u)
#define CAN_S_VCU_ERROR_FRAME_ID (0x102u)
#define CAN_S_VCU_TEMPS_FRAME_ID (0x105u)

/* Frame lengths in bytes. */
#define CAN_S_OCT_GPS_STATS_LENGTH (8u)
#define CAN_S_OCT_GPS_LAT_LONG_LENGTH (8u)
#define CAN_S_VCU_PING_LENGTH (8u)
#define CAN_S_VCU_PING_ACK_LENGTH (8u)
#define CAN_S_VCU_TS_ON_LENGTH (8u)
#define CAN_S_VCU_PDM_LENGTH (8u)
#define CAN_S_VCU_SENSORS_LENGTH (8u)
#define CAN_S_VCU_STATE_LENGTH (4u)
#define CAN_S_VCU_TEMPS_LENGTH (8u)
#define CAN_S_VCU_ERROR_LENGTH (6u)

/* Extended or standard frame types. */
#define CAN_S_OCT_GPS_STATS_IS_EXTENDED (0)
#define CAN_S_OCT_GPS_LAT_LONG_IS_EXTENDED (0)
#define CAN_S_VCU_PING_IS_EXTENDED (0)
#define CAN_S_VCU_PING_ACK_IS_EXTENDED (0)
#define CAN_S_VCU_TS_ON_IS_EXTENDED (0)
#define CAN_S_VCU_PDM_IS_EXTENDED (0)
#define CAN_S_VCU_SENSORS_IS_EXTENDED (0)
#define CAN_S_VCU_STATE_IS_EXTENDED (0)
#define CAN_S_VCU_TEMPS_IS_EXTENDED (0)
#define CAN_S_VCU_ERROR_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/* Frame Names. */
#define CAN_S_OCT_GPS_STATS_NAME "OCT_GPS_Stats"
#define CAN_S_OCT_GPS_LAT_LONG_NAME "OCT_GPS_LatLong"
#define CAN_S_VCU_PING_NAME "VCU_Ping"
#define CAN_S_VCU_PING_ACK_NAME "VCU_Ping_Ack"
#define CAN_S_VCU_TS_ON_NAME "VCU_TS_On"
#define CAN_S_VCU_PDM_NAME "VCU_PDM"
#define CAN_S_VCU_SENSORS_NAME "VCU_Sensors"
#define CAN_S_VCU_STATE_NAME "VCU_State"
#define CAN_S_VCU_ERROR_NAME "VCU_Error"
#define CAN_S_VCU_TEMPS_NAME "VCU_Temps"

/* Signal Names. */
#define CAN_S_OCT_GPS_STATS_OCT_GPS_TIME_UCT_NAME "OCT_GPS_TimeUCT"
#define CAN_S_OCT_GPS_STATS_OCT_GPS_NUM_SATS_NAME "OCT_GPS_NumSats"
#define CAN_S_OCT_GPS_STATS_OCT_GPS_HDOP_NAME "OCT_GPS_HDOP"
#define CAN_S_OCT_GPS_LAT_LONG_OCT_GPS_LONGITUDE_NAME "OCT_GPS_Longitude"
#define CAN_S_OCT_GPS_LAT_LONG_OCT_GPS_LATITUDE_NAME "OCT_GPS_Latitude"
#define CAN_S_VCU_PING_ACK_VER_MAJOR_NAME "VER_MAJOR"
#define CAN_S_VCU_PING_ACK_VER_MINOR_NAME "VER_MINOR"
#define CAN_S_VCU_PING_ACK_VER_PATCH_NAME "VER_PATCH"
#define CAN_S_VCU_PDM_INVERTER_NAME "INVERTER"
#define CAN_S_VCU_PDM_BRAKELIGHT_NAME "BRAKELIGHT"
#define CAN_S_VCU_PDM_PUMP_NAME "PUMP"
#define CAN_S_VCU_PDM_FAN_NAME "FAN"
#define CAN_S_VCU_SENSORS_VCU_APPS_NAME "VCU_APPS"
#define CAN_S_VCU_SENSORS_VCU_BPS_NAME "VCU_BPS"
#define CAN_S_VCU_SENSORS_VCU_SAGL_NAME "VCU_SAGL"
#define CAN_S_VCU_SENSORS_VCU_TORQUE_REQUEST_NAME "VCU_Torque_Request"
#define CAN_S_VCU_STATE_VCU_ROLLING_COUNTER_NAME "VCU_Rolling_Counter"
#define CAN_S_VCU_STATE_VCU_CTRL_STATE_NAME "VCU_CTRL_State"
#define CAN_S_VCU_STATE_VCU_R2_D_NAME "VCU_R2D"
#define CAN_S_VCU_STATE_VCU_DRS_ACTIVE_NAME "VCU_DRS_Active"
#define CAN_S_VCU_STATE_VCU_DRS_ALLOWED_NAME "VCU_DRS_Allowed"
#define CAN_S_VCU_TEMPS_VCU_MAX_TEMP_NAME "VCU_Max_Temp"
#define CAN_S_VCU_ERROR_VCU_CTRL_ERROR_NAME "VCU_CTRL_Error"
#define CAN_S_VCU_ERROR_VCU_SCS_ERROR_NAME "VCU_SCS_Error"
#define CAN_S_VCU_ERROR_VCU_PM100_ERROR_NAME "VCU_PM100_Error"
#define CAN_S_VCU_ERROR_VCU_RTCAN1_ERROR_NAME "VCU_RTCAN1_Error"
#define CAN_S_VCU_ERROR_VCU_RTCAN2_ERROR_NAME "VCU_RTCAN2_Error"
#define CAN_S_VCU_ERROR_VCU_CANBC_ERROR_NAME "VCU_CANBC_Error"

/**
 * Signals in message OCT_GPS_Stats.
 *
 * Horizontal Dilution of Precision (HDOP), number of connected satellites, and UCT Time from satellites.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_oct_gps_stats_t {
    /**
     * Range: 0..2400000000 (0..24000000 -)
     * Scale: 0.01
     * Offset: 0
     */
    uint32_t oct_gps_time_uct;

    /**
     * Range: 0..99 (0..99 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t oct_gps_num_sats;

    /**
     * Range: 0..256 (0..256 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t oct_gps_hdop;
};

/**
 * Signals in message OCT_GPS_LatLong.
 *
 * Latitude and Longitude values in fixed point decimal format.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_oct_gps_lat_long_t {
    /**
     * Range: 0..18099999990000 (0..1809999999 -)
     * Scale: 0.0001
     * Offset: 0
     */
    int32_t oct_gps_longitude;

    /**
     * Range: 0..9099999990000 (0..909999999 -)
     * Scale: 0.0001
     * Offset: 0
     */
    int32_t oct_gps_latitude;
};

/**
 * Signals in message VCU_Ping.
 *
 * Ping the VCU
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_ping_t {
    /**
     * Dummy signal in empty message.
     */
    uint8_t dummy;
};

/**
 * Signals in message VCU_Ping_Ack.
 *
 * Response from VCU to a ping request
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_ping_ack_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t ver_major;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t ver_minor;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t ver_patch;
};

/**
 * Signals in message VCU_TS_On.
 *
 * Enable the TS with the PDU.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_ts_on_t {
    /**
     * Dummy signal in empty message.
     */
    uint8_t dummy;
};

/**
 * Signals in message VCU_PDM.
 *
 * Periodic messages from VCU to PDM
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_pdm_t {
    /**
     * Range: 0..1 (0..1 On/Off)
     * Scale: 1
     * Offset: 0
     */
    uint8_t inverter;

    /**
     * Range: 0..1 (0..1 On/Off)
     * Scale: 1
     * Offset: 0
     */
    uint8_t brakelight;

    /**
     * Range: 0..1 (0..1 On/Off)
     * Scale: 1
     * Offset: 0
     */
    uint8_t pump;

    /**
     * Range: 0..1 (0..1 On/Off)
     * Scale: 1
     * Offset: 0
     */
    uint8_t fan;
};

/**
 * Signals in message VCU_Sensors.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_sensors_t {
    /**
     * Range: 0..1000 (0..100 %)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t vcu_apps;

    /**
     * Range: 0..1000 (0..100 -)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t vcu_bps;

    /**
     * Range: 0..1000 (0..100 deg)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t vcu_sagl;

    /**
     * Range: 0..65535 (0..6553.5 Nm)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t vcu_torque_request;
};

/**
 * Signals in message VCU_State.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_state_t {
    /**
     * Range: 0..65535 (0..65535 -)
     * Scale: 1
     * Offset: 0
     */
    uint16_t vcu_rolling_counter;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_ctrl_state;

    /**
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_r2_d;

    /**
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_drs_active;

    /**
     * Range: 0..1 (0..1 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_drs_allowed;
};

struct can_s_vcu_temps_t {
    /**
     * Range: -128..127 (-128..127 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_max_temp;
};

/**
 * Signals in message VCU_Error.
 *
 * All signal values are as on the CAN bus.
 */
struct can_s_vcu_error_t {
    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_ctrl_error;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_scs_error;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_pm100_error;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_rtcan1_error;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_rtcan2_error;

    /**
     * Range: 0..255 (0..255 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t vcu_canbc_error;
};

/**
 * Pack message OCT_GPS_Stats.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_oct_gps_stats_pack(
    uint8_t *dst_p,
    const struct can_s_oct_gps_stats_t *src_p,
    size_t size);

/**
 * Unpack message OCT_GPS_Stats.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_oct_gps_stats_unpack(
    struct can_s_oct_gps_stats_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from OCT_GPS_Stats.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_oct_gps_stats_init(struct can_s_oct_gps_stats_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint32_t can_s_oct_gps_stats_oct_gps_time_uct_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_oct_gps_stats_oct_gps_time_uct_decode(uint32_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_oct_gps_stats_oct_gps_time_uct_is_in_range(uint32_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_oct_gps_stats_oct_gps_num_sats_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_oct_gps_stats_oct_gps_num_sats_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_oct_gps_stats_oct_gps_num_sats_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_oct_gps_stats_oct_gps_hdop_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_oct_gps_stats_oct_gps_hdop_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_oct_gps_stats_oct_gps_hdop_is_in_range(uint8_t value);

/**
 * Pack message OCT_GPS_LatLong.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_oct_gps_lat_long_pack(
    uint8_t *dst_p,
    const struct can_s_oct_gps_lat_long_t *src_p,
    size_t size);

/**
 * Unpack message OCT_GPS_LatLong.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_oct_gps_lat_long_unpack(
    struct can_s_oct_gps_lat_long_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from OCT_GPS_LatLong.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_oct_gps_lat_long_init(struct can_s_oct_gps_lat_long_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int32_t can_s_oct_gps_lat_long_oct_gps_longitude_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_oct_gps_lat_long_oct_gps_longitude_decode(int32_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_oct_gps_lat_long_oct_gps_longitude_is_in_range(int32_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int32_t can_s_oct_gps_lat_long_oct_gps_latitude_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_oct_gps_lat_long_oct_gps_latitude_decode(int32_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_oct_gps_lat_long_oct_gps_latitude_is_in_range(int32_t value);

/**
 * Pack message VCU_Ping.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_ping_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ping_t *src_p,
    size_t size);

/**
 * Unpack message VCU_Ping.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_ping_unpack(
    struct can_s_vcu_ping_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_Ping.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_ping_init(struct can_s_vcu_ping_t *msg_p);

/**
 * Pack message VCU_Ping_Ack.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_ping_ack_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ping_ack_t *src_p,
    size_t size);

/**
 * Unpack message VCU_Ping_Ack.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_ping_ack_unpack(
    struct can_s_vcu_ping_ack_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_Ping_Ack.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_ping_ack_init(struct can_s_vcu_ping_ack_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_ping_ack_ver_major_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_ping_ack_ver_major_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_ping_ack_ver_major_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_ping_ack_ver_minor_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_ping_ack_ver_minor_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_ping_ack_ver_minor_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_ping_ack_ver_patch_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_ping_ack_ver_patch_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_ping_ack_ver_patch_is_in_range(uint8_t value);

/**
 * Pack message VCU_TS_On.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_ts_on_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ts_on_t *src_p,
    size_t size);

/**
 * Unpack message VCU_TS_On.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_ts_on_unpack(
    struct can_s_vcu_ts_on_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_TS_On.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_ts_on_init(struct can_s_vcu_ts_on_t *msg_p);

/**
 * Pack message VCU_PDM.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_pdm_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_pdm_t *src_p,
    size_t size);

/**
 * Unpack message VCU_PDM.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_pdm_unpack(
    struct can_s_vcu_pdm_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_PDM.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_pdm_init(struct can_s_vcu_pdm_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_pdm_inverter_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_pdm_inverter_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_pdm_inverter_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_pdm_brakelight_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_pdm_brakelight_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_pdm_brakelight_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_pdm_pump_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_pdm_pump_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_pdm_pump_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_pdm_fan_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_pdm_fan_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_pdm_fan_is_in_range(uint8_t value);

/**
 * Init message fields to default values from VCU_TEMPS.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_temps_init(struct can_s_vcu_temps_t *msg_p);

/**
 * Pack message VCU_Temps.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_temps_pack(
    int8_t *dst_p,
    const struct can_s_vcu_temps_t *src_p,
    size_t size);

/**
 * Unpack message VCU_Temps.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_temps_unpack(
    struct can_s_vcu_temps_t *dst_p,
    const int8_t *src_p,
    size_t size);

/**
 * Encode VCU Max Temperature signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int8_t can_s_vcu_temps_max_temp_encode(double value);

/**
 * Decode VCU Max Temperature signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
double can_s_vcu_temps_max_temp_decode(int8_t value);

/**
 * Check that VCU Max Temperature signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_temps_max_temp_is_in_range(int8_t value);

/**
 * Pack message VCU_Sensors.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_sensors_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_sensors_t *src_p,
    size_t size);

/**
 * Unpack message VCU_Sensors.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_sensors_unpack(
    struct can_s_vcu_sensors_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_Sensors.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_sensors_init(struct can_s_vcu_sensors_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t can_s_vcu_sensors_vcu_apps_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_sensors_vcu_apps_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_sensors_vcu_apps_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t can_s_vcu_sensors_vcu_bps_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_sensors_vcu_bps_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_sensors_vcu_bps_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t can_s_vcu_sensors_vcu_sagl_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_sensors_vcu_sagl_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_sensors_vcu_sagl_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t can_s_vcu_sensors_vcu_torque_request_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_sensors_vcu_torque_request_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_sensors_vcu_torque_request_is_in_range(uint16_t value);

/**
 * Pack message VCU_State.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_state_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_state_t *src_p,
    size_t size);

/**
 * Unpack message VCU_State.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_state_unpack(
    struct can_s_vcu_state_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_State.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_state_init(struct can_s_vcu_state_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t can_s_vcu_state_vcu_rolling_counter_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_state_vcu_rolling_counter_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_state_vcu_rolling_counter_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_state_vcu_ctrl_state_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_state_vcu_ctrl_state_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_state_vcu_ctrl_state_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_state_vcu_r2_d_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_state_vcu_r2_d_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_state_vcu_r2_d_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_state_vcu_drs_active_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_state_vcu_drs_active_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_state_vcu_drs_active_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_state_vcu_drs_allowed_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_state_vcu_drs_allowed_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_state_vcu_drs_allowed_is_in_range(uint8_t value);

/**
 * Pack message VCU_Error.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int can_s_vcu_error_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_error_t *src_p,
    size_t size);

/**
 * Unpack message VCU_Error.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int can_s_vcu_error_unpack(
    struct can_s_vcu_error_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Init message fields to default values from VCU_Error.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int can_s_vcu_error_init(struct can_s_vcu_error_t *msg_p);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_ctrl_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_ctrl_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_ctrl_error_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_scs_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_scs_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_scs_error_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_pm100_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_pm100_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_pm100_error_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_rtcan1_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_rtcan1_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_rtcan1_error_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_rtcan2_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_rtcan2_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_rtcan2_error_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t can_s_vcu_error_vcu_canbc_error_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double can_s_vcu_error_vcu_canbc_error_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool can_s_vcu_error_vcu_canbc_error_is_in_range(uint8_t value);


#ifdef __cplusplus
}
#endif

#endif
