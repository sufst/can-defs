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

#include <string.h>

#include "can_s.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
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

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
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

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
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

int can_s_oct_gps_stats_init(struct can_s_oct_gps_stats_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_oct_gps_stats_t));

    return 0;
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

int can_s_oct_gps_lat_long_init(struct can_s_oct_gps_lat_long_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_oct_gps_lat_long_t));

    return 0;
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

int can_s_vcu_ping_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ping_t *src_p,
    size_t size)
{
    (void)src_p;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    return (8);
}

int can_s_vcu_ping_unpack(
    struct can_s_vcu_ping_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    (void)dst_p;
    (void)src_p;

    if (size < 8u) {
        return (-EINVAL);
    }

    return (0);
}

int can_s_vcu_ping_init(struct can_s_vcu_ping_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_ping_t));

    return 0;
}

int can_s_vcu_ping_ack_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ping_ack_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->ver_major, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->ver_minor, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->ver_patch, 0u, 0xffu);

    return (8);
}

int can_s_vcu_ping_ack_unpack(
    struct can_s_vcu_ping_ack_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->ver_major = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->ver_minor = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->ver_patch = unpack_right_shift_u8(src_p[2], 0u, 0xffu);

    return (0);
}

int can_s_vcu_ping_ack_init(struct can_s_vcu_ping_ack_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_ping_ack_t));

    return 0;
}

uint8_t can_s_vcu_ping_ack_ver_major_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_ping_ack_ver_major_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_ping_ack_ver_major_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_ping_ack_ver_minor_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_ping_ack_ver_minor_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_ping_ack_ver_minor_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_ping_ack_ver_patch_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_ping_ack_ver_patch_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_ping_ack_ver_patch_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int can_s_vcu_ts_on_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_ts_on_t *src_p,
    size_t size)
{
    (void)src_p;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    return (8);
}

int can_s_vcu_ts_on_unpack(
    struct can_s_vcu_ts_on_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    (void)dst_p;
    (void)src_p;

    if (size < 8u) {
        return (-EINVAL);
    }

    return (0);
}

int can_s_vcu_ts_on_init(struct can_s_vcu_ts_on_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_ts_on_t));

    return 0;
}

int can_s_vcu_pdm_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_pdm_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->inverter, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->brakelight, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->pump, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->fan, 0u, 0xffu);

    return (8);
}

int can_s_vcu_pdm_unpack(
    struct can_s_vcu_pdm_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inverter = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->brakelight = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->pump = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->fan = unpack_right_shift_u8(src_p[3], 0u, 0xffu);

    return (0);
}

int can_s_vcu_pdm_init(struct can_s_vcu_pdm_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_pdm_t));

    return 0;
}

uint8_t can_s_vcu_pdm_inverter_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_pdm_inverter_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_pdm_inverter_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t can_s_vcu_pdm_brakelight_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_pdm_brakelight_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_pdm_brakelight_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t can_s_vcu_pdm_pump_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_pdm_pump_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_pdm_pump_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t can_s_vcu_pdm_fan_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_pdm_fan_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_pdm_fan_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int can_s_vcu_temps_init(struct can_s_vcu_temps_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_temps_t));

    return 0;
}

int can_s_vcu_temps_pack(
    uint8_t* dst_p,
    const struct can_s_vcu_temps_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->vcu_max_temp, 0u, 0xffu);

    return(8);
}

int can_s_vcu_temps_unpack(
    struct can_s_vcu_temps_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->vcu_max_temp = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return(0);
}

int8_t can_s_vcu_temps_max_temp_encode(double value)
{
    return (int8_t)(value);
}

double can_s_vcu_temps_max_temp_decode(int8_t value)
{
    return ((double)value);
}

bool can_s_vcu_temps_max_temp_is_in_range(int8_t value)
{
    return (value <= 127 && value >= -128);
}

int can_s_vcu_sensors_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_sensors_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->vcu_apps, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->vcu_apps, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->vcu_bps, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->vcu_bps, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->vcu_sagl, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->vcu_sagl, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->vcu_torque_request, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->vcu_torque_request, 8u, 0xffu);

    return (8);
}

int can_s_vcu_sensors_unpack(
    struct can_s_vcu_sensors_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->vcu_apps = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->vcu_apps |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->vcu_bps = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->vcu_bps |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->vcu_sagl = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->vcu_sagl |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->vcu_torque_request = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->vcu_torque_request |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int can_s_vcu_sensors_init(struct can_s_vcu_sensors_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_sensors_t));

    return 0;
}

uint16_t can_s_vcu_sensors_vcu_apps_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double can_s_vcu_sensors_vcu_apps_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool can_s_vcu_sensors_vcu_apps_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}

uint16_t can_s_vcu_sensors_vcu_bps_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double can_s_vcu_sensors_vcu_bps_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool can_s_vcu_sensors_vcu_bps_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}

uint16_t can_s_vcu_sensors_vcu_sagl_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double can_s_vcu_sensors_vcu_sagl_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool can_s_vcu_sensors_vcu_sagl_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}

uint16_t can_s_vcu_sensors_vcu_torque_request_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double can_s_vcu_sensors_vcu_torque_request_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool can_s_vcu_sensors_vcu_torque_request_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int can_s_vcu_state_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_state_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->vcu_rolling_counter, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->vcu_rolling_counter, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->vcu_ctrl_state, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->vcu_r2_d, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->vcu_drs_active, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->vcu_drs_allowed, 2u, 0x04u);

    return (4);
}

int can_s_vcu_state_unpack(
    struct can_s_vcu_state_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->vcu_rolling_counter = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->vcu_rolling_counter |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->vcu_ctrl_state = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->vcu_r2_d = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->vcu_drs_active = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->vcu_drs_allowed = unpack_right_shift_u8(src_p[3], 2u, 0x04u);

    return (0);
}

int can_s_vcu_state_init(struct can_s_vcu_state_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_state_t));

    return 0;
}

uint16_t can_s_vcu_state_vcu_rolling_counter_encode(double value)
{
    return (uint16_t)(value);
}

double can_s_vcu_state_vcu_rolling_counter_decode(uint16_t value)
{
    return ((double)value);
}

bool can_s_vcu_state_vcu_rolling_counter_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_state_vcu_ctrl_state_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_state_vcu_ctrl_state_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_state_vcu_ctrl_state_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_state_vcu_r2_d_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_state_vcu_r2_d_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_state_vcu_r2_d_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t can_s_vcu_state_vcu_drs_active_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_state_vcu_drs_active_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_state_vcu_drs_active_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t can_s_vcu_state_vcu_drs_allowed_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_state_vcu_drs_allowed_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_state_vcu_drs_allowed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int can_s_vcu_error_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_error_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    dst_p[0] |= pack_left_shift_u8(src_p->vcu_ctrl_error, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->vcu_scs_error, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->vcu_pm100_error, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->vcu_rtcan1_error, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->vcu_rtcan2_error, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->vcu_canbc_error, 0u, 0xffu);

    return (6);
}

int can_s_vcu_error_unpack(
    struct can_s_vcu_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    dst_p->vcu_ctrl_error = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->vcu_scs_error = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->vcu_pm100_error = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->vcu_rtcan1_error = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->vcu_rtcan2_error = unpack_right_shift_u8(src_p[4], 0u, 0xffu);
    dst_p->vcu_canbc_error = unpack_right_shift_u8(src_p[5], 0u, 0xffu);

    return (0);
}

int can_s_vcu_error_init(struct can_s_vcu_error_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_error_t));

    return 0;
}

uint8_t can_s_vcu_error_vcu_ctrl_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_ctrl_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_ctrl_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_error_vcu_scs_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_scs_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_scs_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_error_vcu_pm100_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_pm100_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_pm100_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_error_vcu_rtcan1_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_rtcan1_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_rtcan1_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_error_vcu_rtcan2_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_rtcan2_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_rtcan2_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t can_s_vcu_error_vcu_canbc_error_encode(double value)
{
    return (uint8_t)(value);
}

double can_s_vcu_error_vcu_canbc_error_decode(uint8_t value)
{
    return ((double)value);
}

bool can_s_vcu_error_vcu_canbc_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int can_s_vcu_simulate_init(struct can_s_vcu_simulation_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct can_s_vcu_simulation_t));

    return 0;
}

int can_s_vcu_simulation_pack(
    uint8_t *dst_p,
    const struct can_s_vcu_simulation_t *src_p,
    size_t size
)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->sim_torque_request, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->sim_torque_request, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->sim_apps, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->sim_apps, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->sim_bps, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->sim_bps, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u8(src_p->sim_r2_d, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->sim_ts_on, 1u, 0x02u);

    return (8);
}

int can_s_vcu_simulation_unpack(
    struct can_s_vcu_simulation_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    uint8_t multiplexer = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    switch (multiplexer) {

    case 0:
        dst_p->sim_apps = unpack_right_shift_u16(src_p[1], 0u, 0xffu);
        dst_p->sim_apps |= unpack_left_shift_u16(src_p[2], 8u, 0xffu);
        dst_p->sim_bps = unpack_right_shift_u16(src_p[3], 0u, 0xffu);
        dst_p->sim_bps |= unpack_left_shift_u16(src_p[4], 8u, 0xffu);
        dst_p->sim_torque_request = unpack_right_shift_u16(src_p[5], 0u, 0xffu);
        dst_p->sim_torque_request |= unpack_left_shift_u16(src_p[6], 8u, 0xffu);
        dst_p->sim_r2_d = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
        dst_p->sim_ts_on = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
        break;

    case 1:
        dst_p->sim_power = unpack_right_shift_u16(src_p[1], 0u, 0xffu);
        dst_p->sim_power |= unpack_left_shift_u16(src_p[2], 8u, 0xffu);
        break;

    default:
        break;
    }

    return (0);
}