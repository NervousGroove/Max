/*
      Programa para Robo Espiao - ESP32-CAM com PanTilt
      
      Baseado em: https://www.youtube.com/watch?v=pD2VFKUlWC8&t=804s by Hash Robotics
      
      Componentes:
        - ESP-32 CAM;
        - Módulo L293N;
        - Suporte Pan Tilt;
        - 2 Micro Servos SG90;
        - 4 Motores DC com redução.

      Versão 1.0 - Versão inicial com controle pan tilt e camera em webserver - 27/Fev/2021
      
 *    * Criado por Cleber Borges - FunBots - @cleber.funbots  *     *

      Instagram: https://www.instagram.com/cleber.funbots/
      Facebook: https://www.facebook.com/cleber.funbots
      YouTube: https://www.youtube.com/channel/UCKs2l5weIqgJQxiLj0A6Atw
      Telegram: https://t.me/cleberfunbots

*/

#include "esp_wifi.h"
#include "esp_camera.h"
#include <WiFi.h>

/* Wifi Crdentials */
const char* ssid = "REDEWIFI";
const char* password = "SENHAWIFI";

#define CAMERA_MODEL_AI_THINKER

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

void startCameraServer();

/* Defining motor and servo pins */
const int RMotor1 = 14;
const int RMotor2 = 15;
const int LMotor1 = 13;
const int LMotor2 = 16;//12;
const int Servo1Pin = 2;
//const int Servo2Pin = 16;

void initMotors()
{
  /* Configuring motor PWM functionalities to generate the signal */
  /* ledcSetup(Channel, Frequency, Resolution) */
  ledcSetup(3, 2000, 8); /* 2000 hz PWM, 8-bit resolution and range from 0 to 255 */
  ledcSetup(4, 2000, 8); /* 2000 hz PWM, 8-bit resolution and range from 0 to 255 */
  ledcSetup(5, 2000, 8); /* 2000 hz PWM, 8-bit resolution and range from 0 to 255 */
  ledcSetup(6, 2000, 8); /* 2000 hz PWM, 8-bit resolution and range from 0 to 255 */

  /* Attaching the channel to the GPIO to be controlled */
  /* ledcAttachPin(GPIO, Channel) */
  ledcAttachPin(RMotor1, 3);
  ledcAttachPin(RMotor2, 4);
  ledcAttachPin(LMotor1, 5);
  ledcAttachPin(LMotor2, 6);

}

void initServo1() {
  ledcSetup(8, 50, 16); /*50 hz PWM, 16-bit resolution and range from 3250 to 6500 */
  ledcAttachPin(Servo1Pin, 8);
}

void initServo2() {
//  ledcSetup(7, 50, 16); /*50 hz PWM, 16-bit resolution and range from 3250 to 6500 */
//  ledcAttachPin(Servo2Pin, 7);
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if (psramFound()) {
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  //drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_QVGA);
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);

  /* Initializing motor,servo and led */
  initMotors();
  initServo1();
  initServo2();

  /* Connecting to WiFi */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();/* Starting camera server */

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  //WiFiAddr = WiFi.localIP().toString();
  Serial.println("' to connect");

  /* Flash led */
 /* for (int i = 0; i < 5; i++) {
    ledcWrite(7, 10);
    delay(50);
    ledcWrite(7, 0);
    delay(50);
  }*/
}

void loop() {
  // put your main code here, to run repeatedly:

}
