
#ifndef CAN_HANDLERS_H
#define CAN_HANDLERS_H

#include <stdint.h>

/**
 * @brief   Entry in CAN handler table
 */
typedef struct {
    uint32_t identifier;
    void (*unpack_func)(uint8_t*, const uint8_t*, size_t);
} can_handler_t;

/* 
 * function prototypes
 */
const can_handler_t* can_handler_get(uint32_t index);
uint32_t can_handler_table_size();

#endif
