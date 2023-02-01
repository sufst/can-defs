
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

IMPL_HANDLER(can_database_m173_modulation_and_flux_info_t, can_database_m173_modulation_and_flux_info_unpack)
IMPL_HANDLER(can_database_m172_torque_and_timer_info_t, can_database_m172_torque_and_timer_info_unpack)
IMPL_HANDLER(can_database_m194_read_write_param_response_t, can_database_m194_read_write_param_response_unpack)
IMPL_HANDLER(can_database_m193_read_write_param_command_t, can_database_m193_read_write_param_command_unpack)
IMPL_HANDLER(can_database_m192_command_message_t, can_database_m192_command_message_unpack)
IMPL_HANDLER(can_database_m171_fault_codes_t, can_database_m171_fault_codes_unpack)
IMPL_HANDLER(can_database_m170_internal_states_t, can_database_m170_internal_states_unpack)
IMPL_HANDLER(can_database_m169_internal_voltages_t, can_database_m169_internal_voltages_unpack)
IMPL_HANDLER(can_database_m168_flux_id_iq_info_t, can_database_m168_flux_id_iq_info_unpack)
IMPL_HANDLER(can_database_m167_voltage_info_t, can_database_m167_voltage_info_unpack)
IMPL_HANDLER(can_database_m166_current_info_t, can_database_m166_current_info_unpack)
IMPL_HANDLER(can_database_m165_motor_position_info_t, can_database_m165_motor_position_info_unpack)
IMPL_HANDLER(can_database_m164_digital_input_status_t, can_database_m164_digital_input_status_unpack)
IMPL_HANDLER(can_database_m163_analog_input_voltages_t, can_database_m163_analog_input_voltages_unpack)
IMPL_HANDLER(can_database_m162_temperature_set_3_t, can_database_m162_temperature_set_3_unpack)
IMPL_HANDLER(can_database_m161_temperature_set_2_t, can_database_m161_temperature_set_2_unpack)
IMPL_HANDLER(can_database_m160_temperature_set_1_t, can_database_m160_temperature_set_1_unpack)
IMPL_HANDLER(can_database_m174_firmware_info_t, can_database_m174_firmware_info_unpack)
IMPL_HANDLER(can_database_m175_diag_data_t, can_database_m175_diag_data_unpack)
IMPL_HANDLER(can_database_bms_current_limit_t, can_database_bms_current_limit_unpack)
IMPL_HANDLER(can_database_m176_fast_info_t, can_database_m176_fast_info_unpack)

/**
 * @brief   Table of CAN message IDs and associated unpacking functions
 */
static const can_handler_t can_handler_table[] = {
    {CAN_DATABASE_M173_MODULATION_AND_FLUX_INFO_FRAME_ID, can_database_m173_modulation_and_flux_info_t_handler},
    {CAN_DATABASE_M172_TORQUE_AND_TIMER_INFO_FRAME_ID, can_database_m172_torque_and_timer_info_t_handler},
    {CAN_DATABASE_M194_READ_WRITE_PARAM_RESPONSE_FRAME_ID, can_database_m194_read_write_param_response_t_handler},
    {CAN_DATABASE_M193_READ_WRITE_PARAM_COMMAND_FRAME_ID, can_database_m193_read_write_param_command_t_handler},
    {CAN_DATABASE_M192_COMMAND_MESSAGE_FRAME_ID, can_database_m192_command_message_t_handler},
    {CAN_DATABASE_M171_FAULT_CODES_FRAME_ID, can_database_m171_fault_codes_t_handler},
    {CAN_DATABASE_M170_INTERNAL_STATES_FRAME_ID, can_database_m170_internal_states_t_handler},
    {CAN_DATABASE_M169_INTERNAL_VOLTAGES_FRAME_ID, can_database_m169_internal_voltages_t_handler},
    {CAN_DATABASE_M168_FLUX_ID_IQ_INFO_FRAME_ID, can_database_m168_flux_id_iq_info_t_handler},
    {CAN_DATABASE_M167_VOLTAGE_INFO_FRAME_ID, can_database_m167_voltage_info_t_handler},
    {CAN_DATABASE_M166_CURRENT_INFO_FRAME_ID, can_database_m166_current_info_t_handler},
    {CAN_DATABASE_M165_MOTOR_POSITION_INFO_FRAME_ID, can_database_m165_motor_position_info_t_handler},
    {CAN_DATABASE_M164_DIGITAL_INPUT_STATUS_FRAME_ID, can_database_m164_digital_input_status_t_handler},
    {CAN_DATABASE_M163_ANALOG_INPUT_VOLTAGES_FRAME_ID, can_database_m163_analog_input_voltages_t_handler},
    {CAN_DATABASE_M162_TEMPERATURE_SET_3_FRAME_ID, can_database_m162_temperature_set_3_t_handler},
    {CAN_DATABASE_M161_TEMPERATURE_SET_2_FRAME_ID, can_database_m161_temperature_set_2_t_handler},
    {CAN_DATABASE_M160_TEMPERATURE_SET_1_FRAME_ID, can_database_m160_temperature_set_1_t_handler},
    {CAN_DATABASE_M174_FIRMWARE_INFO_FRAME_ID, can_database_m174_firmware_info_t_handler},
    {CAN_DATABASE_M175_DIAG_DATA_FRAME_ID, can_database_m175_diag_data_t_handler},
    {CAN_DATABASE_BMS_CURRENT_LIMIT_FRAME_ID, can_database_bms_current_limit_t_handler},
    {CAN_DATABASE_M176_FAST_INFO_FRAME_ID, can_database_m176_fast_info_t_handler},
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

    if (index < can_handler_table_size())
    {
        handler = &can_handler_table[index];
    }

    return handler;
}

/**
 * @brief   Returns the number of CAN handlers in the table
 */
uint32_t can_handler_table_size()
{
    return sizeof(can_handler_table) / sizeof(can_handler_table[0]);
}
