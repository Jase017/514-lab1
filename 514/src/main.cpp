#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2  // DHT11传感器连接到Arduino的数字引脚2
#define DHTTYPE DHT11  // 使用DHT11传感器

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 TEST");
  dht.begin();
}

void loop() {
  delay(2000);  // 等待2秒钟以便传感器稳定

  float humidity = dht.readHumidity();  // 读取湿度
  float temperature = dht.readTemperature();  // 读取温度（摄氏度）

  // 检查是否成功读取数据
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("无法从DHT传感器读取数据！");
    return;
  }

  // 打印读取到的数据
  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print("%\ttemperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // 在此可以添加其他处理逻辑

  delay(2000);  // 等待2秒钟，然后重新读取数据
}
