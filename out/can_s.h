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
 * This file was generated by cantools version 38.0.2 Sat May 13 12:50:39 2023.
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

/* Frame lengths in bytes. */
#define CAN_S_OCT_GPS_STATS_LENGTH (8u)
#define CAN_S_OCT_GPS_LAT_LONG_LENGTH (8u)

/* Extended or standard frame types. */
#define CAN_S_OCT_GPS_STATS_IS_EXTENDED (0)
#define CAN_S_OCT_GPS_LAT_LONG_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


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


#ifdef __cplusplus
}
#endif

#endif
