
#ifndef CAN_HANDLERS_H
#define CAN_HANDLERS_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define CAN_HANDLERS_TABLE_SIZE 4

/**
 * @brief   Entry in CAN handler table
 */
typedef struct {
    uint32_t identifier;
    uint32_t pdu_id;
    void (*unpack_func)(uint8_t*, const uint8_t*, size_t);
} can_handler_t;

/* 
 * function prototypes
 */
const can_handler_t* can_handler_get(uint32_t index);

#endif
