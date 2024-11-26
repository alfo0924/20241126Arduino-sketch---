
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
