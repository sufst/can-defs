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
 * This file was generated by cantools version 39.3.0 Tue Dec  5 18:06:15 2023.
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

/* Frame lengths in bytes. */
#define CAN_S_OCT_GPS_STATS_LENGTH (8u)
#define CAN_S_OCT_GPS_LAT_LONG_LENGTH (8u)
#define CAN_S_VCU_PING_LENGTH (8u)
#define CAN_S_VCU_PING_ACK_LENGTH (8u)
#define CAN_S_VCU_TS_ON_LENGTH (8u)

/* Extended or standard frame types. */
#define CAN_S_OCT_GPS_STATS_IS_EXTENDED (0)
#define CAN_S_OCT_GPS_LAT_LONG_IS_EXTENDED (0)
#define CAN_S_VCU_PING_IS_EXTENDED (0)
#define CAN_S_VCU_PING_ACK_IS_EXTENDED (0)
#define CAN_S_VCU_TS_ON_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/* Frame Names. */
#define CAN_S_OCT_GPS_STATS_NAME "OCT_GPS_Stats"
#define CAN_S_OCT_GPS_LAT_LONG_NAME "OCT_GPS_LatLong"
#define CAN_S_VCU_PING_NAME "VCU_Ping"
#define CAN_S_VCU_PING_ACK_NAME "VCU_Ping_Ack"
#define CAN_S_VCU_TS_ON_NAME "VCU_TS_On"

/* Signal Names. */
#define CAN_S_OCT_GPS_STATS_OCT_GPS_TIME_UCT_NAME "OCT_GPS_TimeUCT"
#define CAN_S_OCT_GPS_STATS_OCT_GPS_NUM_SATS_NAME "OCT_GPS_NumSats"
#define CAN_S_OCT_GPS_STATS_OCT_GPS_HDOP_NAME "OCT_GPS_HDOP"
#define CAN_S_OCT_GPS_LAT_LONG_OCT_GPS_LONGITUDE_NAME "OCT_GPS_Longitude"
#define CAN_S_OCT_GPS_LAT_LONG_OCT_GPS_LATITUDE_NAME "OCT_GPS_Latitude"
#define CAN_S_VCU_PING_ACK_VER_MAJOR_NAME "VER_MAJOR"
#define CAN_S_VCU_PING_ACK_VER_MINOR_NAME "VER_MINOR"
#define CAN_S_VCU_PING_ACK_VER_PATCH_NAME "VER_PATCH"

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


#ifdef __cplusplus
}
#endif

#endif
