#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 26
#define SCL_PIN 25
#define LIGHT_PIN 13
#define LIGHT_THRESHOLD 500
#define DELAY_TIME 100

// 使用 F() 巨集將字串存儲在 Flash 記憶體中
const char MSG_LIGHT[] PROGMEM = "Light Value:";
const char MSG_NIGHT[] PROGMEM = "Night";
const char MSG_MORNING[] PROGMEM = "Morning";

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
    Wire.begin(SDA_PIN, SCL_PIN);
    lcd.init();
    lcd.backlight();
    
    pinMode(LIGHT_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    static uint16_t light_value;  // 使用 uint16_t 替代 int
    
    light_value = analogRead(LIGHT_PIN);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Light Value:"));  // 使用 F() 巨集
    lcd.print(light_value);
    
    lcd.setCursor(0,1);
    lcd.print(light_value < LIGHT_THRESHOLD ? F("Night") : F("Morning"));
    
    Serial.println(light_value);
    
    delay(DELAY_TIME);
}
