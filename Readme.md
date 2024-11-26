
## 程式碼解析

這是一個 Arduino 的基本程式結構，主要用於讀取類比感測器的數值。

```cpp
void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  Serial.begin(9600);
}
```

**setup() 函式說明**
- 這是 Arduino 程式的初始化區塊，只會在開機時執行一次
- `pinMode(13,INPUT)` 將腳位13設定為輸入模式，準備接收感測器的訊號
- `Serial.begin(9600)` 初始化序列通訊，設定鮑率（Baud Rate）為9600，用於與電腦進行資料傳輸

```cpp
void loop() {
  // put your main code here, to run repeatedly:
  int light_value = analogRead(13);
  Serial.println(light_value);
  delay(100);
}
```

**loop() 函式說明**
- 這是主要的程式區塊，會不斷重複執行
- `analogRead(13)` 讀取腳位13的類比值，範圍是0-1023（10位元解析度）
- `int light_value` 宣告一個整數變數來儲存讀取到的數值
- `Serial.println(light_value)` 將讀取到的數值透過序列埠傳送到電腦
- `delay(100)` 暫停程式執行100毫秒（0.1秒），控制讀取頻率

## 應用場景

這種程式結構常用於：
- 光敏電阻的亮度感測
- 溫度感測器的數值讀取
- 濕度感測器的數值讀取
- 其他需要持續監測類比訊號的應用


# Arduino/ESP32 Blynk 套件：

## Blynk
這是由 Volodymyr Shymanskyy 開發的主要 Blynk 函式庫，版本為 1.3.2。它能讓你快速建立智慧型手機應用程式來控制你的專案，支援 WiFi、乙太網路和行動網路等連接方式[4]。

## BlynkESP32_BT_WF
這是由 Khoi Hoang 開發的擴充套件，版本為 1.2.2。這個套件的特別之處在於：
- 允許在同一個專案中同時包含 ESP32 的藍牙（BT/BLE）和 WiFi 功能
- 可以同時運行 WiFi 和藍牙，或在重啟時選擇其中一種連接方式
- 支援多重 WiFi 和多重 Blynk 連接[3]

這兩個套件結合使用可以讓 ESP32 開發板實現更靈活的連接方式，特別適合需要多重連接方式的物聯網專案。


