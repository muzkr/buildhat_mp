// Board and hardware specific configuration
#define MICROPY_HW_BOARD_NAME                   "Raspberry Pi Build HAT"
// 1 MB 
#define MICROPY_HW_FLASH_STORAGE_BYTES          (1024 * 1024)
// Reserve 64 KB at the end
#define MICROPY_HW_FLASH_STORAGE_BASE           (PICO_FLASH_SIZE_BYTES - MICROPY_HW_FLASH_STORAGE_BYTES - (64 * 1024))
#define MICROPY_HW_ENABLE_UART_REPL             (1)
#define MICROPY_HW_ENABLE_USBDEV                (0)
