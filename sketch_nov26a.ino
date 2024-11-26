void setup() {
  // 設定初始化，此段程式只會執行一次
  pinMode(13, INPUT);    // 設定腳位13為輸入模式
  Serial.begin(9600);    // 啟動序列通訊，鮑率設為9600
}

void loop() {
  // 主要程式區塊，會重複執行
  int light_value = analogRead(13);    // 讀取腳位13的類比值並儲存到 light_value 變數
  Serial.println(light_value);         // 將讀取到的數值透過序列埠輸出
  delay(100);                          // 延遲100毫秒再執行下一次讀取
}
