
#include "can_handlers.h"
#include "can_s.h"
#include "can_c.h"

/**
 * @brief   Function template for handler implementation
 *
 * @details Because the actual unpacking functions have concrete struct types,
            they all have different function signatures and cannot be stored 
            in the CAN handler table. This macro generates a wrapper function 
            which casts the pointer to the bytes to unpack into to the actual
            type and calls the unpacking function.
 */
#define IMPL_HANDLER(T, f) \
    static void T##_handler(uint8_t* dst, const uint8_t* src, size_t length) \
    { \
        struct T* output = (struct T*) dst; \
        f(dst, src, length); \
    } \

IMPL_HANDLER(can_c_vcu_internal_states_t, can_c_vcu_internal_states_unpack)
IMPL_HANDLER(can_c_vcu_driver_inputs_t, can_c_vcu_driver_inputs_unpack)
IMPL_HANDLER(can_c_pm100_fault_codes_t, can_c_pm100_fault_codes_unpack)
IMPL_HANDLER(can_c_pm100_internal_states_t, can_c_pm100_internal_states_unpack)
IMPL_HANDLER(can_c_pm100_current_info_t, can_c_pm100_current_info_unpack)
IMPL_HANDLER(can_c_pm100_motor_position_info_t, can_c_pm100_motor_position_info_unpack)

IMPL_HANDLER(can_s_oct_gps_stats_t, can_s_oct_gps_stats_unpack)
IMPL_HANDLER(can_s_oct_gps_lat_long_t, can_s_oct_gps_lat_long_unpack)

/**
 * @brief   Table of CAN message IDs and associated unpacking functions
 */
static const can_handler_t can_c_handler_table[] = {
    {CAN_C_VCU_INTERNAL_STATES_FRAME_ID, 6, can_c_vcu_internal_states_t_handler},
    {CAN_C_VCU_DRIVER_INPUTS_FRAME_ID, 5, can_c_vcu_driver_inputs_t_handler},
    {CAN_C_PM100_FAULT_CODES_FRAME_ID, 4, can_c_pm100_fault_codes_t_handler},
    {CAN_C_PM100_INTERNAL_STATES_FRAME_ID, 3, can_c_pm100_internal_states_t_handler},
    {CAN_C_PM100_CURRENT_INFO_FRAME_ID, 2, can_c_pm100_current_info_t_handler},
    {CAN_C_PM100_MOTOR_POSITION_INFO_FRAME_ID, 1, can_c_pm100_motor_position_info_t_handler},
};

/**
 * @brief   Table of CAN message IDs and associated unpacking functions
 */
static const can_handler_t can_s_handler_table[] = {
    {CAN_S_OCT_GPS_STATS_FRAME_ID, 8, can_s_oct_gps_stats_t_handler},
    {CAN_S_OCT_GPS_LAT_LONG_FRAME_ID, 7, can_s_oct_gps_lat_long_t_handler},
};

/**
 * @brief       Returns the CAN handler at the specified index in the table, or 
 *              NULL if out of bounds or wrong instance number
 * 
 * @param[in]   index       Index in table
 * @param[in]   instance    Selection of can handler table 
 *                          CAN_C_HANDLER_TABLE_INSTANCE or CAN_S_HANDLER_TABLE_INSTANCE
 */
const can_handler_t* can_handler_get(uint32_t index, uint8_t instance)
{
    const can_handler_t* handler = NULL;

    if (instance == CAN_C_HANDLER_TABLE_INSTANCE)
    {
        if (index < CAN_C_HANDLERS_TABLE_SIZE)
        {
            handler = &can_c_handler_table[index];
        }                    
    }
    else if(instance == CAN_S_HANDLER_TABLE_INSTANCE)
    {
        if (index < CAN_S_HANDLERS_TABLE_SIZE)
        {
            handler = &can_s_handler_table[index];
        }                      
    }
    return handler;
}
