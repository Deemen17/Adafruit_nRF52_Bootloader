#include "boards.h"
#include "board.h"
#include "uf2/configkeys.h"

__attribute__((used, section(".bootloaderConfig")))
const uint32_t bootloaderConfig[] =
{
  /* CF2 START */
  CFG_MAGIC0, CFG_MAGIC1,                       // magic
  5, 100,                                       // used entries, total entries

  204, 0x100000,                                // FLASH_BYTES = 0x100000
  205, 0x40000,                                 // RAM_BYTES = 0x40000
  208, (USB_DESC_VID << 16) | USB_DESC_UF2_PID, // BOOTLOADER_BOARD_ID = USB VID+PID, used for verification when updating bootloader via uf2
  209, 0xada52840,                              // UF2_FAMILY = 0xada52840
  210, 0x20,                                    // PINS_PORT_SIZE = PA_32

  0, 0, 0, 0, 0, 0, 0, 0
  /* CF2 END */
};

bool is_esc_button_pressed(void)
{
  // Return true if ESC button is pressed (P0.28 is LOW)
  return nrf_gpio_pin_read(_PINNUM(0, 28)) == 0;
}

void board_init2(void)
{
  power_on();

  // configure P0.06 for ESC/BUTTON_1
  // P0.06 --- |<- --- / --- P0.28
  //         diode  sw(esc)
  // mode: output, push-pull, low
  nrf_gpio_cfg(
    _PINNUM(0, 6),
    NRF_GPIO_PIN_DIR_OUTPUT,
    NRF_GPIO_PIN_INPUT_DISCONNECT,
    NRF_GPIO_PIN_PULLUP,
    NRF_GPIO_PIN_H0D1,
    NRF_GPIO_PIN_NOSENSE
  );
  nrf_gpio_pin_write(_PINNUM(0, 6), 0);

  // Configure P0.28 as input for ESC/BUTTON_2
  nrf_gpio_cfg_input(_PINNUM(0, 28), NRF_GPIO_PIN_PULLUP);

  // Configure P0.26 as output and set HIGH
  nrf_gpio_cfg_output(_PINNUM(0, 26));
  nrf_gpio_pin_write(_PINNUM(0, 26), 1);

  // Wait the buttons stable.
  // This is mandatory, or the keyboard will enter bootloader whenever
  // booted by pressing the button at back (same with BUTTON_1)
  NRFX_DELAY_MS(100);
}

void board_teardown2(void)
{
  nrf_gpio_pin_write(_PINNUM(0, 26), 1);
}