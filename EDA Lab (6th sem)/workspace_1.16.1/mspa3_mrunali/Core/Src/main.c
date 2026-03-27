#include "main.h"
#include <stdio.h>
#include "ssd1306.h"
#include "ssd1306_fonts.h"

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim1; // Encoder
TIM_HandleTypeDef htim2; // RGB PWM

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);

/* Global variables for logic */
uint32_t soundValue = 0;
int32_t encoderValue = 0;
int32_t threshold = 500;
char oledBuffer[32];

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();

  /* OLED Startup */
  ssd1306_Init();
  HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); // Red
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); // Green
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); // Blue

  ssd1306_Fill(Black);
  ssd1306_SetCursor(10, 10);
  ssd1306_WriteString("SONIC MONITOR", Font_7x10, White);
  ssd1306_UpdateScreen();
  HAL_Delay(1000);

  while (1)
  {
    /* 1. Read Sound Sensor */
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        soundValue = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);

    /* 2. Read Encoder for Threshold */
    encoderValue = __HAL_TIM_GET_COUNTER(&htim1);
    threshold = 257 + (encoderValue * 10);

    /* 3. Logic for RGB Actuator */
    if (soundValue < threshold) { // QUIET (Green)
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 255);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    } else { // LOUD (Red)
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 255);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }

    /* 4. Display Update */
    ssd1306_Fill(Black);
    sprintf(oledBuffer, "Sound: %lu", soundValue);
    ssd1306_SetCursor(0, 5);
    ssd1306_WriteString(oledBuffer, Font_11x18, White);

    sprintf(oledBuffer, "Limit: %ld", threshold);
    ssd1306_SetCursor(0, 35);
    ssd1306_WriteString(oledBuffer, Font_11x18, White);
    ssd1306_UpdateScreen();

    HAL_Delay(100);
  }
}

/* --- PERIPHERAL INITIALIZATION FUNCTIONS (Required to fix your error) --- */

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
}
static void MX_ADC1_Init(void) {
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK) {
    Error_Handler();
  }

  /** Configure Regular Channel */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;  // <--- Fixed: Using '1' instead of ADC_RANK_CHANNEL_NUMBER
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    Error_Handler();
  }
}
static void MX_I2C1_Init(void) {
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  HAL_I2C_Init(&hi2c1);
}

static void MX_TIM1_Init(void) { // Encoder
  TIM_Encoder_InitTypeDef sConfig = {0};
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.Period = 65535;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  HAL_TIM_Encoder_Init(&htim1, &sConfig);
}

static void MX_TIM2_Init(void) { // RGB PWM
  TIM_OC_InitTypeDef sConfigOC = {0};
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.Period = 255;
  HAL_TIM_PWM_Init(&htim2);
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3);
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4);
}

static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Enable Peripherals Clock */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Configure PA1, PA2, PA3 for PWM (RGB LED) */
  GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Connects Timer to Pins
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* Configure PA8, PA9 for Rotary Encoder */
  GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Error_Handler(void) {
  while(1);
}
