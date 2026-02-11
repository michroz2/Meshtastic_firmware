/*
 * LILYGO T-BEAM V1.0 / V1.1 Definition
 * Адаптировано для Dual LoRa Mod (E22-400M33S / SX1268)
 * Выбор режима определяется дефолтовым энвайроментом tbeam или tbeam-e22-433 
 * в файле platformio.ini
 */

// ==========================================
// 1. ОБЩИЕ ПИНЫ (Одинаковые для обоих режимов)
// ==========================================

// I2C (AXP192/2101, OLED)
#define I2C_SDA 21
#define I2C_SCL 22

// Флаги автоопределения радио (как в оригинале)
    #define USE_RF95 
    #define USE_SX1262 //Этот флаг срабатывает на стандартную ЛоРу
    #define USE_SX1268 //Этот флаг срабатывает на E22-400M33S

// GPS (UBLOX NEO-6M / M8N)
#define GPS_RX_PIN 34
#define GPS_TX_PIN 12
#define GPS_UBLOX

// Кнопки (Middle Button)
#define BUTTON_PIN 38
#define BUTTON_ACTIVE_LOW true
#define BUTTON_ACTIVE_PULLUP true

// Питание (Флаг наличия контроллера питания)
#define HAS_AXP192

// ==========================================
// 1. ОЧИСТКА ОТ СТАРЫХ ЗНАЧЕНИЙ (Лечим варнинги)
// ==========================================
#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS
//#undef LORA_RST
#undef LORA_DIO0
#undef LORA_DIO1
#undef LORA_DIO2
#undef LED_PIN

// ==========================================
// 2. РАЗДЕЛЕНИЕ НА РЕЖИМЫ (MOD vs STOCK)
// ==========================================

#ifdef TBEAM_E22_MOD
    // ----------------------------------------------------
    // РЕЖИМ: E22 MOD (Ваш кастомный модуль SX1268)
    // ----------------------------------------------------
    
    // --- РАЗРЕШЕНИЕ КОНФЛИКТОВ ---
    // Отключаем системные функции на пинах, которые мы забрали под радио:
    #define EXT_NOTIFY_OUT 0  // Отключаем пищалку (был 13), т.к. 13 теперь CS
    #define LED_PIN        4  // Отключаем синий LED (был 4), т.к. 4 теперь TXEN
    
    // --- ПИНЫ SPI (Припаяны к дорожкам) ---
    #define LORA_SCK  5
    #define LORA_MISO 19
    #define LORA_MOSI 27

    // --- УПРАВЛЕНИЕ E22 (С гребенки) ---
    #define LORA_CS   13    // NSS (Chip Select) 
    #define LORA_RESET  14    // Reset
    #define LORA_BUSY 15 //32    // Busy (Статус занятости)
    #define LORA_DIO1 35 //33    // DIO1 (Прерывание)
    
    // --- УПРАВЛЕНИЕ ВНЕШНИМ УСИЛИТЕЛЕМ (RXEN/TXEN) ---
    #define LORA_TXEN 2     // Включение передачи (GPIO 4)
    #define LORA_RXEN 25    // Включение приема (GPIO 25)
    #define SX126X_RXEN  LORA_RXEN
    #define SX126X_TXEN  LORA_TXEN
    
    // --- ВАЖНЫЕ НАСТРОЙКИ ДРАЙВЕРА SX126x ---
    // 1. Принудительно отключаем управление через DIO2. 
    //    Мы используем внешние пины (4 и 25), а не внутренний свитч.
    #undef SX126X_DIO2_AS_RF_SWITCH 
    
    // 2. Указываем напряжение для TCXO (Кварца), обязательно 1.8V для E22
    #define SX126X_DIO3_TCXO_VOLTAGE 1.8

    // --- ОТКЛЮЧЕНИЕ СТАРОГО МОДУЛЯ ---
    // Пин, на который мы подадим HIGH в main.cpp, чтобы "заткнуть" старую LoRa
    #define OLD_LORA_KILL_PIN 18

    // Заглушки для совместимости (эти пины не нужны для SX126x)
    #define LORA_DIO0 0
    #define LORA_DIO2 0
    #define SX126X_BUSY  LORA_BUSY

#else
    // ----------------------------------------------------
    // РЕЖИМ: STOCK (Заводской T-Beam со старым модулем)
    // ----------------------------------------------------
    // Все значения взяты из вашего оригинального файла без изменений
    
    #define EXT_NOTIFY_OUT 13 // Внешний зуммер работает (GPIO 13 свободен)
    #define LED_PIN 4         // Светодиод работает (GPIO 4 свободен)
    #define LED_STATE_ON 0    // Логика светодиода

    // Стандартные пины LoRa (SX1276)
    #define LORA_SCK  5
    #define LORA_MISO 19
    #define LORA_MOSI 27
    #define LORA_CS   18
    #define LORA_RST 23
    #define LORA_RESET 23
    
    // Оригинальная разводка DIO
    #define LORA_DIO0 26 
    #define LORA_DIO1 33 
    #define LORA_DIO2 32 
    
    // Стандартный T-Beam использует DIO2 для переключения антенны
    #define SX126X_DIO2_AS_RF_SWITCH
    #define SX126X_DIO3_TCXO_VOLTAGE 1.8
    #define SX126X_BUSY LORA_DIO2

    // В стоке нам не нужно ничего "убивать"
    #undef OLD_LORA_KILL_PIN

#endif

// ==========================================
// 4. "ПЕРЕВОД" ДЛЯ MAIN.CPP (ALIASES)
// ==========================================
// main.cpp просит SX126X_..., мы перенаправляем его на наши LORA_...

#define SX126X_CS    LORA_CS
#define SX126X_RESET LORA_RESET
#define SX126X_DIO1  LORA_DIO1
#define SX126X_SCK LORA_SCK
#define SX126X_MISO LORA_MISO 
#define SX126X_MOSI LORA_MOSI