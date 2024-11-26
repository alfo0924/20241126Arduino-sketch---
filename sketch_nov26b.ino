#include <Wire.h>                    // 引入I2C通訊函式庫
#include <LiquidCrystal_I2C.h>      // 引入LCD I2C控制函式庫

// 定義I2C通訊使用的腳位
#define SDA_PIN 26                   // 設定SDA資料線為26腳位
#define SCL_PIN 25                   // 設定SCL時脈線為25腳位

// 建立LCD物件，設定I2C位址為0x27，16字元×2行的LCD
LiquidCrystal_I2C lcd(0x27,16,2);   // 如果無法顯示，可能要改為0x3F

void setup() {
    // 初始化I2C通訊，設定SDA和SCL腳位
    Wire.begin(SDA_PIN,SCL_PIN);
    
    lcd.init();                      // 初始化LCD
    lcd.backlight();                 // 開啟LCD背光
    lcd.clear();                     // 清除LCD畫面
    
    pinMode(13, INPUT);              // 設定腳位13為輸入模式
    Serial.begin(9600);              // 啟動序列通訊
}

void loop() {
    int light_value = analogRead(13);    // 讀取光感測器數值
    
    // 在LCD第一行顯示文字
    lcd.setCursor(0,0);
    lcd.print("Light Value:");
    
    // 在LCD第二行顯示光感測器數值
    lcd.setCursor(0,1);
    lcd.print(light_value);
    
    // 同時也透過序列埠輸出數值
    Serial.println(light_value);
    
    delay(100);                      // 延遲100毫秒
    lcd.clear();                     // 清除LCD顯示
}
