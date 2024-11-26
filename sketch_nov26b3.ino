#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 硬體設定
struct PinConfig {
    static const uint8_t SDA = 26;
    static const uint8_t SCL = 25;
    static const uint8_t LIGHT = 13;
    static const uint8_t RED = 4;
    static const uint8_t GREEN = 2;
    static const uint8_t BLUE = 0;
};

// PWM 設定
struct PWMConfig {
    static const uint32_t FREQ = 5000;
    static const uint8_t RESOLUTION = 8;
    static const uint16_t MAX_DUTY = 255;
    static const uint16_t LIGHT_THRESHOLD = 500;
    static const uint16_t DELAY = 100;
};

class LEDController {
private:
    static void initPWM(uint8_t pin) {
        ledcAttach(pin, PWMConfig::FREQ, PWMConfig::RESOLUTION);
    }

public:
    static void init() {
        initPWM(PinConfig::RED);
        initPWM(PinConfig::GREEN);
        initPWM(PinConfig::BLUE);
    }

    static void setBrightness(uint16_t light_value) {
        uint8_t brightness = map(light_value, 0, 1023, 0, PWMConfig::MAX_DUTY);
        brightness = PWMConfig::MAX_DUTY - brightness;
        
        ledcWrite(PinConfig::RED, brightness);
        ledcWrite(PinConfig::GREEN, brightness);
        ledcWrite(PinConfig::BLUE, brightness);
    }
};

class DisplayController {
private:
    LiquidCrystal_I2C& lcd;

public:
    DisplayController(LiquidCrystal_I2C& lcd_ref) : lcd(lcd_ref) {}

    void init() {
        Wire.begin(PinConfig::SDA, PinConfig::SCL);
        lcd.init();
        lcd.backlight();
    }

    void updateDisplay(uint16_t light_value) {
        lcd.clear();
        
        lcd.setCursor(0,0);
        lcd.print(F("Light Value:"));
        lcd.print(light_value);
        
        lcd.setCursor(0,1);
        lcd.print(light_value < PWMConfig::LIGHT_THRESHOLD ? F("Night") : F("Morning"));
    }
};

LiquidCrystal_I2C lcd(0x27, 16, 2);
DisplayController display(lcd);

void setup() {
    display.init();
    LEDController::init();
    pinMode(PinConfig::LIGHT, INPUT);
    Serial.begin(9600);
}

void loop() {
    static uint16_t light_value;
    light_value = analogRead(PinConfig::LIGHT);
    
    LEDController::setBrightness(light_value);
    display.updateDisplay(light_value);
    
    Serial.print(F("Light Value: "));
    Serial.println(light_value);
    
    delay(PWMConfig::DELAY);
}
