
#include "can_handlers.h"
#include "can_database.h"

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

IMPL_HANDLER(can_database_pm100_fault_codes_t, can_database_pm100_fault_codes_unpack)
IMPL_HANDLER(can_database_pm100_internal_states_t, can_database_pm100_internal_states_unpack)
IMPL_HANDLER(can_database_pm100_current_info_t, can_database_pm100_current_info_unpack)
IMPL_HANDLER(can_database_pm100_motor_position_info_t, can_database_pm100_motor_position_info_unpack)

/**
 * @brief   Table of CAN message IDs and associated unpacking functions
 */
static const can_handler_t can_handler_table[] = {
    {CAN_DATABASE_PM100_FAULT_CODES_FRAME_ID, 4, can_database_pm100_fault_codes_t_handler},
    {CAN_DATABASE_PM100_INTERNAL_STATES_FRAME_ID, 3, can_database_pm100_internal_states_t_handler},
    {CAN_DATABASE_PM100_CURRENT_INFO_FRAME_ID, 2, can_database_pm100_current_info_t_handler},
    {CAN_DATABASE_PM100_MOTOR_POSITION_INFO_FRAME_ID, 1, can_database_pm100_motor_position_info_t_handler},
};

/**
 * @brief       Returns the CAN handler at the specified index in the table, or 
 *              NULL if out of bounds
 * 
 * @param[in]   index   Index in table
 */
const can_handler_t* can_handler_get(uint32_t index)
{
    const can_handler_t* handler = NULL;

    if (index < CAN_HANDLERS_TABLE_SIZE)
    {
        handler = &can_handler_table[index];
    }

    return handler;
}
