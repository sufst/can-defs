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

#include <string.h>

#include "can_s.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint32_t unpack_left_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint32_t unpack_right_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) >> shift);
}

int can_s_oct_gps_stats_pack(
    uint8_t *dst_p,
    const struct can_s_oct_gps_stats_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u32(src_p->oct_gps_time_uct, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(src_p->oct_gps_time_uct, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(src_p->oct_gps_time_uct, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(src_p->oct_gps_time_uct, 24u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->oct_gps_num_sats, 1u, 0xfeu);
    dst_p[4] |= pack_left_shift_u8(src_p->oct_gps_hdop, 0u, 0xffu);

    return (8);
}

int can_s_oct_gps_stats_unpack(
    struct can_s_oct_gps_stats_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->oct_gps_time_uct = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    dst_p->oct_gps_time_uct |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    dst_p->oct_gps_time_uct |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    dst_p->oct_gps_time_uct |= unpack_left_shift_u32(src_p[3], 24u, 0x01u);
    dst_p->oct_gps_num_sats = unpack_right_shift_u8(src_p[3], 1u, 0xfeu);
    dst_p->oct_gps_hdop = unpack_right_shift_u8(src_p[4], 0u, 0xffu);

    return (0);
}

uint32_t can_s_oct_gps_stats_oct_gps_time_uct_encode(double value)
{
    return (uint32_t)(value / 0.01);
}

double can_s_oct_gps_stats_oct_gps_time_uct_decode(uint32_t value)
{
    return ((double)value * 0.01);
}

bool can_s_oct_gps_stats_oct_gps_time_uct_is_in_range(uint32_t value)
{
    return (value <= 2400000000u);
}

uint8_t can_s_oct_gps_stats_oct_gps_num_sats_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_oct_gps_stats_oct_gps_num_sats_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_oct_gps_stats_oct_gps_num_sats_is_in_range(uint8_t value)
{
    return (value <= 99u);
}

uint8_t can_s_oct_gps_stats_oct_gps_hdop_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_oct_gps_stats_oct_gps_hdop_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_oct_gps_stats_oct_gps_hdop_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int can_s_oct_gps_lat_long_pack(
    uint8_t *dst_p,
    const struct can_s_oct_gps_lat_long_t *src_p,
    size_t size)
{
    uint32_t oct_gps_latitude;
    uint32_t oct_gps_longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    oct_gps_longitude = (uint32_t)src_p->oct_gps_longitude;
    dst_p[0] |= pack_left_shift_u32(oct_gps_longitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(oct_gps_longitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(oct_gps_longitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(oct_gps_longitude, 24u, 0xffu);
    oct_gps_latitude = (uint32_t)src_p->oct_gps_latitude;
    dst_p[4] |= pack_left_shift_u32(oct_gps_latitude, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(oct_gps_latitude, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(oct_gps_latitude, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(oct_gps_latitude, 24u, 0x7fu);

    return (8);
}

int can_s_oct_gps_lat_long_unpack(
    struct can_s_oct_gps_lat_long_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t oct_gps_latitude;
    uint32_t oct_gps_longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    oct_gps_longitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    oct_gps_longitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    oct_gps_longitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    oct_gps_longitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->oct_gps_longitude = (int32_t)oct_gps_longitude;
    oct_gps_latitude = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    oct_gps_latitude |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    oct_gps_latitude |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    oct_gps_latitude |= unpack_left_shift_u32(src_p[7], 24u, 0x7fu);

    if ((oct_gps_latitude & (1u << 30)) != 0u) {
        oct_gps_latitude |= 0x80000000u;
    }

    dst_p->oct_gps_latitude = (int32_t)oct_gps_latitude;

    return (0);
}

int32_t can_s_oct_gps_lat_long_oct_gps_longitude_encode(double value)
{
    return (int32_t)(value / 0.0001);
}

double can_s_oct_gps_lat_long_oct_gps_longitude_decode(int32_t value)
{
    return ((double)value * 0.0001);
}

bool can_s_oct_gps_lat_long_oct_gps_longitude_is_in_range(int32_t value)
{
    return (value >= 0);
}

int32_t can_s_oct_gps_lat_long_oct_gps_latitude_encode(double value)
{
    return (int32_t)(value / 0.0001);
}

double can_s_oct_gps_lat_long_oct_gps_latitude_decode(int32_t value)
{
    return ((double)value * 0.0001);
}

bool can_s_oct_gps_lat_long_oct_gps_latitude_is_in_range(int32_t value)
{
    return (value >= 0);
}